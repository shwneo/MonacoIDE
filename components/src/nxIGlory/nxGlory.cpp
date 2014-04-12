#include "nxGlory.h"
#include "nsIClassInfoImpl.h"
#include "mozilla/ModuleUtils.h"
#include <gfxCore.h>
#include <nsColor.h>
#include <nsCoord.h>
#include <nsEvent.h>
#include <nsIBaseWindow.h>
#include <nsIWidget.h>

#include "Scintilla.h"
#include "SciLexer.h"


#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <set>
#include <queue>

#include "glory_message.h"
#include "glory_autoc.h"
#include "glory_window.h"

using namespace std;
#define GLORY_MAX_CHILD	255

extern int IdentifyAndStyle(struct nxGloryChildren * wnd, const char * name, int hint);
extern int load_user_style_setting(const char * user_setting);
static HWND _g_current_child_wnd = NULL;
static void * _g_current_editor_instance = NULL;
static int (*_g_current_editor_function)(void *, int, int, int);
static set<HWND> _g_child_wnd_set;

typedef class _nxGloryPrivData {
protected:
	HMODULE		ngHmodule;
	int			nInitiallStatus;
	struct nxGloryChildren ngChildWindow[GLORY_MAX_CHILD];
public:
	_nxGloryPrivData();
	~_nxGloryPrivData(){};
	int current_actived;
	int	GetActiveChild();
	int	SetActiveChild(int n);
	int	FindEmptyChild();
	int	FreeChild(int n);

	int OpenFileIntoActiveChild(const char * file_name);
	int CloseFileInChild(int n);
	int SaveFileInChild(int n);
	int SaveFileInActiveChildAs(const char * file_name);
	struct nxGloryChildren * GetChildWindowByHandle(HWND wnd);

	friend nxGlory;
} nxGloryPrivData;

_nxGloryPrivData::_nxGloryPrivData():ngHmodule(NULL),nInitiallStatus(0),current_actived(-1) {
	for (int i = 0; i < GLORY_MAX_CHILD; ++i) {
		ngChildWindow[i].ngIsInited = false;
		ngChildWindow[i].ngIsAcitve = false;
		ngChildWindow[i].ngCommand = NULL;
		ngChildWindow[i].ngHwnd = NULL;
		ngChildWindow[i].ngInstance = NULL;
	}
}

int _nxGloryPrivData::FindEmptyChild() {
	int ret = -1;
	for (int i = 0; i < GLORY_MAX_CHILD; ++i) {
		if (!ngChildWindow[i].ngIsInited) {
			ret = i;
			break;
		}
	}
	return ret;
}

int _nxGloryPrivData::FreeChild(int n) {
	if (ngChildWindow[n].ngIsInited)
		ngChildWindow[n].ngIsInited = false;
	return 0;
}

int _nxGloryPrivData::SetActiveChild(int n) {
	HWND hWnd;
	if (n<0)
		return -1;
	if (ngChildWindow[n].ngIsInited && ngChildWindow[n].ngHwnd) {
		if (current_actived >= 0 && current_actived != n) {
			hWnd = ngChildWindow[current_actived].ngHwnd;
			::ShowWindow(hWnd, SW_HIDE);
			::UpdateWindow(hWnd);
			ngChildWindow[current_actived].ngIsAcitve = false;
		}
		hWnd = ngChildWindow[n].ngHwnd;
		::ShowWindow(hWnd, SW_SHOW);
		::UpdateWindow(hWnd);
		_g_current_child_wnd = hWnd;
		_g_current_editor_instance = ngChildWindow[current_actived].ngInstance;
		_g_current_editor_function = ngChildWindow[current_actived].ngCommand;
		ngChildWindow[n].ngIsAcitve = true;
		SetFocus(ngChildWindow[n].ngHwnd);
		current_actived = n;
		return 0;
	}
	return -1;
}

int _nxGloryPrivData::GetActiveChild() {
	for (int i = 0; i < GLORY_MAX_CHILD; ++i) {
		if (ngChildWindow[i].ngIsInited && 
			ngChildWindow[i].ngHwnd &&
			ngChildWindow[i].ngIsAcitve) {
				return i;
		}
	}
	return -1;
}

