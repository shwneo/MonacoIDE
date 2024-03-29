/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_EventHandlerBinding_h__
#define mozilla_dom_EventHandlerBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/CallbackFunction.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

class JSObject;
class nsDOMEvent;

namespace mozilla {
namespace dom {

class BeforeUnloadEventHandlerNonNull;
class EventHandlerNonNull;
class EventOrString;
class OnErrorEventHandlerNonNull;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

class EventHandlerNonNull : public CallbackFunction
{
public:
  explicit inline EventHandlerNonNull(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline EventHandlerNonNull(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline JS::Value
  Call(const T& thisObj, nsDOMEvent& event, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return JS::UndefinedValue();
    }
    JS::Rooted<JSObject*> thisObjJS(s.GetContext(),
      WrapCallThisObject(s.GetContext(), CallbackPreserveColor(), thisObj));
    if (!thisObjJS) {
      aRv.Throw(NS_ERROR_FAILURE);
      return JS::UndefinedValue();
    }
    return Call(s.GetContext(), thisObjJS, event, aRv);
  }

  inline JS::Value
  Call(nsDOMEvent& event, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return JS::UndefinedValue();
    }
    return Call(s.GetContext(), JS::NullPtr(), event, aRv);
  }

private:
  JS::Value Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, nsDOMEvent& event, ErrorResult& aRv);
};


class BeforeUnloadEventHandlerNonNull : public CallbackFunction
{
public:
  explicit inline BeforeUnloadEventHandlerNonNull(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline BeforeUnloadEventHandlerNonNull(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisObj, nsDOMEvent& event, nsString& retval, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    JS::Rooted<JSObject*> thisObjJS(s.GetContext(),
      WrapCallThisObject(s.GetContext(), CallbackPreserveColor(), thisObj));
    if (!thisObjJS) {
      aRv.Throw(NS_ERROR_FAILURE);
      return;
    }
    return Call(s.GetContext(), thisObjJS, event, retval, aRv);
  }

  inline void
  Call(nsDOMEvent& event, nsString& retval, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::NullPtr(), event, retval, aRv);
  }

private:
  void Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, nsDOMEvent& event, nsString& retval, ErrorResult& aRv);
};


class OnErrorEventHandlerNonNull : public CallbackFunction
{
public:
  explicit inline OnErrorEventHandlerNonNull(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline OnErrorEventHandlerNonNull(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline bool
  Call(const T& thisObj, const EventOrString& event, const Optional<nsAString >& source, const Optional<uint32_t >& lineno, const Optional<uint32_t >& column, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return bool(0);
    }
    JS::Rooted<JSObject*> thisObjJS(s.GetContext(),
      WrapCallThisObject(s.GetContext(), CallbackPreserveColor(), thisObj));
    if (!thisObjJS) {
      aRv.Throw(NS_ERROR_FAILURE);
      return bool(0);
    }
    return Call(s.GetContext(), thisObjJS, event, source, lineno, column, aRv);
  }

  inline bool
  Call(const EventOrString& event, const Optional<nsAString >& source, const Optional<uint32_t >& lineno, const Optional<uint32_t >& column, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return bool(0);
    }
    return Call(s.GetContext(), JS::NullPtr(), event, source, lineno, column, aRv);
  }

private:
  bool Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, const EventOrString& event, const Optional<nsAString >& source, const Optional<uint32_t >& lineno, const Optional<uint32_t >& column, ErrorResult& aRv);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_EventHandlerBinding_h__
