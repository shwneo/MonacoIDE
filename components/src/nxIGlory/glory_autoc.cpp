#include <iostream>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/regex.hpp>
#include <set>
#include <string.h>
#include "Scintilla.h"
#include "SciLexer.h"
#include "glory_autoc.h"

using namespace boost;
namespace fs = boost::filesystem;

int AutoCompleteManagerPython::Begin(void * arguments) {
	Py_Initialize();
	if ( ! Py_IsInitialized() ) {
		return -1;
	}

	std::cout<<"Python AutoC init"<<std::endl;
	return 0;
}

void AutoCompleteManagerPython::Done() {
	std::cout<<"Python AutoC uninit"<<std::endl;
	Py_Finalize();
}

int show_modules_and_packages(string & word_list) {
	word_list = "";
	set<string> py_modules;
	PyRun_SimpleString("import sys");
	PyObject * pyName = PyString_FromString("sys");
	PyObject * sys = PyImport_Import(pyName);
	PyObject * dict = PyModule_GetDict(sys);
	PyObject * path_obj = PyDict_GetItemString(dict, "path");
	if ( ! PyList_Check(path_obj) ) {
		return -1;
	}
	for ( Py_ssize_t i = 0; i < PyList_Size(path_obj); ++i ) {
		char * path_item = PyString_AsString(PyList_GetItem(path_obj, i));
		fs::path search_path(path_item);
		string item_name;
		if ( fs::exists( search_path ) && fs::is_directory( search_path ) ) {
			fs::directory_iterator end_itor;
			for ( fs::directory_iterator dir_itor( search_path ); dir_itor !=  end_itor; ++dir_itor) {
				try {
					if ( fs::is_directory( dir_itor->status() ) ) {

					} else
					if ( fs::is_regular_file( dir_itor->status() ) ) {
						item_name = dir_itor->path().filename().string();
						regex reg("(\\w+).(pyc|pyd|pyw|py)$");
						smatch m;
						if ( boost::regex_search(item_name, m, reg) ) {
							py_modules.insert(m[1].str());
						}
					}
				} catch ( std::exception & ex ) {

				}
			}
		}
	}
	set<string>::iterator set_itor = py_modules.begin();
	while ( set_itor != py_modules.end() ) {
		string mod = * set_itor;
		word_list += " ";
		word_list += mod;
		//cout<<"[Module] "<<mod<<endl;
		++set_itor;
	}
}

/* The heat of the `fake execution` mechanism */
/* We will not execut every statment of the Python source */
/* Sence there would be one or more `while 1` loop(s) in the source */
/* That could cause the execut thread going to a infinite loop*/

/* Sure to be excuted, report errors*/
static regex reg_import("\\s*import\\s+");
static regex reg_from_import("\\s*from\\s+");
/* The assignment case is a little complicated: */
/* If the r-value object (or some part of it) is an executable function, then don't execute this evaluate and
   assign the l-value as an `None` object;
   If the r-value object is an executable class object constructor, then don't execute this evaluate and 
   log the l-value with the type name of the class object, the future `.` calling to the l-value would be
   assign to the class object .
   If the r-value object is NOT an executable object, then execut the evaluate happly, the virtual machine
   would taking care of the syntax errors */
static regex reg_assignment("\\s*(\\w+)\\s*=\\s*(\\.+)");
static regex reg_def_function("\\s*def\\s+");
static regex reg_def_classes("\\s*class\\s+");
/* Must NOT been excuted! Look after the syntax errors ourself */
static regex reg_while_loop("\\s*while\\s+");
static regex reg_for_loop("\\s*for\\s+");
/* Rest lines of the file */
/* Setp 1: Try to use `hasattr('__call__')` to find out wether the object could be excuted*/
/* Setp 2: Check the return value of `hasattr('__call__')`. If true, ignore it; 
           If false or the calling been fault, execut the statment happly.
           The virtual machine would taking care of the syntax errors */

bool need_execute(string & line_statement) {
	cout<<"[python] Seeing what to be done with:\n>>>"<<line_statement<<"\n"<<endl;

	return false;
}

bool AutoCompleteManagerPython::ShowAutoComplete(char ch) {
	char linebuf[512];
	int current; 
	int pos, line_num, edit_pos, line_size;
	int startword;
	/* get neareast word */
	if ( parent ) {
		current = parent->ngCommand(parent->ngInstance, SCI_GETCURLINE, 512, int(linebuf));
		if ( current < 512 ) {
			linebuf[current - 1] = '\0';
		} else {
			return false;
		}
		pos = parent->ngCommand(parent->ngInstance, SCI_GETCURRENTPOS, 0, 0);
		startword = current - 1;
		while ( startword > 0 && _is_alpha(linebuf[startword - 1]) ) {
			--startword;
		}
	} else {
		return false;
	}
	string curr_word(linebuf + startword);
	string line_statement(linebuf);
	regex reg("\\s*from\\s+(\\w+)\\+import");
	smatch m;
	switch ( ch ) {
		case ' ':
		if ( curr_word.compare("import") ) {
			if ( regex_search(line_statement, m, reg) ) {
				/* this is in a 'from XXX import XXXX' */
			} else {
				/* this is in a 'import xxx' or a 'import xxx as xxxx' */
				if ( show_modules_and_packages( autoc_str ) == 0 ) {
					return true;
				}
			}
		} else 
		if ( curr_word.compare("from") ) {
			if ( show_modules_and_packages( autoc_str ) == 0 ) {
					return true;
			}
		}
		break;
		case '\n':
			edit_pos = parent->ngCommand(parent->ngInstance, SCI_GETCURRENTPOS, 0, 0);
			line_num = parent->ngCommand(parent->ngInstance, SCI_LINEFROMPOSITION, edit_pos, 0);
			cout<<"[python] ... new line : "<<line_num<<endl;
			line_size = parent->ngCommand(parent->ngInstance, SCI_GETLINE, line_num - 1, 0);
			if ( line_size >= 512 ) {
				cout<<"[python] long line not be processed"<<endl;
				/* TODO: Re-alloc buffer for containing the whole line */
				break;
			}
			//memset(linebuf, 0, 512);
			line_size = parent->ngCommand(parent->ngInstance, SCI_GETLINE, line_num - 1, (int)linebuf);
			cout<<"[python] get line size = "<<line_size<<endl;
			linebuf[line_size] = '\0';
			//cout<<"[python] processing line statement `"<<linebuf<<"`"<<endl;
			if ( need_execute(string(linebuf)) ) {

			}
		break;
	};
	return false;
}

const char * AutoCompleteManagerPython::FillAutoCompleteList(int command) {
	return autoc_str.c_str();
}

int AutoCompleteManagerPython::SyntaxEngine_FackExecution(string statement) {
	return 0;
}