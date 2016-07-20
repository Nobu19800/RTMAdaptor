#pragma once
#include "adapter_common.h"

#ifdef __cplusplus
extern "C" {
#endif

  ADAPTER_API Result_t OutPort_write(Port_t p);

  ADAPTER_API Result_t InPort_read(Port_t p, int32_t* result);

  ADAPTER_API void* Port_getBuffer();

  ADAPTER_API uint32_t Port_size();

  ADAPTER_API void Port_push_back(void* ptr);

  ADAPTER_API void* Port_get(Port_t p);

#ifdef __cplusplus
}
#endif

