#pragma once
#include "adapter_common.h"
#include "port_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  ADAPTER_API Result_t RTC_addInPort(RTC_t rtc, char* name, Port_t port);

  ADAPTER_API Result_t RTC_addOutPort(RTC_t rtc, char* name, Port_t port);

  ADAPTER_API Result_t RTC_deletePort(RTC_t rtc, Port_t port);

  ADAPTER_API Result_t RTC_exit(RTC_t rtc);

  ADAPTER_API Result_t RTC_onActivated_listen(RTC_t rtc, int(*callback)(int));

  ADAPTER_API Result_t RTC_onDeactivated_listen(RTC_t rtc, int(*callback)(int));

  ADAPTER_API Result_t RTC_onExecute_listen(RTC_t rtc, int(*callback)(int));

  ADAPTER_API Result_t RTC_onAborting_listen(RTC_t rtc, int(*callback)(int));

  ADAPTER_API Result_t RTC_onError_listen(RTC_t rtc, int(*callback)(int));

  ADAPTER_API Result_t RTC_onReset_listen(RTC_t rtc, int(*callback)(int));

  ADAPTER_API Result_t RTC_bindParameter(RTC_t rtc, char* name, char* defaultValue);

  ADAPTER_API Result_t RTC_updateParameters(RTC_t rtc, char* confsetName);

  ADAPTER_API Result_t RTC_getParameterStringLength(RTC_t rtc, char* name, int32_t* size);

  ADAPTER_API Result_t RTC_getParameter(RTC_t rtc, char* name, char* value);

#ifdef __cplusplus
}
#endif





