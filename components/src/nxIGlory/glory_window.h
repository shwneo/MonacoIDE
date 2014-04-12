#ifndef __EDITOR_H__
#define __EDITOR_H__
#include <queue>
#include <string>
#include <windows.h>
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
};

#endif /* __EDITOR_H__ */