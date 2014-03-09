#include "pistachio.h"
#include <string>
#include <iostream>
#include <boost\regex.hpp>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace boost;

PistObject::~PistObject() {
	if (_type == PIST_OBJ_STRING &&
		_value.pist_str)
		delete _value.pist_str;
	else 
	if (_type == PIST_OBJ_LIST &&
		_value.pist_list) {
		delete _value.pist_list;
	}
}
#if 1
PistObject::PistObject(const PistObject& pist) {
	if ( pist._type == PIST_OBJ_STRING ) {
		_type = PIST_OBJ_STRING;
		_value.pist_str = new string(*pist._value.pist_str);
		return;
	}
	if ( pist._type == PIST_OBJ_LIST ) {
		_type = PIST_OBJ_LIST;
		_value.pist_list = new PistList(*pist._value.pist_list);
		return;
	}
}
#endif
PistDocParser::PistDocParser(const string f_name) {
	if (Load(f_name) == 0)
		_m_inited = false;
	else
		_m_inited = true;
}

int PistDocParser::Load(const string f_name) {
	return doc.LoadFile(f_name.c_str());
}

string PistParser::queryString(const string query) {
	PistObject query_obj;
	query_obj._type = PistObject::PIST_OBJ_STRING;
	_pist_do_query(query_obj, query);
	if (query_obj._type == PistObject::PIST_OBJ_STRING &&
		query_obj._value.pist_str != NULL) {
		//cout<<"queryString: return "<<*query_obj._value.pist_str<<endl;
		return *query_obj._value.pist_str;
	}
	return string("");
}

string PObject::toString() {
	return _data;
}

bool PObject::toBoolean() {
	if ( _type == PistObject::PIST_OBJ_BOOLEAN ) {
		regex _true("true", boost::regex::icase);
		if (regex_match(_data, _true))
			return true;
		else
			return false;
	}
	return is_valid();
}

int PObject::toInteger() {
	int t;
	bool b;
	string number_str = _data;
	
	regex hex("#([0-9a-fA-F]+)");
	regex decimal("\\d+"); 
	if ( regex_match(_data, hex) ) {
		number_str = regex_replace(_data, hex, "0x$1");
		//cout<<"toInteger convert hex format "<<number_str<<endl;
		sscanf(number_str.c_str(), "%x", &t);
	} else
	if ( regex_match(_data, decimal) ) {
		sscanf(number_str.c_str(), "%d", &t);
	}
	return t;
	
	if ( _type == PistObject::PIST_OBJ_BOOLEAN ) {
		b = toBoolean();
		if (b)
			return 1;
		else
			return 0;
	}
	return 0;
}

int PistParser::queryInteger(const string query) {
	PistObject query_obj;
	query_obj._type = PistObject::PIST_OBJ_INTEGER;
	_pist_do_query(query_obj, query);
	if (query_obj._type == PistObject::PIST_OBJ_INTEGER)
		return query_obj._value.pist_int;
	return 0;
}

bool PistParser::queryBoolean(const string query) {
	PistObject query_obj;
	query_obj._type = PistObject::PIST_OBJ_BOOLEAN;
	_pist_do_query(query_obj, query);
	if (query_obj._type == PistObject::PIST_OBJ_BOOLEAN)
		return query_obj._value.pist_bool;
	return false;
}

double PistParser::queryDouble(const string query) {
	PistObject query_obj;
	query_obj._type = PistObject::PIST_OBJ_DOUBLE;
	_pist_do_query(query_obj, query);
	if (query_obj._type == PistObject::PIST_OBJ_DOUBLE)
		return query_obj._value.pist_double;
	return 0.0;
}

list<PistNodeParser> PistParser::queryList(const string query) {
	PistObject query_obj;
	query_obj._type = PistObject::PIST_OBJ_LIST;
	query_obj._value.pist_list = NULL;
	_pist_do_query(query_obj, query);
	if (query_obj._type == PistObject::PIST_OBJ_LIST &&
		query_obj._value.pist_list != NULL)
		return *query_obj._value.pist_list;
	list<PistNodeParser> ret;
	return ret;
}

void PObject::_adjust_type() {
	//if ( this->_data.size() > 0 ) {
		/* is number? */
		regex number("[\\d+]");
		if (regex_match(_data.c_str(), number)) {
			_type = PistObject::PIST_OBJ_INTEGER;
			return;
		}
		regex hex("#[0-9a-fA-F]+");
		if (regex_match(_data.c_str(), hex)) {
			_type = PistObject::PIST_OBJ_INTEGER;
			return;
		}
		regex decimal("\\d*\\.[\\d]+");
		if (regex_match(_data.c_str(), decimal)) {
			_type = PistObject::PIST_OBJ_DOUBLE;
			return;
		}
		/* is boolean */
		regex boolean("true|false", boost::regex::icase);
		if (regex_match(_data.c_str(), boolean)) {
			_type = PistObject::PIST_OBJ_BOOLEAN;
			return;
		}

		/* fall over assume string */
		_type = PistObject::PIST_OBJ_STRING;
	//}
	//cout<<"Got unknown type"<<endl;
	//_type = PistObject::PIST_OBJ_UNKNOWN;
}

