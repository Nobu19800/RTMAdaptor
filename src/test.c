#include <stdlib.h>
#include "rtm_adapter.h"
#include "coil_adapter.h"

static RTC_t rtc;
static Manager_t m;


static int counter; 
int on_activated(int ec_id) {
	printf("on_activated called.\n");
	counter = 0;
	return 0;
}

int on_deactivated(int ec_id) {
	printf("on_deactivated called.\n");
	return 0;
}

int on_execute(int ec_id) {
	printf("%d / 20 : on_execute called.\n", counter);
	coil_usleep(1*1000*1000);
	if (counter++ == 20) {
		return -1;
	}
	return 0;
}

int on_aborting(int ec_id) {
	printf("on_aborted called.\n");
	return 0;
}


int on_error(int ec_id) {
	printf("%d: on_error called.\n", counter);
	coil_usleep(1 * 1000 * 1000);
	return 0;
}

int on_reset(int ec_id){
	printf("on_reset called.\n");
	return 0;
}


void MyModuleInit(Manager_t m) {
	Manager_setRTMAdapterSpec(m, "implementation_id", "ModifiedRTC");
	Manager_setRTMAdapterSpec(m, "type_name", "ModifiedRTC");
	Manager_RTMAdapter_init(m);
	if ((rtc = Manager_createComponent(m, "ModifiedRTC")) == RTC_INVALID_ID) {
		printf(" -Failure to createComponent::Manager\n");
		return;
	}

	RTC_onActivated_listen(rtc, on_activated);

	RTC_onDeactivated_listen(rtc, on_deactivated);

	RTC_onExecute_listen(rtc, on_execute);

	RTC_onAborting_listen(rtc, on_aborting);

	RTC_onError_listen(rtc, on_error);

	RTC_onReset_listen(rtc, on_reset);
}

int main(int argc, char** argv) {
  m = Manager_initManager(argc, argv);
  if (Manager_init(m, argc, argv) != RESULT_OK) {
	  printf("Manager_init failed.\n");
	  return -1;
  }

  if (Manager_setModuleInitProc(m, MyModuleInit) != RESULT_OK) {

	  printf("Manager_setRTMAdapterModuleInitProc failed.\n");
	  return -2;
  }

  if (Manager_activateManager(m) != RESULT_OK) {
	  printf("Manager_activateManager failed.\n");
    return -1;
  }

  
  Manager_runManager(m, 0);  
  return 0;
}
