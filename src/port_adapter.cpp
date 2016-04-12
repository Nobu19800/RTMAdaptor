#include <vector>
#include <memory>

#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include "port_adapter.h"

extern std::vector<std::shared_ptr<RTC::PortBase> > __ports;
#define CHECK_PORT_ID(port) do {if(port<0 || port>=__ports.size()){return RESULT_INVALID_PORT;} }while(false)

Result_t OutPort_write(Port_t port) {
  CHECK_PORT_ID(port);
  std::shared_ptr<RTC::OutPortBase> outport = std::dynamic_pointer_cast<RTC::OutPortBase>(__ports[port]);
  if (outport == nullptr) { return RESULT_INVALID_PORT; }

  outport->write();
}


Result_t InPort_read(Port_t port, int32_t* result) {
  CHECK_PORT_ID(port);
  std::shared_ptr<RTC::InPortBase> inport = std::dynamic_pointer_cast<RTC::InPortBase>(__ports[port]);
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
