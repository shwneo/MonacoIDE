#include "nxFerrando.h"
#include "nsIClassInfoImpl.h"
#include "mozilla/ModuleUtils.h"

#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/* Implementation file */
NS_IMPL_ISUPPORTS1(nxFerrando, nxIFerrando)

nxFerrando::nxFerrando()
{
  /* member initializers and constructor code */
}

nxFerrando::~nxFerrando()
{
  /* destructor code */
}

/* long Add (in long a, in long b); */
NS_IMETHODIMP nxFerrando::Add(int32_t a, int32_t b, int32_t *_retval)
{
	//return NS_ERROR_NOT_IMPLEMENTED;
	if (!_retval)
		return NS_ERROR_NULL_POINTER;
	*_retval = a + b;
	return NS_OK;
}

string Unichar2str(const wchar_t * unichar) {
	char * c_str;
	int AStrSize = WideCharToMultiByte(CP_ACP, 0, unichar, -1, NULL, 0, NULL, NULL);
	c_str = new char[AStrSize+1]; // the ANSI char version of the string paramter
	if (!WideCharToMultiByte(CP_ACP, 0, unichar, -1, c_str, AStrSize, NULL, NULL)) {
		delete [] c_str;
		printf("Cmd-Str Warnning Failed to convert wstring\n");
	}
	string ret(c_str);
	delete [] c_str;
	return ret;
}

#define F_CREATE_FORCE 0x10

/* long CreateFileFromTemplate (in wstring file_path_name, in wstring template_file, in wstring project_file); */
NS_IMETHODIMP nxFerrando::CreateFileFromTemplate(const PRUnichar * file_path_name, int32_t construct_type, const PRUnichar * template_file, const PRUnichar * project_file, int32_t *_retval)
{
	if (!_retval)
		return NS_ERROR_NULL_POINTER;

	string file_name = Unichar2str(file_path_name);
	string temp_str = Unichar2str(template_file);
	string proj_file = Unichar2str(project_file);
	cout<<"Ferrando: get output file name ["<<file_name<<"]"<<endl;
	cout<<"Ferrando: get template string ["<<temp_str<<"]"<<endl;
	cout<<"Ferrando: get project file ["<<proj_file<<"]"<<endl;

	ifstream new_i_file(file_name);
	if (!(construct_type & F_CREATE_FORCE)) {
		if (new_i_file) {
			cout<<"file exist!"<<endl;
			*_retval = 3776;
			return NS_OK;
		}
	}
	ofstream new_o_file(file_name);
	if (!new_o_file) {
		cout<<"cannot create file "<<new_o_file<<endl;
		*_retval = 3521;
		return NS_OK;
	}

	new_o_file<<temp_str;
	new_o_file.close();

	*_retval = 0;
    return NS_OK;
}

/* End of implementation class template. */

NS_GENERIC_FACTORY_CONSTRUCTOR(nxFerrando)
NS_DEFINE_NAMED_CID(NX_FERRANDO_CID);

static const mozilla::Module::CIDEntry kFerrandoCIDs[] = {
    { &kNX_FERRANDO_CID, false, NULL, nxFerrandoConstructor },
    { NULL }
};

static const mozilla::Module::ContractIDEntry kFerrandoContracts[] = {
    { NX_FERRANDO_CONTRACTID, &kNX_FERRANDO_CID },
    { NULL }
};

static const mozilla::Module::CategoryEntry kFerrandoCategories[] = {
    { "my-category", "my-key", NX_FERRANDO_CONTRACTID },
    { NULL }
};

static const mozilla::Module kFerrandoModule = {
    mozilla::Module::kVersion,
    kFerrandoCIDs,
    kFerrandoContracts,
    kFerrandoCategories
};

NSMODULE_DEFN(nxFerrandoModule) = &kFerrandoModule;
NS_IMPL_MOZILLA192_NSGETMODULE(&kFerrandoModule)

