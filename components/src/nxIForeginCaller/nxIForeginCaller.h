/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ./nxIForeginCaller.idl
 */

#ifndef __gen_nxIForeginCaller_h__
#define __gen_nxIForeginCaller_h__


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

/* starting interface:    nxIForeginCaller */
#define NXIFOREGINCALLER_IID_STR "0449e1c8-ae6c-419f-acd2-ac79267649f0"

#define NXIFOREGINCALLER_IID \
  {0x0449e1c8, 0xae6c, 0x419f, \
    { 0xac, 0xd2, 0xac, 0x79, 0x26, 0x76, 0x49, 0xf0 }}

class NS_NO_VTABLE nxIForeginCaller : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NXIFOREGINCALLER_IID)

  /* long Add (in long a, in long b); */
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) = 0;

  /* long ForeginCall (in wstring command); */
  NS_IMETHOD ForeginCall(const PRUnichar * command, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nxIForeginCaller, NXIFOREGINCALLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NXIFOREGINCALLER \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval); \
  NS_IMETHOD ForeginCall(const PRUnichar * command, int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NXIFOREGINCALLER(_to) \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) { return _to Add(a, b, _retval); } \
  NS_IMETHOD ForeginCall(const PRUnichar * command, int32_t *_retval) { return _to ForeginCall(command, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NXIFOREGINCALLER(_to) \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(a, b, _retval); } \
  NS_IMETHOD ForeginCall(const PRUnichar * command, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForeginCall(command, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nxForeginCaller : public nxIForeginCaller
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NXIFOREGINCALLER

  nxForeginCaller();

private:
  ~nxForeginCaller();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nxForeginCaller, nxIForeginCaller)

nxForeginCaller::nxForeginCaller()
{
  /* member initializers and constructor code */
}

nxForeginCaller::~nxForeginCaller()
{
  /* destructor code */
}

/* long Add (in long a, in long b); */
NS_IMETHODIMP nxForeginCaller::Add(int32_t a, int32_t b, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long ForeginCall (in wstring command); */
NS_IMETHODIMP nxForeginCaller::ForeginCall(const PRUnichar * command, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nxIForeginCaller_h__ */
