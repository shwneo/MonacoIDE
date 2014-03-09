/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM d:/xulrunner-24.0.source/mozilla-release/dom/time/nsIDOMNavigatorTime.idl
 */

#ifndef __gen_nsIDOMNavigatorTime_h__
#define __gen_nsIDOMNavigatorTime_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozNavigatorTime */
#define NS_IDOMMOZNAVIGATORTIME_IID_STR "88df63f0-814d-4424-b1f9-9184149639e5"

#define NS_IDOMMOZNAVIGATORTIME_IID \
  {0x88df63f0, 0x814d, 0x4424, \
    { 0xb1, 0xf9, 0x91, 0x84, 0x14, 0x96, 0x39, 0xe5 }}

class NS_NO_VTABLE nsIDOMMozNavigatorTime : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZNAVIGATORTIME_IID)

  /* readonly attribute nsISupports mozTime; */
  NS_IMETHOD GetMozTime(nsISupports * *aMozTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozNavigatorTime, NS_IDOMMOZNAVIGATORTIME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZNAVIGATORTIME \
  NS_IMETHOD GetMozTime(nsISupports * *aMozTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZNAVIGATORTIME(_to) \
  NS_IMETHOD GetMozTime(nsISupports * *aMozTime) { return _to GetMozTime(aMozTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZNAVIGATORTIME(_to) \
  NS_IMETHOD GetMozTime(nsISupports * *aMozTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozTime(aMozTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozNavigatorTime : public nsIDOMMozNavigatorTime
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZNAVIGATORTIME

  nsDOMMozNavigatorTime();

private:
  ~nsDOMMozNavigatorTime();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozNavigatorTime, nsIDOMMozNavigatorTime)

nsDOMMozNavigatorTime::nsDOMMozNavigatorTime()
{
  /* member initializers and constructor code */
}

nsDOMMozNavigatorTime::~nsDOMMozNavigatorTime()
{
  /* destructor code */
}

/* readonly attribute nsISupports mozTime; */
NS_IMETHODIMP nsDOMMozNavigatorTime::GetMozTime(nsISupports * *aMozTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorTime_h__ */
