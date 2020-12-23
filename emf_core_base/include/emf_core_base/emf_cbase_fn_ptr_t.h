#ifndef EMF_CORE_BASE_EMF_CBASE_FN_PTR_T_H
#define EMF_CORE_BASE_EMF_CBASE_FN_PTR_T_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_bool_t.h>
#include <emf_core_base/emf_cbase_fn_ptr_id_t.h>
#include <emf_core_base/emf_cbase_library.h>
#include <emf_core_base/emf_cbase_macros.h>
#include <emf_core_base/emf_cbase_module.h>
#include <emf_core_base/emf_cbase_sys.h>
#include <emf_core_base/emf_cbase_version_t.h>

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

/// An opaque structure representing the emf-core-base interface.
typedef struct emf_cbase_t emf_cbase_t;

/// A type-erased function pointer.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase, void, void)

/******************************************************************************************************
******************************************  EMF_CBASE_SYS_H  ******************************************
******************************************************************************************************/

/// Function pointer to the `emf_cbase_sys_lock` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_lock, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_sys_try_lock` function.
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_sys_try_lock, EMF_CBASE_NODISCARD emf_cbase_bool_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_sys_unlock` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_unlock, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_sys_shutdown` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_shutdown, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_sys_panic` function.
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_sys_panic, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const char* EMF_CBASE_MAYBE_NULL error)

/// Function pointer to the `emf_cbase_sys_has_function` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_has_function, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_fn_ptr_id_t fn_id)

/// Function pointer to the `emf_cbase_sys_get_function` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_get_function, EMF_CBASE_NODISCARD emf_cbase_sys_fn_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_fn_ptr_id_t fn_id)

/// Function pointer to the `emf_cbase_sys_get_sync_handler` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_get_sync_handler,
    EMF_CBASE_NODISCARD const emf_sync_handler_interface_t* EMF_CBASE_NOT_NULL, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_sys_set_sync_handler` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_set_sync_handler, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_sync_handler_interface_t* EMF_CBASE_MAYBE_NULL sync_handler)

/******************************************************************************************************
***************************************  EMF_CBASE_VERSION_T_H  ***************************************
******************************************************************************************************/

/// Function pointer to the `emf_cbase_version_construct_short` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_construct_short, EMF_CBASE_NODISCARD emf_cbase_version_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, int32_t major, int32_t minor, int32_t patch)

/// Function pointer to the `emf_cbase_version_construct_long` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_construct_long, EMF_CBASE_NODISCARD emf_cbase_version_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, int32_t major, int32_t minor, int32_t patch,
    emf_cbase_version_release_t release_type, int8_t release_number)

/// Function pointer to the `emf_cbase_version_construct_full` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_construct_full, EMF_CBASE_NODISCARD emf_cbase_version_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, int32_t major, int32_t minor, int32_t patch,
    emf_cbase_version_release_t release_type, int8_t release_number, int64_t build)

/// Function pointer to the `emf_cbase_version_construct_from_string` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_construct_from_string, EMF_CBASE_NODISCARD emf_cbase_version_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_version_const_string_buffer_t* EMF_CBASE_NOT_NULL version_string)

/// Function pointer to the `emf_cbase_version_representation_is_valid` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_representation_is_valid, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_version_const_string_buffer_t* EMF_CBASE_NOT_NULL version_string)

/// Function pointer to the `emf_cbase_version_get_short_representation` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_get_short_representation, EMF_CBASE_NODISCARD emf_cbase_version_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer)

/// Function pointer to the `emf_cbase_version_get_short_representation_length` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_get_short_representation_length, EMF_CBASE_NODISCARD size_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version)

/// Function pointer to the `emf_cbase_version_get_long_representation` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_get_long_representation, EMF_CBASE_NODISCARD emf_cbase_version_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer)

/// Function pointer to the `emf_cbase_version_get_long_representation_length` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_get_long_representation_length, EMF_CBASE_NODISCARD size_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version)

