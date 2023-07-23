// -*- C++ -*-
/*!
 * @file  RTMAdapter.cpp
 * @brief RTM / C language Adapter
 * @date $Date$
 *
 * $Id$
 */

#include "RTMAdapter.h"

// Module specification
// <rtc-template block="module_spec">
#define SPEC_MAX_NUM 64
char* rtmadapter_spec[SPEC_MAX_NUM] =
  {
    "implementation_id", "RTMAdapter",
    "type_name",         "RTMAdapter",
    "description",       "RTM / C language Adapter",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Utilit",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    "",
  };
// </rtc-template>

std::map<std::string, std::string> specMap;

void init_default_spec_map() {
  ///std::cout << "init_default_spec_map" << std::endl;
  for(int i = 0;i < SPEC_MAX_NUM;i+=2) {
    std::string key = rtmadapter_spec[i];



    if (key.length() == 0) {
      break;
    }

    std::string value = rtmadapter_spec[i+1];
    //std::cout << "map[" << key << "] = " << value << std::endl;
    specMap[key] = value;
  }
}

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
RTMAdapter::RTMAdapter(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
  m_id(0)

    // </rtc-template>
{

	init_callbacks();
}

/*!
 * @brief destructor
 */
RTMAdapter::~RTMAdapter()
{
}



RTC::ReturnCode_t RTMAdapter::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RTMAdapter::onFinalize()
{
  RTC::ReturnCode_t ret = on_finalize_callback_g(m_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_finalize_callback() == 0 ? ret : RTC::RTC_ERROR;
}
 
RTC::ReturnCode_t RTMAdapter::onStartup(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_startup_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_startup_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}
 
RTC::ReturnCode_t RTMAdapter::onShutdown(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_shutdown_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_shutdown_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}

RTC::ReturnCode_t RTMAdapter::onActivated(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_activated_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
	return on_activated_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}


RTC::ReturnCode_t RTMAdapter::onDeactivated(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_deactivated_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_deactivated_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}


RTC::ReturnCode_t RTMAdapter::onExecute(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_execute_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_execute_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}


RTC::ReturnCode_t RTMAdapter::onAborting(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_aborting_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_aborting_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}

RTC::ReturnCode_t RTMAdapter::onError(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_error_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_error_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}

RTC::ReturnCode_t RTMAdapter::onReset(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_reset_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_reset_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}

RTC::ReturnCode_t RTMAdapter::onStateUpdate(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_state_update_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_state_update_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}

RTC::ReturnCode_t RTMAdapter::onRateChanged(RTC::UniqueId ec_id)
{
  RTC::ReturnCode_t ret = on_rate_changed_callback_g(m_id, ec_id) == 0 ? RTC::RTC_OK : RTC::RTC_ERROR;
  return on_rate_changed_callback(ec_id) == 0 ? ret : RTC::RTC_ERROR;
}



extern "C"
{
 
  void RTMAdapterInit(RTC::Manager* manager)
  {
    //coil::Properties profile(rtmadapter_spec);
    // init_default_spec_map();
    coil::Properties profile(specMap);
    manager->registerFactory(profile,
                             RTC::Create<RTMAdapter>,
                             RTC::Delete<RTMAdapter>);
  }
  
};

int do_nothing_void_callback() {
  return 0;
}

int do_nothing_callback(int id) {
	return 0;
}

int do_nothing_void_callback_g(int r) {
  return 0;
}

int do_nothing_callback_g(int r, int id) {
  return 0;
}
