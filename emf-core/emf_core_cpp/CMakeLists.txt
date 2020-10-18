set(EMF_CORE_CXX_SRC include/emf_core/emf_config.hpp
        include/emf_core/emf_core.hpp
        include/emf_core/emf_event.hpp
        include/emf_core/emf_fs.hpp
        include/emf_core/emf_library.hpp
        include/emf_core/emf_lock.hpp
        include/emf_core/emf_module.hpp
        include/emf_core/emf_version_t.hpp
        include/emf_core/version.hpp
        )

add_library(emf_core_cpp INTERFACE)
target_link_libraries(emf_core_cpp INTERFACE emf_core)
target_compile_features(emf_core_cpp INTERFACE cxx_std_20)
target_include_directories(emf_core_cpp INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/emf_core_cpp/include>
        $<INSTALL_INTERFACE:include>)

foreach(f IN LISTS EMF_CORE_CXX_SRC)
    target_sources(emf_core_cpp INTERFACE
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/emf_core_cpp/${f}>
            $<INSTALL_INTERFACE:${f}>)
endforeach()

install(DIRECTORY include/emf_core
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        )

install(TARGETS emf_core_cpp
        EXPORT ${PROJECT_NAME}Targets)