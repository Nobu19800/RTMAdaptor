// -*- C++ -*-
/*!
 * @file RTMAdapterComp.cpp
 * @brief Standalone component
 * @date $Date$
 *
 * $Id$
 */

// #include <rtm/Manager.h>
#include <iostream>
#include <string>
#include <stdlib.h>
// #include "RTMAdapter.h"
#include "rtm_adapter.h"

#include "ports/timedlong.h"
#include "ports/timeddoubleseq.h"

size_t Ports_size();
/*
void MyModuleInit(RTC::Manager* manager)
{
  RTMAdapterInit(manager);
  RTC::RtcBase* comp;

  // Create a component
  comp = manager->createComponent("RTMAdapter");

  if (comp==NULL)
  {
    std::cerr << "Component create failed." << std::endl;
    abort();
  }

  // Example
  // The following procedure is examples how handle RT-Components.
  // These should not be in this function.

  // Get the component's object reference
//  RTC::RTObject_var rtobj;
//  rtobj = RTC::RTObject::_narrow(manager->getPOA()->servant_to_reference(comp));

  // Get the port list of the component
//  PortServiceList* portlist;
//  portlist = rtobj->get_ports();

  // getting port profiles
//  std::cout << "Number of Ports: ";
//  std::cout << portlist->length() << std::endl << std::endl; 
//  for (CORBA::ULong i(0), n(portlist->length()); i < n; ++i)
//  {
//    PortService_ptr port;
//    port = (*portlist)[i];
//    std::cout << "Port" << i << " (name): ";
//    std::cout << port->get_port_profile()->name << std::endl;
//    
//    RTC::PortInterfaceProfileList iflist;
//    iflist = port->get_port_profile()->interfaces;
//    std::cout << "---interfaces---" << std::endl;
//    for (CORBA::ULong i(0), n(iflist.length()); i < n; ++i)
//    {
//      std::cout << "I/F name: ";
//      std::cout << iflist[i].instance_name << std::endl;
//      std::cout << "I/F type: ";
//      std::cout << iflist[i].type_name << std::endl;
//      const char* pol;
//      pol = iflist[i].polarity == 0 ? "PROVIDED" : "REQUIRED";
//      std::cout << "Polarity: " << pol << std::endl;
//    }
//    std::cout << "---properties---" << std::endl;
//    NVUtil::dump(port->get_port_profile()->properties);
//    std::cout << "----------------" << std::endl << std::endl;
//  }

  return;
}
*/
int main (int argc, char** argv)
{

  Manager_t m = Manager_initManager(argc, argv);
  Manager_init(m, argc, argv);
  Manager_setRTMAdapterModuleInitProc(m);
  Manager_activateManager(m);

  RTC_t r = Manager_createComponent(m, "RTMAdapter");
  TimedLong_registerDataType(Port_getBuffer());
  std::cout << "Register" << std::endl;
  DataType_t t = TimedLong_create();
  std::cout << "create" << std::endl;
  Port_t p = InPort_TimedLong_create("in", t);
  std::cout << "Port create" << std::endl;
  if (p < 0) {
    std::cout << "Failed to create port." << std::endl;
  }
  int ret;
  if ((ret = RTC_addInPort(r, "in", p)) < 0) {
    std::cout << "Failed to addPort (" << ret << ")" << std::endl;
  }
  
  Manager_runManager(m, 0);



  //RTC::Manager* manager;
  //manager = RTC::Manager::init(argc, argv);

  // Initialize manager
  //  manager->init(argc, argv);

  // Set module initialization proceduer
  // This procedure will be invoked in activateManager() function.
  //manager->setModuleInitProc(MyModuleInit);

  // Activate manager and register to naming service
  //manager->activateManager();

  // run the manager in blocking mode
  // runManager(false) is the default.
  //manager->runManager();

  // If you want to run the manager in non-blocking mode, do like this
  // manager->runManager(true);

  return 0;
}

