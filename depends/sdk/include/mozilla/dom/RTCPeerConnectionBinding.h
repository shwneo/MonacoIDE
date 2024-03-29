/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_RTCPeerConnectionBinding_h__
#define mozilla_dom_RTCPeerConnectionBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/CallbackFunction.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"
#include "nsDOMEventTargetHelper.h"

class JSObject;
class nsIDOMDataChannel;

namespace mozilla {

class DOMMediaStream;

namespace dom {

class EventHandlerNonNull;
struct RTCConfiguration;
struct RTCDataChannelInit;
class RTCPeerConnectionErrorCallback;
class RTCSessionDescriptionCallback;
class VoidFunction;
class mozRTCIceCandidate;
class mozRTCPeerConnection;
class mozRTCSessionDescription;

} // namespace dom

} // namespace mozilla

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::mozRTCPeerConnection>
{
  enum
  {
    Depth = 1
  };
  typedef mozilla::dom::mozRTCPeerConnection NativeType;
};
template <>
struct PrototypeIDMap<mozilla::dom::mozRTCPeerConnection>
{
  enum
  {
    PrototypeID = prototypes::id::mozRTCPeerConnection
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {


MOZ_BEGIN_ENUM_CLASS(RTCSignalingState, uint32_t)
  Stable,
  Have_local_offer,
  Have_remote_offer,
  Have_local_pranswer,
  Have_remote_pranswer,
  Closed
MOZ_END_ENUM_CLASS(RTCSignalingState)

namespace RTCSignalingStateValues {
extern const EnumEntry strings[7];
} // namespace RTCSignalingStateValues



MOZ_BEGIN_ENUM_CLASS(RTCIceGatheringState, uint32_t)
  New,
  Gathering,
  Complete
MOZ_END_ENUM_CLASS(RTCIceGatheringState)

namespace RTCIceGatheringStateValues {
extern const EnumEntry strings[4];
} // namespace RTCIceGatheringStateValues



MOZ_BEGIN_ENUM_CLASS(RTCIceConnectionState, uint32_t)
  New,
  Checking,
  Connected,
  Completed,
  Failed,
  Disconnected,
  Closed
MOZ_END_ENUM_CLASS(RTCIceConnectionState)

namespace RTCIceConnectionStateValues {
extern const EnumEntry strings[8];
} // namespace RTCIceConnectionStateValues


struct RTCDataChannelInit : public MainThreadDictionaryBase
{
  Nullable<uint16_t> mId;
  Optional<uint16_t > mMaxRetransmitNum;
  Nullable<uint16_t> mMaxRetransmitTime;
  Nullable<uint16_t> mMaxRetransmits;
  bool mNegotiated;
  bool mOrdered;
  Optional<bool > mOutOfOrderAllowed;
  Optional<bool > mPreset;
  nsString mProtocol;
  Optional<uint16_t > mStream;

private:
  static bool initedIds;
  static jsid id_id;
  static jsid maxRetransmitNum_id;
  static jsid maxRetransmitTime_id;
  static jsid maxRetransmits_id;
  static jsid negotiated_id;
  static jsid ordered_id;
  static jsid outOfOrderAllowed_id;
  static jsid preset_id;
  static jsid protocol_id;
  static jsid stream_id;

  RTCDataChannelInit(const RTCDataChannelInit&) MOZ_DELETE;

public:
  inline RTCDataChannelInit()
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
struct RTCDataChannelInitInitializer : public RTCDataChannelInit
{
  inline RTCDataChannelInitInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


class RTCSessionDescriptionCallback : public CallbackFunction
{
public:
  explicit inline RTCSessionDescriptionCallback(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline RTCSessionDescriptionCallback(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisObj, mozilla::dom::mozRTCSessionDescription& sdp, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
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
    return Call(s.GetContext(), thisObjJS, sdp, aRv);
  }

  inline void
  Call(mozilla::dom::mozRTCSessionDescription& sdp, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::NullPtr(), sdp, aRv);
  }

private:
  void Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, mozilla::dom::mozRTCSessionDescription& sdp, ErrorResult& aRv);
};


class RTCPeerConnectionErrorCallback : public CallbackFunction
{
public:
  explicit inline RTCPeerConnectionErrorCallback(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline RTCPeerConnectionErrorCallback(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisObj, const nsAString& errorInformation, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
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
    return Call(s.GetContext(), thisObjJS, errorInformation, aRv);
  }

  inline void
  Call(const nsAString& errorInformation, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::NullPtr(), errorInformation, aRv);
  }

private:
  void Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, const nsAString& errorInformation, ErrorResult& aRv);
};


class VoidFunction : public CallbackFunction
{
public:
  explicit inline VoidFunction(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline VoidFunction(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisObj, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
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
    return Call(s.GetContext(), thisObjJS, aRv);
  }

  inline void
  Call(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::NullPtr(), aRv);
  }

private:
  void Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, ErrorResult& aRv);
};


namespace mozRTCPeerConnectionBinding {

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
    if (!protoAndIfaceArray[prototypes::id::mozRTCPeerConnection]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[prototypes::id::mozRTCPeerConnection]);
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
    if (!protoAndIfaceArray[constructors::id::mozRTCPeerConnection]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[constructors::id::mozRTCPeerConnection]);
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  bool
  ConstructorEnabled(JSContext* /* unused */, JS::Handle<JSObject*> /* unused */);

