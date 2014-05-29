#ifndef __EDITOR_H__
#define __EDITOR_H__
#include <queue>
#include <string>
#include <sstream>
#include <windows.h>
#include <nsIServiceManager.h>
#include <nsObserverService.h>

#include "glory_message.h"

using namespace std;

class AutoCompleteManager;
struct nxGloryChildren {
		bool	ngIsInited;
		bool	ngIsAcitve;
		queue<LexerMessage> ngMessageQueue;
		string	ngPathName; //e.g /usr/home/user_name/Hello.cpp
		string	ngFileName; //e.g Hello.cpp
		string	ngExtName;  //e.g cpp
		char *  local_buffer;
		const char *  autoc_buffer;
		void * autoc_priv;
		AutoCompleteManager * autoc_manager;
		int (*ngCommand)(void*,int,int,int);
		void *  ngInstance;
		HWND	ngHwnd;
		HANDLE	hFile; // Handle to document
		HHOOK	hNotifyLisstener;
		HANDLE  hInputHelperThread;
		HANDLE  hInputMessageSemaphore;
		void message_to_helper(LexerMessage & msg) {
			ngMessageQueue.push(msg);
			msg.__base.message_type = message_none;
			ReleaseSemaphore(hInputMessageSemaphore, 1, NULL);
		};
};

static void AutoComplete_Notify_IDE ( const char * topic, const char * message ) {
	nsCOMPtr<nsIServiceManager> servMan;
	nsresult rv = NS_GetServiceManager(getter_AddRefs(servMan));
	if ( NS_FAILED(rv) ) {
		printf("Cannot get service manager!\n");
		return;
	}
	nsCOMPtr<nsIObserverService> observerService;
	rv = servMan->GetServiceByContractID("@mozilla.org/observer-service;1",
									NS_GET_IID(nsIObserverService),
									getter_AddRefs(observerService));
	if ( NS_FAILED(rv) ) {
		printf("Cannot get observer service!\n");
		return;
	}
	const PRUnichar * strData = NS_ConvertASCIItoUTF16(message).get();
	observerService->NotifyObservers(NULL, topic, strData);
}

static void ReportToMessageBox(int line, char * type, char * message) {
	ostringstream report_str;
	report_str << line << ";" << type <<";"<<message;
	AutoComplete_Notify_IDE("MonacoIDE.compile_complain_message.append", report_str.str().c_str());
}

static void ClearMessageBox() {
	AutoComplete_Notify_IDE("MonacoIDE.compile_complain_message.clear", "");
}

#endif /* __EDITOR_H__ */