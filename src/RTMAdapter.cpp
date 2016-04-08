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
static const char* rtmadapter_spec[] =
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
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
RTMAdapter::RTMAdapter(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager)

    // </rtc-template>
{
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

/*
RTC::ReturnCode_t RTMAdapter::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RTMAdapter::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RTMAdapter::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t RTMAdapter::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RTMAdapter::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RTMAdapter::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RTMAdapter::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RTMAdapter::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RTMAdapter::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RTMAdapter::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RTMAdapter::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void RTMAdapterInit(RTC::Manager* manager)
  {
    coil::Properties profile(rtmadapter_spec);
    manager->registerFactory(profile,
                             RTC::Create<RTMAdapter>,
                             RTC::Delete<RTMAdapter>);
  }
  
};