  extern DOMJSClass Class;

  JSObject*
  Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, mozilla::dom::mozRTCPeerConnection* aObject, nsWrapperCache* aCache);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, T* aObject)
  {
    return Wrap(aCx, aScope, aObject, aObject);
  }

} // namespace mozRTCPeerConnectionBinding



class mozRTCPeerConnectionJSImpl : public CallbackInterface
{
public:
  explicit inline mozRTCPeerConnectionJSImpl(JSObject* aCallback)
    : CallbackInterface(aCallback)
  {
  }

  void CreateOffer(RTCSessionDescriptionCallback& successCallback, RTCPeerConnectionErrorCallback* failureCallback, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void CreateAnswer(RTCSessionDescriptionCallback& successCallback, RTCPeerConnectionErrorCallback* failureCallback, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetLocalDescription(mozilla::dom::mozRTCSessionDescription& description, const Optional<OwningNonNull<VoidFunction> >& successCallback, const Optional<OwningNonNull<RTCPeerConnectionErrorCallback> >& failureCallback, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetRemoteDescription(mozilla::dom::mozRTCSessionDescription& description, const Optional<OwningNonNull<VoidFunction> >& successCallback, const Optional<OwningNonNull<RTCPeerConnectionErrorCallback> >& failureCallback, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void UpdateIce(const RTCConfiguration& configuration, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void AddIceCandidate(mozilla::dom::mozRTCIceCandidate& candidate, const Optional<OwningNonNull<VoidFunction> >& successCallback, const Optional<OwningNonNull<RTCPeerConnectionErrorCallback> >& failureCallback, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void GetLocalStreams(nsTArray<nsRefPtr<DOMMediaStream> >& retval, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void GetRemoteStreams(nsTArray<nsRefPtr<DOMMediaStream> >& retval, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<DOMMediaStream> GetStreamById(const nsAString& streamId, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void AddStream(mozilla::DOMMediaStream& stream, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void RemoveStream(mozilla::DOMMediaStream& stream, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void Close(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<nsIDOMDataChannel> CreateDataChannel(const nsAString& label, const RTCDataChannelInit& dataChannelDict, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void __Init(const RTCConfiguration& configuration, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<mozRTCSessionDescription> GetLocalDescription(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<mozRTCSessionDescription> GetRemoteDescription(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  RTCSignalingState GetSignalingState(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  RTCIceGatheringState GetIceGatheringState(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  RTCIceConnectionState GetIceConnectionState(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<EventHandlerNonNull> GetOnnegotiationneeded(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<EventHandlerNonNull> GetOnicecandidate(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<EventHandlerNonNull> GetOnsignalingstatechange(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<EventHandlerNonNull> GetOnaddstream(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<EventHandlerNonNull> GetOnremovestream(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<EventHandlerNonNull> GetOniceconnectionstatechange(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<RTCPeerConnectionErrorCallback> GetOnicechange(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<RTCPeerConnectionErrorCallback> GetOngatheringchange(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  JSObject* GetLocalStreams(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  JSObject* GetRemoteStreams(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void GetReadyState(nsString& retval, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<EventHandlerNonNull> GetOndatachannel(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<EventHandlerNonNull> GetOnconnection(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<EventHandlerNonNull> GetOnclosedconnection(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOnnegotiationneeded(EventHandlerNonNull* arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOnicecandidate(EventHandlerNonNull* arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOnsignalingstatechange(EventHandlerNonNull* arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOnaddstream(EventHandlerNonNull* arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOnremovestream(EventHandlerNonNull* arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOniceconnectionstatechange(EventHandlerNonNull* arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOnicechange(RTCPeerConnectionErrorCallback& arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOngatheringchange(RTCPeerConnectionErrorCallback& arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOndatachannel(EventHandlerNonNull* arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOnconnection(EventHandlerNonNull* arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void SetOnclosedconnection(EventHandlerNonNull* arg, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);
};


class mozRTCPeerConnection MOZ_FINAL : public nsDOMEventTargetHelper
{
public:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(mozRTCPeerConnection, nsDOMEventTargetHelper)

private:
  nsRefPtr<mozRTCPeerConnectionJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  mozRTCPeerConnection(JS::Handle<JSObject*> aJSImplObject, nsPIDOMWindow* aParent);

  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE;

  static already_AddRefed<mozRTCPeerConnection> Constructor(const GlobalObject& global, JSContext* cx, const RTCConfiguration& configuration, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv);

  void CreateOffer(RTCSessionDescriptionCallback& successCallback, RTCPeerConnectionErrorCallback* failureCallback, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv);

  void CreateAnswer(RTCSessionDescriptionCallback& successCallback, RTCPeerConnectionErrorCallback* failureCallback, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv);

  void SetLocalDescription(mozilla::dom::mozRTCSessionDescription& description, const Optional<OwningNonNull<VoidFunction> >& successCallback, const Optional<OwningNonNull<RTCPeerConnectionErrorCallback> >& failureCallback, ErrorResult& aRv);

  void SetRemoteDescription(mozilla::dom::mozRTCSessionDescription& description, const Optional<OwningNonNull<VoidFunction> >& successCallback, const Optional<OwningNonNull<RTCPeerConnectionErrorCallback> >& failureCallback, ErrorResult& aRv);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<mozRTCSessionDescription> GetLocalDescription(ErrorResult& aRv) const;

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<mozRTCSessionDescription> GetRemoteDescription(ErrorResult& aRv) const;

  RTCSignalingState GetSignalingState(ErrorResult& aRv) const;

  void UpdateIce(const RTCConfiguration& configuration, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv);

  void AddIceCandidate(mozilla::dom::mozRTCIceCandidate& candidate, const Optional<OwningNonNull<VoidFunction> >& successCallback, const Optional<OwningNonNull<RTCPeerConnectionErrorCallback> >& failureCallback, ErrorResult& aRv);

  RTCIceGatheringState GetIceGatheringState(ErrorResult& aRv) const;

  RTCIceConnectionState GetIceConnectionState(ErrorResult& aRv) const;

  void GetLocalStreams(nsTArray<// Mark this as resultNotAddRefed to return raw pointers
  nsRefPtr<DOMMediaStream> >& retval, ErrorResult& aRv);

  void GetRemoteStreams(nsTArray<// Mark this as resultNotAddRefed to return raw pointers
  nsRefPtr<DOMMediaStream> >& retval, ErrorResult& aRv);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<DOMMediaStream> GetStreamById(const nsAString& streamId, ErrorResult& aRv);

  void AddStream(mozilla::DOMMediaStream& stream, const Optional<JS::Handle<JSObject*> >& constraints, ErrorResult& aRv);

  void RemoveStream(mozilla::DOMMediaStream& stream, ErrorResult& aRv);

  void Close(ErrorResult& aRv);

  already_AddRefed<EventHandlerNonNull> GetOnnegotiationneeded(ErrorResult& aRv) const;

  void SetOnnegotiationneeded(EventHandlerNonNull* arg, ErrorResult& aRv);

  already_AddRefed<EventHandlerNonNull> GetOnicecandidate(ErrorResult& aRv) const;

  void SetOnicecandidate(EventHandlerNonNull* arg, ErrorResult& aRv);

  already_AddRefed<EventHandlerNonNull> GetOnsignalingstatechange(ErrorResult& aRv) const;

  void SetOnsignalingstatechange(EventHandlerNonNull* arg, ErrorResult& aRv);

  already_AddRefed<EventHandlerNonNull> GetOnaddstream(ErrorResult& aRv) const;

  void SetOnaddstream(EventHandlerNonNull* arg, ErrorResult& aRv);

  already_AddRefed<EventHandlerNonNull> GetOnremovestream(ErrorResult& aRv) const;

  void SetOnremovestream(EventHandlerNonNull* arg, ErrorResult& aRv);

  already_AddRefed<EventHandlerNonNull> GetOniceconnectionstatechange(ErrorResult& aRv) const;

  void SetOniceconnectionstatechange(EventHandlerNonNull* arg, ErrorResult& aRv);

  already_AddRefed<RTCPeerConnectionErrorCallback> GetOnicechange(ErrorResult& aRv) const;

  void SetOnicechange(RTCPeerConnectionErrorCallback& arg, ErrorResult& aRv);

  already_AddRefed<RTCPeerConnectionErrorCallback> GetOngatheringchange(ErrorResult& aRv) const;

  void SetOngatheringchange(RTCPeerConnectionErrorCallback& arg, ErrorResult& aRv);

  JSObject* GetLocalStreams(ErrorResult& aRv) const;

  JSObject* GetRemoteStreams(ErrorResult& aRv) const;

  void GetReadyState(nsString& retval, ErrorResult& aRv) const;

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<nsIDOMDataChannel> CreateDataChannel(const nsAString& label, const RTCDataChannelInit& dataChannelDict, ErrorResult& aRv);

  already_AddRefed<EventHandlerNonNull> GetOndatachannel(ErrorResult& aRv) const;

  void SetOndatachannel(EventHandlerNonNull* arg, ErrorResult& aRv);

  already_AddRefed<EventHandlerNonNull> GetOnconnection(ErrorResult& aRv) const;

  void SetOnconnection(EventHandlerNonNull* arg, ErrorResult& aRv);

  already_AddRefed<EventHandlerNonNull> GetOnclosedconnection(ErrorResult& aRv) const;

  void SetOnclosedconnection(EventHandlerNonNull* arg, ErrorResult& aRv);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_RTCPeerConnectionBinding_h__
