#include <vector>
#include <memory>

#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include "port_adapter.h"

extern std::vector<RTC::PortBase*> __ports;
#define CHECK_PORT_ID(port) do {if(port<0 || port>=__ports.size()){return RESULT_INVALID_PORT;} }while(false)

Result_t OutPort_write(Port_t port) {
  CHECK_PORT_ID(port);
  RTC::OutPortBase* outport = dynamic_cast<RTC::OutPortBase*>(__ports[port]);
  if (outport == nullptr) { return RESULT_INVALID_PORT; }

  if (outport->write())
  {
    return RESULT_OK;
  }
  else
  {
    return RESULT_ERROR;
  }
}


Result_t InPort_read(Port_t port, int32_t* result) {
  CHECK_PORT_ID(port);
  RTC::InPortBase* inport = dynamic_cast<RTC::InPortBase*>(__ports[port]);
  if (inport == nullptr) { return RESULT_INVALID_PORT; }

  if (!inport->read()) {
    *result = 0;
  } else {
    *result = 1;
  }
  return RESULT_OK;

}

void* Port_getBuffer() {
  return (void*)(&__ports);
}

uint32_t Port_size() {
	return __ports.size();
}

void Port_push_back(void* ptr) {
  __ports.push_back((RTC::PortBase*)ptr);
}

void* Port_get(Port_t p) {
  return __ports[p];
}