#include <vector>
#include <memory>

#include <rtm/Manager.h>
#include "RTMAdapter.h"
#include "rtc_adapter.h"

#ifndef DEBUG
#define DEBUG
#endif

//extern std::vector<std::shared_ptr<RTC::RtcBase> > __rtcs;
extern std::vector<RTC::RtcBase* > __rtcs;

#define CHECK_RTC_ID(rtc)  do { if(rtc < 0 || rtc >= __rtcs.size()) { return RESULT_INVALID_RTC; } }while(false)

extern std::vector<std::shared_ptr<RTC::PortBase> > __ports;

#define CHECK_PORT_ID(port) do {if(port < 0 || port >=__ports.size()) { return RESULT_INVALID_PORT; } }while(false)


Result_t RTC_addInPort(RTC_t rtc, char* name, Port_t port) {
#ifdef DEBUG
  std::cout << "RTC_addInPort(" << rtc << ", " << name << ", " << port << ")" << std::endl;
#endif
  CHECK_RTC_ID(rtc);
  RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
  //std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
  if (comp == nullptr) { return RESULT_INVALID_RTC; }

  CHECK_PORT_ID(port);
  std::shared_ptr<RTC::InPortBase> inport = std::dynamic_pointer_cast<RTC::InPortBase>(__ports[port]);
  if (inport == nullptr) { return RESULT_INVALID_PORT; }

  if (comp->addInPort(name, *inport)) return RESULT_OK;
  return RESULT_ERROR;
}

Result_t RTC_addOutPort(RTC_t rtc, char* name, Port_t port) {
#ifdef DEBUG
  std::cout << "RTC_addOutPort(" << rtc << ", " << name << ", " << port << ")---" << std::endl;
#endif
  CHECK_RTC_ID(rtc);
  RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
  //std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
  if (comp == nullptr) { return RESULT_INVALID_RTC; }
  
  std::cout << "__ports.size() = " << __ports.size() << std::endl;
  CHECK_PORT_ID(port);
  std::shared_ptr<RTC::OutPortBase> outport = std::dynamic_pointer_cast<RTC::OutPortBase>(__ports[port]);
  if (outport.get() == nullptr) { return RESULT_INVALID_PORT; }
  
  std::cout << "addOutPort " << std::endl;
  if (comp->addOutPort(name, *outport)) return RESULT_OK;
  return RESULT_ERROR;
}

Result_t RTC_deletePort(RTC_t rtc, Port_t port) {
  CHECK_RTC_ID(rtc);
  RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
  //std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
  if (comp == nullptr) { return RESULT_INVALID_RTC; }
  
  CHECK_PORT_ID(port);
  comp->deletePort(*__ports[port]);
  return RESULT_OK;
}

Result_t RTC_exit(RTC_t rtc) {
	CHECK_RTC_ID(rtc);
	RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
	//std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
	if (comp == nullptr) { return RESULT_INVALID_RTC; }

	comp->exit();

	return RESULT_OK;
}

Result_t RTC_onActivated_listen(RTC_t rtc, int (*callback)(int)) {
	CHECK_RTC_ID(rtc);
	RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
	//std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
	if (comp == nullptr) { return RESULT_INVALID_RTC; }

	comp->onActivated_listen(callback);
	return RESULT_OK;
}

Result_t RTC_onDeactivated_listen(RTC_t rtc, int(*callback)(int)) {
	CHECK_RTC_ID(rtc);
	RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
	//std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
	if (comp == nullptr) { return RESULT_INVALID_RTC; }

	comp->onDeactivated_listen(callback);
	return RESULT_OK;
}

Result_t RTC_onExecute_listen(RTC_t rtc, int(*callback)(int)) {
	CHECK_RTC_ID(rtc);
	RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
	//std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
	if (comp == nullptr) { return RESULT_INVALID_RTC; }

	comp->onExecute_listen(callback);
	return RESULT_OK;
}

Result_t RTC_onAborting_listen(RTC_t rtc, int (*callback)(int)) {
	CHECK_RTC_ID(rtc);
	RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
	//std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
	if (comp == nullptr) { return RESULT_INVALID_RTC; }

	comp->onAborting_listen(callback);
	return RESULT_OK;
}

Result_t RTC_onError_listen(RTC_t rtc, int (*callback)(int)) {
	CHECK_RTC_ID(rtc);
	RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
	//std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
	if (comp == nullptr) { return RESULT_INVALID_RTC; }

	comp->onError_listen(callback);
	return RESULT_OK;
}

Result_t RTC_onReset_listen(RTC_t rtc, int (*callback)(int)) {
	CHECK_RTC_ID(rtc);
	RTMAdapter* comp = dynamic_cast<RTMAdapter*>(__rtcs[rtc]);
	//std::shared_ptr<RTMAdapter> comp = std::dynamic_pointer_cast<RTMAdapter>(__rtcs[rtc]);
	if (comp == nullptr) { return RESULT_INVALID_RTC; }

	comp->onReset_listen(callback);
	return RESULT_OK;
}
