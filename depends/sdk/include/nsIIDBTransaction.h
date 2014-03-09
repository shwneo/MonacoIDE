/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM d:/xulrunner-24.0.source/mozilla-release/dom/indexedDB/nsIIDBTransaction.idl
 */

#ifndef __gen_nsIIDBTransaction_h__
#define __gen_nsIIDBTransaction_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIIDBObjectStore; /* forward declaration */

class nsIIDBRequest; /* forward declaration */

class nsIIDBDatabase; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */


/* starting interface:    nsIIDBTransaction */
#define NS_IIDBTRANSACTION_IID_STR "e17e36f6-a7d8-40b7-82d4-b54847169834"

#define NS_IIDBTRANSACTION_IID \
  {0xe17e36f6, 0xa7d8, 0x40b7, \
    { 0x82, 0xd4, 0xb5, 0x48, 0x47, 0x16, 0x98, 0x34 }}

class NS_NO_VTABLE nsIIDBTransaction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBTRANSACTION_IID)

  /* readonly attribute nsIIDBDatabase db; */
  NS_IMETHOD GetDb(nsIIDBDatabase * *aDb) = 0;

  /* readonly attribute DOMString mode; */
  NS_IMETHOD GetMode(nsAString & aMode) = 0;

  /* readonly attribute nsISupports error; */
  NS_IMETHOD GetError(nsISupports * *aError) = 0;

  /* readonly attribute nsIDOMDOMStringList objectStoreNames; */
  NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames) = 0;

  /* nsIIDBObjectStore objectStore ([Null (Stringify)] in DOMString name); */
  NS_IMETHOD ObjectStore(const nsAString & name, nsIIDBObjectStore * *_retval) = 0;

  /* void abort (); */
  NS_IMETHOD Abort(void) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) = 0;

  /* [implicit_jscontext] attribute jsval oncomplete; */
  NS_IMETHOD GetOncomplete(JSContext* cx, JS::Value *aOncomplete) = 0;
  NS_IMETHOD SetOncomplete(JSContext* cx, const JS::Value & aOncomplete) = 0;

  /* [implicit_jscontext] attribute jsval onabort; */
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) = 0;
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBTransaction, NS_IIDBTRANSACTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBTRANSACTION \
  NS_IMETHOD GetDb(nsIIDBDatabase * *aDb); \
  NS_IMETHOD GetMode(nsAString & aMode); \
  NS_IMETHOD GetError(nsISupports * *aError); \
  NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames); \
  NS_IMETHOD ObjectStore(const nsAString & name, nsIIDBObjectStore * *_retval); \
  NS_IMETHOD Abort(void); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror); \
  NS_IMETHOD GetOncomplete(JSContext* cx, JS::Value *aOncomplete); \
  NS_IMETHOD SetOncomplete(JSContext* cx, const JS::Value & aOncomplete); \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort); \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBTRANSACTION(_to) \
  NS_IMETHOD GetDb(nsIIDBDatabase * *aDb) { return _to GetDb(aDb); } \
  NS_IMETHOD GetMode(nsAString & aMode) { return _to GetMode(aMode); } \
  NS_IMETHOD GetError(nsISupports * *aError) { return _to GetError(aError); } \
  NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames) { return _to GetObjectStoreNames(aObjectStoreNames); } \
  NS_IMETHOD ObjectStore(const nsAString & name, nsIIDBObjectStore * *_retval) { return _to ObjectStore(name, _retval); } \
  NS_IMETHOD Abort(void) { return _to Abort(); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return _to SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOncomplete(JSContext* cx, JS::Value *aOncomplete) { return _to GetOncomplete(cx, aOncomplete); } \
  NS_IMETHOD SetOncomplete(JSContext* cx, const JS::Value & aOncomplete) { return _to SetOncomplete(cx, aOncomplete); } \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return _to GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return _to SetOnabort(cx, aOnabort); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBTRANSACTION(_to) \
  NS_IMETHOD GetDb(nsIIDBDatabase * *aDb) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDb(aDb); } \
  NS_IMETHOD GetMode(nsAString & aMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } \
  NS_IMETHOD GetError(nsISupports * *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } \
  NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectStoreNames(aObjectStoreNames); } \
  NS_IMETHOD ObjectStore(const nsAString & name, nsIIDBObjectStore * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ObjectStore(name, _retval); } \
  NS_IMETHOD Abort(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Abort(); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOncomplete(JSContext* cx, JS::Value *aOncomplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncomplete(cx, aOncomplete); } \
  NS_IMETHOD SetOncomplete(JSContext* cx, const JS::Value & aOncomplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncomplete(cx, aOncomplete); } \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(cx, aOnabort); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBTransaction : public nsIIDBTransaction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBTRANSACTION

  nsIDBTransaction();

private:
  ~nsIDBTransaction();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBTransaction, nsIIDBTransaction)

nsIDBTransaction::nsIDBTransaction()
{
  /* member initializers and constructor code */
}

nsIDBTransaction::~nsIDBTransaction()
{
  /* destructor code */
}

/* readonly attribute nsIIDBDatabase db; */
NS_IMETHODIMP nsIDBTransaction::GetDb(nsIIDBDatabase * *aDb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mode; */
NS_IMETHODIMP nsIDBTransaction::GetMode(nsAString & aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports error; */
NS_IMETHODIMP nsIDBTransaction::GetError(nsISupports * *aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList objectStoreNames; */
NS_IMETHODIMP nsIDBTransaction::GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBObjectStore objectStore ([Null (Stringify)] in DOMString name); */
NS_IMETHODIMP nsIDBTransaction::ObjectStore(const nsAString & name, nsIIDBObjectStore * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (); */
NS_IMETHODIMP nsIDBTransaction::Abort()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsIDBTransaction::GetOnerror(JSContext* cx, JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBTransaction::SetOnerror(JSContext* cx, const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncomplete; */
NS_IMETHODIMP nsIDBTransaction::GetOncomplete(JSContext* cx, JS::Value *aOncomplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBTransaction::SetOncomplete(JSContext* cx, const JS::Value & aOncomplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onabort; */
NS_IMETHODIMP nsIDBTransaction::GetOnabort(JSContext* cx, JS::Value *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBTransaction::SetOnabort(JSContext* cx, const JS::Value & aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBTransaction_h__ */
