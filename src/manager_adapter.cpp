#include <vector>
#include <memory>

#include <rtm/Manager.h>
#include "manager_adapter.h"
#include "RTMAdapter.h"

#define MAX_MANAGER 1
static RTC::Manager* _manager;


std::vector<std::shared_ptr<RTC::RtcBase> > __rtcs;
std::vector<std::shared_ptr<RTC::PortBase> > __ports;



void MyModuleInit(RTC::Manager* manager)
{
  RTMAdapterInit(manager);
  //  RTC::RtcBase* comp;

  // Create a component
  //comp = manager->createComponent("RTMAdapter");
  //if (comp==NULL)
  //{
  //std::cerr << "Component create failed." << std::endl;
  //abort();
  //}

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


#define MANAGER_ARG_CHECK do {if (m < 0) { \
    return ERROR;\
  }\
}while(false)

Manager_t Manager_initManager(int argc, char** argv) {
  _manager = RTC::Manager::init(argc, argv);
  return 0;
}

Result_t Manager_init(Manager_t m, int argc, char** argv) {
  MANAGER_ARG_CHECK;

  _manager->init(argc, argv);
  return OK;
}

Result_t Manager_setRTMAdapterModuleInitProc(Manager_t m) {
  MANAGER_ARG_CHECK;

  _manager->setModuleInitProc(MyModuleInit);
  return OK;
}

Result_t Manager_activateManager(Manager_t m) {
  MANAGER_ARG_CHECK;

  _manager->activateManager();
  return OK;
}

Result_t Manager_runManager(Manager_t m, int32_t flag) {
  MANAGER_ARG_CHECK;
  
  _manager->runManager(flag == 0 ? false : true);
  return OK;
}

RTC_t Manager_createComponent(Manager_t m, char* identifier) {
  MANAGER_ARG_CHECK;

  RTC::RtcBase* comp = _manager->createComponent(identifier);
  if (comp == NULL) {
    return RTC_INVALID_ID;
  }

  __rtcs.push_back(std::shared_ptr<RTC::RtcBase>(comp));
  return __rtcs.size()-1;
}

Result_t Manager_shutdown(Manager_t m) {
  MANAGER_ARG_CHECK;
  
  _manager->shutdown();
  return OK;
}