/// Function pointer to the `emf_cbase_version_get_full_representation` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_get_full_representation, EMF_CBASE_NODISCARD emf_cbase_version_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer)

/// Function pointer to the `emf_cbase_version_get_full_representation_length` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_get_full_representation_length, EMF_CBASE_NODISCARD size_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version)

/// Function pointer to the `emf_cbase_version_compare` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_compare, EMF_CBASE_NODISCARD int32_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs, const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs)

/// Function pointer to the `emf_cbase_version_compare_weak` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_compare_weak, EMF_CBASE_NODISCARD int32_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs,
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs)

/// Function pointer to the `emf_cbase_version_compare_strong` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_compare_strong, EMF_CBASE_NODISCARD int32_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs,
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs)

/// Function pointer to the `emf_cbase_version_is_compatible` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_is_compatible, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs,
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs)

/******************************************************************************************************
****************************************  EMF_CBASE_LIBRARY_H  ****************************************
******************************************************************************************************/

/// Function pointer to the `emf_cbase_library_register_loader` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_register_loader, EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_library_loader_interface_t* EMF_CBASE_NOT_NULL loader_interface,
    const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type)

/// Function pointer to the `emf_cbase_library_unregister_loader` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unregister_loader, EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_loader_handle_t loader_handle)

/// Function pointer to the `emf_cbase_library_get_num_loaders` function.
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_library_get_num_loaders, EMF_CBASE_NODISCARD size_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_library_get_library_types` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_library_types, EMF_CBASE_NODISCARD emf_cbase_library_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_type_span_t* EMF_CBASE_NOT_NULL buffer)

/// Function pointer to the `emf_cbase_library_get_loader_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_loader_handle, EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type)

/// Function pointer to the `emf_cbase_library_type_exists` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_type_exists, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type)

/// Function pointer to the `emf_cbase_library_library_exists` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_library_exists, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle)

/// Function pointer to the `emf_cbase_library_unsafe_create_library_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unsafe_create_library_handle, EMF_CBASE_NODISCARD emf_cbase_library_handle_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_library_unsafe_remove_library_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unsafe_remove_library_handle, EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle)

/// Function pointer to the `emf_cbase_library_unsafe_link_library` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unsafe_link_library, EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle,
    emf_cbase_library_loader_handle_t loader_handle, emf_cbase_library_loader_library_handle_t loader_library_handle)

/// Function pointer to the `emf_cbase_library_unsafe_get_loader_library_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unsafe_get_loader_library_handle,
    EMF_CBASE_NODISCARD emf_cbase_library_loader_library_handle_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_library_handle_t library_handle)

/// Function pointer to the `emf_cbase_library_unsafe_get_loader_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unsafe_get_loader_handle, EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle)

/// Function pointer to the `emf_cbase_library_unsafe_get_loader_interface` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unsafe_get_loader_interface,
    EMF_CBASE_NODISCARD emf_cbase_library_loader_interface_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_library_loader_handle_t loader_handle)

/// Function pointer to the `emf_cbase_library_load` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_load, EMF_CBASE_NODISCARD emf_cbase_library_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_loader_handle_t loader_handle,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path)

/// Function pointer to the `emf_cbase_library_unload` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unload, EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle)

/// Function pointer to the `emf_cbase_library_get_data_symbol` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_data_symbol, EMF_CBASE_NODISCARD emf_cbase_library_data_symbol_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle,
    const char* EMF_CBASE_NOT_NULL symbol_name)

/// Function pointer to the `emf_cbase_library_get_function_symbol` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_function_symbol, EMF_CBASE_NODISCARD emf_cbase_library_fn_symbol_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle,
    const char* EMF_CBASE_NOT_NULL symbol_name)

/******************************************************************************************************
*******************************************  EMF_MODULE_H  *******************************************
******************************************************************************************************/

/// Function pointer to the `emf_cbase_module_register_loader` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_register_loader, EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_module_loader_interface_t* EMF_CBASE_NOT_NULL loader_interface,
    const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type)