PObject PistParser::queryObject(const std::string query) {
	PObject ret;
	string str = queryString(query);
	if ( !str.empty() ) {
		ret._data = str;
		ret._adjust_type();
		//cout<<str<<" : "<<ret._data<<endl;
		//cout<<"ret._type = "<<ret._type<<endl;
		//cout<<"A"<<endl;
		return ret;
	}
	//cout<<str<<endl;
	//cout<<"B"<<endl;
	return ret;
}

#define QUERY_NEXT		0
#define QUERY_ATTR		1
#define QUERY_TEXT		2
#define QUERY_DATA		3

static int _fix_element_name(const string & tmp, string & element, string & attribute) {
	static regex parentheses("([a-zA-Z0-9_-]*):(.*)");
	smatch sub_query;
	int ret = QUERY_NEXT;
	if (regex_search(tmp, sub_query, parentheses)) {
		if (sub_query[1].matched) // espected to be the actrul element name
			element = sub_query[1];
		if (sub_query[2].matched) {// espected to be the attribute name. null for text content
			attribute = sub_query[2];
			if ( !attribute.empty() )
				ret = QUERY_ATTR;
			else
				ret = QUERY_TEXT;
		}
		else {
			attribute.clear();
			ret = QUERY_TEXT;
		}
	} else {
		element = tmp;
		attribute.clear();
		ret = QUERY_NEXT;
	}

	return ret;
}

static string _do_query_string(TiXmlElement * elem, const string & attr, int flag) {
	const char * str = NULL;
	string ret("");
	if (!elem)
		return ret;
	switch (flag) {
	case QUERY_ATTR:
		str = elem->Attribute(attr.c_str());
		//cout<<"***querying attr : "<<attr<<"from ele @"<<(unsigned int)elem<<endl;
		if ( str != NULL )
			ret = str;
		break;
	case QUERY_TEXT:
		//cout<<"***querying text"<<endl;
		str = elem->GetText();
		if ( str != NULL)
			ret = str;
		break;
	}

	return ret;
}

#define GO_NEXT(pElem, next_step) \
	do {\
		if ( pElem && (next_step != QUERY_NEXT) ) { \
			switch (p_obj._type) { \
			case PistObject::PIST_OBJ_STRING: \
			case PistObject::PIST_OBJ_COLOR:\
				p_obj._value.pist_str = new string(_do_query_string(pElem, attribute_name, next_step)); \
				if ( p_obj._value.pist_str->empty() ) \
					p_obj._type = PistObject::PIST_OBJ_UNKNOWN; \
				break; \
			case PistObject::PIST_OBJ_INTEGER: \
				if ( pElem->QueryIntAttribute(attribute_name.c_str(), &p_obj._value.pist_int) != TIXML_SUCCESS ) \
					p_obj._type = PistObject::PIST_OBJ_UNKNOWN; \
				break;\
			case PistObject::PIST_OBJ_BOOLEAN: \
				if ( pElem->QueryBoolAttribute(attribute_name.c_str(), &p_obj._value.pist_bool) != TIXML_SUCCESS ) \
					p_obj._type = PistObject::PIST_OBJ_UNKNOWN; \
				break; \
			case PistObject::PIST_OBJ_DOUBLE: \
				if ( pElem->QueryDoubleAttribute(attribute_name.c_str(), &p_obj._value.pist_double) != TIXML_SUCCESS ) \
					p_obj._type = PistObject::PIST_OBJ_UNKNOWN; \
				break; \
			case PistObject::PIST_OBJ_LIST: \
				pElem = pElem->FirstChildElement(); \
				break; \
			default: \
				p_obj._type = PistObject::PIST_OBJ_UNKNOWN; \
			} \
			return 0; \
		}\
	} while (0)

int PistDocParser::_pist_do_query(PistObject & p_obj, const std::string & query) {
	TiXmlElement * pElem;
	list<PistNodeParser> * ele_list;
	regex separator("\\.");
	
	string attribute_name("");
	string curr_query;

	sregex_token_iterator itor(query.begin(), query.end(), separator, -1);
	sregex_token_iterator end;
	sregex_token_iterator last;

	if ( itor != end ) {
		int next_step = _fix_element_name(*itor, curr_query, attribute_name);
		pElem = doc.FirstChildElement(curr_query.c_str());
		GO_NEXT(pElem, next_step);
		++itor;
	}
	while (itor != end) {
		if (pElem) {
			int next_step = _fix_element_name(*itor, curr_query, attribute_name);
			if (!curr_query.empty())
				pElem = pElem->FirstChildElement(curr_query.c_str());
			if ( !pElem )
				goto DOC_OUT;
			GO_NEXT(pElem, next_step);
			last = itor;
			++itor;
		}
	}
	/* Quering list */
	curr_query = *last;
	if ( p_obj._type == PistObject::PIST_OBJ_LIST ) {
		//cout<<"query list"<<endl;
		ele_list = new list<PistNodeParser>;
		while (pElem) {
			PistNodeParser tmp(pElem);
			ele_list->push_back(tmp);
			pElem = pElem->NextSiblingElement(curr_query.c_str());
		}
		p_obj._value.pist_list = ele_list;
		return 0;
	}
DOC_OUT:
	p_obj._type = PistObject::PIST_OBJ_UNKNOWN;
	return 0;
}

