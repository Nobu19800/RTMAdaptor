#include <iostream>
#include <string>
#include <stdlib.h>
#include "rtm_adapter.h"
#include "coil_adapter.h"
#include "ports/timedlong.h"
#include "ports/timeddoubleseq.h"

static RTC_t rtc;
static Port_t inIn;
static DataType_t in;
static Manager_t m;


int on_execute(int ec_id) {
  int32_t result;
  InPort_TimedLong_isNew(inIn, &result);
  if (result) {
    InPort_read(inIn, &result);
    
    uint32_t sec, nsec;
    int32_t data;
    TimedLong_get(in, &sec, &nsec, &data);
    
    std::cout << "Received Data is " << data << std::endl;
  }
  
  return 0;
}

int SimpleRTCTest();

int main(int argc, char** argv) {
  m = Manager_initManager(argc, argv);
  if (Manager_init(m, argc, argv) != RESULT_OK) {
    std::cout << "Manager_init failed." << std::endl;
    return -1;
  }

  if (Manager_setRTMAdapterModuleInitProc(m) != RESULT_OK) {
    std::cout << "Manager_setRTMAdapterModuleInitProc failed." << std::endl;
    return -1;
  }

  if (Manager_activateManager(m) != RESULT_OK) {
    std::cout << "Manager_activateManager failed." << std::endl;
    return -1;
  }

  
  Manager_runManager(m, 1);  
  coil_usleep(1000*1000);
  SimpleRTCTest();
  return 0;
}


int SimpleRTCTest() {
  std::cout << "Simple RTC Test" << std::endl;
  if ((rtc = Manager_createComponent(m, "RTMAdapter")) == RTC_INVALID_ID) {
    std::cout << " -Failure to createComponent::Manager" << std::endl;
    return -1;
  }
  coil_usleep(10*1000*1000);
  RTC_exit(rtc);
  std::cout << "- Test End." << std::endl;
  coil_usleep(1*1000*1000);
  return 0;
}

int RTAdapterTest() {

  rtc = Manager_createComponent(m, "RTMAdapter");
  TimedLong_registerDataType(Port_getBuffer());
  std::cout << "Register" << std::endl;
  in = TimedLong_create();
  std::cout << "create" << std::endl;
  inIn = InPort_TimedLong_create("in", in);
  std::cout << "Port create" << std::endl;
  if (inIn < 0) {
    std::cout << "Failed to create port." << std::endl;
  }
  int ret;
  if ((ret = RTC_addInPort(rtc, "in", inIn)) < 0) {
    std::cout << "Failed to addPort (" << ret << ")" << std::endl;
  }

  RTC_onExecute_listen(rtc, on_execute);



  return 0;
}


