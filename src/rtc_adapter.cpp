#include <rtm/Manager.h>
#include "RTMAdapter.h"
#include "rtc_adapter.h"

extern RTC::RtcBase* __rtcs[MAX_RTC];
extern uint32_t __rtcs_counter;

#define CHECK_RTC_ID(rtc)  do { if(rtc < 0 || rtc >= __rtcs_counter) { return INVALID_RTC; } }while(false)

extern RTC::PortBase* __ports[MAX_PORT];
extern uint32_t __ports_counter;

#define CHECK_PORT_ID(port) do {if(port<0 || port>=__ports_counter){return INVALID_PORT;} }while(false)

Result_t RTC_addInPort(RTC_t rtc, char* name, Port_t port) {
  CHECK_RTC_ID(rtc);
  RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
  if (comp == NULL) { return INVALID_RTC; }
  
  CHECK_PORT_ID(port);
  RTC::InPortBase *inport = dynamic_cast<RTC::InPortBase*>(__ports[port]);
  if (inport == NULL) {return INVALID_PORT;}

  if (comp->addInPort(name, *inport)) return OK;
  return ERROR;
}

Result_t RTC_addOutPort(RTC_t rtc, char* name, Port_t port) {
  CHECK_RTC_ID(rtc);
  RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
  if (comp == NULL) { return INVALID_RTC; }
  
  CHECK_PORT_ID(port);
  RTC::OutPortBase *outport = dynamic_cast<RTC::OutPortBase*>(__ports[port]);
  if (outport == NULL) {return INVALID_PORT;}

  if (comp->addOutPort(name, *outport)) return OK;
  return ERROR;
}

Result_t RTC_deletePort(RTC_t rtc, Port_t port) {
}

Result_t RTC_onActivate_listen(RTC_t rtc, void (*callback)(int)) {

}

Result_t RTC_onDeactivate_listen(RTC_t rtc, void (*callback)(int)) {

}

Result_t RTC_onExecute_listen(RTC_t rtc, void (*callback)(int)) {

}

Result_t RTC_onAborting_listen(RTC_t rtc, void(*callback)(int)) {

}

Result_t RTC_onError_listen(RTC_t rtc, void(*callback)(int)) {

}

Result_t RTC_onReset_listen(RTC_t rtc, void(*callback)(int)) {

}
