#ifndef __GLORY_AUTOC_H__
#define __GLORY_AUTOC_H__

#include <Python.h>
#include <string>
#include <stack>
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
	virtual const char * FillAutoCompleteList(int command) = 0;
};

class AutoCompleteManagerPython : public AutoCompleteManager {
private:
	string autoc_str;
	PyObject * py_env_base;
	volatile PyObject * py_env_current;
	stack<PyObject*> py_env_frame;
	
public:
	string stage_buf;
	int indent_level;
	int last_frame_level;
	int last_dir_builtin;
	//PyObject * py_global_environment;
	//PyObject * py_locale_environment;
	int AddToStage(string & stage);
	void FlushStage();
	PyObject * GetCurrentEnv(){return (PyObject*)py_env_current;};
	void PushCurrentEnv();
	void PopCurrentEnv();
	AutoCompleteManagerPython (struct nxGloryChildren * _par):AutoCompleteManager(_par),last_frame_level(0) {
		last_dir_builtin = -1;
	};
	~AutoCompleteManagerPython () {
		cout<<"Python Autoc: destory"<<endl;
		Done();
	};

	int Begin(void * arguments);
	void Done();
	bool ShowAutoComplete(char ch);
	const char * FillAutoCompleteList(int command);
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