/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_RTCDataChannelEventBinding_h__
#define mozilla_dom_RTCDataChannelEventBinding_h__

#include "EventBinding.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"
#include "nsDOMEvent.h"
#include "nsIDOMDataChannel.h"

class nsIDOMDataChannel;

namespace mozilla {
namespace dom {

class RTCDataChannelEvent;
struct RTCDataChannelEventInit;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::RTCDataChannelEvent>
{
  enum
  {
    Depth = 1
  };
  typedef mozilla::dom::RTCDataChannelEvent NativeType;
};
template <>
struct PrototypeIDMap<mozilla::dom::RTCDataChannelEvent>
{
  enum
  {
    PrototypeID = prototypes::id::RTCDataChannelEvent
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {

struct RTCDataChannelEventInit : public EventInit
{
  nsRefPtr<nsIDOMDataChannel> mChannel;

private:
  static bool initedIds;
  static jsid channel_id;

  RTCDataChannelEventInit(const RTCDataChannelEventInit&) MOZ_DELETE;

public:
  inline RTCDataChannelEventInit()
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
struct RTCDataChannelEventInitInitializer : public RTCDataChannelEventInit
{
  inline RTCDataChannelEventInitInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


namespace RTCDataChannelEventBinding {

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
    if (!protoAndIfaceArray[prototypes::id::RTCDataChannelEvent]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[prototypes::id::RTCDataChannelEvent]);
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
    if (!protoAndIfaceArray[constructors::id::RTCDataChannelEvent]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[constructors::id::RTCDataChannelEvent]);
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  bool
  ConstructorEnabled(JSContext* /* unused */, JS::Handle<JSObject*> /* unused */);

  extern DOMJSClass Class;

  JSObject*
  Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, mozilla::dom::RTCDataChannelEvent* aObject, nsWrapperCache* aCache);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, T* aObject)
  {
    return Wrap(aCx, aScope, aObject, aObject);
  }

} // namespace RTCDataChannelEventBinding



class RTCDataChannelEventJSImpl : public CallbackInterface
{
public:
  explicit inline RTCDataChannelEventJSImpl(JSObject* aCallback)
    : CallbackInterface(aCallback)
  {
  }

  void __Init(const nsAString& type, const RTCDataChannelEventInit& eventInitDict, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<nsIDOMDataChannel> GetChannel(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);
};


class RTCDataChannelEvent MOZ_FINAL : public nsDOMEvent
{
public:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(RTCDataChannelEvent, nsDOMEvent)

private:
  nsRefPtr<RTCDataChannelEventJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  RTCDataChannelEvent(JS::Handle<JSObject*> aJSImplObject, nsPIDOMWindow* aParent);

  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE;

  static already_AddRefed<RTCDataChannelEvent> Constructor(const GlobalObject& global, JSContext* cx, const nsAString& type, const RTCDataChannelEventInit& eventInitDict, ErrorResult& aRv);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<nsIDOMDataChannel> GetChannel(ErrorResult& aRv) const;
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_RTCDataChannelEventBinding_h__
