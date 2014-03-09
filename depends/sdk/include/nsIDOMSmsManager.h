/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM d:/xulrunner-24.0.source/mozilla-release/dom/mobilemessage/interfaces/nsIDOMSmsManager.idl
 */

#ifndef __gen_nsIDOMSmsManager_h__
#define __gen_nsIDOMSmsManager_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMCursor; /* forward declaration */

class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */

class nsIDOMMozSmsFilter; /* forward declaration */

class nsIDOMMozSmsSegmentInfo; /* forward declaration */


/* starting interface:    nsIDOMMozSmsManager */
#define NS_IDOMMOZSMSMANAGER_IID_STR "8ce00d77-71b4-43f6-92a1-2eae7c9581b9"

#define NS_IDOMMOZSMSMANAGER_IID \
  {0x8ce00d77, 0x71b4, 0x43f6, \
    { 0x92, 0xa1, 0x2e, 0xae, 0x7c, 0x95, 0x81, 0xb9 }}

class NS_NO_VTABLE nsIDOMMozSmsManager : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZSMSMANAGER_IID)

  /* nsIDOMMozSmsSegmentInfo getSegmentInfoForText (in DOMString text); */
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) = 0;

  /* jsval send (in jsval number, in DOMString message); */
  NS_IMETHOD Send(const JS::Value & number, const nsAString & message, JS::Value *_retval) = 0;

  /* [binaryname(GetMessageMoz)] nsIDOMDOMRequest getMessage (in long id); */
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest delete (in jsval param); */
  NS_IMETHOD Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMCursor getMessages (in nsIDOMMozSmsFilter filter, in boolean reverse); */
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval) = 0;

  /* nsIDOMDOMRequest markMessageRead (in long id, in boolean aValue); */
  NS_IMETHOD MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMCursor getThreads (); */
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval) = 0;

  /* [implicit_jscontext] attribute jsval onreceived; */
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::Value *aOnreceived) = 0;
  NS_IMETHOD SetOnreceived(JSContext* cx, const JS::Value & aOnreceived) = 0;

  /* [implicit_jscontext] attribute jsval onsending; */
  NS_IMETHOD GetOnsending(JSContext* cx, JS::Value *aOnsending) = 0;
  NS_IMETHOD SetOnsending(JSContext* cx, const JS::Value & aOnsending) = 0;

  /* [implicit_jscontext] attribute jsval onsent; */
  NS_IMETHOD GetOnsent(JSContext* cx, JS::Value *aOnsent) = 0;
  NS_IMETHOD SetOnsent(JSContext* cx, const JS::Value & aOnsent) = 0;

  /* [implicit_jscontext] attribute jsval onfailed; */
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::Value *aOnfailed) = 0;
  NS_IMETHOD SetOnfailed(JSContext* cx, const JS::Value & aOnfailed) = 0;

  /* [implicit_jscontext] attribute jsval ondeliverysuccess; */
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess) = 0;
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess) = 0;

  /* [implicit_jscontext] attribute jsval ondeliveryerror; */
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror) = 0;
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozSmsManager, NS_IDOMMOZSMSMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZSMSMANAGER \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval); \
  NS_IMETHOD Send(const JS::Value & number, const nsAString & message, JS::Value *_retval); \
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval); \
  NS_IMETHOD MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval); \
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::Value *aOnreceived); \
  NS_IMETHOD SetOnreceived(JSContext* cx, const JS::Value & aOnreceived); \
  NS_IMETHOD GetOnsending(JSContext* cx, JS::Value *aOnsending); \
  NS_IMETHOD SetOnsending(JSContext* cx, const JS::Value & aOnsending); \
  NS_IMETHOD GetOnsent(JSContext* cx, JS::Value *aOnsent); \
  NS_IMETHOD SetOnsent(JSContext* cx, const JS::Value & aOnsent); \
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::Value *aOnfailed); \
  NS_IMETHOD SetOnfailed(JSContext* cx, const JS::Value & aOnfailed); \
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess); \
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess); \
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror); \
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZSMSMANAGER(_to) \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) { return _to GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(const JS::Value & number, const nsAString & message, JS::Value *_retval) { return _to Send(number, message, _retval); } \
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval) { return _to GetMessageMoz(id, _retval); } \
  NS_IMETHOD Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval) { return _to Delete(param, _retval); } \
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval) { return _to GetMessages(filter, reverse, _retval); } \
  NS_IMETHOD MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval) { return _to MarkMessageRead(id, aValue, _retval); } \
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval) { return _to GetThreads(_retval); } \
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::Value *aOnreceived) { return _to GetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD SetOnreceived(JSContext* cx, const JS::Value & aOnreceived) { return _to SetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD GetOnsending(JSContext* cx, JS::Value *aOnsending) { return _to GetOnsending(cx, aOnsending); } \
  NS_IMETHOD SetOnsending(JSContext* cx, const JS::Value & aOnsending) { return _to SetOnsending(cx, aOnsending); } \
  NS_IMETHOD GetOnsent(JSContext* cx, JS::Value *aOnsent) { return _to GetOnsent(cx, aOnsent); } \
  NS_IMETHOD SetOnsent(JSContext* cx, const JS::Value & aOnsent) { return _to SetOnsent(cx, aOnsent); } \
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::Value *aOnfailed) { return _to GetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD SetOnfailed(JSContext* cx, const JS::Value & aOnfailed) { return _to SetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess) { return _to GetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess) { return _to SetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror) { return _to GetOndeliveryerror(cx, aOndeliveryerror); } \
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror) { return _to SetOndeliveryerror(cx, aOndeliveryerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZSMSMANAGER(_to) \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(const JS::Value & number, const nsAString & message, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(number, message, _retval); } \
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(id, _retval); } \
  NS_IMETHOD Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(param, _retval); } \
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessages(filter, reverse, _retval); } \
  NS_IMETHOD MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkMessageRead(id, aValue, _retval); } \
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreads(_retval); } \
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::Value *aOnreceived) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD SetOnreceived(JSContext* cx, const JS::Value & aOnreceived) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD GetOnsending(JSContext* cx, JS::Value *aOnsending) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsending(cx, aOnsending); } \
  NS_IMETHOD SetOnsending(JSContext* cx, const JS::Value & aOnsending) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsending(cx, aOnsending); } \
  NS_IMETHOD GetOnsent(JSContext* cx, JS::Value *aOnsent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsent(cx, aOnsent); } \
  NS_IMETHOD SetOnsent(JSContext* cx, const JS::Value & aOnsent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsent(cx, aOnsent); } \
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::Value *aOnfailed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD SetOnfailed(JSContext* cx, const JS::Value & aOnfailed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndeliveryerror(cx, aOndeliveryerror); } \
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndeliveryerror(cx, aOndeliveryerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozSmsManager : public nsIDOMMozSmsManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZSMSMANAGER

  nsDOMMozSmsManager();

private:
  ~nsDOMMozSmsManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozSmsManager, nsIDOMMozSmsManager)

