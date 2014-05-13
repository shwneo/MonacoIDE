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
	PyObject * main_module = PyImport_AddModule("__main__");
	py_env_current = py_env_base = PyModule_GetDict(main_module);
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
	return 0;
}

static bool need_execute(string & line_statement, AutoCompleteManagerPython * vm) {
	cout<<"[python] Seeing what to be done with:\n>>>"<<line_statement<<"\n"<<endl;
	regex reg_global_stage("^[0-9a-zA-Z_]+.*");
	regex reg_sub_stage_start(".+:\\s*[\n\r]+$");
	regex reg_sub_stage("^\\s+.+");
	regex reg_empty_line("^\\s*[\n\r]+$");
	regex reg_retrun_stage("^\\s*return[\\s+\\n].*");
	
	if ( regex_match( line_statement, reg_sub_stage_start ) ) {
		cout<<"[python] sub statement start, execute later..."<<endl;
		vm->stage_buf += line_statement;
		vm->indent_level = 1;
		return false;
	}
	if ( regex_match( line_statement, reg_retrun_stage) ) {
		cout<<"[python] return statement"<<endl;
		vm->stage_buf += line_statement;
		vm->indent_level = -1;
		return false;
	}
	if ( regex_match( line_statement, reg_global_stage) ) {
		cout<<"[python] global statement, execute now..."<<endl;
		goto REJOIN;
	}
	if ( regex_match( line_statement, reg_empty_line) ) {
		cout<<"[python] new empty line"<<endl;
		goto REJOIN;
	}
	if ( regex_match( line_statement, reg_sub_stage) ) {
		cout<<"[python] sub statement, execute later..."<<endl;
		vm->stage_buf += line_statement;
		return false;
	}
REJOIN:
	if ( ! vm->stage_buf.empty() ) {
		cout<<"[python] re-join sub statement"<<endl;
		line_statement += vm->stage_buf;
		vm->stage_buf.clear();
	}
	return true;
}

static int evaluate_execute(string & line_statement, AutoCompleteManagerPython * vm) {
	//PyRun_SimpleString(line_statement.c_str());
	cout<<"[python] Runnint >>>"<<endl;
	cout<<line_statement<<endl;
	
	if (PyRun_String( line_statement.c_str(), Py_file_input, 
					vm->GetCurrentEnv(), vm->GetCurrentEnv() ) == NULL) {
		cout<<"Execut failed!"<<endl;
		return -1;
	}
	cout<<"Execut success!"<<endl;
	return 0;
}

static int python_dir(string & obj, AutoCompleteManagerPython * vm, set<string> & ret_set)  {
	int ret;
	string _dir_("dir(");
	_dir_ += obj;
	_dir_ += ")";
	cout<<"[python] diring "<<_dir_<<endl;
	PyObject * _result = PyRun_String(_dir_.c_str(), Py_eval_input, vm->GetCurrentEnv(), vm->GetCurrentEnv());
	if ( _result && PyList_Check( _result )) {
		for ( int i = 0; i < PyList_Size(_result); ++i ) {
			char * res_item = PyString_AsString( PyList_GetItem(_result, i));
			if ( res_item ) {
				//ret += res_item;
				//ret += " ";
				ret_set.insert(string(res_item));
				ret++;
			}
		}
	}
	return ret;
}

static inline bool _is_subexpression_alpha(char ch) {
	if ( ch == '.' ||
		 ch == '_' ||
		 (ch >= 'a' && ch <= 'z') ||
		 (ch >= 'A' && ch <= 'Z') ||
		 (ch >= '0' && ch <= '9')
		) {
		return true;
	}
	return false;
}

char * get_subexpression_from_line(char * line_buffer, int length) {
	int start = length - 1;
	cout<<"len = "<<length<<endl;
	while ( start > 0 &&  _is_subexpression_alpha( line_buffer[ start - 1 ] ) ) {
		--start;
	}
	cout<<"start = "<<start<<endl;
	return line_buffer + start;
}

