#ifndef __PISTACHIO_H__
#define __PISTACHIO_H__
#include <string>
#include <iostream>
#include <list>
#include "tinyxml.h"


class PistObject;
class PistNodeParser;
class PObject;

class PistObject {
protected:
	enum query_type;
	query_type _type;
	union {
		std::string * pist_str;
		std::list<PistNodeParser> * pist_list;
		void * p_list;
		int			pist_int;
		bool		pist_bool;
		double		pist_double;
	} _value;
public:
	enum query_type {
		PIST_OBJ_UNKNOWN = 0,
		PIST_OBJ_STRING,
		PIST_OBJ_COLOR,
		PIST_OBJ_INTEGER,
		PIST_OBJ_BOOLEAN,
		PIST_OBJ_DOUBLE,
		PIST_OBJ_LIST,
	};
	PistObject():_type(PIST_OBJ_UNKNOWN){};
	PistObject(const PistObject&);
	virtual ~PistObject();
	friend class PistParser;
	friend class PistDocParser;
	friend class PistNodeParser;
	friend class PObject;
};

typedef std::list<PistNodeParser> PistList;

class  PistParser {
protected:
	virtual int _pist_do_query(PistObject & p_obj, const std::string & query) = 0;
public:
	PistParser(){};
	virtual ~PistParser(){};
	std::string queryString(const std::string query);
	int    queryInteger(const std::string query);
	bool   queryBoolean(const std::string query);
	double queryDouble(const std::string query);
	PistList queryList(const std::string query);
	PObject queryObject(const std::string query);
};

class  PistNodeParser : public PistParser {
protected:
	
	int _pist_do_query(PistObject & p_obj, const std::string & query);
public:
	TiXmlElement * node;
	PistNodeParser():node(NULL){};
	PistNodeParser(TiXmlElement * n):node(n){};
	PistNodeParser(const PistNodeParser& p){ node = p.node;};
	virtual ~PistNodeParser(){};
};

class  PistDocParser : public PistParser {
protected:
	bool _m_inited;
	TiXmlDocument doc;
	int _pist_do_query(PistObject & p_obj, const std::string & query);
public:
	PistDocParser():_m_inited(false){};
	PistDocParser(const std::string f_name);
	virtual ~PistDocParser(){};
	int Load(const std::string f_name);
	operator bool(){return _m_inited;};
};

class PObject {
protected:
	//PistObject * _data;
	std::string _data;
	PistObject::query_type _type;
	void _adjust_type();
public:
	PObject():_type(PistObject::PIST_OBJ_UNKNOWN){};
	PObject(const PObject& p){ _data = p._data;_type=p._type;};
	PObject(const std::string & str) {
		_data.clear();
		_data = str;
	};
	virtual ~PObject() {};

	
	bool is_string() {return _type == PistObject::PIST_OBJ_STRING; };
	bool is_integer() {return _type == PistObject::PIST_OBJ_INTEGER; };
	bool is_double() {return _type == PistObject::PIST_OBJ_DOUBLE; };
	bool is_boolean() {return _type == PistObject::PIST_OBJ_BOOLEAN; };
	bool is_list() { return _type == PistObject::PIST_OBJ_LIST; };
	bool is_valid () { return _type != PistObject::PIST_OBJ_UNKNOWN; };

	std::string toString();
	bool		toBoolean();
	int 		toInteger();

	operator bool();
	friend class PistParser;
};

void sharp_to_rgb(const std::string sharp, int & R, int & G, int & B);
unsigned int sharp_to_rgb(const std::string sharp);
int string_to_int(const std::string & str);
bool string_to_bool(const std::string & str);

#endif