int PistNodeParser::_pist_do_query(PistObject & p_obj, const std::string & query) {
	TiXmlElement * pElem;
	list<PistNodeParser> * ele_list;
	regex separator("\\.");
	
	string attribute_name("");
	string curr_query;

	sregex_token_iterator itor(query.begin(), query.end(), separator, -1);
	sregex_token_iterator end;
	sregex_token_iterator last;

	pElem = this->node;

	while (itor != end) {
		if (pElem) {
			int next_step = _fix_element_name(*itor, curr_query, attribute_name);
			if (!curr_query.empty())
				pElem = pElem->FirstChildElement(curr_query.c_str());
			if ( !pElem )
				goto NODE_OUT;
			GO_NEXT(pElem, next_step);
			last = itor;
			++itor;
		}
	}
	/* Quering list */
	curr_query = *last;
	if ( p_obj._type == PistObject::PIST_OBJ_LIST ) {
		//cout<<"query list"<<endl;
		ele_list = new list<PistNodeParser>;
		while (pElem) {
			PistNodeParser tmp(pElem);
			ele_list->push_back(tmp);
			pElem = pElem->NextSiblingElement(curr_query.c_str());
		}
		p_obj._value.pist_list = ele_list;
		return 0;
	}
NODE_OUT:
	p_obj._type = PistObject::PIST_OBJ_UNKNOWN;
	return 0;
}

#ifndef	RGB(...)
#define RGB(red, green, blue) \
	int(red | (green << 8) | (blue << 16))
#endif

void sharp_to_rgb(const string sharp, int & R, int & G, int & B) {
	unsigned int t = 0;
	R = G = B = 0;
	regex hex("#([0-9a-fA-F]+)");
	string s = regex_replace(sharp, hex, "0x$1");
	sscanf(s.c_str(), "%x", &t);
	//cout<<t;
	B = t & 0xFF;
	G = (t >> 8) & 0xFF;
	R = (t >> 16) & 0xFF;
}

unsigned int sharp_to_rgb(const string sharp) {
	int R, G, B;
	sharp_to_rgb(sharp, R, G, B);
	return unsigned int(RGB(R,G,B));
}

int string_to_int(const std::string & str) {
	int t;
	regex hex("#([0-9a-fA-F]+)");
	string number_str;
	if ( regex_match(str, hex) ) {
		number_str = regex_replace(str, hex, "0x$1");
		//cout<<"toInteger convert hex format "<<number_str<<endl;
		sscanf(number_str.c_str(), "%x", &t);
	} else {
		sscanf(number_str.c_str(), "%d", &t);
	}
	return t;
}

bool string_to_bool(const std::string & str) {
	regex _true("true", boost::regex::icase);
	regex _false("false", boost::regex::icase);
	if (regex_match(str, _true))
		return true;
	if (regex_match(str, _false))
		return false;
	return false;
}

PObject::operator bool() {
	if ( _type == PistObject::PIST_OBJ_BOOLEAN )
		return toBoolean();
	return is_valid();
}


#if 0
int main() {
	//PistDocParser pars("E:\\gecko_file_types.xml");
	PistDocParser pars("E:\\lexer_settings.xml");
	list<PistNodeParser> lst = pars.queryList("languages.language.settings.setting");
	list<PistNodeParser>::iterator itor = lst.begin();
	
	while (itor != lst.end()) {
		PistNodeParser curr_set = *itor;
		//cout<<"query list, got setting node \""<<p.queryString(":name")<<"\""<<endl;
		PObject obj = curr_set.queryObject(":name");
		if ( obj )
			cout<<"query object, got setting node \""<<obj.toString()<<"\""<<endl;
		obj = curr_set.queryObject(":font-name");
		obj = curr_set.queryObject(":font-name");
					if (obj) {
						cout<<"[User Lexer Style] get font name \'"<<obj.toString()<<"\'"<<endl;
					} else {
						cout<<"[User Lexer Style] no font name dedined, using default"<<endl;
					}

					obj = curr_set.queryObject(":font-size");
					if (obj) {
						cout<<"[User Lexer Style] get font size \'"<<obj.toInteger()<<"\'"<<endl;
					} else {
						cout<<"[User Lexer Style] no font size dedined, using default"<<endl;
					}

		++itor;
	}
	system("pause");
	return 0;
}
#endif