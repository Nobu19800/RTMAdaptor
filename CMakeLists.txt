cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(RTMAdapter)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
include("${PROJECT_SOURCE_DIR}/cmake/utils.cmake")
set(PROJECT_VERSION 1.0.0 CACHE STRING "RTMAdapter version")
DISSECT_VERSION()
set(PROJECT_DESCRIPTION "RTM / C language Adapter")
set(PROJECT_VENDOR "Sugar Sweet Robotics")
set(PROJECT_AUTHOR "Sugar Sweet Robotics")
set(PROJECT_AUTHOR_SHORT "Sugar Sweet Robotics")

# Add an "uninstall" target
CONFIGURE_FILE ("${PROJECT_SOURCE_DIR}/cmake/uninstall_target.cmake.in"
    "${PROJECT_BINARY_DIR}/uninstall_target.cmake" IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET (uninstall "${CMAKE_COMMAND}" -P
    "${PROJECT_BINARY_DIR}/uninstall_target.cmake")

option(STATIC_LIBS "Build static libraries" OFF)
if(STATIC_LIBS)
    set(LIB_TYPE STATIC)
else(STATIC_LIBS)
    set(LIB_TYPE SHARED)
endif(STATIC_LIBS)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
   # Mac OS X specific code
   SET(CMAKE_CXX_COMPILER "g++")
endif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")


# Set up installation directories
set(BIN_INSTALL_DIR "bin")
set(LIB_INSTALL_DIR "lib")
set(INC_INSTALL_DIR
    "include/${PROJECT_NAME_LOWER}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} ")
set(SHARE_INSTALL_DIR
    "share/${PROJECT_NAME_LOWER}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} ")

# Get necessary dependency information
find_package(OpenRTM)
if(${OpenRTM_FOUND})
  MESSAGE(STATUS "OpenRTM configuration Found")
else(${OpenRTM_FOUND})
  message(STATUS "Use cmake/Modules/FindOpenRTM.cmake in the project")
  list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
  find_package(OpenRTM REQUIRED)
endif(${OpenRTM_FOUND})

# Subdirectories
add_subdirectory(cmake)
add_subdirectory(include)
MAP_ADD_STR(headers  "include/" comp_hdrs)
add_subdirectory(src)


# Package creation
# By default, do not warn when built on machines using only VS Express:
IF(NOT DEFINED CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_NO_WARNINGS)
SET(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_NO_WARNINGS ON)
ENDIF()
include(InstallRequiredSystemLibraries)
#set(PROJECT_EXECUTABLES ${PROJECT_NAME_LOWER}Comp
#    "${PROJECT_NAME_LOWER}Comp")

set(cpack_options "${PROJECT_BINARY_DIR}/cpack_options.cmake")

configure_file("${PROJECT_SOURCE_DIR}/cmake/cpack_options.cmake.in"
    ${cpack_options} @ONLY)

set(CPACK_PROJECT_CONFIG_FILE ${cpack_options})
include(${CPACK_PROJECT_CONFIG_FILE})
include(CPack)


