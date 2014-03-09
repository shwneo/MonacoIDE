#include "nxForeginCaller.h"
#include "nsIClassInfoImpl.h"
#include "mozilla/ModuleUtils.h"

#include <Windows.h>

/* Implementation file */
NS_IMPL_ISUPPORTS1(nxForeginCaller, nxIForeginCaller)

nxForeginCaller::nxForeginCaller()
{
  /* member initializers and constructor code */
}

nxForeginCaller::~nxForeginCaller()
{
  /* destructor code */
}

/* long Add (in long a, in long b); */
NS_IMETHODIMP nxForeginCaller::Add(int32_t a, int32_t b, int32_t *_retval)
{
	if (!_retval)
		return NS_ERROR_NULL_POINTER;
	*_retval = a + b;
    return NS_OK;
}

/* long ForeginCall (in wstring command); */
NS_IMETHODIMP nxForeginCaller::ForeginCall(const PRUnichar * command, int32_t *_retval)
{
	if (!_retval)
		return NS_ERROR_NULL_POINTER;
//#ifdef WIN32
	PROCESS_INFORMATION piProcInfo;
	STARTUPINFO siStartInfo;
	ZeroMemory(&piProcInfo, sizeof(piProcInfo));
	ZeroMemory(&siStartInfo, sizeof(siStartInfo));
	siStartInfo.cb = sizeof(siStartInfo);
	//MessageBox(NULL, LPCWSTR(command), TEXT("Title"), 0);
	CreateProcess(NULL, LPWSTR(command), NULL, NULL, TRUE, 0, NULL, NULL, &siStartInfo, &piProcInfo);
//#endif /* WIN32 */
    return NS_OK;
}

NS_GENERIC_FACTORY_CONSTRUCTOR(nxForeginCaller)
NS_DEFINE_NAMED_CID(NX_FOREGINCALLER_CID);

static const mozilla::Module::CIDEntry kForeginCallerCIDs[] = {
    { &kNX_FOREGINCALLER_CID, false, NULL, nxForeginCallerConstructor },
    { NULL }
};

static const mozilla::Module::ContractIDEntry kForeginCallerContracts[] = {
    { NX_FOREGINCALLER_CONTRACTID, &kNX_FOREGINCALLER_CID },
    { NULL }
};

static const mozilla::Module::CategoryEntry kForeginCallerCategories[] = {
    { "my-category", "my-key", NX_FOREGINCALLER_CONTRACTID },
    { NULL }
};

static const mozilla::Module kForeginCallerModule = {
    mozilla::Module::kVersion,
    kForeginCallerCIDs,
    kForeginCallerContracts,
    kForeginCallerCategories
};


NSMODULE_DEFN(nxForeginCallerModule) = &kForeginCallerModule;
NS_IMPL_MOZILLA192_NSGETMODULE(&kForeginCallerModule)
