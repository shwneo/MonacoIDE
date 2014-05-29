//var EXPORTED_SYMBOLS = ["open_a_file", "test_fun", "set_file_canceled", "set_file_created", "is_create_canceled", "get_file_name", "set_file_name", "open_a_file_in_tab"];

function win_resize() {
	//dump("resizing detected");
	var ele_frame = document.getElementById("main_frame");
	var container_x = ele_frame.contentWindow.mozInnerScreenX - ele_frame.contentWindow.screenX - 10;
	var container_y = ele_frame.contentWindow.mozInnerScreenY - ele_frame.contentWindow.screenY - 33;
	if (obj) {
		obj.ResizeWindow(container_x, container_y, ele_frame.contentWindow.innerWidth, ele_frame.contentWindow.innerHeight);
	}
}

var obj;
var tab_list;
var observerService;
var message_box;

function open_a_file(file_name) {
	
	var ret = -1;
	var ele_frame = document.getElementById("main_frame");
	var container_x = ele_frame.contentWindow.mozInnerScreenX - ele_frame.contentWindow.screenX - 10;
	var container_y = ele_frame.contentWindow.mozInnerScreenY - ele_frame.contentWindow.screenY - 33;
	var baseWindow = window.QueryInterface(Components.interfaces.nsIInterfaceRequestor)
                        .getInterface(Components.interfaces.nsIWebNavigation)
                        .QueryInterface(Components.interfaces.nsIDocShellTreeItem)
                        .treeOwner
                        .QueryInterface(Components.interfaces.nsIInterfaceRequestor)
                        .getInterface(Components.interfaces.nsIXULWindow)
                        .docShell
                        .QueryInterface(Components.interfaces.nsIBaseWindow);
	if (obj) {
		var wnd = obj.AttachWindow(baseWindow);

		dump("Get registed "+wnd+" \n");
		if (wnd >= 0) {
			ret = obj.CommandWindow(2, wnd, 0);
			dump("wnd set active "+wnd +"\n");
		}
		ret = obj.CommandWindowWithString(4, file_name);
		dump(ret+"\n");
		obj.ResizeWindow(container_x, container_y, ele_frame.contentWindow.innerWidth, ele_frame.contentWindow.innerHeight);
	}

	var toOpen = file_name;
	var a = toOpen.match(/(.*)[\\|\/]([\w\d\.()$#&@-_^%\[\]\s]+)/);
	var new_tab_title = RegExp.$2;
	var tabs = document.getElementById("all_tabs");
	var new_tab = document.createElementNS("http://www.mozilla.org/keymaster/gatekeeper/there.is.only.xul", "tabwithclosebutton");
	if (new_tab) {
		new_tab.setAttribute("title", new_tab_title);
		new_tab.setAttribute("onclosebutton", "on_tab_close(event)");
		new_tab.setAttribute("value", wnd.toString());
		new_tab.setAttribute("onmouseup", "on_tab_command()");
		tabs.appendChild(new_tab);
		tabs.selectedItem = new_tab;
		tab_list.add(new_tab);
	}
	/* testing code for observer */
	observerService = Components.classes["@mozilla.org/observer-service;1"]
		.getService(Components.interfaces.nsIObserverService);
	if ( observerService ) {
		observerService.addObserver(testObserver,"MonacoIDE.compile_complain_message.clear",false);
		observerService.addObserver(testObserver,"MonacoIDE.compile_complain_message.append",false);
		observerService.addObserver(testObserver,"MonacoIDE.compile_complain_message.new",false);
	}
	message_box = document.getElementById("message_box");
	return wnd;
}

function flush_config() {
	var aPath = "chrome://MonacoIDE/content/";
	try {
		obj = Components.classes["@monaco-nx.com/interfaces/nxGlory;1"].createInstance();
		obj = obj.QueryInterface(Components.interfaces.nxIGlory);
		var ios = Components.classes['@mozilla.org/network/io-service;1']
					.getService(Components.interfaces["nsIIOService"]);
		var uri = ios.newURI(aPath, "UTF-8", null);
		var cr = Components.classes['@mozilla.org/chrome/chrome-registry;1']
					.getService(Components.interfaces["nsIChromeRegistry"]);
		var rv = cr.convertChromeURL(uri).spec;
		dump(rv);
	} catch (exp) {
		window.alert(exp);
	}
	return rv;
}


function get_url_from_chrome(chrome_name) {
	dump(chrome_name);
	try {
		obj = Components.classes["@monaco-nx.com/interfaces/nxGlory;1"].createInstance();
		obj = obj.QueryInterface(Components.interfaces.nxIGlory);
		var ios = Components.classes['@mozilla.org/network/io-service;1']
					.getService(Components.interfaces["nsIIOService"]);
		var uri = ios.newURI(chrome_name, "UTF-8", null);
		var cr = Components.classes['@mozilla.org/chrome/chrome-registry;1']
					.getService(Components.interfaces["nsIChromeRegistry"]);
		var rv = cr.convertChromeURL(uri).spec;
	} catch (exp) {
		window.alert(exp);
	}
	return rv;
}

let testObserver = {
	observe : function (aSubject, aTopic, aData) {
		if ( aTopic == "MonacoIDE.compile_complain_message.clear" ) {
			//window.alert("Now clearing the complain message!");
			var del_ele;
			do {
				del_ele = message_box.removeItemAt( 0 );
				dump("clearing item...");
			} while(del_ele);
		} else
		if ( aTopic == "MonacoIDE.compile_complain_message.append" ) {
			//window.alert("Getting complain message " + aData);
			if ( message_box ) {
				message_box.appendItem(aData, 0);
				dump("append message done");
			} else {
				dump("message_box is null");
			}
		} else
		if ( aTopic == "MonacoIDE.compile_complain_message.new" ) {
			window.alert("New complain session with message " + aData);
		}
	}
}

function on_window_load() {
	dump("Now loading window...\n");
	
	var init_path = get_url_from_chrome("chrome://MonacoIDE/content/config");
	var conf_path = get_url_from_chrome("chrome://MonacoIDE/content/config");
	init_path = init_path  + "/../../../depends/lib/SciLexer.dll";
	
	var ret = obj.CommandWindowWithString(2, init_path);
	ret = obj.CommandWindowWithString(6, conf_path);
	
	var ele_frame = document.getElementById("main_frame");
	ele_frame.addEventListener("resize", win_resize, true);
	tab_list = createLinkList();
	
	var tabs = getElementById("all_tabs");
	var saveAs = getElementById("menu_save_as");
}

function on_test_observer_1() {
	obj.CommandWindow(6,0,0);
}

function on_test_observer_2() {
	obj.CommandWindow(7,0,0);
}

function on_tab_command() {
	var ele_tabs = document.getElementById("all_tabs");
	var ele_selected = ele_tabs.selectedItem;
	var ele_bind_window = Number(ele_selected.value);
	ret = obj.CommandWindow(2, ele_bind_window, 0);
	dump("wnd set active "+ele_bind_window +"\n");
	tab_list.remove(ele_selected);
	tab_list.add(ele_selected);
}

function on_tab_close(event) {

	var tabs = document.getElementById("all_tabs");
	var target = event.currentTarget.parentNode.parentNode;
	var wnd_bind = new Number(target.value);
	//window.alert(target.tagName+" "+(wnd_bind+1));
	var idx = tabs.getIndexOfItem(target);
	obj.CommandWindow(4, wnd_bind, 0);
	tab_list.remove(target);
	tabs.removeItemAt(idx);
	tabs.selectedItem = tab_list.first.data;
	obj.CommandWindow(2, Number(tab_list.first.data.value), 0);
}

function on_open_command() {

	var nsIFilePicker = Components.interfaces.nsIFilePicker;
	var fp = Components.classes["@mozilla.org/filepicker;1"].createInstance(nsIFilePicker);
	fp.init(window, "Open file", nsIFilePicker.modeOpen);
	var ret = fp.show();
	var toOpen="";
	if (ret != nsIFilePicker.returnCancel) {
		toOpen = fp.file.path;
	} else {
		return;
	}

	var wnd_bind = open_a_file(toOpen);
}

var createLinkList = function() {
	var _this = {}, first = null;
	_this.first=null;
	_this.length = 0;
	
	_this.add = function(val) {
		first = {data:val, next: first || null};
		_this.length++;
		_this.first = first;
		dump("\n\nadded "+val.value+"\n\n");
	}
	
	_this.get = function(val) {
		for(var i = first; i; i = i.next) {
			if (i.data == val) {
				return i;
			}
		}
	}

	_this.remove = function(val) {
		if (first.data == val){
			first = first.next;
			_this.first = first;
			dump("\nPPPPPPPPP\n");
			return ;
		} 
		var ptemp = temp = first;
		for( ; temp; ptemp = temp ,temp= temp.next){
			if(temp.data == val){
				ptemp.next = temp.next;
				dump("\nDeleting list itme "+val.value+"\n");
				if (val == _this.last) {
					_this.first = ptemp;
					dump("\nJust removed the last\n");
				}
				_this.length--;
				return ;
                }
            }
	}
	
	return _this;
}

function on_save_as_command() {
	var nsIFilePicker = Components.interfaces.nsIFilePicker;
	var fp = Components.classes["@mozilla.org/filepicker;1"].createInstance(nsIFilePicker);
	fp.init(window, "Save as", nsIFilePicker.modeSave);
	var ret = fp.show();
	var toSave="";
	if (ret != nsIFilePicker.returnCancel) {
		toSave = fp.file.path;
	} else {
		return;
	}
	obj.CommandWindowWithString(5, toSave);
}

function on_save_command() {
	var tabs = document.getElementById("all_tabs");
	var curr_tab = tabs.selectedItem;
	var tab_value = -1;
	if (curr_tab) {
		tab_value = Number(curr_tab.value);
		if (tab_value > -1) {
			obj.CommandWindow(5, tab_value, 0);
		}
	}
}

function on_new_command() {
	var confirm_obj = new Object();
	confirm_obj.file_name = "";
	confirm_obj.confirmed = false;
	window.openDialog("chrome://MonacoIDE/content/CreateFileDialog.xul", "New File", "chrome,modal,centerscreen", confirm_obj);
	
	if (!confirm_obj.confirmed) {
		return;
	} 
	
	open_a_file(confirm_obj.file_name);
}


function on_test_ferrando() {
	var btn = document.getElementById("details");
	var ele = document.getElementById("search-panel");
	ele.openPopup(btn, "after_start", 0,0,false, false);
}

function chrome2URI(chrome_name) {
	var iosys = Components.classes['@mozilla.org/network/io-service;1']
					.getService(Components.interfaces["nsIIOService"]);
	var uri = iosys.newURI(chrome_name, "UTF-8", null);
	var cr = Components.classes['@mozilla.org/chrome/chrome-registry;1']
					.getService(Components.interfaces["nsIChromeRegistry"]);
	var rv = cr.convertChromeURL(uri).spec;
	rv.match(/(.*\:\/\/\/)([a-zA-Z]:.*)/);
	var uri = RegExp.$1;
	var uri_s=RegExp.$2;
	uri_s=uri_s.replace(/\:/, "|");
	return uri + uri_s;
}

function on_project_run() {
	try {
		var obj = Components.classes['@general.org/interface/nxIForeginCaller;1'].createInstance();
		obj = obj.QueryInterface(Components.interfaces.nxIForeginCaller);
		//window.alert(obj.Add(5, 6));
		obj.ForeginCall("xulrunner.exe C:\\Users\\shwneo\\Desktop\\MonacoIDE\\application.ini");
	} catch (e) {
		window.alert(e);
	}
}


