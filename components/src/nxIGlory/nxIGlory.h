/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ./nxIGlory.idl
 */

#ifndef __gen_nxIGlory_h__
#define __gen_nxIGlory_h__


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

/* starting interface:    nxIGlory */
#define NXIGLORY_IID_STR "c13d16b4-3b2a-11e3-b51c-00e04c32f3ec"

#define NXIGLORY_IID \
  {0xc13d16b4, 0x3b2a, 0x11e3, \
    { 0xb5, 0x1c, 0x00, 0xe0, 0x4c, 0x32, 0xf3, 0xec }}

class NS_NO_VTABLE nxIGlory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NXIGLORY_IID)

  /* attribute nsIBaseWindow baseWindow; */
  NS_IMETHOD GetBaseWindow(nsIBaseWindow * *aBaseWindow) = 0;
  NS_IMETHOD SetBaseWindow(nsIBaseWindow *aBaseWindow) = 0;

  /* long Add (in long a, in long b); */
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) = 0;

  /* long AttachWindow (in nsIBaseWindow window); */
  NS_IMETHOD AttachWindow(nsIBaseWindow *window, int32_t *_retval) = 0;

  /* long ResizeWindow (in long x, in long y, in long width, in long height); */
  NS_IMETHOD ResizeWindow(int32_t x, int32_t y, int32_t width, int32_t height, int32_t *_retval) = 0;

  /* long CommandWindow (in long cmd, in long lparam, in long wparam); */
  NS_IMETHOD CommandWindow(int32_t cmd, int32_t lparam, int32_t wparam, int32_t *_retval) = 0;

  /* long CommandWindowWithString (in long cmd, in wstring w_str); */
  NS_IMETHOD CommandWindowWithString(int32_t cmd, const PRUnichar * w_str, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nxIGlory, NXIGLORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NXIGLORY \
  NS_IMETHOD GetBaseWindow(nsIBaseWindow * *aBaseWindow); \
  NS_IMETHOD SetBaseWindow(nsIBaseWindow *aBaseWindow); \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval); \
  NS_IMETHOD AttachWindow(nsIBaseWindow *window, int32_t *_retval); \
  NS_IMETHOD ResizeWindow(int32_t x, int32_t y, int32_t width, int32_t height, int32_t *_retval); \
  NS_IMETHOD CommandWindow(int32_t cmd, int32_t lparam, int32_t wparam, int32_t *_retval); \
  NS_IMETHOD CommandWindowWithString(int32_t cmd, const PRUnichar * w_str, int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NXIGLORY(_to) \
  NS_IMETHOD GetBaseWindow(nsIBaseWindow * *aBaseWindow) { return _to GetBaseWindow(aBaseWindow); } \
  NS_IMETHOD SetBaseWindow(nsIBaseWindow *aBaseWindow) { return _to SetBaseWindow(aBaseWindow); } \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) { return _to Add(a, b, _retval); } \
  NS_IMETHOD AttachWindow(nsIBaseWindow *window, int32_t *_retval) { return _to AttachWindow(window, _retval); } \
  NS_IMETHOD ResizeWindow(int32_t x, int32_t y, int32_t width, int32_t height, int32_t *_retval) { return _to ResizeWindow(x, y, width, height, _retval); } \
  NS_IMETHOD CommandWindow(int32_t cmd, int32_t lparam, int32_t wparam, int32_t *_retval) { return _to CommandWindow(cmd, lparam, wparam, _retval); } \
  NS_IMETHOD CommandWindowWithString(int32_t cmd, const PRUnichar * w_str, int32_t *_retval) { return _to CommandWindowWithString(cmd, w_str, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NXIGLORY(_to) \
  NS_IMETHOD GetBaseWindow(nsIBaseWindow * *aBaseWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseWindow(aBaseWindow); } \
  NS_IMETHOD SetBaseWindow(nsIBaseWindow *aBaseWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseWindow(aBaseWindow); } \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(a, b, _retval); } \
  NS_IMETHOD AttachWindow(nsIBaseWindow *window, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AttachWindow(window, _retval); } \
  NS_IMETHOD ResizeWindow(int32_t x, int32_t y, int32_t width, int32_t height, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResizeWindow(x, y, width, height, _retval); } \
  NS_IMETHOD CommandWindow(int32_t cmd, int32_t lparam, int32_t wparam, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CommandWindow(cmd, lparam, wparam, _retval); } \
  NS_IMETHOD CommandWindowWithString(int32_t cmd, const PRUnichar * w_str, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CommandWindowWithString(cmd, w_str, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nxGlory : public nxIGlory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NXIGLORY

  nxGlory();

private:
  ~nxGlory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nxGlory, nxIGlory)

nxGlory::nxGlory()
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
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long AttachWindow (in nsIBaseWindow window); */
NS_IMETHODIMP nxGlory::AttachWindow(nsIBaseWindow *window, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long ResizeWindow (in long x, in long y, in long width, in long height); */
NS_IMETHODIMP nxGlory::ResizeWindow(int32_t x, int32_t y, int32_t width, int32_t height, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long CommandWindow (in long cmd, in long lparam, in long wparam); */
NS_IMETHODIMP nxGlory::CommandWindow(int32_t cmd, int32_t lparam, int32_t wparam, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long CommandWindowWithString (in long cmd, in wstring w_str); */
NS_IMETHODIMP nxGlory::CommandWindowWithString(int32_t cmd, const PRUnichar * w_str, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nxIGlory_h__ */
