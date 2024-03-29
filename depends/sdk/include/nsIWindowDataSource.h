/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM d:/xulrunner-24.0.source/mozilla-release/xpfe/components/windowds/nsIWindowDataSource.idl
 */

#ifndef __gen_nsIWindowDataSource_h__
#define __gen_nsIWindowDataSource_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIDOMWindow_h__
#include "nsIDOMWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWindowDataSource */
#define NS_IWINDOWDATASOURCE_IID_STR "3722a5b9-5323-4ed0-bb1a-8299f27a4e89"

#define NS_IWINDOWDATASOURCE_IID \
  {0x3722a5b9, 0x5323, 0x4ed0, \
    { 0xbb, 0x1a, 0x82, 0x99, 0xf2, 0x7a, 0x4e, 0x89 }}

class NS_NO_VTABLE nsIWindowDataSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWDATASOURCE_IID)

  /* nsIDOMWindow getWindowForResource (in string inResource); */
  NS_IMETHOD GetWindowForResource(const char * inResource, nsIDOMWindow * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowDataSource, NS_IWINDOWDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWDATASOURCE \
  NS_IMETHOD GetWindowForResource(const char * inResource, nsIDOMWindow * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWDATASOURCE(_to) \
  NS_IMETHOD GetWindowForResource(const char * inResource, nsIDOMWindow * *_retval) { return _to GetWindowForResource(inResource, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWDATASOURCE(_to) \
  NS_IMETHOD GetWindowForResource(const char * inResource, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowForResource(inResource, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowDataSource : public nsIWindowDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWDATASOURCE

  nsWindowDataSource();

private:
  ~nsWindowDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowDataSource, nsIWindowDataSource)

nsWindowDataSource::nsWindowDataSource()
{
  /* member initializers and constructor code */
}

nsWindowDataSource::~nsWindowDataSource()
{
  /* destructor code */
}

/* nsIDOMWindow getWindowForResource (in string inResource); */
NS_IMETHODIMP nsWindowDataSource::GetWindowForResource(const char * inResource, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowDataSource_h__ */
