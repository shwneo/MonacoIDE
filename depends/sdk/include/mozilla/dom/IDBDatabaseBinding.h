/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_IDBDatabaseBinding_h__
#define mozilla_dom_IDBDatabaseBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

namespace mozilla {
namespace dom {

struct IDBObjectStoreParameters : public MainThreadDictionaryBase
{
  bool mAutoIncrement;
  JS::Value mKeyPath;

private:
  static bool initedIds;
  static jsid autoIncrement_id;
  static jsid keyPath_id;

  IDBObjectStoreParameters(const IDBObjectStoreParameters&) MOZ_DELETE;

public:
  inline IDBObjectStoreParameters()
    : mKeyPath(JS::UndefinedValue())
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
struct IDBObjectStoreParametersInitializer : public IDBObjectStoreParameters
{
  inline IDBObjectStoreParametersInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_IDBDatabaseBinding_h__
