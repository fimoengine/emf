cmake_minimum_required(VERSION 3.15)

if(${CMAKE_SOURCE_DIR} EQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  find_package(Python3 REQUIRED COMPONENTS Interpreter)

  list(APPEND CMAKE_MODULE_PATH ../${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
  include(VersionHelper)

  if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "CMAKE_BUILD_TYPE must be set")
  endif()

  # The path to the version management script
  set_version_script_path(
    "../${CMAKE_SOURCE_DIR}/scripts/version_management.py")
endif()

extract_version(${CMAKE_CURRENT_SOURCE_DIR}/version.json EMF_CORE_BASE_VERSION)

project(
  emf-core-base
  DESCRIPTION "Specification of the emf-core-base interface"
  VERSION ${EMF_CORE_BASE_VERSION})

set(EMF_CORE_BASE_SRC
    include/emf_core_base/emf_cbase_bool_t.h
    include/emf_core_base/emf_cbase_fn_ptr_id_t.h
    include/emf_core_base/emf_cbase_interface_t.h
    include/emf_core_base/emf_cbase_library.h
    include/emf_core_base/emf_cbase_macros.h
    include/emf_core_base/emf_cbase_module.h
    include/emf_core_base/emf_cbase_sys.h
    include/emf_core_base/emf_cbase_version_t.h
    include/emf_core_base/extensions/emf_unwind_internal/emf_unwind_internal.h)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
  set(CXX_17_STANDARD_FLAG /std:c++17)
else()
  set(CXX_17_STANDARD_FLAG -std=c++17)
endif()

monitor_version(
  emf_core_base_replace_version.ini
  ${PROJECT_SOURCE_DIR}/include/emf_core_base/version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/emf_core_base/emf_cbase_version.h
  ${PROJECT_SOURCE_DIR}/version.json
  --prefix
  EMF_CBASE_VERSION_
  --version_long_key
  STRING
  --build
  -2)

add_library(emf_core_base INTERFACE)
add_dependencies(emf_core_base emf_core_base_replace_version.ini)
target_include_directories(
  emf_core_base
  INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
            $<INSTALL_INTERFACE:include>)

if(EMF_ENABLE_DEBUG_ASSERTIONS)
  target_compile_definitions(emf_core_base
                             INTERFACE EMF_ENABLE_DEBUG_ASSERTIONS)
endif()

target_compile_options(
  emf_core_base
  INTERFACE
    $<$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang,GNU,MSVC>:${CXX_17_STANDARD_FLAG}>
)

target_sources(
  emf_core_base
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/emf_core_base/emf_cbase_version.h>
    $<INSTALL_INTERFACE:include/emf_core_base/emf_cbase_version.h>)

foreach(f IN LISTS EMF_CORE_BASE_SRC)
  target_sources(
    emf_core_base INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/${f}>
                            $<INSTALL_INTERFACE:${f}>)
endforeach()

add_library(emf_core_base.int STATIC empty.c)
target_link_libraries(emf_core_base.int PUBLIC emf_core_base)
target_compile_features(emf_core_base.int PRIVATE cxx_std_17)
set_target_properties(emf_core_base.int PROPERTIES LINKER_LANGUAGE CXX)

install(DIRECTORY include/emf_core_base
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/include/emf_core_base/emf_cbase_version.h
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/emf_core_base)

install(TARGETS emf_core_base EXPORT ${PROJECT_NAME}Targets)

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
