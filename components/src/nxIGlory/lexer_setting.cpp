#include <stdlib.h>
#include <boost\regex.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include "Scintilla.h"
#include "SciLexer.h"
#include "pistachio.h"
#include "glory_autoc.h"
#include "glory_window.h"

using namespace std;
using namespace boost;

typedef int (__cdecl * style_setting_callback)(void *,int,int,int);
typedef void * style_setting_instance;

#ifndef	RGB(...)
#define RGB(red, green, blue) \
	int(red | (green << 8) | (blue << 16))
#endif

typedef struct {
	char * style_name; //e.g. default, string, cpreprocessor, operator...
	char * style_description; //e.g. 'string'=> Setting string style
	char * style_font_name; //e.g. consola
	int    style_font_size;
	int    style_font_italic;
	int    style_font_bold;
	int    style_fgcolor;
	int    style_bgcolor;
	unsigned int style_identy;
}conf_style_set;

#define CLASS_SHIM_DEFINE(type, name) \
void set_##name(type value){this->name = value;};\
type get_##name(void){return (this->name);};

class conf_style_set_c {
private:
	
	string style_name;
	string style_description;
	string style_font_name;
	int    style_font_size;
	bool   style_font_italic;
	bool   style_font_bold;
	int    style_fgcolor;
	int    style_bgcolor;
	int    style_identy;
public:
	conf_style_set_c(){};
	conf_style_set_c(const string & name, const string & description,
		const string & font_name, int font_size, bool font_italic, bool font_bold,
		int fgcolor, int bgcolor, int identify);
	virtual ~conf_style_set_c(){};
	void dump();

	CLASS_SHIM_DEFINE(string, style_name)
	CLASS_SHIM_DEFINE(string, style_description)
	CLASS_SHIM_DEFINE(string, style_font_name)
	CLASS_SHIM_DEFINE(int, style_font_size)
	CLASS_SHIM_DEFINE(bool, style_font_italic)
	CLASS_SHIM_DEFINE(bool, style_font_bold)
	CLASS_SHIM_DEFINE(int, style_fgcolor)
	CLASS_SHIM_DEFINE(int, style_bgcolor)
	CLASS_SHIM_DEFINE(int, style_identy)
};

void conf_style_set_c::dump() {
	cout<<"name:"<<style_name<<",ft-name:"<<style_font_name<<",ft-size:"<<style_font_size<<",fg-color:"<<style_fgcolor<<",bg-color:"\
	<<style_bgcolor<<endl;
}

typedef struct {
	char * tklist_name;
	char * tklist;
	unsigned int tklist_identy;
}conf_style_token_list;

class conf_style_keywords_c {
public:
	string keylist;
	int    key_identy;
};

const static int LANG_PROPERTY_TYPE_STRING = 0;
const static int LANG_PROPERTY_TYPE_NUMBER = 1;

typedef struct {
	char * property_name;
	char * property_value_str;
	int    property_value_int;
	int    property_type;
} conf_style_lexer_property;

typedef struct 
{
	char * guide_query;
	int    guide_identy;
} conf_guideline;

typedef struct {
	char * lang_name;
	char * lang_postfix;
	char * lang_identy_string;
	int    lang_identy_number;
	conf_guideline * lang_style_guide;
	conf_guideline * lang_keywords_guide;
	//conf_style_set * lang_style_set;
	conf_style_lexer_property * lang_property_set;
	//conf_style_token_list * lang_keywords[8];
	AutoCompleteManager * (*create_autoc_manager)(struct nxGloryChildren *);

	list<conf_style_set_c> lang_user_style;
	list<conf_style_keywords_c> lang_keyword_list;
} conf_style_language;

static conf_guideline conf_style_guideline_c[] = {
	{"settings.Default", 0},
	{"settings.Comment", 1},
	{"settings.Comment", 2},
	{"settings.Comment", 3},
	{"settings.Number", 4},
	{"settings.KeyWords", 5},
	{"settings.String", 6},
	{"settings.Character", 7},
	{"settings.Preprocessor", 9},
	{"settings.Operator", 10},
	{"settings.Identifier", 11},
	{"settings.ExtOperator", 14},
	{"settings.Types", 19},
	{"settings.Include", 25},
	{NULL, -1}
};

static conf_guideline conf_keyword_guideline_c[] = {
	{"KeyWords", 0},
	{"ExternalOperators", 1},
	{"BuiltinTypes", 3},
	{NULL, -1}
};

