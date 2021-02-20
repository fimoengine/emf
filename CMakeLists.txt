cmake_minimum_required(VERSION 3.15)

# Find Python3
find_package(Python3 REQUIRED COMPONENTS Interpreter)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
include(VersionHelper)

if(NOT CMAKE_BUILD_TYPE)
  message(FATAL_ERROR "CMAKE_BUILD_TYPE must be set")
endif()

project(
  emf
  DESCRIPTION "emf-* interfaces and libraries"
  LANGUAGES C CXX)

# The path to the version management script
set_version_script_path("${CMAKE_SOURCE_DIR}/scripts/version_management.py")

# Build options
option(EMF_ENABLE_DEBUG_ASSERTIONS "Asserts the validity of preconditions" OFF)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  set(EMF_ENABLE_DEBUG_ASSERTIONS ON)
endif()

# Interfaces
option(EMF_ENABLE_EMF_CORE "Enable emf-core" ON)
option(EMF_ENABLE_EMF_CORE_BASE "Enable emf-core-base" ON)

# Libraries
option(EMF_ENABLE_EMF_CORE_BINDINGS "Enable emf-core-bindings" ON)

# Enable dependencies

# emf-core-bindings
if(EMF_ENABLE_EMF_CORE_BINDINGS)
  set(EMF_ENABLE_EMF_CORE ON)
endif()

# Add subprojects

# emf-core
if(EMF_ENABLE_EMF_CORE)
  add_subdirectory(emf_core)
endif()

# emf-core-bindings
if(EMF_ENABLE_EMF_CORE_BINDINGS)
  add_subdirectory(emf_core_bindings)
endif()

# emf-core-base
if(EMF_ENABLE_EMF_CORE_BASE)
  add_subdirectory(emf_core_base)
endif()
