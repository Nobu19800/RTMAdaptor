#include <vector>
#include <memory>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>f
#include <rtm/Manager.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

#include "ports/cameraimage.h"

static std::vector<std::shared_ptr<RTC::CameraImage> > _data;
static std::vector<std::shared_ptr<RTC::PortBase> >* __ports;

#define CHECK_PORT_ID(port) do {if(port<0 || port>=__ports->size()){return RESULT_INVALID_PORT;} }while(false)

Result_t CameraImage_registerDataType(void* portBuffer) {
  __ports = static_cast<std::vector<std::shared_ptr<RTC::PortBase> >* >(portBuffer);
  return RESULT_OK;
}

DataType_t CameraImage_create() {
  _data.push_back(std::shared_ptr<RTC::CameraImage>(new RTC::CameraImage()));
  return _data.size() -1;
}

Result_t CameraImage_set(DataType_t d, uint32_t sec, uint32_t nsec, uint32_t width, uint32_t height, uint8_t* data, uint32_t channels, double fDiv, char* format) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }

	uint32_t size = width * height;
	_data[d]->tm.sec = sec;
	_data[d]->tm.nsec = nsec;
	_data[d]->width = width;
	_data[d]->height = height;
	_data[d]->bpp = channels;
	_data[d]->pixels.length(size);
	memcpy(&(_data[d]->pixels[0]), data, size);
	_data[d]->fDiv = fDiv;
	_data[d]->format = CORBA::string_dup(format);
	return RESULT_OK;
}

Result_t CameraImage_pixels_Length(DataType_t d, uint32_t* size) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }

	*size = _data[d]->pixels.length();
	return RESULT_OK;
}

Result_t CameraImage_format_Length(DataType_t d, uint32_t* size) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }

	*size = strlen(_data[d]->format);
	return RESULT_OK;
}


Result_t CameraImage_get(DataType_t d, uint32_t* sec, uint32_t* nsec, uint32_t* width, uint32_t* height, uint8_t* data, uint32_t buf_size, uint32_t* channels, double* fDiv, char* format, uint32_t format_buf_size) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }
	if (_data[d]->pixels.length() > buf_size) {
		return RESULT_ERROR;
	}
	if (strlen(_data[d]->format) > format_buf_size) {
		return RESULT_ERROR;
	}

	*sec = _data[d]->tm.sec;
	*nsec = _data[d]->tm.nsec;
	*width = _data[d]->width;
	*height = _data[d]->height;
	*channels = _data[d]->bpp;
	memcpy(data, &(_data[d]->pixels[0]), _data[d]->pixels.length());
	*fDiv = _data[d]->fDiv;
	memcpy(format, (void*)(_data[d]->format), strlen(_data[d]->format));
	return RESULT_OK;
}

Port_t InPort_CameraImage_create(char* name, DataType_t d) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }
  __ports->push_back(std::shared_ptr<RTC::PortBase>(new RTC::InPort<RTC::CameraImage>(name, *(_data[d]))));
  return __ports->size() - 1;
}

Port_t OutPort_CameraImage_create(char* name, DataType_t d) {
	if (d < 0 || d >= _data.size()) { return RESULT_INVALID_DATA; }
  __ports->push_back(std::shared_ptr<RTC::PortBase>(new RTC::OutPort<RTC::CameraImage>(name, *(_data[d]))));
  return __ports->size() - 1;
}


Result_t InPort_CameraImage_isNew(Port_t port, int32_t* flag) {
  CHECK_PORT_ID(port);
  std::shared_ptr<RTC::InPort<RTC::CameraImage> > inport = std::dynamic_pointer_cast<RTC::InPort<RTC::CameraImage> >((*__ports)[port]);
  if (inport == nullptr) { return RESULT_INVALID_PORT; }

  *flag = inport->isNew() ? 1 : 0;
  return RESULT_OK;
}
