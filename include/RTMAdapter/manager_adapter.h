#pragma once
#include "adapter_common.h"

#ifdef __cplusplus
extern "C" {
#endif

  Manager_t Manager_initManager(int argc, char** argv);
  
  Result_t Manager_init(Manager_t m, int argc, char** argv);
  
  Result_t Manager_setRTMAdapterModuleInitProc(Manager_t m);
  
  Result_t Manager_activateManager(Manager_t m);
  
  Result_t Manager_runManager(Manager_t m, int32_t flag);

  RTC_t Manager_createComponent(Manager_t m, char* identifier);

  RTC_t Manager_createAdapterComponent(Manager_t m);

#ifdef __cplusplus
}
#endif
