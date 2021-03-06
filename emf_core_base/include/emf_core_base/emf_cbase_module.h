#ifndef EMF_CBASE_EMF_CBASE_MODULE_H
#define EMF_CBASE_EMF_CBASE_MODULE_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_fn_ptr_id_t.h>
#include <emf_core_base/emf_cbase_library.h>
#include <emf_core_base/emf_cbase_macros.h>
#include <emf_core_base/emf_cbase_sys.h>
#include <emf_core_base/emf_cbase_version_t.h>

#define EMF_CBASE_MODULE_INFO_NAME_MAX_LENGTH 32
#define EMF_CBASE_MODULE_INFO_VERSION_MAX_LENGTH 32
#define EMF_CBASE_INTERFACE_INFO_NAME_MAX_LENGTH 32
#define EMF_CBASE_INTERFACE_EXTENSION_NAME_MAX_LENGTH 32
#define EMF_CBASE_MODULE_LOADER_TYPE_MAX_LENGTH 64
#define EMF_CBASE_NATIVE_MODULE_TYPE_NAME "emf::core_base::native"
#define EMF_CBASE_NATIVE_MODULE_INTERFACE_SYMBOL_NAME emf_cbase_native_module_interface

#define EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE                                                                                   \
    (emf_cbase_module_loader_handle_t) { emf_cbase_module_predefined_handles_native }

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

typedef struct emf_cbase_t emf_cbase_t;

typedef enum emf_cbase_module_predefined_handles_t : int32_t {
    emf_cbase_module_predefined_handles_native = 0,
} emf_cbase_module_predefined_handles_t;

typedef enum emf_cbase_module_error_t : int32_t {
    emf_cbase_module_error_path_invalid = 0,
    emf_cbase_module_error_module_state_invalid = 1,
    emf_cbase_module_error_module_handle_invalid = 2,
    emf_cbase_module_error_loader_handle_invalid = 3,
    emf_cbase_module_error_internal_handle_invalid = 4,
    emf_cbase_module_error_module_type_invalid = 5,
    emf_cbase_module_error_module_type_not_found = 6,
    emf_cbase_module_error_duplicate_module_type = 7,
    emf_cbase_module_error_interface_not_found = 8,
    emf_cbase_module_error_duplicate_interface = 9,
    emf_cbase_module_error_module_dependency_not_found = 10,
    emf_cbase_module_error_buffer_overflow = 11,
} emf_cbase_module_error_t;

typedef enum emf_cbase_module_status_t : int32_t {
    emf_cbase_module_status_unloaded = 0,
    emf_cbase_module_status_terminated = 1,
    emf_cbase_module_status_ready = 2,
} emf_cbase_module_status_t;

typedef struct emf_cbase_module_handle_t {
    int32_t id;
} emf_cbase_module_handle_t;

typedef struct emf_cbase_module_loader_handle_t {
    int32_t id;
} emf_cbase_module_loader_handle_t;

typedef struct emf_cbase_internal_module_handle_t {
    intptr_t id;
} emf_cbase_internal_module_handle_t;

typedef struct emf_cbase_module_interface_t {
    void* EMF_CBASE_NOT_NULL interface;
} emf_cbase_module_interface_t;

EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_module_name_t, char, EMF_CBASE_MODULE_INFO_NAME_MAX_LENGTH)
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_module_type_t, char, EMF_CBASE_MODULE_LOADER_TYPE_MAX_LENGTH)
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_module_version_t, char, EMF_CBASE_MODULE_INFO_VERSION_MAX_LENGTH)
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_interface_name_t, char, EMF_CBASE_INTERFACE_INFO_NAME_MAX_LENGTH)
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_interface_extension_t, char, EMF_CBASE_INTERFACE_EXTENSION_NAME_MAX_LENGTH)

typedef struct emf_cbase_module_info_t {
    emf_cbase_module_name_t name;
    emf_cbase_module_version_t version;
} emf_cbase_module_info_t;

EMF_CBASE_SPAN_TYPEDEF(emf_cbase_module_type_span_t, emf_cbase_module_type_t)
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_module_info_span_t, emf_cbase_module_info_t)
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_interface_extension_span_t, const emf_cbase_interface_extension_t)

