#include <vector>
#include <memory>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/Manager.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

#include "ports/timedlong.h"

static std::vector<std::shared_ptr<RTC::TimedLong> > _data;
static std::vector<std::shared_ptr<RTC::PortBase> > *__ports;

#define CHECK_PORT_ID(port) do {if(port<0 || port>= __ports->size()){return RESULT_INVALID_PORT;} }while(false)


Result_t TimedLong_registerDataType(void* portBuffer) {
  __ports = static_cast<std::vector<std::shared_ptr<RTC::PortBase> >* >(portBuffer);
  return RESULT_OK;
}

DataType_t TimedLong_create() {
  _data.push_back(std::shared_ptr<RTC::TimedLong>(new RTC::TimedLong()));
  return _data.size() -1;
}

Result_t TimedLong_set(DataType_t d, uint32_t sec, uint32_t nsec, int32_t data) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }

  _data[d]->tm.sec = sec;
  _data[d]->tm.nsec = nsec;
  _data[d]->data = data;

  return RESULT_OK;
}

Result_t TimedLong_get(DataType_t d, uint32_t* sec, uint32_t* nsec, int32_t* data) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }
  *sec = _data[d]->tm.sec;
  *nsec = _data[d]->tm.nsec;
  *data = _data[d]->data;

  return RESULT_OK;
}

Port_t InPort_TimedLong_create(char* name, DataType_t d) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }
  __ports->push_back(std::shared_ptr<RTC::PortBase>(new RTC::InPort<RTC::TimedLong>(name, *(_data[d]))));
  return __ports->size() - 1;
}

Port_t OutPort_TimedLong_create(char* name, DataType_t d) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }
  __ports->push_back(std::shared_ptr<RTC::PortBase>(new RTC::OutPort<RTC::TimedLong>(name, *(_data[d]))));
  return __ports->size() - 1;
}

Result_t InPort_TimedLong_isNew(Port_t port, int32_t* flag) {
  CHECK_PORT_ID(port);
  std::shared_ptr<RTC::InPort<RTC::TimedLong> > inport = std::dynamic_pointer_cast<RTC::InPort<RTC::TimedLong> >((*__ports)[port]);
  if (inport == nullptr) { return RESULT_INVALID_PORT; }

  *flag = inport->isNew() ? 1 : 0;
  return RESULT_OK;
}