int _nxGloryPrivData::OpenFileIntoActiveChild(const char * file_name) {
	int nActive, ret;
	HANDLE hFile;
	DWORD nFsize, nReaded, nFsize_hi;
	char * pReadBuffer;

	nActive = GetActiveChild();
	if (nActive < 0)
		return -5; /* no child actived */
	printf("Open a new file [%s] into acitve window %d\n", file_name, nActive);
	hFile = CreateFileA(file_name, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile) {
		nFsize = GetFileSize(hFile, &nFsize_hi);
	} else {
		printf("Fail to open file %s\n", file_name);
		return -2;
	}
	char tmp_buf[100];
	sprintf(tmp_buf, "GetFileSIze = %d\n", nFsize);
	//MessageBoxA(pData->ngChildWindow[nActive].ngHwnd, tmp_buf, "Oh~", MB_OK);
	printf(tmp_buf);
	
	if (nFsize < 0) {
		printf("Error occored when getting file size\n");
		return -6;
	} else if (nFsize < 40*1024*1024) {
		pReadBuffer = (char*) malloc(nFsize * sizeof(DWORD) + 1);
		memset(pReadBuffer, 0, nFsize * sizeof(DWORD) + 1);
		if (!ReadFile(hFile, pReadBuffer, nFsize, &nReaded, NULL)) {
			printf("Fail to read file %s\n", file_name);
			free(pReadBuffer);
			return -3;
		}
	} else {
		printf("Single file (%d Bytes) is larger than 40MB\n", nFsize);
		free(pReadBuffer);
		return -4;
	}
	
	ngChildWindow[nActive].ngFileName = file_name;
	ngChildWindow[nActive].hFile = hFile;
	

	if (ngChildWindow[nActive].ngCommand && ngChildWindow[nActive].ngInstance) {
		//Load the file
		ngChildWindow[nActive].ngCommand(ngChildWindow[nActive].ngInstance, SCI_SETTEXT, 0, (int)pReadBuffer); 
		// Set the style...
		IdentifyAndStyle(&ngChildWindow[nActive], 
				file_name, -1);
		
		if (ngChildWindow[nActive].autoc_manager) {
			ngChildWindow[nActive].autoc_manager->Begin(NULL);
		}

	}
	ngChildWindow[nActive].local_buffer = pReadBuffer;
	return 0;
}

