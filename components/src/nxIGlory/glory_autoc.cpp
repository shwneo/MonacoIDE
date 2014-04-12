#include <iostream>
#include "glory_autoc.h"


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
	return false;
}

int AutoCompleteManagerPython::FillAutoComplete(int command) {
	return 0;
}