/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef _gen_mozilla_idl_dictionary_helpers_h_
#define _gen_mozilla_idl_dictionary_helpers_h_

#include "jsapi.h"
#include "nsError.h"
#include "nsString.h"
#include "nsCOMPtr.h"

#undef near


class nsIDOMBlob;
class nsIDOMStorage;
class nsIVariant;
class mozIDOMApplication;
class nsIDOMCSSRule;
class nsIDOMCSSStyleSheet;
class nsIDOMElement;
class nsIDOMMozSmsMessage;
class nsIDOMMozMmsMessage;
class nsIURI;
class nsIDOMWindow;
class nsIDOMDocument;
class nsISupports;

namespace mozilla {
namespace idl {

class IDBIndexParameters
{
public:
  IDBIndexParameters();
  ~IDBIndexParameters();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool multiEntry;
  bool unique;
};

class GeoPositionOptions
{
public:
  GeoPositionOptions();
  ~GeoPositionOptions();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool enableHighAccuracy;
  int32_t maximumAge;
  int32_t timeout;
};

class DOMFileMetadataParameters
{
public:
  DOMFileMetadataParameters();
  ~DOMFileMetadataParameters();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool lastModified;
  bool size;
};

class CameraSize
{
public:
  CameraSize();
  ~CameraSize();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  uint32_t height;
  uint32_t width;
};

class CameraRegion
{
public:
  CameraRegion();
  ~CameraRegion();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  int32_t bottom;
  int32_t left;
  int32_t right;
  int32_t top;
  uint32_t weight;
};

class CameraPosition
{
public:
  CameraPosition();
  ~CameraPosition();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  double altitude;
  double latitude;
  double longitude;
  double timestamp;
};

class CameraRecorderOptions
{
public:
  CameraRecorderOptions();
  ~CameraRecorderOptions();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsString profile;
  int32_t rotation;
};

class CameraStartRecordingOptions
{
public:
  CameraStartRecordingOptions();
  ~CameraStartRecordingOptions();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  int64_t maxFileSizeBytes;
  int64_t maxVideoLengthMs;
  int32_t rotation;
};

class SmsThreadListItem
{
public:
  SmsThreadListItem();
  ~SmsThreadListItem();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsString body;
  uint64_t id;
  nsString senderOrReceiver;
  uint64_t timestamp;
  uint64_t unreadCount;
};

class MmsAttachment
{
public:
  MmsAttachment();
  ~MmsAttachment();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIDOMBlob> content;
  nsString id;
  nsString location;
};

class EventInit
{
public:
  EventInit();
  ~EventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool bubbles;
  bool cancelable;
};

class ProgressEventInit : public EventInit
{
public:
  ProgressEventInit();
  ~ProgressEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool lengthComputable;
  uint64_t loaded;
  uint64_t total;
};

class StorageEventInit : public EventInit
{
public:
  StorageEventInit();
  ~StorageEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsString key;
  nsString newValue;
  nsString oldValue;
  nsCOMPtr<nsIDOMStorage> storageArea;
  nsString url;
};

class DeviceProximityEventInit : public EventInit
{
public:
  DeviceProximityEventInit();
  ~DeviceProximityEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  double max;
  double min;
  double value;
};

class MozSettingsEventInit : public EventInit
{
public:
  MozSettingsEventInit();
  ~MozSettingsEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsString settingName;
  nsCOMPtr<nsIVariant> settingValue;
};

class UserProximityEventInit : public EventInit
{
public:
  UserProximityEventInit();
  ~UserProximityEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool near;
};

class CustomEventInit : public EventInit
{
public:
  CustomEventInit();
  ~CustomEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIVariant> detail;
};

class PageTransitionEventInit : public EventInit
{
public:
  PageTransitionEventInit();
  ~PageTransitionEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool persisted;
};

class DOMTransactionEventInit : public EventInit
{
public:
  DOMTransactionEventInit();
  ~DOMTransactionEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIVariant> transactions;
};

class PopStateEventInit : public EventInit
{
public:
  PopStateEventInit();
  ~PopStateEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIVariant> state;
};

class HashChangeEventInit : public EventInit
{
public:
  HashChangeEventInit();
  ~HashChangeEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsString newURL;
  nsString oldURL;
};

class CloseEventInit : public EventInit
{
public:
  CloseEventInit();
  ~CloseEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  uint16_t code;
  nsString reason;
  bool wasClean;
};

class MozContactChangeEventInit : public EventInit
{
public:
  MozContactChangeEventInit();
  ~MozContactChangeEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsString contactID;
  nsString reason;
};

class DeviceOrientationEventInit : public EventInit
{
public:
  DeviceOrientationEventInit();
  ~DeviceOrientationEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool absolute;
  double alpha;
  double beta;
  double gamma;
};

class DeviceLightEventInit : public EventInit
{
public:
  DeviceLightEventInit();
  ~DeviceLightEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  double value;
};

class MozApplicationEventInit : public EventInit
{
public:
  MozApplicationEventInit();
  ~MozApplicationEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<mozIDOMApplication> application;
};

class SmartCardEventInit : public EventInit
{
public:
  SmartCardEventInit();
  ~SmartCardEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsString tokenName;
};

class StyleRuleChangeEventInit : public EventInit
{
public:
  StyleRuleChangeEventInit();
  ~StyleRuleChangeEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIDOMCSSRule> rule;
  nsCOMPtr<nsIDOMCSSStyleSheet> stylesheet;
};

class StyleSheetChangeEventInit : public EventInit
{
public:
  StyleSheetChangeEventInit();
  ~StyleSheetChangeEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool documentSheet;
  nsCOMPtr<nsIDOMCSSStyleSheet> stylesheet;
};

class StyleSheetApplicableStateChangeEventInit : public EventInit
{
public:
  StyleSheetApplicableStateChangeEventInit();
  ~StyleSheetApplicableStateChangeEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  bool applicable;
  nsCOMPtr<nsIDOMCSSStyleSheet> stylesheet;
};

class ElementReplaceEventInit : public EventInit
{
public:
  ElementReplaceEventInit();
  ~ElementReplaceEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIDOMElement> upgrade;
};

class MozSmsEventInit : public EventInit
{
public:
  MozSmsEventInit();
  ~MozSmsEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIDOMMozSmsMessage> message;
};

class MozMmsEventInit : public EventInit
{
public:
  MozMmsEventInit();
  ~MozMmsEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIDOMMozMmsMessage> message;
};

class SpeechSynthesisEventInit : public EventInit
{
public:
  SpeechSynthesisEventInit();
  ~SpeechSynthesisEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  uint32_t charIndex;
  float elapsedTime;
  nsString name;
};

class DeviceStorageChangeEventInit : public EventInit
{
public:
  DeviceStorageChangeEventInit();
  ~DeviceStorageChangeEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsString path;
  nsString reason;
};

class PopupBlockedEventInit : public EventInit
{
public:
  PopupBlockedEventInit();
  ~PopupBlockedEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsString popupWindowFeatures;
  nsString popupWindowName;
  nsCOMPtr<nsIURI> popupWindowURI;
  nsCOMPtr<nsIDOMWindow> requestingWindow;
};

class BlobEventInit : public EventInit
{
public:
  BlobEventInit();
  ~BlobEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIDOMBlob> data;
};

class SpeechRecognitionEventInit : public EventInit
{
public:
  SpeechRecognitionEventInit();
  ~SpeechRecognitionEventInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  nsCOMPtr<nsIDOMDocument> emma;
  nsString interpretation;
  uint32_t resultIndex;
  nsCOMPtr<nsISupports> results;
};

class SpeechRecognitionErrorInit : public EventInit
{
public:
  SpeechRecognitionErrorInit();
  ~SpeechRecognitionErrorInit();

  // If aCx or aVal is null, NS_OK is returned and 
  // dictionary will use the default values. 
  nsresult Init(JSContext* aCx, const jsval* aVal);

  uint32_t error;
  nsString message;
};

}
}
#endif
