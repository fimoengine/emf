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

execute_process(
  COMMAND ${Python3_EXECUTABLE} ${EMF_VERSION_MANAGEMENT_SCRIPT} extract
          ${CMAKE_CURRENT_SOURCE_DIR}/version.json -
  OUTPUT_VARIABLE EMF_CORE_BINDINGS_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE)

project(
  emf-core-bindings
  DESCRIPTION "Bindings to the emf-core interface"
  VERSION ${EMF_CORE_BINDINGS_VERSION})

set(EMF_CORE_BINDINGS_SRC
    src/emf_core_bindings.cpp
    src/emf_config.cpp
    src/emf_core.cpp
    src/emf_event.cpp
    src/emf_fs.cpp
    src/emf_library.cpp
    src/emf_module.cpp
    src/emf_version_t.cpp)

monitor_version(
  ${PROJECT_SOURCE_DIR}/include/emf_core_bindings/version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/emf_core_bindings/version.h
  ${PROJECT_SOURCE_DIR}/version.json --prefix EMF_CORE_BINDINGS_)

add_library(emf_core_bindings STATIC ${EMF_CORE_BINDINGS_SRC})
add_dependencies(emf_core include/emf_core_bindings/version.h)
target_link_libraries(emf_core_bindings PUBLIC emf_core)
target_include_directories(
  emf_core_bindings
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
         $<INSTALL_INTERFACE:include>)
target_compile_features(emf_core_bindings PRIVATE cxx_std_17)

target_sources(
  emf_core_bindings
  PUBLIC
    $<BUILD_INTERFACE:include/emf_core_bindings/emf_core_bindings.h>
    $<INSTALL_INTERFACE:include/emf_core_bindings/emf_core_bindings.h>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/emf_core_bindings/version.h>
    $<INSTALL_INTERFACE:include/emf_core_bindings/version.h>)

install(DIRECTORY include/emf_core_bindings
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/emf_core_bindings/version.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/emf_core_bindings)

install(TARGETS emf_core_bindings EXPORT ${PROJECT_NAME}Targets)

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
