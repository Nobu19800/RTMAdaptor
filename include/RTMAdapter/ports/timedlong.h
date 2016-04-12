#pragma once
#include "adapter_common.h"

#ifdef __cplusplus
extern "C" {
#endif

  ADAPTER_API Result_t TimedLong_registerDataType(void* portBuffer);

  ADAPTER_API DataType_t TimedLong_create();

  ADAPTER_API Result_t TimedLong_set(DataType_t d, uint32_t sec, uint32_t nsec, int32_t data);
  ADAPTER_API Result_t TimedLong_get(DataType_t d, uint32_t* sec, uint32_t* nsec, int32_t* data);

  ADAPTER_API Port_t InPort_TimedLong_create(char* name, DataType_t d);

  ADAPTER_API Result_t InPort_TimedLong_isNew(Port_t port, int32_t* flag);

  ADAPTER_API Port_t OutPort_TimedLong_create(char* name, DataType_t d);


#ifdef __cplusplus
}
#endif