static conf_guideline conf_style_guideline_python[] = {
	{"settings.Default", 0},
	{"settings.Comment", 1},
	{"settings.Number", 2},
	{"settings.String", 3},
	{"settings.Character", 4},
	{"settings.KeyWords", 5},
	{"settings.TripleQuoteString", 6},
	{"settings.TripleDoubleQuoteString", 7},
	{"settings.ClassName", 8},
	{"settings.DefName", 9},
	{"settings.Operator", 10},
	{"settings.Identifier", 11},
	{"settings.Comment", 12},
	//{"settings.StringEOL", 13},
	{"settings.Highlight", 14},
	{"settings.Decorator", 15},
	{NULL, -1}
};

static conf_guideline conf_keyword_guideline_python[] = {
	{"KeyWords", 0},
	{"Highlight", 1},
	{NULL, -1}
};

static conf_style_set xml_default_setting[] = {
	{"default", " ", "Courier", 11,0,0,0x000000,RGB(0xFF,0xFF,0xFF), 0},
	{"tag", " ", "Consolas", 11, 0, 0, RGB(48, 135, 150), RGB(0xFF,0xFF,0xFF), 1},
	{"tag", " ", "Consolas", 11, 0, 0, RGB(48, 135, 150), RGB(0xFF,0xFF,0xFF), 2},
	{"attribute", " ", "Consolas", 11, 0, 0, RGB(34, 177, 76), RGB(0xFF,0xFF,0xFF), 3},
	{"attribute", " ", "Consolas", 11, 0, 0, RGB(34, 177, 76), RGB(0xFF,0xFF,0xFF), 4},
	{"number", " ", "Consolas", 11, 0, 0, RGB(148, 188, 21), RGB(0xFF,0xFF,0xFF), 5},
	{"string", " ", "Consolas", 11, 0, 0, RGB(139, 0, 21), RGB(0xFF,0xFF,0xFF), 6},
	{"string", " ", "Consolas", 11, 0, 0, RGB(139, 0, 21), RGB(0xFF,0xFF,0xFF), 7},
	{"other", " ", "Consolas", 11, 2, 0, RGB(163, 73, 164), RGB(0xFF,0xFF,0xFF), 8},
	{"comment", " ", "Consolas", 11, 0, 0, RGB(255, 201, 14), RGB(0xFF,0xFF,0xFF), 9},
	{"CDATA", " ", "Consolas", 11, 0, 0, RGB(112, 146, 190), RGB(0xFF,0xFF,0xFF), 17},
	{"xml doctype end", " ", "Consolas", 11, 2, 0, RGB(163, 73, 164), RGB(0xFF,0xFF,0xFF), 12},
	{"xml doctype end", " ", "Consolas", 11, 2, 0, RGB(163, 73, 164), RGB(0xFF,0xFF,0xFF), 13},
	{ (char*)NULL, (char*)NULL, (char*)NULL, 0,0,0,0,0,0xFFFF},	//Must be the last one
};


static conf_style_lexer_property cxx_lang_propertys[] = {
	{"lexer.cpp.track.preprocessor", "0", 0, LANG_PROPERTY_TYPE_STRING},
	{NULL, NULL, -1, -1}
};

static conf_style_language c_style_languages[] = {
	{"C", "C|INC|INL", "c", SCLEX_CPP, conf_style_guideline_c, conf_keyword_guideline_c, cxx_lang_propertys, NULL},
	{"C++", "CPP|CXX|HPP|HXX|H", "cpp", SCLEX_CPP, conf_style_guideline_c, conf_keyword_guideline_c, cxx_lang_propertys, NULL},
	{"Python", "PY|PYW", "python", SCLEX_PYTHON, conf_style_guideline_python, conf_keyword_guideline_python, NULL, create_python_autoc_manager}
	//{"javascript", "JS|JAVASCRIPT", "js", SCLEX_CPP, NULL, NULL, javascript_default_setting, cxx_lang_propertys, {&js_keyword_token_list, &js_builtin_types, NULL, NULL, NULL, NULL, NULL, NULL}},
	//{"xml", "XML|XUL|HTML|XHTML", "xml", SCLEX_XML, NULL, NULL, xml_default_setting, NULL, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}}
};