nsDOMMozSmsManager::nsDOMMozSmsManager()
{
  /* member initializers and constructor code */
}

nsDOMMozSmsManager::~nsDOMMozSmsManager()
{
  /* destructor code */
}

/* nsIDOMMozSmsSegmentInfo getSegmentInfoForText (in DOMString text); */
NS_IMETHODIMP nsDOMMozSmsManager::GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval send (in jsval number, in DOMString message); */
NS_IMETHODIMP nsDOMMozSmsManager::Send(const JS::Value & number, const nsAString & message, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(GetMessageMoz)] nsIDOMDOMRequest getMessage (in long id); */
NS_IMETHODIMP nsDOMMozSmsManager::GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest delete (in jsval param); */
NS_IMETHODIMP nsDOMMozSmsManager::Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMCursor getMessages (in nsIDOMMozSmsFilter filter, in boolean reverse); */
NS_IMETHODIMP nsDOMMozSmsManager::GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest markMessageRead (in long id, in boolean aValue); */
NS_IMETHODIMP nsDOMMozSmsManager::MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMCursor getThreads (); */
NS_IMETHODIMP nsDOMMozSmsManager::GetThreads(nsIDOMDOMCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onreceived; */
NS_IMETHODIMP nsDOMMozSmsManager::GetOnreceived(JSContext* cx, JS::Value *aOnreceived)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsManager::SetOnreceived(JSContext* cx, const JS::Value & aOnreceived)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsending; */
NS_IMETHODIMP nsDOMMozSmsManager::GetOnsending(JSContext* cx, JS::Value *aOnsending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsManager::SetOnsending(JSContext* cx, const JS::Value & aOnsending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsent; */
NS_IMETHODIMP nsDOMMozSmsManager::GetOnsent(JSContext* cx, JS::Value *aOnsent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsManager::SetOnsent(JSContext* cx, const JS::Value & aOnsent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onfailed; */
NS_IMETHODIMP nsDOMMozSmsManager::GetOnfailed(JSContext* cx, JS::Value *aOnfailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsManager::SetOnfailed(JSContext* cx, const JS::Value & aOnfailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondeliverysuccess; */
NS_IMETHODIMP nsDOMMozSmsManager::GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsManager::SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondeliveryerror; */
NS_IMETHODIMP nsDOMMozSmsManager::GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsManager::SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSmsManager_h__ */
