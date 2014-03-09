
//var EXPORTED_SYMBOLS = ["set_overwrite_true", "set_overwrite_false", "is_overwrite_confirmed"];

var curr_overlay;

function on_create_file_dialog_create() {
	var template_menu_list = document.getElementById("file_template_list");
	template_menu_list.selectedIndex = 1;
}

function on_tree_selected() {

	var tree = document.getElementById("fileTypeSelect");
	var curr_idx = tree.currentIndex;

	var start = new Object();
	var end = new Object();
	var numRanges = tree.view.selection.getRangeCount();

	var children = tree.getElementsByTagName("treechildren");
	var child = children[0]; //top children
	var curr_item = tree.view.getItemAtIndex(curr_idx);
	var curr_item_row = curr_item.getElementsByTagName("treerow")[0];
	var curr_item_cell = curr_item_row.getElementsByTagName("treecell")[0];
	var lang_config_id = curr_item_cell.getAttribute("value");
	var template_menu = document.getElementById("file_template_menu");
	var template_menu_list = document.getElementById("file_template_list");
	var newmenu = document.createElement("menupopup");
	newmenu.setAttribute("datasources", "chrome://MonacoIDE/content/gecko_file_types3.rdf");
	newmenu.setAttribute("ref", lang_config_id);
	newmenu.id="file_template_menu";
	var newtemplate = document.createElement("template");
	var newrule =  document.createElement("rule");
	var newmenuitem =  document.createElement("menuitem");
	newmenuitem.setAttribute("uri", "rdf:*");
	newmenuitem.setAttribute("label", "rdf:http://www.general.org/file-templates/rdf#name");
	newmenuitem.setAttribute("selected", "rdf:http://www.general.org/file-templates/rdf#selected");
	newmenuitem.setAttribute("value", "rdf:http://www.general.org/file-templates/rdf#value");
	newrule.appendChild(newmenuitem);
	newtemplate.appendChild(newrule);
	newmenu.appendChild(newtemplate);
	template_menu_list.replaceChild(newmenu, template_menu);
	template_menu.delete
	//window.alert(lang_config_id);
	//template_menu.setAttribute("ref", lang_config_id);
	//template_menu.ref=lang_config_id;
	
	template_menu_list.selectedIndex = 1;
};

function browse_a_folder() {
	var nsIFilePicker = Components.interfaces.nsIFilePicker;
	var fp = Components.classes["@mozilla.org/filepicker;1"].createInstance(nsIFilePicker);
	fp.init(window, "Open file", nsIFilePicker.modeGetFolder);
	var ret = fp.show();
	var toOpen="";
	if (ret != nsIFilePicker.returnCancel) {
		toOpen = fp.file.path;
	} else {
		return;
	}
	//window.alert(toOpen);
	var location_label = document.getElementById("new_file_location");
	location_label.value = toOpen;
}

function on_dialog_accept() {

	var sele_value = "";
	var template_list = document.getElementById("file_template_list");
	var selected = template_list.selectedItem;
	sele_value = selected.getAttribute("value");
	//window.alert(sele_value);
	var location = document.getElementById("new_file_location").value;
	var file_name = document.getElementById("new_file_name").value;
	var overwrite_confirm = new Object();
	overwrite_confirm.file_name = file_name;
	overwrite_confirm.confirmed = false;
	if (location.length == 0) {
		var relate = document.getElementById("new_file_location");
		var panic_panel = document.getElementById("panic_about_location");
		panic_panel.openPopup(relate, "after_start", 0, 0, false, false);
		return false;
	}
	if (file_name == 0) {
		var relate = document.getElementById("new_file_name");
		var panic_panel = document.getElementById("panic_about_name");
		panic_panel.openPopup(relate, "after_start", 0, 0, false, false);
		return false;
	}
	try {
		var ferrando =  Components.classes["@general.org/interface/nxIFerrando;1"].createInstance();
		ferrando = ferrando.QueryInterface(Components.interfaces.nxIFerrando);
		//Try normal mode first
		ret = ferrando.CreateFileFromTemplate(location + "\\" +file_name, 1, sele_value, "E:\\sample_project.xml");
		
		if (ret == 0) {
			/* Done to create, then open it */
			window.arguments[0].confirmed = true;
			window.arguments[0].file_name = location + "\\" +file_name;
			return true;
		} else
		if (ret == 3776) {
			window.openDialog("overwrite_confirm.xul", "Confirm file overwrite", "chrome,modal,centerscreen", overwrite_confirm);
		}

		if (overwrite_confirm.confirmed) {
			//window.alert("fine to overwrite");
			ret = ferrando.CreateFileFromTemplate(location + "\\" +file_name, 0x11, sele_value, "E:\\sample_project.xml");
			window.arguments[0].confirmed = true;
			window.arguments[0].file_name = location + "\\" +file_name;
			return true;
		} else {
			//window.alert("Oh~~~");
			return false;
		}

		//window.alert(ret);
	} catch (e) {
		window.alert(e);
	}

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

function on_confirm_create_show() {

	var warn_label = document.getElementById("overwriting_warning1");
	var label_str = "Regular file " + window.arguments[0].file_name + " is exist.";
	warn_label.value=label_str;
	
}

function on_cancel_create_file() {
	return false;
}

function on_confirm_overwrite() {
	window.arguments[0].confirmed = true;
	return true;
}
