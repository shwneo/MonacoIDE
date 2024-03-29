/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_BlobBinding_h__
#define mozilla_dom_BlobBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

namespace mozilla {
namespace dom {


MOZ_BEGIN_ENUM_CLASS(EndingTypes, uint32_t)
  Transparent,
  Native
MOZ_END_ENUM_CLASS(EndingTypes)

namespace EndingTypesValues {
extern const EnumEntry strings[3];
} // namespace EndingTypesValues


struct BlobPropertyBagWorkers : public DictionaryBase
{
  EndingTypes mEndings;
  nsString mType;

  inline BlobPropertyBagWorkers()
  {
  }

private:
  BlobPropertyBagWorkers(const BlobPropertyBagWorkers&) MOZ_DELETE;

public:
  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value");

  bool
  ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceDictionary(JSTracer* trc);
};
struct BlobPropertyBagWorkersInitializer : public BlobPropertyBagWorkers
{
  inline BlobPropertyBagWorkersInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


struct BlobPropertyBag : public MainThreadDictionaryBase
{
  EndingTypes mEndings;
  nsString mType;

private:
  static bool initedIds;
  static jsid endings_id;
  static jsid type_id;

  BlobPropertyBag(const BlobPropertyBag&) MOZ_DELETE;

public:
  inline BlobPropertyBag()
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
struct BlobPropertyBagInitializer : public BlobPropertyBag
{
  inline BlobPropertyBagInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_BlobBinding_h__
