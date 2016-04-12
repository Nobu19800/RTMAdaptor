#pragma once
#include "adapter_common.h"


#ifdef __cplusplus
extern "C" {
#endif


  ADAPTER_API Result_t TimedDoubleSeq_registerDataType(void* portBuffer);

  ADAPTER_API DataType_t TimedDoubleSeq_create();

  ADAPTER_API Result_t TimedDoubleSeq_set(DataType_t d, uint32_t sec, uint32_t usec, double* data, uint32_t size);

  ADAPTER_API Result_t TimedDoubleSeq_data_Length(DataType_t d, uint32_t* size);

  ADAPTER_API Result_t TimedDoubleSeq_get(DataType_t d, uint32_t* sec, uint32_t* usec, double* data, uint32_t *size);

  ADAPTER_API Port_t InPort_TimedDoubleSeq_create(char* name, DataType_t d);

  ADAPTER_API Result_t InPort_TimedDoubleSeq_isNew(Port_t port, int32_t* flag);

  ADAPTER_API Port_t OutPort_TimedDoubleSeq_create(char* name, DataType_t d);


#ifdef __cplusplus
}
#endif

