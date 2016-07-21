set(headers coil_adapter.h manager_adapter.h adapter_common.h port_adapter.h rtc_adapter.h rtm_adapter.h)

set(hdrs ${headers}
    PARENT_SCOPE
    )


install(FILES ${headers} DESTINATION ${INC_INSTALL_DIR})

