#include <vector>
#include <memory>

#include <rtm/Manager.h>
#include "manager_adapter.h"
#include "RTMAdapter.h"

#define MAX_MANAGER 1
static RTC::Manager* _manager;


//std::vector<std::shared_ptr<RTC::RtcBase> > __rtcs;
std::vector<RTC::RtcBase*> __rtcs;
std::vector<std::shared_ptr<RTC::PortBase> > __ports;
extern std::map<std::string, std::string> specMap;
#define SPEC_MAX_STR 64
#define SPEC_MAX_NUM 24
static char spec_memory[SPEC_MAX_NUM][SPEC_MAX_STR];
static int spec_counter;
static char* end_str = "";
extern char* rtmadapter_spec[];
static bool set_spec(const char* key, const char* value);

void init_default_spec_map();

void do_nothing_routine(Manager_t m) {

}

void* argument = NULL;
void (*init_routine)(Manager_t m) = do_nothing_routine;

void MyModuleInit(RTC::Manager* manager)
{
  init_routine(0);
  return;
}

#define MANAGER_ARG_CHECK do {if (m < 0) { \
    return RESULT_ERROR;\
  }\
}while(false)

Manager_t Manager_initManager(int argc, char** argv) {
  init_default_spec_map();
  _manager = RTC::Manager::init(argc, argv);
  return 0;
}

Result_t Manager_init(Manager_t m, int argc, char** argv) {
  MANAGER_ARG_CHECK;

  _manager->init(argc, argv);
  return RESULT_OK;
}

Result_t Manager_initRTMAdapter(Manager_t m) {
  MANAGER_ARG_CHECK;
  RTMAdapterInit(_manager);
  return RESULT_OK;
}

Result_t Manager_setModuleInitProc(Manager_t m, void(*initRoutine)(Manager_t m)) {
	init_routine = initRoutine;
	_manager->setModuleInitProc(MyModuleInit);
	return RESULT_OK;
}

Result_t Manager_setRTMAdapterModuleInitProc(Manager_t m) {
  MANAGER_ARG_CHECK;
  _manager->setModuleInitProc(MyModuleInit);
  return RESULT_OK;
}

Result_t Manager_activateManager(Manager_t m) {
  MANAGER_ARG_CHECK;

  _manager->activateManager();
  return RESULT_OK;
}

Result_t Manager_runManager(Manager_t m, int32_t flag) {
  MANAGER_ARG_CHECK;
  
  _manager->runManager(flag == 0 ? false : true);
  return RESULT_OK;
}

RTC_t Manager_createComponent(Manager_t m, char* identifier) {
  MANAGER_ARG_CHECK;

  RTC::RtcBase* comp = _manager->createComponent(identifier);
  if (comp == NULL) {
    return RTC_INVALID_ID;
  }
  __rtcs.push_back(comp);
  //__rtcs.push_back(std::shared_ptr<RTC::RtcBase>(comp));
  return __rtcs.size()-1;
}

RTC_t Manager_createAdapterComponent(Manager_t m) {
  MANAGER_ARG_CHECK;

  RTC::RtcBase* comp = _manager->createComponent("RTMAdapter");
  if (comp == NULL) {
    return RTC_INVALID_ID;
  }
  __rtcs.push_back(comp);
  //__rtcs.push_back(std::shared_ptr<RTC::RtcBase>(comp));
  return __rtcs.size() - 1;
}


Result_t Manager_shutdown(Manager_t m) {
  MANAGER_ARG_CHECK;
  //_manager->terminate();
  _manager->shutdown();
  return RESULT_OK;
}

Result_t Manager_deleteComponent(Manager_t m, RTC_t rtc) {
	MANAGER_ARG_CHECK;
	if (rtc < 0 || rtc >= __rtcs.size()) {
		return RESULT_INVALID_RTC;
	}
	_manager->deleteComponent(__rtcs[rtc]);
//	_manager->deleteComponent(__rtcs[rtc].get());
	return RESULT_OK;
}

Result_t Manager_getComponent(Manager_t m, char* instance_name, RTC_t* rtc) {
	MANAGER_ARG_CHECK;

	for (uint32_t i = 0; i < __rtcs.size(); i++) {
		if (__rtcs[i] != nullptr) {
			if (strcmp(__rtcs[i]->getInstanceName(), instance_name) == 0) {
				*rtc = i;
				return RESULT_OK;
			}
		}
	}
	return RESULT_ERROR;
}


Result_t Manager_setRTMAdapterSpec(Manager_t m, const char* key, const char* value) {
  MANAGER_ARG_CHECK;

  //if (!set_spec(key, value)) {
  //return RESULT_ERROR;
  //}
  specMap[key] = value;

  return RESULT_OK;
}
/*
static bool set_spec(const char* key, const char* value) {
  if (strlen(value) >= SPEC_MAX_STR) {
    std::cerr << "[RTMAdapter] Spec String Must Be Shorter than " << SPEC_MAX_STR << "." << std::endl;
    return false;
  } 
  if (spec_counter == SPEC_MAX_NUM) {
    std::cerr << "[RTMAdapter] Spec can not change any more." << std::endl;
    return false;
  }

  strcpy(spec_memory[spec_counter], value);

  int i = 0;
  for(;strlen(rtmadapter_spec[i]) != 0;i+=2) {
    if (strcmp(rtmadapter_spec[i], key) == 0) {
      rtmadapter_spec[i+1] = spec_memory[spec_counter];
      spec_counter++;
      return true;
    }
  }
  
  strcpy(spec_memory[spec_counter+1], key);
  rtmadapter_spec[i] = spec_memory[spec_counter+1];
  rtmadapter_spec[i+1] = spec_memory[spec_counter];
  rtmadapter_spec[i+2] = end_str;
  spec_counter += 2;
  return true;
};
*/
Result_t Manager_RTMAdapter_init(Manager_t m) {
  MANAGER_ARG_CHECK;
  RTMAdapterInit(_manager);
  return RESULT_OK;
}
