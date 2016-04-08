#pragma once

#include <stdint.h>

#ifdef WIN32


#else
#define ADAPTER_API
#endif


#define MAX_RTC 16
#define MAX_PORT 64

#ifdef __cplusplus
extern "C" { 
#endif


  typedef int32_t Manager_t;
  static const Manager_t MANAGER_INVALID_ID = -1;

  typedef int32_t RTC_t;
  static const RTC_t RTC_INVALID_ID = -2;

  typedef int32_t Port_t;
  static const Port_t PORT_INVALID_ID = -3;

  enum Result_t {
    ERROR = -1,
    INVALID_RTC = -2,
    INVALID_PORT = -3,
    OK = 0,
  };

#ifdef __cplusplus
}
#endif



