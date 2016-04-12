#pragma once
#include "adapter_common.h"


#ifdef __cplusplus
extern "C" {
#endif


  ADAPTER_API Result_t CameraImage_registerDataType(void* portBuffer);

  ADAPTER_API DataType_t CameraImage_create();

  ADAPTER_API Result_t CameraImage_set(DataType_t d, uint32_t sec, uint32_t nsec, uint32_t width, uint32_t height, uint8_t* data, uint32_t channels, double fDiv, char* format);
	  

  ADAPTER_API Result_t CameraImage_data_Length(DataType_t d, uint32_t* size);

  ADAPTER_API Result_t CameraImage_format_Length(DataType_t d, uint32_t* size);

  ADAPTER_API Result_t CameraImage_get(DataType_t d, uint32_t* sec, uint32_t* nsec, uint32_t* width, uint32_t* height, uint8_t* data, uint32_t buf_size, uint32_t* channels, double* fDiv, char* format, uint32_t format_buf_size);
	  
  ADAPTER_API Port_t InPort_CameraImage_create(char* name, DataType_t d);

  ADAPTER_API Result_t InPort_CameraImage_isNew(Port_t port, int32_t* flag);

  ADAPTER_API Port_t OutPort_CameraImage_create(char* name, DataType_t d);


#ifdef __cplusplus
}
#endif

