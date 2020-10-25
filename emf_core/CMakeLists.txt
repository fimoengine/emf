cmake_minimum_required(VERSION 3.15)

if(${CMAKE_SOURCE_DIR} EQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  find_package(Python3 REQUIRED COMPONENTS Interpreter)

  list(APPEND CMAKE_MODULE_PATH ../${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
  include(VersionHelper)

  if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "CMAKE_BUILD_TYPE must be set")
  endif()

  # The path to the version management script
  set(EMF_VERSION_MANAGEMENT_SCRIPT
      "../${CMAKE_SOURCE_DIR}/scripts/version_management.py")
endif()

extract_version(${CMAKE_CURRENT_SOURCE_DIR}/version.json EMF_CORE_VERSION)

project(
  emf-core
  DESCRIPTION "Specification of the emf-core interface"
  VERSION ${EMF_CORE_VERSION})

set(EMF_CORE_SRC
    include/emf_core/emf_bool_t.h
    include/emf_core/emf_config.h
    include/emf_core/emf_core.h
    include/emf_core/emf_core_interface_t.h
    include/emf_core/emf_error_t.h
    include/emf_core/emf_event.h
    include/emf_core/emf_fn_ptr_id_t.h
    include/emf_core/emf_fn_ptr_t.h
    include/emf_core/emf_fs.h
    include/emf_core/emf_library.h
    include/emf_core/emf_macros.h
    include/emf_core/emf_module.h
    include/emf_core/emf_version_t.h)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT
                                            STREQUAL "MSVC")
  set(CXX_17_STANDARD_FLAG /std:c++17)
else()
  set(CXX_17_STANDARD_FLAG -std=c++17)
endif()

monitor_version(
  ${PROJECT_SOURCE_DIR}/include/emf_core/version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/emf_core/version.h
  ${PROJECT_SOURCE_DIR}/version.json --prefix EMF_CORE_)

add_library(emf_core INTERFACE)
add_dependencies(emf_core include/emf_core/version.h)
target_include_directories(
  emf_core
  INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
            $<INSTALL_INTERFACE:include>)

target_compile_options(
  emf_core
  INTERFACE
    $<$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang,GNU,MSVC>:${CXX_17_STANDARD_FLAG}>
)

target_sources(
  emf_core
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/emf_core/version.h>
    $<INSTALL_INTERFACE:include/emf_core/version.h>)

foreach(f IN LISTS EMF_CORE_SRC)
  target_sources(
    emf_core INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/${f}>
                       $<INSTALL_INTERFACE:${f}>)
endforeach()

install(DIRECTORY include/emf_core DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/emf_core/version.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/emf_core)

install(TARGETS emf_core EXPORT ${PROJECT_NAME}Targets)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  ${PROJECT_NAME}ConfigVersion.cmake
  VERSION ${PACKAGE_VERSION}
  COMPATIBILITY AnyNewerVersion)

install(
  EXPORT ${PROJECT_NAME}Targets
  FILE ${PROJECT_NAME}Config.cmake
  NAMESPACE emf::
  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME})