typedef struct emf_cbase_interface_descriptor_t {
    emf_cbase_interface_name_t name;
    emf_cbase_version_t version;
    emf_cbase_interface_extension_span_t extensions;
} emf_cbase_interface_descriptor_t;

EMF_CBASE_SPAN_TYPEDEF(emf_cbase_interface_descriptor_span_t, emf_cbase_interface_descriptor_t)
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_interface_descriptor_const_span_t, const emf_cbase_interface_descriptor_t)

EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_result_t, int8_t, emf_cbase_module_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_size_result_t, size_t, emf_cbase_module_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_status_result_t, emf_cbase_module_status_t, emf_cbase_module_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_handle_result_t, emf_cbase_module_handle_t, emf_cbase_module_error_t)
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_os_path_char_result_t, const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL, emf_cbase_module_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_interface_result_t, emf_cbase_module_interface_t, emf_cbase_module_error_t)
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_module_info_ptr_result_t, const emf_cbase_module_info_t* EMF_CBASE_NOT_NULL, emf_cbase_module_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_loader_handle_result_t, emf_cbase_module_loader_handle_t, emf_cbase_module_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_internal_module_handle_result_t, emf_cbase_internal_module_handle_t, emf_cbase_module_error_t)
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_interface_descriptor_const_span_result_t, emf_cbase_interface_descriptor_const_span_t, emf_cbase_module_error_t)

// module loader interface
typedef struct emf_cbase_module_loader_t emf_cbase_module_loader_t;

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_add_module_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_internal_module_handle_result_t, emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL module_path)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_remove_module_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_load_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_unload_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_initialize_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_terminate_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_fetch_status_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_module_status_result_t, emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader,
    emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_interface_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_module_interface_result_t, emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader,
    emf_cbase_internal_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_module_info_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_module_info_ptr_result_t, emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader,
    emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_module_path_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_os_path_char_result_t, emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader,
    emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_load_dependencies_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_runtime_dependencies_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_exportable_interfaces_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_internal_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_internal_interface_fn_t,
    EMF_CBASE_NODISCARD const void* EMF_CBASE_NOT_NULL, emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader)

typedef struct emf_cbase_module_loader_interface_t {
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader;
    emf_cbase_module_loader_interface_add_module_fn_t EMF_CBASE_NOT_NULL add_module_fn;
    emf_cbase_module_loader_interface_remove_module_fn_t EMF_CBASE_NOT_NULL remove_module_fn;
    emf_cbase_module_loader_interface_load_fn_t EMF_CBASE_NOT_NULL load_fn;
    emf_cbase_module_loader_interface_unload_fn_t EMF_CBASE_NOT_NULL unload_fn;
    emf_cbase_module_loader_interface_initialize_fn_t EMF_CBASE_NOT_NULL initialize_fn;
    emf_cbase_module_loader_interface_terminate_fn_t EMF_CBASE_NOT_NULL terminate_fn;
    emf_cbase_module_loader_interface_fetch_status_fn_t EMF_CBASE_NOT_NULL fetch_status_fn;
    emf_cbase_module_loader_interface_get_interface_fn_t EMF_CBASE_NOT_NULL get_interface_fn;
    emf_cbase_module_loader_interface_get_module_info_fn_t EMF_CBASE_NOT_NULL get_module_info_fn;
    emf_cbase_module_loader_interface_get_module_path_fn_t EMF_CBASE_NOT_NULL get_module_path_fn;
    emf_cbase_module_loader_interface_get_load_dependencies_fn_t EMF_CBASE_NOT_NULL get_load_dependencies_fn;
    emf_cbase_module_loader_interface_get_runtime_dependencies_fn_t EMF_CBASE_NOT_NULL get_runtime_dependencies_fn;
    emf_cbase_module_loader_interface_get_exportable_interfaces_fn_t EMF_CBASE_NOT_NULL get_exportable_interfaces_fn;
    emf_cbase_module_loader_interface_get_internal_interface_fn_t EMF_CBASE_NOT_NULL get_internal_interface_fn;
} emf_cbase_module_loader_interface_t;

EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_loader_interface_result_t,
    const emf_cbase_module_loader_interface_t* EMF_CBASE_NOT_NULL, emf_cbase_module_error_t)

