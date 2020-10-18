set(EMF_CORE_BINDING_SRC include/emf_core/emf_binding.h
        src/emf_binding.cpp
        src/emf_config.cpp
        src/emf_core.cpp
        src/emf_event.cpp
        src/emf_fs.cpp
        src/emf_library.cpp
        src/emf_module.cpp
        src/emf_version_t.cpp
        )

add_library(emf_core_binding STATIC ${EMF_CORE_BINDING_SRC})
target_link_libraries(emf_core_binding PUBLIC emf_core)
target_include_directories(emf_core_binding PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/emf_core_binding/include>
        $<INSTALL_INTERFACE:include>)
target_compile_definitions(emf_core_binding PUBLIC EMF_C_BINDINGS=1)
target_compile_features(emf_core_binding PRIVATE cxx_std_17)

install(DIRECTORY include/emf_core
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        )

install(TARGETS emf_core_binding
        EXPORT ${PROJECT_NAME}Targets)