/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM d:/xulrunner-24.0.source/mozilla-release/dom/camera/nsIDOMNavigatorCamera.idl
 */

#ifndef __gen_nsIDOMNavigatorCamera_h__
#define __gen_nsIDOMNavigatorCamera_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMCameraManager; /* forward declaration */


/* starting interface:    nsIDOMNavigatorCamera */
#define NS_IDOMNAVIGATORCAMERA_IID_STR "46a5710b-8dfb-430e-8705-90bea31c55aa"

#define NS_IDOMNAVIGATORCAMERA_IID \
  {0x46a5710b, 0x8dfb, 0x430e, \
    { 0x87, 0x05, 0x90, 0xbe, 0xa3, 0x1c, 0x55, 0xaa }}

class NS_NO_VTABLE nsIDOMNavigatorCamera : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATORCAMERA_IID)

  /* readonly attribute nsISupports mozCameras; */
  NS_IMETHOD GetMozCameras(nsISupports * *aMozCameras) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigatorCamera, NS_IDOMNAVIGATORCAMERA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATORCAMERA \
  NS_IMETHOD GetMozCameras(nsISupports * *aMozCameras); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATORCAMERA(_to) \
  NS_IMETHOD GetMozCameras(nsISupports * *aMozCameras) { return _to GetMozCameras(aMozCameras); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATORCAMERA(_to) \
  NS_IMETHOD GetMozCameras(nsISupports * *aMozCameras) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozCameras(aMozCameras); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigatorCamera : public nsIDOMNavigatorCamera
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATORCAMERA

  nsDOMNavigatorCamera();

private:
  ~nsDOMNavigatorCamera();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNavigatorCamera, nsIDOMNavigatorCamera)

nsDOMNavigatorCamera::nsDOMNavigatorCamera()
{
  /* member initializers and constructor code */
}

nsDOMNavigatorCamera::~nsDOMNavigatorCamera()
{
  /* destructor code */
}

/* readonly attribute nsISupports mozCameras; */
NS_IMETHODIMP nsDOMNavigatorCamera::GetMozCameras(nsISupports * *aMozCameras)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorCamera_h__ */