bool AutoCompleteManagerPython::ShowAutoComplete(char ch) {
	char linebuf[512]={0};
	int current; 
	int pos, line_num, edit_pos, line_size;
	int startword;
	bool any_active;
	int tab_width, indent, ws_size, last_indent = 0;
	string indent_buffer = "";
	string buffered_line;
	string dir_subexpression = "";
	set<string> autoc_str_set;
	set<string>::iterator autoc_str_set_itor;
	/* get neareast word */
	if ( parent ) {
		current = parent->ngCommand( parent->ngInstance, SCI_GETCURLINE, 512, int(linebuf) );
		if ( current < 512 ) {
			linebuf[current - 1] = '\0';
		} else {
			return false;
		}
		pos = parent->ngCommand( parent->ngInstance, SCI_GETCURRENTPOS, 0, 0 );
		startword = current - 1;
		while ( startword > 0 && _is_alpha( linebuf[startword - 1] ) ) {
			--startword;
		}
	} else {
		return false;
	}
	string curr_word( linebuf + startword );
	string line_statement( linebuf );
	regex reg( "\\s*from\\s+(\\w+)\\+import" );
	smatch m;
	switch ( ch ) {
		case ' ':
		if ( curr_word.compare( "import" ) == 0 ) {
			if ( regex_search( line_statement, m, reg ) ) {
				/* this is in a 'from XXX import XXXX' */
			} else {
				/* this is in a 'import xxx' or a 'import xxx as xxxx' */
				if ( show_modules_and_packages( autoc_str ) == 0 ) {
					return true;
				}
			}
		} else 
		if ( curr_word.compare("from") == 0 ) {
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
			buffered_line = linebuf;
			if ( need_execute(buffered_line, this) ) {
				if (evaluate_execute(buffered_line, this) != 0 ) {
					cout<<"[python] TODO: handle running exceptions!"<<endl;
				}
			}
			
			tab_width = parent->ngCommand(parent->ngInstance, SCI_GETTABWIDTH, 0, 0);
			
			if ( line_num >= 1 ) {
				last_indent = parent->ngCommand(parent->ngInstance, SCI_GETLINEINDENTATION, line_num - 1, 0);
			}
			cout<<"Get line "<<line_num - 1<<" ident width "<<last_indent<<endl;
			indent = 0;
			if ( tab_width ) {
				indent = last_indent / tab_width;
			} else {
				indent = last_indent;
			}
			indent += this->indent_level;
			
			while ( 0 < indent--) {
				//parent->ngCommand(parent->ngInstance, SCI_INSERTTEXT, edit_pos, (int)"\t");
				indent_buffer += "\t";
			}
			parent->ngCommand(parent->ngInstance, SCI_REPLACESEL, 0, (int)indent_buffer.c_str());
			this->indent_level = 0;
			cout<<"[python] with sub statement = "<<stage_buf<<endl;
		break;
		case '.':
			autoc_str_set.clear();
			autoc_str = "";
			dir_subexpression = get_subexpression_from_line(linebuf, current);
			cout<<"[Python] dot subexpression = "<<dir_subexpression<<endl;
			//python_dir(curr_word, this, autoc_str_set);
			python_dir(dir_subexpression, this, autoc_str_set);
			for ( autoc_str_set_itor = autoc_str_set.begin(); autoc_str_set_itor != autoc_str_set.end(); ++autoc_str_set_itor ) {
				autoc_str += *autoc_str_set_itor;
				autoc_str += " ";
			}
			if ( !autoc_str.empty() ) {
				return true;
			}
		break;
		default:
			any_active = parent->ngCommand(parent->ngInstance, SCI_AUTOCACTIVE, 0, 0);
			edit_pos = parent->ngCommand(parent->ngInstance, SCI_GETCURRENTPOS, 0, 0);
			line_num = parent->ngCommand(parent->ngInstance, SCI_LINEFROMPOSITION, edit_pos, 0);
			if ( any_active ) {
				return false;
			} else {
				if ( ch == '_' ||
					 (ch >= 'a' && ch <= 'z') ||
					 (ch >= 'A' && ch <= 'Z') ) {
					if ( line_num != last_dir_builtin ) {
						autoc_str = "";
						autoc_str_set.clear();
						python_dir(string("__builtins__"), this, autoc_str_set);
						python_dir(string(" "), this, autoc_str_set);
						last_dir_builtin = line_num;
					}
					for ( autoc_str_set_itor = autoc_str_set.begin(); autoc_str_set_itor != autoc_str_set.end(); ++autoc_str_set_itor ) {
						autoc_str += *autoc_str_set_itor;
						autoc_str += " ";
						cout<<*autoc_str_set_itor<<endl;
					}
					
					return true;
				}
			}
		break;
	};
	return false;
}

const char * AutoCompleteManagerPython::FillAutoCompleteList(int command) {
	return autoc_str.c_str();
}

/*
 * Copy another dict object from current environment, then push the current environment
 * into the env stack
 */
void AutoCompleteManagerPython::PushCurrentEnv() {
	PyObject * new_frame = PyDict_Copy(GetCurrentEnv());
	py_env_frame.push(GetCurrentEnv());
	py_env_current = new_frame;
}

/*
 * Delete the current environment, replace it with the one from the stack top
 */
 void AutoCompleteManagerPython::PopCurrentEnv() {
 	if ( py_env_frame.empty() )
 		return;
 	PyObject_Del(GetCurrentEnv());
 	py_env_current = py_env_frame.top();
 	py_env_frame.pop();
 }

int AutoCompleteManagerPython::AddToStage(string & stage) {
	return 0;
}

void AutoCompleteManagerPython::FlushStage() {

}