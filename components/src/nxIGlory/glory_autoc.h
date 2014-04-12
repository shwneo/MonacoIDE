#ifndef __GLORY_AUTOC_H__
#define __GLORY_AUTOC_H__

#include <Python.h>
#include "glory_window.h"


#define FIND_IMPORT 			1
#define FIND_FROM 				2
#define FIND_FROM_IMPORT		3

class AutoCompleteManager {
private:
	struct nxGloryChildren * parent;
public:
	AutoCompleteManager():parent(NULL){};
	AutoCompleteManager(struct nxGloryChildren * par):parent(par){};
	virtual ~AutoCompleteManager(){};

	virtual int Begin(void * arguments) = 0;
	virtual void Done() = 0;
	virtual bool ShowAutoComplete(char ch) = 0;
	virtual int FillAutoComplete(int command) = 0;

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
	int FillAutoComplete(int command);
};

static inline
AutoCompleteManager * create_python_autoc_manager(struct nxGloryChildren * parent) {
	AutoCompleteManagerPython * ret = new AutoCompleteManagerPython(parent);
	return ret;
}


#endif