static inline
void get_keyword_list_from_node(PistNodeParser & p, const conf_guideline * guide, list<conf_style_keywords_c> & l) {
	string query = ".";
	query += guide->guide_query;
	query += ":";
	conf_style_keywords_c key;
	key.key_identy = guide->guide_identy;
	key.keylist = p.queryString(query);
	cout<<"query key word list uing:"<<query<<endl;
	cout<<"Get word list from user setting:"<<key.keylist<<endl;
	l.push_back(key);
}

static inline
conf_style_set_c get_user_setting_from_node(PistNodeParser & p, 
											const conf_guideline * guide,
											const conf_style_set_c & def_set) {
	string query;
	PObject obj;
	conf_style_set_c ret = def_set;
	query = guide->guide_query;
	ret.set_style_identy(guide->guide_identy);

	obj = p.queryObject(query + ".FontName:");
	if ( obj.is_valid() ) {
		cout<<" 1 "<<obj.toString()<<endl;
		ret.set_style_font_name(obj.toString());
	}
	obj = p.queryObject(query + ".FontSize:");
	if ( obj.is_valid() ) {
		cout<<" 1 "<<obj.toString()<<endl;
		ret.set_style_font_size(obj.toInteger());
	}
	obj = p.queryObject(query + ".ForeColor:");
	if ( obj.is_valid() ) {
		cout<<" 1 "<<obj.toString()<<endl;
		ret.set_style_fgcolor(sharp_to_rgb(obj.toString()));
	}
	obj = p.queryObject(query + ".BackColor:");
	if ( obj.is_valid() ) {
		cout<<" 1 "<<obj.toString()<<endl;
		ret.set_style_bgcolor(sharp_to_rgb(obj.toString()));
	}
	obj = p.queryObject(query + ".FontItalic:");
	if ( obj.is_valid() ) {
		cout<<" 1 "<<obj.toString()<<endl;
		ret.set_style_font_italic(obj.toBoolean());
	}
	obj = p.queryObject(query + ".FontBold:");
	if ( obj.is_valid() ) {
		cout<<" 1 "<<obj.toString()<<endl;
		ret.set_style_font_bold(obj.toBoolean());
	}

	return ret;
}

int load_user_style_setting(const char  * user_setting) {
	int num_of_styles = sizeof(c_style_languages)/sizeof(conf_style_language);
	int detected_style = -1;
	conf_style_set_c global_set;
	string str;
	int R,G,B;
	ostringstream reg_parten;
	/* Read user setting from a xml file */

	printf("PistDocParser Opening file %s\n", user_setting);
	PistDocParser pars(user_setting);
	if ( !pars ) {
		cout<<"Cannot open file "<<user_setting<<endl;
		return -1;
	}

	/* Get the global setting */
	str = pars.queryString("global.settings.setting.BackColor:");
	sharp_to_rgb(str, R, G, B);
	global_set.set_style_bgcolor( RGB(R,G,B) );
	str = pars.queryString("global.settings.setting.ForeColor:");
	sharp_to_rgb(str, R, G, B);
	global_set.set_style_fgcolor( RGB(R,G,B) );
	str = pars.queryString("global.settings.setting.FontName:");
	global_set.set_style_font_name(str);
	
	global_set.set_style_font_size(pars.queryObject("global.settings.setting.FontSize:").toInteger());
	global_set.set_style_font_italic(pars.queryBoolean("global.settings.setting.FontItalic:"));
	global_set.set_style_font_bold(pars.queryBoolean("global.settings.setting.FontBold:"));

	list<PistNodeParser> languages = pars.queryList("languages.language");
	list<PistNodeParser>::iterator lang_itor = languages.begin();
	
	while (lang_itor != languages.end()) {
		for (int i = 0; i < num_of_styles; ++i) {
			reg_parten.str("");
			reg_parten<<".*\\.("<<c_style_languages[i].lang_postfix<<")";
			regex file_postfix_reg_c(reg_parten.str(), regex::perl|regex::icase);
			PistNodeParser p = *lang_itor;
			cout<<p.queryString(":name")<<endl;
			//printf("[User Lexer going through Style] %s", p.queryString(":name"));
			if (regex_match(p.queryString(":file"), file_postfix_reg_c)) {
				detected_style = i;
				printf("[User Lexer Style] %s detected\n", c_style_languages[detected_style].lang_name);	
				conf_guideline* curr_guide  = c_style_languages[detected_style].lang_style_guide;
				while (curr_guide && curr_guide->guide_query) {
					conf_style_set_c tmp_set = get_user_setting_from_node(p, curr_guide, global_set);
					c_style_languages[detected_style].lang_user_style.push_back(tmp_set);
					curr_guide++;
				}
				curr_guide = c_style_languages[detected_style].lang_keywords_guide;
				while (curr_guide && curr_guide->guide_query) {
					get_keyword_list_from_node(p, curr_guide, c_style_languages[detected_style].lang_keyword_list);
					cout<<"EEEEEEEEEEEEEEEEEEEEEEEE"<<endl;
					curr_guide++;
				}
			}
		}
		lang_itor++;
	}
	return 0;
}

