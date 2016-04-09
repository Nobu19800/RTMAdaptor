#pragma once
#include "adapter_common.h"

#ifdef __cplusplus
extern "C" {
#endif

  ADAPTER_API Result_t OutPort_write(Port_t p);

  ADAPTER_API Result_t InPort_read(Port_t p, int32_t* result);

  ADAPTER_API void* Port_getBuffer();

#ifdef __cplusplus
}
#endif

