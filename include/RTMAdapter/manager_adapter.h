#pragma once
#include "adapter_common.h"

#ifdef __cplusplus
extern "C" {
#endif

  ADAPTER_API Manager_t Manager_initManager(int argc, char** argv);
  
  ADAPTER_API Result_t Manager_init(Manager_t m, int argc, char** argv);
  
  ADAPTER_API Result_t Manager_setRTMAdapterModuleInitProc(Manager_t m);
  
  ADAPTER_API Result_t Manager_activateManager(Manager_t m);
  
  ADAPTER_API Result_t Manager_runManager(Manager_t m, int32_t flag);

  ADAPTER_API RTC_t Manager_createComponent(Manager_t m, char* identifier);

  ADAPTER_API RTC_t Manager_createAdapterComponent(Manager_t m);

  ADAPTER_API Result_t Manager_shutdown(Manager_t m);

  ADAPTER_API Result_t Manager_deleteComponent(Manager_t m, RTC_t rtc);

  ADAPTER_API Result_t Manager_getComponent(Manager_t m, char* instance_name, RTC_t* rtc);

  ADAPTER_API Result_t Manager_setRTMAdapterSpec(Manager_t m, const char* key, const char* value);

  ADAPTER_API Result_t Manager_RTMAdapter_init(Manager_t m);

#ifdef __cplusplus
}
#endif
