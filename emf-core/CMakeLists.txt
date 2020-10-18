cmake_minimum_required(VERSION 3.15)

# Set the version of the project
set(EMF_INTERFACE_C_VERSION_MAJOR 0)
set(EMF_INTERFACE_C_VERSION_MINOR 1)
set(EMF_INTERFACE_C_VERSION_PATCH 0)
set(EMF_INTERFACE_C_VERSION_PRE_RELEASE_TYPE_STRING "gold")
set(EMF_INTERFACE_C_VERSION_PRE_RELEASE_NUMBER 0)
string(TIMESTAMP EMF_INTERFACE_C_VERSION_BUILD "%s" UTC)

# List of valid release types
set(EMF_RELEASE_TYPES "gold" "pre-alpha" "alpha" "beta" "rc")

# Validate the release type
list(FIND EMF_RELEASE_TYPES ${EMF_INTERFACE_C_VERSION_PRE_RELEASE_TYPE_STRING} EMF_INTERFACE_C_VERSION_PRE_RELEASE_TYPE)
if(EMF_INTERFACE_C_VERSION_PRE_RELEASE_TYPE EQUAL -1)
    message(FATAL_ERROR "EMF_INTERFACE_C_VERSION_PRE_RELEASE_TYPE_STRING must be one of ${EMF_RELEASE_TYPES}")
endif()

# Construct the version strings
set(EMF_INTERFACE_C_VERSION_SHORT "${EMF_INTERFACE_C_VERSION_MAJOR}.${EMF_INTERFACE_C_VERSION_MINOR}.${EMF_INTERFACE_C_VERSION_PATCH}")

if (EMF_INTERFACE_C_VERSION_PRE_RELEASE_TYPE EQUAL 0)
    set(EMF_INTERFACE_C_VERSION_PRE_RELEASE_NUMBER 0)
    set(EMF_INTERFACE_C_VERSION_LONG ${EMF_INTERFACE_C_VERSION_SHORT})
else()
    set(EMF_INTERFACE_C_VERSION_LONG "${EMF_INTERFACE_C_VERSION_SHORT}-${EMF_INTERFACE_C_VERSION_PRE_RELEASE_TYPE_STRING}.${EMF_INTERFACE_C_VERSION_PRE_RELEASE_NUMBER}")
endif()

set(EMF_INTERFACE_C_VERSION_FULL "${EMF_INTERFACE_C_VERSION_LONG}+${EMF_INTERFACE_C_VERSION_BUILD}")

project(emf-c VERSION ${EMF_INTERFACE_C_VERSION_SHORT}
        DESCRIPTION "Interface for the Engine-Module-Framework"
        LANGUAGES C CXX)

option(EMF_BUILD_DOCS "Build the documentation." ON)
option(EMF_BUILD_BINDINGS "Build the bindings library." ON)
option(EMF_BUILD_CORE_CPP "Export the emf-core-cpp interface." ON)
option(EMF_ENABLE_ERROR_CHECKING "Enables the checking of preconditions." OFF)
option(EMF_DISABLE_OPTIMIZATIONS "Disables the optimization flags for debugging purposes." OFF)
option(EMF_ENABLE_NATIVE_ARCH "Enables the flag -march=native if it exists" OFF)
option(EMF_ENABLE_CLANG_TIDY "Enables linting using clang-tidy" ON)

if (NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "CMAKE_BUILD_TYPE must be set")
endif ()

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(EMF_ENABLE_ERROR_CHECKING ON)
    set(EMF_DISABLE_OPTIMIZATIONS ON)
endif ()

# Setup clang-tidy
if (EMF_ENABLE_CLANG_TIDY)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        set(CMAKE_CXX_CLANG_TIDY clang-tidy --extra-arg=--driver-mode=cl --extra-arg=/EHca)
    else ()
        set(CMAKE_CXX_CLANG_TIDY clang-tidy)
    endif ()
endif ()

# Add platform dependent compiler flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    # using msvc or clang with cl front end
    set(COMPILER_FLAGS /W4 /WX /EHca)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
        # using clang with regular front end
        set(COMPILER_FLAGS -Wall -Wextra -pedantic -Werror -fexceptions -Wno-nullability-extension -Wno-gnu-zero-variadic-macro-arguments)
    endif ()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using gcc
    set(COMPILER_FLAGS -Wall -Wextra -pedantic -Werror -fexceptions -Wno-gnu-zero-variadic-macro-arguments -Wno-attributes -Wno-ignored-qualifiers)
endif ()

if (EMF_ENABLE_ERROR_CHECKING)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        list(APPEND COMPILER_FLAGS /DEMF_ENABLE_ERROR_CHECKING)
    else ()
        list(APPEND COMPILER_FLAGS -D EMF_ENABLE_ERROR_CHECKING)
    endif ()
endif ()

if (NOT EMF_DISABLE_OPTIMIZATIONS)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        list(APPEND COMPILER_FLAGS /O2)
    else ()
        list(APPEND COMPILER_FLAGS -O2)
    endif ()
endif ()

if (EMF_ENABLE_NATIVE_ARCH AND NOT (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
    list(APPEND COMPILER_FLAGS -march=native)
endif ()

message(STATUS "")
message(STATUS "Project: emf_c")
message(STATUS "Version: ${EMF_INTERFACE_C_VERSION_FULL}")
message(STATUS "Option: EMF_BUILD_TESTS = ${EMF_BUILD_TESTS}")
message(STATUS "Option: EMF_DISABLE_OPTIMIZATIONS = ${EMF_DISABLE_OPTIMIZATIONS}")
message(STATUS "Option: EMF_ENABLE_NATIVE_ARCH = ${EMF_ENABLE_NATIVE_ARCH}")
message(STATUS "Option: EMF_ENABLE_CLANG_TIDY = ${EMF_ENABLE_CLANG_TIDY}")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

add_subdirectory(emf_core)

if (EMF_BUILD_CORE_CPP)
    add_subdirectory(emf_core_cpp)
endif()

if (EMF_BUILD_BINDINGS)
    add_subdirectory(emf_core_binding)
endif()

if (EMF_BUILD_DOCS)
    add_subdirectory(docs)
endif()

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
        ${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion
)

install(FILES README.md
        DESTINATION ${CMAKE_INSTALL_PREFIX}/share/doc/${PROJECT_NAME}
        )

install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Config.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME})
