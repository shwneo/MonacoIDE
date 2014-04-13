#include <iostream>
#include <boost/regex.hpp>
#include "Scintilla.h"
#include "SciLexer.h"
#include "glory_autoc.h"

using namespace boost;

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

bool AutoCompleteManagerPython::ShowAutoComplete(char ch) {
	char linebuf[512];
	int current; 
	int pos;
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

			}
		}
		break;
	};
	return false;
}

char * AutoCompleteManagerPython::FillAutoCompleteList(int command) {
	return NULL;
}

int AutoCompleteManagerPython::SyntaxEngine_FackExecution(string statement) {
	return 0;
}