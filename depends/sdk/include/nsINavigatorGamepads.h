/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM d:/xulrunner-24.0.source/mozilla-release/dom/interfaces/gamepad/nsINavigatorGamepads.idl
 */

#ifndef __gen_nsINavigatorGamepads_h__
#define __gen_nsINavigatorGamepads_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsINavigatorGamepads */
#define NS_INAVIGATORGAMEPADS_IID_STR "bd2593a6-7df9-4dc7-8abe-20171c36a7a7"

#define NS_INAVIGATORGAMEPADS_IID \
  {0xbd2593a6, 0x7df9, 0x4dc7, \
    { 0x8a, 0xbe, 0x20, 0x17, 0x1c, 0x36, 0xa7, 0xa7 }}

class NS_NO_VTABLE nsINavigatorGamepads : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVIGATORGAMEPADS_IID)

  /* nsIVariant getGamepads (); */
  NS_IMETHOD GetGamepads(nsIVariant * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavigatorGamepads, NS_INAVIGATORGAMEPADS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVIGATORGAMEPADS \
  NS_IMETHOD GetGamepads(nsIVariant * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVIGATORGAMEPADS(_to) \
  NS_IMETHOD GetGamepads(nsIVariant * *_retval) { return _to GetGamepads(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVIGATORGAMEPADS(_to) \
  NS_IMETHOD GetGamepads(nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGamepads(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavigatorGamepads : public nsINavigatorGamepads
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVIGATORGAMEPADS

  nsNavigatorGamepads();

private:
  ~nsNavigatorGamepads();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavigatorGamepads, nsINavigatorGamepads)

nsNavigatorGamepads::nsNavigatorGamepads()
{
  /* member initializers and constructor code */
}

nsNavigatorGamepads::~nsNavigatorGamepads()
{
  /* destructor code */
}

/* nsIVariant getGamepads (); */
NS_IMETHODIMP nsNavigatorGamepads::GetGamepads(nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINavigatorGamepads_h__ */
