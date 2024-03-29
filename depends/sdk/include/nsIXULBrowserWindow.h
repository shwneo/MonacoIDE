/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM d:/xulrunner-24.0.source/mozilla-release/xpfe/appshell/public/nsIXULBrowserWindow.idl
 */

#ifndef __gen_nsIXULBrowserWindow_h__
#define __gen_nsIXULBrowserWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIURI_h__
#include "nsIURI.h"
#endif

#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */

class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIXULBrowserWindow */
#define NS_IXULBROWSERWINDOW_IID_STR "7c91b4bd-f855-4872-b3fa-a2076d28eb03"

#define NS_IXULBROWSERWINDOW_IID \
  {0x7c91b4bd, 0xf855, 0x4872, \
    { 0xb3, 0xfa, 0xa2, 0x07, 0x6d, 0x28, 0xeb, 0x03 }}

class NS_NO_VTABLE nsIXULBrowserWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULBROWSERWINDOW_IID)

  /* void setJSStatus (in AString status); */
  NS_IMETHOD SetJSStatus(const nsAString & status) = 0;

  /* void setOverLink (in AString link, in nsIDOMElement element); */
  NS_IMETHOD SetOverLink(const nsAString & link, nsIDOMElement *element) = 0;

  /* AString onBeforeLinkTraversal (in AString originalTarget, in nsIURI linkURI, in nsIDOMNode linkNode, in boolean isAppTab); */
  NS_IMETHOD OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULBrowserWindow, NS_IXULBROWSERWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULBROWSERWINDOW \
  NS_IMETHOD SetJSStatus(const nsAString & status); \
  NS_IMETHOD SetOverLink(const nsAString & link, nsIDOMElement *element); \
  NS_IMETHOD OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULBROWSERWINDOW(_to) \
  NS_IMETHOD SetJSStatus(const nsAString & status) { return _to SetJSStatus(status); } \
  NS_IMETHOD SetOverLink(const nsAString & link, nsIDOMElement *element) { return _to SetOverLink(link, element); } \
  NS_IMETHOD OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval) { return _to OnBeforeLinkTraversal(originalTarget, linkURI, linkNode, isAppTab, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULBROWSERWINDOW(_to) \
  NS_IMETHOD SetJSStatus(const nsAString & status) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetJSStatus(status); } \
  NS_IMETHOD SetOverLink(const nsAString & link, nsIDOMElement *element) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOverLink(link, element); } \
  NS_IMETHOD OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeforeLinkTraversal(originalTarget, linkURI, linkNode, isAppTab, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULBrowserWindow : public nsIXULBrowserWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULBROWSERWINDOW

  nsXULBrowserWindow();

private:
  ~nsXULBrowserWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULBrowserWindow, nsIXULBrowserWindow)

nsXULBrowserWindow::nsXULBrowserWindow()
{
  /* member initializers and constructor code */
}

nsXULBrowserWindow::~nsXULBrowserWindow()
{
  /* destructor code */
}

/* void setJSStatus (in AString status); */
NS_IMETHODIMP nsXULBrowserWindow::SetJSStatus(const nsAString & status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setOverLink (in AString link, in nsIDOMElement element); */
NS_IMETHODIMP nsXULBrowserWindow::SetOverLink(const nsAString & link, nsIDOMElement *element)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString onBeforeLinkTraversal (in AString originalTarget, in nsIURI linkURI, in nsIDOMNode linkNode, in boolean isAppTab); */
NS_IMETHODIMP nsXULBrowserWindow::OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULBrowserWindow_h__ */
