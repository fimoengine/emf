#ifndef EMF_CORE_BASE_EMF_CBASE_INTERFACE_T_H
#define EMF_CORE_BASE_EMF_CBASE_INTERFACE_T_H

#include <emf_core_base/emf_cbase_library.h>
#include <emf_core_base/emf_cbase_macros.h>
#include <emf_core_base/emf_cbase_module.h>
#include <emf_core_base/emf_cbase_sys.h>
#include <emf_core_base/emf_cbase_version_t.h>

#define EMF_CORE_BASE_INTERFACE_NAME "emf::core_base"

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

typedef struct emf_cbase_interface_t {
    emf_cbase_version_t interface_version;
    emf_cbase_t* cbase;

    emf_cbase_sys_shutdown_fn_t sys_shutdown_fn;
    emf_cbase_sys_panic_fn_t sys_panic_fn;
    emf_cbase_sys_has_function_fn_t sys_has_function_fn;
    emf_cbase_sys_get_function_fn_t sys_get_function_fn;
    emf_cbase_sys_lock_fn_t sys_lock_fn;
    emf_cbase_sys_try_lock_fn_t sys_try_lock_fn;
    emf_cbase_sys_unlock_fn_t sys_unlock_fn;
    emf_cbase_sys_get_sync_handler_fn_t sys_get_sync_handler_fn;
    emf_cbase_sys_set_sync_handler_fn_t sys_set_sync_handler_fn;

    emf_cbase_version_new_short_fn_t version_new_short_fn;
    emf_cbase_version_new_long_fn_t version_new_long_fn;
    emf_cbase_version_new_full_fn_t version_new_full_fn;
    emf_cbase_version_from_string_fn_t version_from_string_fn;
    emf_cbase_version_string_length_short_fn_t version_string_length_short_fn;
    emf_cbase_version_string_length_long_fn_t version_string_length_long_fn;
    emf_cbase_version_string_length_full_fn_t version_string_length_full_fn;
    emf_cbase_version_as_string_short_fn_t version_as_string_short_fn;
    emf_cbase_version_as_string_long_fn_t version_as_string_long_fn;
    emf_cbase_version_as_string_full_fn_t version_as_string_full_fn;
    emf_cbase_version_string_is_valid_fn_t version_string_is_valid_fn;
    emf_cbase_version_compare_fn_t version_compare_fn;
    emf_cbase_version_compare_weak_fn_t version_compare_weak_fn;
    emf_cbase_version_compare_strong_fn_t version_compare_strong_fn;
    emf_cbase_version_is_compatible_fn_t version_is_compatible_fn;

    emf_cbase_library_register_loader_fn_t library_register_loader_fn;
    emf_cbase_library_unregister_loader_fn_t library_unregister_loader_fn;
    emf_cbase_library_get_loader_interface_fn_t library_get_loader_interface_fn;
    emf_cbase_library_get_loader_handle_from_type_fn_t library_get_loader_handle_from_type_fn;
    emf_cbase_library_get_loader_handle_from_library_fn_t library_get_loader_handle_from_library_fn;
    emf_cbase_library_get_num_loaders_fn_t library_get_num_loaders_fn;
    emf_cbase_library_library_exists_fn_t library_library_exists_fn;
    emf_cbase_library_type_exists_fn_t library_type_exists_fn;
    emf_cbase_library_get_library_types_fn_t library_get_library_types_fn;
    emf_cbase_library_create_library_handle_fn_t library_create_library_handle_fn;
    emf_cbase_library_remove_library_handle_fn_t library_remove_library_handle_fn;
    emf_cbase_library_link_library_fn_t library_link_library_fn;
    emf_cbase_library_get_internal_library_handle_fn_t library_get_internal_library_handle_fn;
    emf_cbase_library_load_fn_t library_load_fn;
    emf_cbase_library_unload_fn_t library_unload_fn;
    emf_cbase_library_get_data_symbol_fn_t library_get_data_symbol_fn;
    emf_cbase_library_get_function_symbol_fn_t library_get_function_symbol_fn;

    emf_cbase_module_register_loader_fn_t module_register_loader_fn;
    emf_cbase_module_unregister_loader_fn_t module_unregister_loader_fn;
    emf_cbase_module_get_loader_interface_fn_t module_get_loader_interface_fn;
    emf_cbase_module_get_loader_handle_from_type_fn_t module_get_loader_handle_from_type_fn;
    emf_cbase_module_get_loader_handle_from_module_fn_t module_get_loader_handle_from_module_fn;
    emf_cbase_module_get_num_modules_fn_t module_get_num_modules_fn;
    emf_cbase_module_get_num_loaders_fn_t module_get_num_loaders_fn;
    emf_cbase_module_get_num_exported_interfaces_fn_t module_get_num_exported_interfaces_fn;
    emf_cbase_module_module_exists_fn_t module_module_exists_fn;
    emf_cbase_module_type_exists_fn_t module_type_exists_fn;
    emf_cbase_module_exported_interface_exists_fn_t module_exported_interface_exists_fn;
    emf_cbase_module_get_modules_fn_t module_get_modules_fn;
    emf_cbase_module_get_module_types_fn_t module_get_module_types_fn;
    emf_cbase_module_get_exported_interfaces_fn_t module_get_exported_interfaces_fn;
    emf_cbase_module_get_exported_interface_handle_fn_t module_get_exported_interface_handle_fn;
    emf_cbase_module_create_module_handle_fn_t module_create_module_handle_fn;
    emf_cbase_module_remove_module_handle_fn_t module_remove_module_handle_fn;
    emf_cbase_module_link_module_fn_t module_link_module_fn;
    emf_cbase_module_get_internal_module_handle_fn_t module_get_internal_module_handle_fn;
    emf_cbase_module_add_module_fn_t module_add_module_fn;
    emf_cbase_module_remove_module_fn_t module_remove_module_fn;
    emf_cbase_module_load_fn_t module_load_fn;
    emf_cbase_module_unload_fn_t module_unload_fn;
    emf_cbase_module_initialize_fn_t module_initialize_fn;
    emf_cbase_module_terminate_fn_t module_terminate_fn;
    emf_cbase_module_add_dependency_fn_t module_add_dependency_fn;
    emf_cbase_module_remove_dependency_fn_t module_remove_dependency_fn;
    emf_cbase_module_export_interface_fn_t module_export_interface_fn;
    emf_cbase_module_get_load_dependencies_fn_t module_get_load_dependencies_fn;
    emf_cbase_module_get_runtime_dependencies_fn_t module_get_runtime_dependencies_fn;
    emf_cbase_module_get_exportable_interfaces_fn_t module_get_exportable_interfaces_fn;
    emf_cbase_module_fetch_status_fn_t module_fetch_status_fn;
    emf_cbase_module_get_module_path_fn_t module_get_module_path_fn;
    emf_cbase_module_get_module_info_fn_t module_get_module_info_fn;
    emf_cbase_module_get_interface_fn_t module_get_interface_fn;
} emf_cbase_interface_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BASE_EMF_CBASE_INTERFACE_T_H