// native module interface
typedef struct emf_cbase_native_module_t emf_cbase_native_module_t;
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_native_module_ptr_result_t, emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL, emf_cbase_module_error_t)

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_load_fn_t, EMF_CBASE_NODISCARD emf_cbase_native_module_ptr_result_t,
    emf_cbase_module_handle_t module_handle, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_sys_has_function_fn_t EMF_CBASE_NOT_NULL has_function_fn,
    emf_cbase_sys_get_function_fn_t EMF_CBASE_NOT_NULL get_function_fn)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_unload_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_initialize_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_terminate_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_interface_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_module_interface_result_t, emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_module_info_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_module_info_ptr_result_t, emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_load_dependencies_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_t, void)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_runtime_dependencies_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_exportable_interfaces_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)

typedef struct emf_cbase_native_module_interface_t {
    emf_cbase_native_module_interface_load_fn_t EMF_CBASE_NOT_NULL load_fn;
    emf_cbase_native_module_interface_unload_fn_t EMF_CBASE_NOT_NULL unload_fn;
    emf_cbase_native_module_interface_initialize_fn_t EMF_CBASE_NOT_NULL initialize_fn;
    emf_cbase_native_module_interface_terminate_fn_t EMF_CBASE_NOT_NULL terminate_fn;
    emf_cbase_native_module_interface_get_interface_fn_t EMF_CBASE_NOT_NULL get_interface_fn;
    emf_cbase_native_module_interface_get_module_info_fn_t EMF_CBASE_NOT_NULL get_module_info_fn;
    emf_cbase_native_module_interface_get_load_dependencies_fn_t EMF_CBASE_NOT_NULL get_load_dependencies_fn;
    emf_cbase_native_module_interface_get_runtime_dependencies_fn_t EMF_CBASE_NOT_NULL get_runtime_dependencies_fn;
    emf_cbase_native_module_interface_get_exportable_interfaces_fn_t EMF_CBASE_NOT_NULL get_exportable_interfaces_fn;
} emf_cbase_native_module_interface_t;

// native module loader interface
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_loader_interface_get_native_module_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_native_module_ptr_result_t, emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader,
    emf_cbase_internal_module_handle_t module_handle)

typedef struct emf_cbase_native_module_loader_interface_t {
    const emf_cbase_module_loader_interface_t* EMF_CBASE_NOT_NULL module_loader_interface;
    emf_cbase_native_module_loader_interface_get_native_module_fn_t EMF_CBASE_NOT_NULL get_native_module_fn;
} emf_cbase_native_module_loader_interface_t;

// module api
// loader management
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_register_loader_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_module_loader_interface_t* EMF_CBASE_NOT_NULL loader_interface,
    const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unregister_loader_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_loader_handle_t loader_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_loader_interface_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_module_loader_interface_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_module_loader_handle_t loader_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_loader_handle_from_type_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_loader_handle_from_module_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_module_handle_t module_handle)

// queries
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_module_get_num_modules_fn_t, EMF_CBASE_NODISCARD size_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_module_get_num_loaders_fn_t, EMF_CBASE_NODISCARD size_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_module_get_num_exported_interfaces_fn_t, EMF_CBASE_NODISCARD size_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_module_exists_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_type_exists_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_exported_interface_exists_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_modules_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_info_span_t* EMF_CBASE_NOT_NULL buffer)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_module_types_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_type_span_t* EMF_CBASE_NOT_NULL buffer)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_exported_interfaces_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_interface_descriptor_span_t* EMF_CBASE_NOT_NULL buffer)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_exported_interface_handle_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_module_handle_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface)

// internal module management
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_create_module_handle_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_handle_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_remove_module_handle_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_link_module_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    emf_cbase_module_loader_handle_t loader_handle, emf_cbase_internal_module_handle_t internal_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_internal_module_handle_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_internal_module_handle_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_module_handle_t module_handle)

// module management
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_add_module_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_loader_handle_t loader_handle,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL module_path)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_remove_module_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_load_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unload_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_initialize_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_terminate_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_add_dependency_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_remove_dependency_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_export_interface_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_load_dependencies_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_runtime_dependencies_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_exportable_interfaces_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_fetch_status_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_status_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_module_path_fn_t, EMF_CBASE_NODISCARD emf_cbase_os_path_char_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_module_info_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_info_ptr_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_interface_fn_t, EMF_CBASE_NODISCARD emf_cbase_module_interface_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CBASE_EMF_CBASE_MODULE_H
