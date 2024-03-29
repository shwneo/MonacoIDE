/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_CameraManagerBinding_h__
#define mozilla_dom_CameraManagerBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

class nsDOMCameraManager;

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::CameraManager>
{
  enum
  {
    Depth = 0
  };
  typedef nsDOMCameraManager NativeType;
};
template <>
struct PrototypeIDMap<nsDOMCameraManager>
{
  enum
  {
    PrototypeID = prototypes::id::CameraManager
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {

struct CameraPictureOptions : public MainThreadDictionaryBase
{
  int64_t mDateTime;
  nsString mFileFormat;
  JS::Value mPictureSize;
  JS::Value mPosition;
  int32_t mRotation;

private:
  static bool initedIds;
  static jsid dateTime_id;
  static jsid fileFormat_id;
  static jsid pictureSize_id;
  static jsid position_id;
  static jsid rotation_id;

  CameraPictureOptions(const CameraPictureOptions&) MOZ_DELETE;

public:
  inline CameraPictureOptions()
    : mPictureSize(JS::UndefinedValue()),
      mPosition(JS::UndefinedValue())
  {
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value");

  bool
  Init(const nsAString& aJSON);

  bool
  ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceDictionary(JSTracer* trc);

private:
  static bool
  InitIds(JSContext* cx);
};
struct CameraPictureOptionsInitializer : public CameraPictureOptions
{
  inline CameraPictureOptionsInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


struct CameraSelector : public MainThreadDictionaryBase
{
  nsString mCamera;

private:
  static bool initedIds;
  static jsid camera_id;

  CameraSelector(const CameraSelector&) MOZ_DELETE;

public:
  inline CameraSelector()
  {
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value");

  bool
  Init(const nsAString& aJSON);

  bool
  ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceDictionary(JSTracer* trc);

private:
  static bool
  InitIds(JSContext* cx);
};
struct CameraSelectorInitializer : public CameraSelector
{
  inline CameraSelectorInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


namespace CameraManagerBinding {

  extern const NativePropertyHooks sNativePropertyHooks;

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JSObject** protoAndIfaceArray);

  inline JS::Handle<JSObject*> GetProtoObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal)
  {

    /* Get the interface prototype object for this class.  This will create the
       object as needed. */

    /* Make sure our global is sane.  Hopefully we can remove this sometime */
    if (!(js::GetObjectClass(aGlobal)->flags & JSCLASS_DOM_GLOBAL)) {
      return JS::NullPtr();
    }
    /* Check to see whether the interface objects are already installed */
    JSObject** protoAndIfaceArray = GetProtoAndIfaceArray(aGlobal);
    if (!protoAndIfaceArray[prototypes::id::CameraManager]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[prototypes::id::CameraManager]);
  }

  inline JS::Handle<JSObject*> GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal)
  {

    /* Get the interface object for this class.  This will create the object as
       needed. */

    /* Make sure our global is sane.  Hopefully we can remove this sometime */
    if (!(js::GetObjectClass(aGlobal)->flags & JSCLASS_DOM_GLOBAL)) {
      return JS::NullPtr();
    }
    /* Check to see whether the interface objects are already installed */
    JSObject** protoAndIfaceArray = GetProtoAndIfaceArray(aGlobal);
    if (!protoAndIfaceArray[constructors::id::CameraManager]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[constructors::id::CameraManager]);
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  extern DOMJSClass Class;

  JSObject*
  Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, nsDOMCameraManager* aObject, nsWrapperCache* aCache);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, T* aObject)
  {
    return Wrap(aCx, aScope, aObject, aObject);
  }

} // namespace CameraManagerBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_CameraManagerBinding_h__
