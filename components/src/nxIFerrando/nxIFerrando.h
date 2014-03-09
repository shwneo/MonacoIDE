/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ./nxIFerrando.idl
 */

#ifndef __gen_nxIFerrando_h__
#define __gen_nxIFerrando_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIBaseWindow_h__
#include "nsIBaseWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nxIFerrando */
#define NXIFERRANDO_IID_STR "9a41d581-7f33-4ded-b053-eaf683abead4"

#define NXIFERRANDO_IID \
  {0x9a41d581, 0x7f33, 0x4ded, \
    { 0xb0, 0x53, 0xea, 0xf6, 0x83, 0xab, 0xea, 0xd4 }}

class NS_NO_VTABLE nxIFerrando : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NXIFERRANDO_IID)

  /* long Add (in long a, in long b); */
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) = 0;

  /* long CreateFileFromTemplate (in wstring file_path_name, in long construct_type, in wstring template_file, in wstring project_file); */
  NS_IMETHOD CreateFileFromTemplate(const PRUnichar * file_path_name, int32_t construct_type, const PRUnichar * template_file, const PRUnichar * project_file, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nxIFerrando, NXIFERRANDO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NXIFERRANDO \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval); \
  NS_IMETHOD CreateFileFromTemplate(const PRUnichar * file_path_name, int32_t construct_type, const PRUnichar * template_file, const PRUnichar * project_file, int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NXIFERRANDO(_to) \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) { return _to Add(a, b, _retval); } \
  NS_IMETHOD CreateFileFromTemplate(const PRUnichar * file_path_name, int32_t construct_type, const PRUnichar * template_file, const PRUnichar * project_file, int32_t *_retval) { return _to CreateFileFromTemplate(file_path_name, construct_type, template_file, project_file, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NXIFERRANDO(_to) \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(a, b, _retval); } \
  NS_IMETHOD CreateFileFromTemplate(const PRUnichar * file_path_name, int32_t construct_type, const PRUnichar * template_file, const PRUnichar * project_file, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFileFromTemplate(file_path_name, construct_type, template_file, project_file, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nxFerrando : public nxIFerrando
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NXIFERRANDO

  nxFerrando();

private:
  ~nxFerrando();

protected:
  /* additional members */
};

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
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long CreateFileFromTemplate (in wstring file_path_name, in long construct_type, in wstring template_file, in wstring project_file); */
NS_IMETHODIMP nxFerrando::CreateFileFromTemplate(const PRUnichar * file_path_name, int32_t construct_type, const PRUnichar * template_file, const PRUnichar * project_file, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nxIFerrando_h__ */