/// Function pointer to the `emf_cbase_module_unregister_loader` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unregister_loader, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_loader_handle_t loader_handle)

/// Function pointer to the `emf_cbase_module_get_num_loaders` function.
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_module_get_num_loaders, EMF_CBASE_NODISCARD size_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_module_get_module_types` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_module_types, EMF_CBASE_NODISCARD emf_cbase_module_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_type_span_t* EMF_CBASE_NOT_NULL buffer)

/// Function pointer to the `emf_cbase_module_get_num_modules` function.
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_module_get_num_modules, EMF_CBASE_NODISCARD size_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_module_get_modules` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_modules, EMF_CBASE_NODISCARD emf_cbase_module_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_info_span_t* EMF_CBASE_NOT_NULL buffer)

/// Function pointer to the `emf_cbase_module_get_num_exported_interfaces` function.
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_module_get_num_exported_interfaces, EMF_CBASE_NODISCARD size_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_module_get_exported_interfaces` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_exported_interfaces, EMF_CBASE_NODISCARD emf_cbase_module_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_interface_descriptor_span_t* EMF_CBASE_NOT_NULL buffer)

/// Function pointer to the `emf_cbase_module_get_loader_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_loader_handle, EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type)

/// Function pointer to the `emf_cbase_module_type_exists` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_type_exists, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type)

/// Function pointer to the `emf_cbase_module_module_exists` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_module_exists, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_get_exported_interface_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_exported_interface_handle, EMF_CBASE_NODISCARD emf_cbase_module_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface)

/// Function pointer to the `emf_cbase_module_exported_interface_exists` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_exported_interface_exists, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface)

/// Function pointer to the `emf_cbase_module_unsafe_create_module_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unsafe_create_module_handle, EMF_CBASE_NODISCARD emf_cbase_module_handle_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

/// Function pointer to the `emf_cbase_module_unsafe_remove_module_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unsafe_remove_module_handle, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_unsafe_link_module` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unsafe_link_module, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    emf_cbase_module_loader_handle_t loader_handle, emf_cbase_module_loader_module_handle_t loader_module_handle)

/// Function pointer to the `emf_cbase_module_unsafe_get_loader_module_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unsafe_get_loader_module_handle,
    EMF_CBASE_NODISCARD emf_cbase_module_loader_module_handle_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_unsafe_get_loader_handle` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unsafe_get_loader_handle, EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_unsafe_get_loader` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unsafe_get_loader, EMF_CBASE_NODISCARD emf_cbase_module_loader_interface_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_loader_handle_t loader_handle)

/// Function pointer to the `emf_cbase_module_add_module` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_add_module, EMF_CBASE_NODISCARD emf_cbase_module_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_loader_handle_t loader_handle,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL module_path)

/// Function pointer to the `emf_cbase_module_remove_module` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_remove_module, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_get_load_dependencies` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_load_dependencies, EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_span_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_fetch_status` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_fetch_status, EMF_CBASE_NODISCARD emf_cbase_module_status_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_add_dependency` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_add_dependency, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)

/// Function pointer to the `emf_cbase_module_remove_dependency` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_remove_dependency, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)

/// Function pointer to the `emf_cbase_module_export_interface` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_export_interface, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)

/// Function pointer to the `emf_cbase_module_load` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_load, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_unload` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_unload, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_initialize` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_initialize, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_terminate` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_terminate, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_get_module_info` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_module_info, EMF_CBASE_NODISCARD emf_cbase_module_info_ptr_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_get_exportable_interfaces` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_exportable_interfaces,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_span_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_get_runtime_dependencies` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_runtime_dependencies,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_span_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_module_handle_t module_handle)

/// Function pointer to the `emf_cbase_module_get_interface` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_get_interface, EMF_CBASE_NODISCARD emf_cbase_module_interface_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BASE_EMF_CBASE_FN_PTR_T_H
