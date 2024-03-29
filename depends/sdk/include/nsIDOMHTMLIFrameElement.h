/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM d:/xulrunner-24.0.source/mozilla-release/dom/interfaces/html/nsIDOMHTMLIFrameElement.idl
 */

#ifndef __gen_nsIDOMHTMLIFrameElement_h__
#define __gen_nsIDOMHTMLIFrameElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLIFrameElement */
#define NS_IDOMHTMLIFRAMEELEMENT_IID_STR "21ffbe98-51f5-499e-8d6f-612ae798c1e1"

#define NS_IDOMHTMLIFRAMEELEMENT_IID \
  {0x21ffbe98, 0x51f5, 0x499e, \
    { 0x8d, 0x6f, 0x61, 0x2a, 0xe7, 0x98, 0xc1, 0xe1 }}

class NS_NO_VTABLE nsIDOMHTMLIFrameElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLIFRAMEELEMENT_IID)

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

  /* attribute DOMString frameBorder; */
  NS_IMETHOD GetFrameBorder(nsAString & aFrameBorder) = 0;
  NS_IMETHOD SetFrameBorder(const nsAString & aFrameBorder) = 0;

  /* attribute DOMString height; */
  NS_IMETHOD GetHeight(nsAString & aHeight) = 0;
  NS_IMETHOD SetHeight(const nsAString & aHeight) = 0;

  /* attribute DOMString longDesc; */
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc) = 0;
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc) = 0;

  /* attribute DOMString marginHeight; */
  NS_IMETHOD GetMarginHeight(nsAString & aMarginHeight) = 0;
  NS_IMETHOD SetMarginHeight(const nsAString & aMarginHeight) = 0;

  /* attribute DOMString marginWidth; */
  NS_IMETHOD GetMarginWidth(nsAString & aMarginWidth) = 0;
  NS_IMETHOD SetMarginWidth(const nsAString & aMarginWidth) = 0;

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute DOMString scrolling; */
  NS_IMETHOD GetScrolling(nsAString & aScrolling) = 0;
  NS_IMETHOD SetScrolling(const nsAString & aScrolling) = 0;

  /* attribute DOMString src; */
  NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

  /* attribute DOMString width; */
  NS_IMETHOD GetWidth(nsAString & aWidth) = 0;
  NS_IMETHOD SetWidth(const nsAString & aWidth) = 0;

  /* readonly attribute nsIDOMDocument contentDocument; */
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) = 0;

  /* readonly attribute nsIDOMWindow contentWindow; */
  NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow) = 0;

  /* attribute DOMString sandbox; */
  NS_IMETHOD GetSandbox(nsAString & aSandbox) = 0;
  NS_IMETHOD SetSandbox(const nsAString & aSandbox) = 0;

  /* attribute boolean allowFullscreen; */
  NS_IMETHOD GetAllowFullscreen(bool *aAllowFullscreen) = 0;
  NS_IMETHOD SetAllowFullscreen(bool aAllowFullscreen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLIFrameElement, NS_IDOMHTMLIFRAMEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLIFRAMEELEMENT \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); \
  NS_IMETHOD GetFrameBorder(nsAString & aFrameBorder); \
  NS_IMETHOD SetFrameBorder(const nsAString & aFrameBorder); \
  NS_IMETHOD GetHeight(nsAString & aHeight); \
  NS_IMETHOD SetHeight(const nsAString & aHeight); \
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc); \
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc); \
  NS_IMETHOD GetMarginHeight(nsAString & aMarginHeight); \
  NS_IMETHOD SetMarginHeight(const nsAString & aMarginHeight); \
  NS_IMETHOD GetMarginWidth(nsAString & aMarginWidth); \
  NS_IMETHOD SetMarginWidth(const nsAString & aMarginWidth); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); \
  NS_IMETHOD GetScrolling(nsAString & aScrolling); \
  NS_IMETHOD SetScrolling(const nsAString & aScrolling); \
  NS_IMETHOD GetSrc(nsAString & aSrc); \
  NS_IMETHOD SetSrc(const nsAString & aSrc); \
  NS_IMETHOD GetWidth(nsAString & aWidth); \
  NS_IMETHOD SetWidth(const nsAString & aWidth); \
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument); \
  NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow); \
  NS_IMETHOD GetSandbox(nsAString & aSandbox); \
  NS_IMETHOD SetSandbox(const nsAString & aSandbox); \
  NS_IMETHOD GetAllowFullscreen(bool *aAllowFullscreen); \
  NS_IMETHOD SetAllowFullscreen(bool aAllowFullscreen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLIFRAMEELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } \
  NS_IMETHOD GetFrameBorder(nsAString & aFrameBorder) { return _to GetFrameBorder(aFrameBorder); } \
  NS_IMETHOD SetFrameBorder(const nsAString & aFrameBorder) { return _to SetFrameBorder(aFrameBorder); } \
  NS_IMETHOD GetHeight(nsAString & aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(const nsAString & aHeight) { return _to SetHeight(aHeight); } \
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc) { return _to GetLongDesc(aLongDesc); } \
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc) { return _to SetLongDesc(aLongDesc); } \
  NS_IMETHOD GetMarginHeight(nsAString & aMarginHeight) { return _to GetMarginHeight(aMarginHeight); } \
  NS_IMETHOD SetMarginHeight(const nsAString & aMarginHeight) { return _to SetMarginHeight(aMarginHeight); } \
  NS_IMETHOD GetMarginWidth(nsAString & aMarginWidth) { return _to GetMarginWidth(aMarginWidth); } \
  NS_IMETHOD SetMarginWidth(const nsAString & aMarginWidth) { return _to SetMarginWidth(aMarginWidth); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_IMETHOD GetScrolling(nsAString & aScrolling) { return _to GetScrolling(aScrolling); } \
  NS_IMETHOD SetScrolling(const nsAString & aScrolling) { return _to SetScrolling(aScrolling); } \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return _to GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return _to SetSrc(aSrc); } \
  NS_IMETHOD GetWidth(nsAString & aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(const nsAString & aWidth) { return _to SetWidth(aWidth); } \
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) { return _to GetContentDocument(aContentDocument); } \
  NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow) { return _to GetContentWindow(aContentWindow); } \
  NS_IMETHOD GetSandbox(nsAString & aSandbox) { return _to GetSandbox(aSandbox); } \
  NS_IMETHOD SetSandbox(const nsAString & aSandbox) { return _to SetSandbox(aSandbox); } \
  NS_IMETHOD GetAllowFullscreen(bool *aAllowFullscreen) { return _to GetAllowFullscreen(aAllowFullscreen); } \
  NS_IMETHOD SetAllowFullscreen(bool aAllowFullscreen) { return _to SetAllowFullscreen(aAllowFullscreen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLIFRAMEELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } \
  NS_IMETHOD GetFrameBorder(nsAString & aFrameBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameBorder(aFrameBorder); } \
  NS_IMETHOD SetFrameBorder(const nsAString & aFrameBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFrameBorder(aFrameBorder); } \
  NS_IMETHOD GetHeight(nsAString & aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(const nsAString & aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLongDesc(aLongDesc); } \
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLongDesc(aLongDesc); } \
  NS_IMETHOD GetMarginHeight(nsAString & aMarginHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginHeight(aMarginHeight); } \
  NS_IMETHOD SetMarginHeight(const nsAString & aMarginHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginHeight(aMarginHeight); } \
  NS_IMETHOD GetMarginWidth(nsAString & aMarginWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginWidth(aMarginWidth); } \
  NS_IMETHOD SetMarginWidth(const nsAString & aMarginWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginWidth(aMarginWidth); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetScrolling(nsAString & aScrolling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrolling(aScrolling); } \
  NS_IMETHOD SetScrolling(const nsAString & aScrolling) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrolling(aScrolling); } \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } \
  NS_IMETHOD GetWidth(nsAString & aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(const nsAString & aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDocument(aContentDocument); } \
  NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentWindow(aContentWindow); } \
  NS_IMETHOD GetSandbox(nsAString & aSandbox) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSandbox(aSandbox); } \
  NS_IMETHOD SetSandbox(const nsAString & aSandbox) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSandbox(aSandbox); } \
  NS_IMETHOD GetAllowFullscreen(bool *aAllowFullscreen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowFullscreen(aAllowFullscreen); } \
  NS_IMETHOD SetAllowFullscreen(bool aAllowFullscreen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowFullscreen(aAllowFullscreen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLIFrameElement : public nsIDOMHTMLIFrameElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLIFRAMEELEMENT

  nsDOMHTMLIFrameElement();

private:
  ~nsDOMHTMLIFrameElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLIFrameElement, nsIDOMHTMLIFrameElement)

nsDOMHTMLIFrameElement::nsDOMHTMLIFrameElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLIFrameElement::~nsDOMHTMLIFrameElement()
{
  /* destructor code */
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString frameBorder; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetFrameBorder(nsAString & aFrameBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetFrameBorder(const nsAString & aFrameBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString height; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetHeight(nsAString & aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetHeight(const nsAString & aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString longDesc; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetLongDesc(nsAString & aLongDesc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetLongDesc(const nsAString & aLongDesc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString marginHeight; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetMarginHeight(nsAString & aMarginHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetMarginHeight(const nsAString & aMarginHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString marginWidth; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetMarginWidth(nsAString & aMarginWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetMarginWidth(const nsAString & aMarginWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString scrolling; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetScrolling(nsAString & aScrolling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetScrolling(const nsAString & aScrolling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString src; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetSrc(nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetSrc(const nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString width; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetWidth(nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetWidth(const nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument contentDocument; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetContentDocument(nsIDOMDocument * *aContentDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow contentWindow; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetContentWindow(nsIDOMWindow * *aContentWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString sandbox; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetSandbox(nsAString & aSandbox)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetSandbox(const nsAString & aSandbox)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowFullscreen; */
NS_IMETHODIMP nsDOMHTMLIFrameElement::GetAllowFullscreen(bool *aAllowFullscreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLIFrameElement::SetAllowFullscreen(bool aAllowFullscreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLIFrameElement_h__ */