int _nxGloryPrivData::SaveFileInActiveChildAs(const char * file_name) {
	int nActive, ret;
	HANDLE hFile;
	DWORD Fsize, Fwritten;

	nActive = GetActiveChild();
	if (nActive < 0)
		return -5; /* no child actived */
	hFile = CreateFileA(file_name, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if(ngChildWindow[nActive].hFile) {
		CloseHandle(ngChildWindow[nActive].hFile);
		ngChildWindow[nActive].ngFileName = string(file_name);
	}
	if (hFile) {
		ret = 0;
		if (ngChildWindow[nActive].ngCommand && ngChildWindow[nActive].ngInstance) {
			Fsize = ngChildWindow[nActive].ngCommand(ngChildWindow[nActive].ngInstance, SCI_GETLENGTH, 0, 0);
			char * tmp_buf = (char *) malloc(Fsize);
			ngChildWindow[nActive].ngCommand(ngChildWindow[nActive].ngInstance, SCI_GETTEXT, Fsize, (int)tmp_buf);
			WriteFile(hFile, tmp_buf, Fsize, &Fwritten, NULL);
			if (Fwritten != Fsize) {
				ret = -7; /* file cannot be written entirly, full disk or write production */
			}
		}
		ngChildWindow[nActive].hFile = hFile;
	} else
		ret = -2;
	return ret;
}

int _nxGloryPrivData::CloseFileInChild(int n) {
	if (ngChildWindow[n].ngIsInited) {
		printf("Window command 4: got child %d\n", n);
		::SendMessageA(ngChildWindow[n].ngHwnd, WM_CLOSE, 0, 0);
		DestroyWindow(ngChildWindow[n].ngHwnd);
		_g_child_wnd_set.erase(ngChildWindow[n].ngHwnd);
		UnhookWindowsHookEx(ngChildWindow[n].hNotifyLisstener);
		CloseHandle(ngChildWindow[n].hFile);
		ngChildWindow[n].ngExtName.clear();
		ngChildWindow[n].ngFileName.clear();
		ngChildWindow[n].ngPathName.clear();
		free ( ngChildWindow[n].local_buffer );
		if ( ngChildWindow[n].autoc_manager ) {
			ngChildWindow[n].autoc_manager->Done();
			delete ngChildWindow[n].autoc_manager;
			ngChildWindow[n].autoc_manager = NULL;
		}
		FreeChild(n);
	}
	return 0;
}

int _nxGloryPrivData::SaveFileInChild(int n) {
	HANDLE hFile;
	DWORD Fsize, Fwritten;
	OVERLAPPED over_lapped;

	memset(&over_lapped, 0, sizeof(over_lapped));

	if (ngChildWindow[n].ngIsInited) {
		hFile = ngChildWindow[n].hFile;
		if (ngChildWindow[n].ngCommand && ngChildWindow[n].ngInstance) {
			Fsize = ngChildWindow[n].ngCommand(ngChildWindow[n].ngInstance, SCI_GETLENGTH, 0, 0);
			char * tmp_buf = (char *) malloc(Fsize);
			ngChildWindow[n].ngCommand(ngChildWindow[n].ngInstance, SCI_GETTEXT, Fsize, (int)tmp_buf);
			WriteFile(hFile, tmp_buf, Fsize, &Fwritten, NULL);
			if (Fwritten != Fsize) {
				printf("file cannot be written entirly, full disk or write production");
				return -7; /* file cannot be written entirly, full disk or write production */
			}
		}
	}
	return 0;
}

struct nxGloryChildren * _nxGloryPrivData::GetChildWindowByHandle(HWND wnd) {
	for (int i = 0; i < GLORY_MAX_CHILD; ++i) {
		if (ngChildWindow[i].ngHwnd == wnd)
			return &ngChildWindow[i];
	}
	return NULL;
}

static inline
bool _is_alpha(char c) {
	if ( (c >= 'A' && c <= 'Z') ||
		 (c >= 'a' && c <= 'z') ||
		 (c >= '0' && c <= '9') ||
		 (c == '_') )
		return true;
	return false;
}


/* Implementation file */
NS_IMPL_ISUPPORTS1(nxGlory, nxIGlory)

nxGlory::nxGlory():pnxGloryPrivData(NULL)
{
	/* member initializers and constructor code */
}

nxGlory::~nxGlory()
{
  /* destructor code */
}

/* attribute nsIBaseWindow baseWindow; */
NS_IMETHODIMP nxGlory::GetBaseWindow(nsIBaseWindow * *aBaseWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
	
}
NS_IMETHODIMP nxGlory::SetBaseWindow(nsIBaseWindow *aBaseWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
	
}

/* long Add (in long a, in long b); */
NS_IMETHODIMP nxGlory::Add(int32_t a, int32_t b, int32_t *_retval)
{
    //return NS_ERROR_NOT_IMPLEMENTED;
	if (_retval == NULL)
		return NS_ERROR_NULL_POINTER;
	*_retval = a + b;
	return NS_OK;
}

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

static inline
void post_message_to_helper(struct nxGloryChildren * dist, LexerMessage & msg) {
	dist->ngMessageQueue.push(msg);
	msg.__base.message_type = message_none;
	ReleaseSemaphore(dist->hInputMessageSemaphore, 1, NULL);
}




static
bool show_auto_complete(struct nxGloryChildren * dist_wnd, char ch) {
	string * autoc_str;
	char linebuf[512];
	int current = dist_wnd->ngCommand(dist_wnd->ngInstance, SCI_GETCURLINE, 512, int(linebuf));
	int pos = dist_wnd->ngCommand(dist_wnd->ngInstance, SCI_GETCURRENTPOS, 0, 0);
	int startword = current - 1;
	while ( startword > 0 && _is_alpha(linebuf[startword - 1]) ) {
		--startword;
	}
	linebuf[current - 1] = '\0';
	string curr_word(linebuf + startword);
	switch ( ch ) {
		case ' ':
		if ( curr_word.compare("import") == 0 ||
			 curr_word.compare("from") == 0 ) {
			autoc_str = new string();
			autoc_str->append("abc ");
			autoc_str->append("abcde ");
			autoc_str->append("bcdef ");
			autoc_str->append("ffeddff");
			dist_wnd->autoc_buffer = autoc_str->c_str();
			dist_wnd->autoc_priv = (void*)autoc_str;
			return true;
		}
		break;
		case '\n':
			return false;
		break;
	}

	return false;
}

LRESULT CALLBACK SciWndHookProc(int nCode, WPARAM wParam, LPARAM lParam ) {
	LRESULT ret = 0;
	CWPSTRUCT * msgDetails;
	LPARAM msg_lParam;
	WPARAM msg_wParam;
	UINT   msg_message;
	NMHDR * lpnmhdr;
	SCNotification* notify;
	nxGloryPrivData * privData = NULL;
	struct nxGloryChildren * dist_wnd;
	int enterd = 0;
	string * autoc_priv;
	LexerMessage msg;

	int position, margin, line_number;	
	//printf("Hooked message received\n");
	msgDetails = (CWPSTRUCT*)lParam;
	if (msgDetails) {
		msg_lParam = msgDetails->lParam;
		msg_wParam = msgDetails->wParam;
		msg_message = msgDetails->message;
		if (msg_message == WM_NOTIFY && msg_lParam) {
			lpnmhdr = (LPNMHDR) msg_lParam;
			notify = (SCNotification*) msg_lParam;
			privData = (nxGloryPrivData*) notify->privData;
			if ( privData )
				dist_wnd = privData->GetChildWindowByHandle(lpnmhdr->hwndFrom);
			if ( dist_wnd ) {
				switch (lpnmhdr->code) {
					case SCN_MARGINCLICK:
						msg.__margin.base.message_type = message_margin;
						msg.__margin.margin_number = notify->margin;
						msg.__margin.edit_position = notify->position;
						post_message_to_helper(dist_wnd, msg);
					break;
					case SCN_CHARADDED:
						msg.__char.base.message_type = message_char;
						msg.__char.added_char = notify->ch;
						post_message_to_helper(dist_wnd, msg);
						/* Alas, the auto complete window must be shown here */
						if ( show_auto_complete(dist_wnd, notify->ch) ) {
							dist_wnd->ngCommand(dist_wnd->ngInstance, SCI_AUTOCSETMAXHEIGHT, 5, 5);
							dist_wnd->ngCommand(dist_wnd->ngInstance, SCI_AUTOCSHOW, enterd, int(dist_wnd->autoc_buffer));
							enterd++;
						} else {
							enterd = 0;
						}
					break;
					case SCN_AUTOCSELECTION:
					case SCN_AUTOCCANCELLED:
						autoc_priv = (string*)dist_wnd->autoc_priv;
						free(autoc_priv);
						enterd = 0;
						break;
					case SCN_AUTOCCHARDELETED:
						enterd--;
						break;
				}
			}
		}

	}
	if (nCode < 0) {
		ret = CallNextHookEx(NULL, nCode, wParam, lParam);
	}
	return ret;
}


DWORD WINAPI inputHelperMessageThreadProc(LPVOID lpParameter) {
	int line_number;
	int line_pos, page_pos, startword;
	char ch, *curr_word;
	struct nxGloryChildren * ch_wnd = (struct nxGloryChildren*) lpParameter;
	if ( ch_wnd && ch_wnd->hInputMessageSemaphore ) {

		while ( ch_wnd->ngIsInited ) {
			WaitForSingleObject(ch_wnd->hInputMessageSemaphore, INFINITE);
			cout<<" $$$$$$$$$$$$$$$ Chedking for helper message!"<<endl;
			LexerMessage msg = ch_wnd->ngMessageQueue.front();
			struct lexer_message_base * pMsg = (struct lexer_message_base*) &msg;
			switch ( pMsg->message_type ) {
				case message_margin:
				cout<<"Message thread reciving margin message"<<endl;
				line_number = ch_wnd->ngCommand(ch_wnd->ngInstance, SCI_TOGGLEFOLD, msg.__margin.edit_position, 0);
				ch_wnd->ngCommand(ch_wnd->ngInstance, SCI_TOGGLEFOLD, line_number, 0);
				break;
			}
			ch_wnd->ngMessageQueue.pop();
		}
	}

	return 0;
}

/* long AttachWindow (in nsIBaseWindow window); */
NS_IMETHODIMP nxGlory::AttachWindow(nsIBaseWindow *window, int32_t *_retval)
{
	HWND _hwnd, _newWnd;
	HDC  _hdc;
	HBRUSH _hbrush;
	RECT _rect;
	WNDCLASS mywndclass;
	HMODULE hModule;
	nsCOMPtr< nsIWidget > widget;
	nxGloryPrivData * pData;
	DWORD nThreadID;
	int ret;
	int child_idx;

	if (_retval == NULL)
		return NS_ERROR_NULL_POINTER;

	pData = (nxGloryPrivData*) pnxGloryPrivData;
	if (!pData || !pData->nInitiallStatus) {
		*_retval = 4367; // Not init
		return NS_OK;
	}

	window->GetMainWidget(getter_AddRefs(widget));
	if (widget)
		_hwnd = (HWND) widget->GetNativeData(NS_NATIVE_WINDOW);
	if (_hwnd == NULL) {
		*_retval = 1236;
		return NS_OK;
	}
	/* TODO: Get main window's thread id for message hooking
	 * if message hooking moved to another place, do move these
	 * code as well
	 */
	nThreadID = GetWindowThreadProcessId(_hwnd, NULL);
	
	HINSTANCE hInstance = (HINSTANCE) GetWindowLong (_hwnd, GWL_HINSTANCE);

	RegisterClass(&mywndclass);
	_newWnd = CreateWindow(TEXT("Scintilla"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_CLIPCHILDREN,
					0,0, 100,100, _hwnd, NULL, hInstance, (LPVOID)pData);
	ShowWindow(_newWnd, SW_HIDE);
	//UpdateWindow(_newWnd);
	_g_child_wnd_set.insert(_newWnd);

	child_idx = pData->FindEmptyChild();
	if (child_idx >= 0) {
		pData->ngChildWindow[child_idx].ngHwnd = _newWnd;
		pData->ngChildWindow[child_idx].ngIsAcitve = false;
		pData->ngChildWindow[child_idx].ngIsInited = true;
		pData->ngChildWindow[child_idx].ngCommand = 
			(int (__cdecl *)(void *,int,int,int))::SendMessage(_newWnd, SCI_GETDIRECTFUNCTION, 0, 0);
		pData->ngChildWindow[child_idx].ngInstance = (void *)SendMessage(_newWnd,SCI_GETDIRECTPOINTER,0,0);

		pData->ngChildWindow[child_idx].hNotifyLisstener = SetWindowsHookEx(WH_CALLWNDPROC,
																			(HOOKPROC)SciWndHookProc,
																			hInstance,
																			nThreadID);
		pData->ngChildWindow[child_idx].hInputMessageSemaphore = CreateSemaphore(NULL, 0, 255, NULL);
		pData->ngChildWindow[child_idx].hInputHelperThread = CreateThread(NULL, 0, inputHelperMessageThreadProc, &(pData->ngChildWindow[child_idx]),
																				0, NULL);
		
		if (pData->ngChildWindow[child_idx].hNotifyLisstener == NULL) {
			printf("[error] Fail to hook message\n");
		}

		*_retval = child_idx;
		printf("Window has been attached to %d\n", child_idx);
		return NS_OK;
	}

	*_retval = 1234; /* Max open doc */
	return NS_OK;
}



LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (message) {
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

/* long ResizeWindow (in long x, in long y, in long width, in long height); */
NS_IMETHODIMP nxGlory::ResizeWindow(int32_t x, int32_t y, int32_t width, int32_t height, int32_t *_retval)
{
	HWND _hWnd;
	nxGloryPrivData * pData;
	int active_child = -1;

	pData = (nxGloryPrivData*) pnxGloryPrivData;
	if (_retval == NULL)
		return NS_ERROR_NULL_POINTER;
	if (!pData) {
		return NS_ERROR_NOT_INITIALIZED;
	}
	active_child = pData->GetActiveChild();
	if (active_child < 0) {
		printf("Ood, no child window is actived!\n");
		*_retval = 4748;/* No window actived */
		return NS_OK; 
	}

    //return NS_ERROR_NOT_IMPLEMENTED;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (width < 0)
		width = 0;
	if (height < 0)
		height = 0;
	
	_hWnd = pData->ngChildWindow[active_child].ngHwnd;
	if (_hWnd) {
		::SetWindowPos(_hWnd, 0, x, y, width, height, 0);
		printf("Window pos setted %d %d %d %d\n", x, y, width, height);
	}
	*_retval = 0;
	return NS_OK;
}

/* long CommandWindow (in long cmd, in long lparam, in long wparam); */
NS_IMETHODIMP nxGlory::CommandWindow(int32_t cmd, int32_t lparam, int32_t wparam, int32_t *_retval)
{
	nxGloryPrivData * pData;
	if (_retval == NULL)
		return NS_ERROR_NULL_POINTER;
	pData = (nxGloryPrivData*) pnxGloryPrivData;
	if (!pData)
		return NS_ERROR_NOT_INITIALIZED;
	*_retval = 0;
	switch (cmd) {
	case 1:
		printf("Doing cmd-int with %d, %d\n", lparam,  wparam);
		break;
	case 2: /* set active window; lparam=window to active, wparam=<unused> */
		pData->SetActiveChild(lparam);
		break;
	case 3:/* get active window number */
		*_retval = pData->GetActiveChild();
		break;
	case 4:/* Destory the window */
		if (lparam >= 0) {
			*_retval = pData->CloseFileInChild(lparam);
		}
		break;
	case 5:
		if (lparam >= 0) {
			*_retval = pData->SaveFileInChild(lparam);
		}
		break;
	};
    return NS_OK;
}



/* long CommandWindowWithString (in long cmd, in wstring w_str); */
NS_IMETHODIMP nxGlory::CommandWindowWithString(int32_t cmd, const PRUnichar * w_str, int32_t *_retval)
{
	nxGloryPrivData *	pData;;
	HMODULE				hModule;
	HANDLE				hFile;
	char * c_str, *pReadBuffer;
	int nActive, ret;
	DWORD nFsize, nFsize_hi, nReaded;

	// First, convert wide-char-string form JS to native c-type string, we need it later
	int AStrSize = WideCharToMultiByte(CP_ACP, 0, w_str, -1, NULL, 0, NULL, NULL);
	c_str = new char[AStrSize+1]; // the ANSI char version of the string paramter
	if (!WideCharToMultiByte(CP_ACP, 0, w_str, -1, c_str, AStrSize, NULL, NULL)) {
		delete [] c_str;
		printf("Cmd-Str Warnning Failed to convert wstring\n");
	}

	if (cmd != 2 && !pnxGloryPrivData) {
		*_retval = -6;// Need initial
		goto out_clear;
	} else {
		pData = (nxGloryPrivData*)pnxGloryPrivData;
	}

	if (_retval == NULL) {
		return NS_ERROR_NULL_POINTER;
	}
	switch (cmd) {
	case 1:
		printf("Doing cmd-str test: %s\n", c_str);
		break;
	case 2: /* load scinitilla library */
		printf("Initing scintilla with %s\n", c_str+8);
		hModule = ::LoadLibrary(w_str+8);
		if (!hModule) {
			::MessageBoxA(NULL, "Error: Cannot load library", "Error", MB_OK|MB_ICONERROR);
		}
		pData = new nxGloryPrivData;
		pData->ngHmodule = hModule;
		pnxGloryPrivData = (void*) pData;
		pData->nInitiallStatus = 1;
		break;
	case 3: /* NO NEEDED */
		printf("De-initing scintilla\n");
		if (pnxGloryPrivData) {
			pData = (nxGloryPrivData*) pnxGloryPrivData;
			/* TODO: make sure all opened document have been closed */
			delete pData;
			pnxGloryPrivData = NULL;
		}
		break;
	case 4: /* open a file, bind it to the current actived child window */
		*_retval = pData->OpenFileIntoActiveChild(c_str);
		if (*_retval < 0)
			goto out_clear;
		break;
	case 5: /* save the file opened in current child window as an other name */
		*_retval = pData->SaveFileInActiveChildAs(c_str);
		if (*_retval < 0)
			goto out_clear;
		break;
	case 6: /* (re)flush the user configs */
		printf("(re)flush user configs with url %s\n", c_str);
		string conf_file(c_str + 8);
		conf_file += "/lexer_settings.xml";
		printf("Adjust config file = %s\n", conf_file.c_str());
		load_user_style_setting(conf_file.c_str());
		break;
	}
	
	*_retval = 0;
out_clear:
	delete [] c_str;
	return NS_OK;
}

/* End of implementation class template. */

NS_GENERIC_FACTORY_CONSTRUCTOR(nxGlory)
NS_DEFINE_NAMED_CID(NX_GLORY_CID);

static const mozilla::Module::CIDEntry knxGloryCIDs[] = {
	{ &kNX_GLORY_CID, false, NULL, nxGloryConstructor },{NULL}
};
static const mozilla::Module::ContractIDEntry knxGloryContracts[] = {
    { NX_GLORY_CONTRACTID, &kNX_GLORY_CID },
    { NULL }
};
static const mozilla::Module::CategoryEntry knxGloryCategories[] = {
    { "nxGlory-category", "nxGlory-key", NX_GLORY_CONTRACTID },
    { NULL }
};
static const mozilla::Module knxGloryModule = {
	mozilla::Module::kVersion,
	knxGloryCIDs,
	knxGloryContracts,
	knxGloryCategories
};
NSMODULE_DEFN(knxGloryModule) = &knxGloryModule; 
NS_IMPL_MOZILLA192_NSGETMODULE(&knxGloryModule)

