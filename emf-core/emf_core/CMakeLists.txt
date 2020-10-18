set(EMF_CORE_SRC include/emf_core/emf_bool_t.h
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
        include/emf_core/emf_version_t.h
        )

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    SET(CXX_17_STANDARD_FLAG /std:c++17)
else ()
    SET(CXX_17_STANDARD_FLAG -std=c++17)
endif ()

add_library(emf_core INTERFACE)
configure_file("include/emf_core/version.h.in" "include/emf_core/version.h")
target_include_directories(emf_core INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/emf_core/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_compile_options(emf_core INTERFACE
        $<$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang,GNU,MSVC>:${CXX_17_STANDARD_FLAG}>)

foreach(FLAG IN LISTS COMPILER_FLAGS)
    target_compile_options(emf_core INTERFACE ${FLAG})
    message(STATUS "Added ${FLAG} to the compilation flags")
endforeach()

target_sources(emf_core INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/emf_core/version.h>
        $<INSTALL_INTERFACE:include/emf_core/version.h>)

foreach(f IN LISTS EMF_CORE_SRC)
    target_sources(emf_core INTERFACE
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/emf_core/${f}>
            $<INSTALL_INTERFACE:${f}>)
endforeach()

install(DIRECTORY include/emf_core
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        )

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/emf_core/version.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/emf_core)

install(TARGETS emf_core
        EXPORT ${PROJECT_NAME}Targets)