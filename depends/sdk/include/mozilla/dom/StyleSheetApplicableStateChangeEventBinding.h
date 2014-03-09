/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_StyleSheetApplicableStateChangeEventBinding_h__
#define mozilla_dom_StyleSheetApplicableStateChangeEventBinding_h__

#include "EventBinding.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"
#include "nsCSSStyleSheet.h"

class nsCSSStyleSheet;

namespace mozilla {
namespace dom {

class StyleSheetApplicableStateChangeEvent;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::StyleSheetApplicableStateChangeEvent>
{
  enum
  {
    Depth = 1
  };
  typedef mozilla::dom::StyleSheetApplicableStateChangeEvent NativeType;
};
template <>
struct PrototypeIDMap<mozilla::dom::StyleSheetApplicableStateChangeEvent>
{
  enum
  {
    PrototypeID = prototypes::id::StyleSheetApplicableStateChangeEvent
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {

struct StyleSheetApplicableStateChangeEventInit : public EventInit
{
  bool mApplicable;
  nsRefPtr<nsCSSStyleSheet> mStylesheet;

private:
  static bool initedIds;
  static jsid applicable_id;
  static jsid stylesheet_id;

  StyleSheetApplicableStateChangeEventInit(const StyleSheetApplicableStateChangeEventInit&) MOZ_DELETE;

public:
  inline StyleSheetApplicableStateChangeEventInit()
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
struct StyleSheetApplicableStateChangeEventInitInitializer : public StyleSheetApplicableStateChangeEventInit
{
  inline StyleSheetApplicableStateChangeEventInitInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


namespace StyleSheetApplicableStateChangeEventBinding {

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
    if (!protoAndIfaceArray[prototypes::id::StyleSheetApplicableStateChangeEvent]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[prototypes::id::StyleSheetApplicableStateChangeEvent]);
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
    if (!protoAndIfaceArray[constructors::id::StyleSheetApplicableStateChangeEvent]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[constructors::id::StyleSheetApplicableStateChangeEvent]);
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  extern DOMJSClass Class;

  JSObject*
  Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, mozilla::dom::StyleSheetApplicableStateChangeEvent* aObject, nsWrapperCache* aCache);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, T* aObject)
  {
    return Wrap(aCx, aScope, aObject, aObject);
  }

} // namespace StyleSheetApplicableStateChangeEventBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_StyleSheetApplicableStateChangeEventBinding_h__
