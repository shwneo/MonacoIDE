/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM d:/xulrunner-24.0.source/mozilla-release/dom/interfaces/html/nsIDOMHTMLParamElement.idl
 */

#ifndef __gen_nsIDOMHTMLParamElement_h__
#define __gen_nsIDOMHTMLParamElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLParamElement */
#define NS_IDOMHTMLPARAMELEMENT_IID_STR "f85e1b05-6dc4-442d-bea8-7cf551f9bc9f"

#define NS_IDOMHTMLPARAMELEMENT_IID \
  {0xf85e1b05, 0x6dc4, 0x442d, \
    { 0xbe, 0xa8, 0x7c, 0xf5, 0x51, 0xf9, 0xbc, 0x9f }}

class NS_NO_VTABLE nsIDOMHTMLParamElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLPARAMELEMENT_IID)

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* attribute DOMString valueType; */
  NS_IMETHOD GetValueType(nsAString & aValueType) = 0;
  NS_IMETHOD SetValueType(const nsAString & aValueType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLParamElement, NS_IDOMHTMLPARAMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLPARAMELEMENT \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetValue(nsAString & aValue); \
  NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_IMETHOD GetValueType(nsAString & aValueType); \
  NS_IMETHOD SetValueType(const nsAString & aValueType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLPARAMELEMENT(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD GetValueType(nsAString & aValueType) { return _to GetValueType(aValueType); } \
  NS_IMETHOD SetValueType(const nsAString & aValueType) { return _to SetValueType(aValueType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLPARAMELEMENT(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetValueType(nsAString & aValueType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueType(aValueType); } \
  NS_IMETHOD SetValueType(const nsAString & aValueType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValueType(aValueType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLParamElement : public nsIDOMHTMLParamElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLPARAMELEMENT

  nsDOMHTMLParamElement();

private:
  ~nsDOMHTMLParamElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLParamElement, nsIDOMHTMLParamElement)

nsDOMHTMLParamElement::nsDOMHTMLParamElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLParamElement::~nsDOMHTMLParamElement()
{
  /* destructor code */
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLParamElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLParamElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLParamElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLParamElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMHTMLParamElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLParamElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString valueType; */
NS_IMETHODIMP nsDOMHTMLParamElement::GetValueType(nsAString & aValueType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLParamElement::SetValueType(const nsAString & aValueType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLParamElement_h__ */
