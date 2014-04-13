#ifndef __GLORY_AUTOC_H__
#define __GLORY_AUTOC_H__

#include <Python.h>
#include <string>
#include "glory_window.h"

using namespace std;

#define FIND_IMPORT 			1
#define FIND_FROM 				2
#define FIND_FROM_IMPORT		3

class AutoCompleteManager {
protected:
	struct nxGloryChildren * parent;
public:
	AutoCompleteManager():parent(NULL){};
	AutoCompleteManager(struct nxGloryChildren * par):parent(par){};
	virtual ~AutoCompleteManager(){};

	virtual int Begin(void * arguments) = 0;
	virtual void Done() = 0;
	virtual bool ShowAutoComplete(char ch) = 0;
	virtual char * FillAutoCompleteList(int command) = 0;
	virtual int  SyntaxEngine_FackExecution(string statement) = 0;
};

class AutoCompleteManagerPython : public AutoCompleteManager {
private:
	string autoc_str;
public:
	AutoCompleteManagerPython (struct nxGloryChildren * _par):AutoCompleteManager(_par) {};
	~AutoCompleteManagerPython () {cout<<"Python Autoc: destory"<<endl;};

	int Begin(void * arguments);
	void Done();
	bool ShowAutoComplete(char ch);
	char * FillAutoCompleteList(int command);
	int  SyntaxEngine_FackExecution(string statement);
};

static inline
bool _is_alpha(char c) {
	if ( (c >= 'A' && c <= 'Z') ||
		 (c >= 'a' && c <= 'z') ||
		 (c >= '0' && c <= '9') ||
		 (c == '_') )
		return true;
	return false;
}

static inline
AutoCompleteManager * create_python_autoc_manager(struct nxGloryChildren * parent) {
	AutoCompleteManagerPython * ret = new AutoCompleteManagerPython(parent);
	return ret;
}


#endif