static int language_detect_and_styling(char * file_name, int inhint, style_setting_callback callback, style_setting_instance instance, void ** output) {
	ostringstream reg_parten;
	int num_of_styles;
	int detected_style, style_identy;
	conf_style_set * curr_set;
	
	if (!file_name && inhint == -1)
		return -1;
	num_of_styles = sizeof(c_style_languages)/sizeof(conf_style_language);
	detected_style = -1;

	for (int i = 0; i < num_of_styles; ++i) {
		reg_parten.str("");
		reg_parten<<".*\\w*\\.("<<c_style_languages[i].lang_postfix<<")";
		printf("[Lexer] regex pattrn %s\n", reg_parten.str().c_str());
		regex file_postfix_reg_c(reg_parten.str(), regex::perl|regex::icase);
		if (regex_match(file_name, file_postfix_reg_c)) {
			detected_style = i;
			printf("[Lexer] %s detected\n", c_style_languages[detected_style].lang_name);
			break;
		}
		printf("[Lexer] %s passed\n", c_style_languages[i].lang_name);
	}
	if (detected_style >= 0 && callback && instance) {
		style_identy = c_style_languages[detected_style].lang_identy_number;
		//curr_set = c_style_languages[detected_style].lang_style_set;
		callback(instance, SCI_SETLEXER, style_identy, style_identy);
		conf_style_lexer_property * curr_property = c_style_languages[detected_style].lang_property_set;
		while (curr_property && curr_property->property_name) {
			if (curr_property->property_type == LANG_PROPERTY_TYPE_STRING) {
				callback(instance, SCI_SETPROPERTY, int(curr_property->property_name), int(curr_property->property_value_str));
			} else {
				callback(instance, SCI_SETPROPERTY, int(curr_property->property_name), int(curr_property->property_value_int));
			}
			curr_property++;
		};
#if 0
		while (curr_set && curr_set->style_name) {
			//callback(instance, SCI_STYLESETFONT, curr_set->style_identy, (int)curr_set->style_font_name);
			//callback(instance, SCI_STYLESETFORE, curr_set->style_identy, (int)curr_set->style_fgcolor);
			//callback(instance, SCI_STYLESETBACK, curr_set->style_identy, (int)curr_set->style_bgcolor);
			//callback(instance, SCI_STYLESETSIZE, curr_set->style_identy, (int)curr_set->style_font_size);
			//callback(instance, SCI_STYLESETBOLD, curr_set->style_identy, (int)curr_set->style_font_bold);
			//callback(instance, SCI_STYLEGETITALIC, curr_set->style_identy, (int)curr_set->style_font_italic);
			//cout<<curr_set->style_name<<" Default Setted "<<endl;
			curr_set++;
		}
#endif
		list<conf_style_set_c>::iterator user_set_itor = c_style_languages[detected_style].lang_user_style.begin();
		list<conf_style_set_c>::iterator user_set_end = c_style_languages[detected_style].lang_user_style.end();
		
		while ( user_set_itor != user_set_end ) {
			callback(instance, SCI_STYLESETFONT, user_set_itor->get_style_identy(), (int)(user_set_itor->get_style_font_name()).c_str());
			callback(instance, SCI_STYLESETFORE, user_set_itor->get_style_identy(), (int)(user_set_itor->get_style_fgcolor()));
			callback(instance, SCI_STYLESETBACK, user_set_itor->get_style_identy(), (int)(user_set_itor->get_style_bgcolor()));
			callback(instance, SCI_STYLESETSIZE, user_set_itor->get_style_identy(), (int)(user_set_itor->get_style_font_size()));
			callback(instance, SCI_STYLESETBOLD, user_set_itor->get_style_identy(), (int)(user_set_itor->get_style_font_bold()));
			callback(instance, SCI_STYLEGETITALIC, user_set_itor->get_style_identy(), (int)(user_set_itor->get_style_font_italic()));
			user_set_itor++;
		}
#if 0
		conf_style_token_list * curr_list;
		for (int i = 0; i < 8; ++i) {
			curr_list = c_style_languages[detected_style].lang_keywords[i];
			if (curr_list) {
				callback(instance, SCI_SETKEYWORDS, curr_list->tklist_identy, (int)curr_list->tklist);
			}
		}
#endif

		list<conf_style_keywords_c>::iterator keyword_itor = c_style_languages[detected_style].lang_keyword_list.begin();
		list<conf_style_keywords_c>::iterator keyword_end = c_style_languages[detected_style].lang_keyword_list.end();
		cout<<"FFFFFFFFFFFFFFFFFFFFFF"<<endl;
		while ( keyword_itor != keyword_end ) {
			cout<<"GGGGGGGGGGGGGGGGG"<<endl;
			conf_style_keywords_c curr_list = *keyword_itor;
			callback(instance, SCI_SETKEYWORDS, curr_list.key_identy, (int)curr_list.keylist.c_str());
			cout<<" *** Outputing key word list : "<<curr_list.keylist<<endl;
			cout<<" *** as identy : "<<curr_list.key_identy<<endl;
			++keyword_itor;
		}



		static const int MARGIN_SCRIPT_FOLD_INDEX = 1;
		/* For common setting */
		callback(instance, SCI_SETPROPERTY, (int)"fold", (int)"1");
		callback(instance, SCI_SETPROPERTY, (int)"fold.comment", (int)"1");
		callback(instance, SCI_SETPROPERTY, (int)"fold.preprocessor", (int)"1");
    	callback(instance, SCI_SETMARGINWIDTHN, MARGIN_SCRIPT_FOLD_INDEX, 0);
		callback(instance, SCI_SETMARGINTYPEN,  MARGIN_SCRIPT_FOLD_INDEX, SC_MARGIN_SYMBOL);
    	callback(instance, SCI_SETMARGINMASKN, MARGIN_SCRIPT_FOLD_INDEX, SC_MASK_FOLDERS);
    	callback(instance, SCI_SETMARGINWIDTHN, MARGIN_SCRIPT_FOLD_INDEX, 20);
    	callback(instance, SCI_MARKERDEFINE, SC_MARKNUM_FOLDER, SC_MARK_ARROW);
    	callback(instance, SCI_MARKERDEFINE, SC_MARKNUM_FOLDEROPEN, SC_MARK_ARROWDOWN);
    	callback(instance, SCI_MARKERDEFINE, SC_MARKNUM_FOLDEREND, SC_MARK_EMPTY);
    	callback(instance, SCI_MARKERDEFINE, SC_MARKNUM_FOLDERMIDTAIL, SC_MARK_EMPTY);
    	callback(instance, SCI_MARKERDEFINE, SC_MARKNUM_FOLDEROPENMID, SC_MARK_EMPTY);
    	callback(instance, SCI_MARKERDEFINE, SC_MARKNUM_FOLDERSUB, SC_MARK_EMPTY);
    	callback(instance, SCI_MARKERDEFINE, SC_MARKNUM_FOLDERTAIL, SC_MARK_EMPTY);
    	callback(instance, SCI_SETMARGINSENSITIVEN, MARGIN_SCRIPT_FOLD_INDEX, 1);
    	callback(instance, SCI_SETFOLDFLAGS, 16, 0); // 16  	Draw line below if not expanded
    	callback(instance, SCI_SETTABWIDTH, 4, 0); // Set tab width as 4
    	callback(instance, SCI_SETUSETABS, 1, 0);
    	callback(instance, SCI_SETWHITESPACESIZE, 10, 0);
    	//callback(instance, SCI_SETINDENT, 4, 0);

    	*output = (void*) c_style_languages[detected_style].create_autoc_manager;
	}

	return detected_style;
}

int IdentifyAndStyle(struct nxGloryChildren * wnd, const char * name, int hint) {
	AutoCompleteManager * (*output)(struct nxGloryChildren *)  = NULL;
	int ret = language_detect_and_styling((char*)name, hint, (style_setting_callback)wnd->ngCommand, (style_setting_instance)wnd->ngInstance, (void**)&output);
	if ( output )
		wnd->autoc_manager = output(wnd);
	return ret;
}
