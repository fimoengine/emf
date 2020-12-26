#ifndef EMF_CORE_BASE_EMF_CBASE_FN_PTR_ID_T_H
#define EMF_CORE_BASE_EMF_CBASE_FN_PTR_ID_T_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif // __cplusplus

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

/// Id's of the exported functions.
///
/// The values `0-1000` are reserved for future use.
typedef enum emf_cbase_fn_ptr_id_t : int32_t {
    // EMF_CBASE_SYS_H
    /// Id of `emf_cbase_sys_lock`
    emf_cbase_fn_ptr_id_sys_lock = 1,
    /// Id of `emf_cbase_sys_try_lock`
    emf_cbase_fn_ptr_id_sys_try_lock = 2,
    /// Id of `emf_cbase_sys_unlock`
    emf_cbase_fn_ptr_id_sys_unlock = 3,
    /// Id of `emf_cbase_sys_shutdown`
    emf_cbase_fn_ptr_id_sys_shutdown = 4,
    /// Id of `emf_cbase_sys_panic`
    emf_cbase_fn_ptr_id_sys_panic = 5,
    /// Id of `emf_cbase_sys_has_function`
    emf_cbase_fn_ptr_id_sys_has_function = 6,
    /// Id of `emf_cbase_sys_get_function`
    emf_cbase_fn_ptr_id_sys_get_function = 7,
    /// Id of `emf_cbase_sys_get_sync_handler`
    emf_cbase_fn_ptr_id_sys_get_sync_handler = 8,
    /// Id of `emf_cbase_sys_set_sync_handler`
    emf_cbase_fn_ptr_id_sys_set_sync_handler = 9,

    // EMF_CBASE_VERSION_T_H
    /// Id of `emf_cbase_version_construct_short`
    emf_cbase_fn_ptr_id_version_construct_short = 101,
    /// Id of `emf_cbase_version_construct_long`
    emf_cbase_fn_ptr_id_version_construct_long = 102,
    /// Id of `emf_cbase_version_construct_full`
    emf_cbase_fn_ptr_id_version_construct_full = 103,
    /// Id of `emf_cbase_version_construct_from_string`
    emf_cbase_fn_ptr_id_version_construct_from_string = 104,
    /// Id of `emf_cbase_version_representation_is_valid`
    emf_cbase_fn_ptr_id_version_representation_is_valid = 105,
    /// Id of `emf_cbase_version_get_short_representation`
    emf_cbase_fn_ptr_id_version_get_short_representation = 106,
    /// Id of `emf_cbase_version_get_short_representation_length`
    emf_cbase_fn_ptr_id_version_get_short_representation_length = 107,
    /// Id of `emf_cbase_version_get_long_representation`
    emf_cbase_fn_ptr_id_version_get_long_representation = 108,
    /// Id of `emf_cbase_version_get_long_representation_length`
    emf_cbase_fn_ptr_id_version_get_long_representation_length = 109,
    /// Id of `emf_cbase_version_get_full_representation`
    emf_cbase_fn_ptr_id_version_get_full_representation = 110,
    /// Id of `emf_cbase_version_get_full_representation_length`
    emf_cbase_fn_ptr_id_version_get_full_representation_length = 111,
    /// Id of `emf_cbase_version_compare`
    emf_cbase_fn_ptr_id_version_compare = 112,
    /// Id of `emf_cbase_version_compare_weak`
    emf_cbase_fn_ptr_id_version_compare_weak = 113,
    /// Id of `emf_cbase_version_compare_strong`
    emf_cbase_fn_ptr_id_version_compare_strong = 114,
    /// Id of `emf_cbase_version_is_compatible`
    emf_cbase_fn_ptr_id_version_is_compatible = 115,

    // EMF_CBASE_LIBRARY_H
    /// Id of `emf_cbase_library_register_loader`
    emf_cbase_fn_ptr_id_library_register_loader = 201,
    /// Id of `emf_cbase_library_unregister_loader`
    emf_cbase_fn_ptr_id_library_unregister_loader = 202,
    /// Id of `emf_cbase_library_get_num_loaders`
    emf_cbase_fn_ptr_id_library_get_num_loaders = 203,
    /// Id of `emf_cbase_library_get_library_types`
    emf_cbase_fn_ptr_id_library_get_library_types = 204,
    /// Id of `emf_cbase_library_get_loader_handle`
    emf_cbase_fn_ptr_id_library_get_loader_handle = 205,
    /// Id of `emf_cbase_library_type_exists`
    emf_cbase_fn_ptr_id_library_type_exists = 206,
    /// Id of `emf_cbase_library_library_exists`
    emf_cbase_fn_ptr_id_library_library_exists = 207,
    /// Id of `emf_cbase_library_unsafe_create_library_handle`
    emf_cbase_fn_ptr_id_library_unsafe_create_library_handle = 208,
    /// Id of `emf_cbase_library_unsafe_remove_library_handle`
    emf_cbase_fn_ptr_id_library_unsafe_remove_library_handle = 209,
    /// Id of `emf_cbase_library_unsafe_link_library`
    emf_cbase_fn_ptr_id_library_unsafe_link_library = 210,
    /// Id of `emf_cbase_library_unsafe_get_loader_library_handle`
    emf_cbase_fn_ptr_id_library_unsafe_get_loader_library_handle = 211,
    /// Id of `emf_cbase_cbase_library_unsafe_get_loader_handle`
    emf_cbase_fn_ptr_id_library_unsafe_get_loader_handle = 212,
    /// Id of `emf_cbase_library_unsafe_get_loader_interface`
    emf_cbase_fn_ptr_id_library_unsafe_get_loader_interface = 213,
    /// Id of `emf_cbase_library_load`
    emf_cbase_fn_ptr_id_library_load = 214,
    /// Id of `emf_cbase_library_unload`
    emf_cbase_fn_ptr_id_library_unload = 215,
    /// Id of `emf_cbase_library_get_data_symbol`
    emf_cbase_fn_ptr_id_library_get_data_symbol = 216,
    /// Id of `emf_cbase_library_get_function_symbol`
    emf_cbase_fn_ptr_id_library_get_function_symbol = 217,

    // EMF_CBASE_MODULE_H
    /// Id of `emf_cbase_module_register_loader`
    emf_cbase_fn_ptr_id_module_register_loader = 301,
    /// Id of `emf_cbase_module_unregister_loader`
    emf_cbase_fn_ptr_id_module_unregister_loader = 302,
    /// Id of `emf_cbase_module_get_num_loaders`
    emf_cbase_fn_ptr_id_module_get_num_loaders = 303,
    /// Id of `emf_cbase_module_get_module_types`
    emf_cbase_fn_ptr_id_module_get_module_types = 304,
    /// Id of `emf_cbase_module_get_num_modules`
    emf_cbase_fn_ptr_id_module_get_num_modules = 305,
    /// Id of `emf_cbase_module_get_modules`
    emf_cbase_fn_ptr_id_module_get_modules = 306,
    /// Id of `emf_cbase_module_get_num_exported_interfaces`
    emf_cbase_fn_ptr_id_module_get_num_exported_interfaces = 307,
    /// Id of `emf_cbase_module_get_exported_interfaces`
    emf_cbase_fn_ptr_id_module_get_exported_interfaces = 308,
    /// Id of `emf_cbase_module_get_loader_handle`
    emf_cbase_fn_ptr_id_module_get_loader_handle = 309,
    /// Id of `emf_cbase_module_type_exists`
    emf_cbase_fn_ptr_id_module_type_exists = 310,
    /// Id of `emf_cbase_module_module_exists`
    emf_cbase_fn_ptr_id_module_module_exists = 311,
    /// Id of `emf_cbase_module_get_exported_interface_handle`
    emf_cbase_fn_ptr_id_module_get_exported_interface_handle = 312,
    /// Id of `emf_cbase_module_exported_interface_exists`
    emf_cbase_fn_ptr_id_module_exported_interface_exists = 313,
    /// Id of `emf_cbase_module_unsafe_create_module_handle`
    emf_cbase_fn_ptr_id_module_unsafe_create_module_handle = 314,
    /// Id of `emf_cbase_module_unsafe_remove_module_handle`
    emf_cbase_fn_ptr_id_module_unsafe_remove_module_handle = 315,
    /// Id of `emf_cbase_module_unsafe_link_module`
    emf_cbase_fn_ptr_id_module_unsafe_link_module = 316,
    /// Id of `emf_cbase_module_unsafe_get_loader_module_handle`
    emf_cbase_fn_ptr_id_module_unsafe_get_loader_module_handle = 317,
    /// Id of `emf_cbase_module_unsafe_get_loader_handle`
    emf_cbase_fn_ptr_id_module_unsafe_get_loader_handle = 318,
    /// Id of `emf_cbase_module_unsafe_get_loader`
    emf_cbase_fn_ptr_id_module_unsafe_get_loader = 319,
    /// Id of `emf_cbase_module_add_module`
    emf_cbase_fn_ptr_id_module_add_module = 320,
    /// Id of `emf_cbase_module_remove_module`
    emf_cbase_fn_ptr_id_module_remove_module = 321,
    /// Id of `emf_cbase_module_get_load_dependencies`
    emf_cbase_fn_ptr_id_module_get_load_dependencies = 322,
    /// Id of `emf_cbase_module_fetch_status`
    emf_cbase_fn_ptr_id_module_fetch_status = 323,
    /// Id of `emf_cbase_module_add_dependency`
    emf_cbase_fn_ptr_id_module_add_dependency = 324,
    /// Id of `emf_cbase_module_remove_dependency`
    emf_cbase_fn_ptr_id_module_remove_dependency = 325,
    /// Id of `emf_cbase_module_export_interface`
    emf_cbase_fn_ptr_id_module_export_interface = 326,
    /// Id of `emf_cbase_module_load`
    emf_cbase_fn_ptr_id_module_load = 327,
    /// Id of `emf_cbase_module_unload`
    emf_cbase_fn_ptr_id_module_unload = 328,
    /// Id of `emf_cbase_module_initialize`
    emf_cbase_fn_ptr_id_module_initialize = 329,
    /// Id of `emf_cbase_module_terminate`
    emf_cbase_fn_ptr_id_module_terminate = 330,
    /// Id of `emf_cbase_module_get_module_info`
    emf_cbase_fn_ptr_id_module_get_module_info = 331,
    /// Id of `emf_cbase_module_get_exportable_interfaces`
    emf_cbase_fn_ptr_id_module_get_exportable_interfaces = 332,
    /// Id of `emf_cbase_module_get_runtime_dependencies`
    emf_cbase_fn_ptr_id_module_get_runtime_dependencies = 333,
    /// Id of `emf_cbase_module_get_interface`
    emf_cbase_fn_ptr_id_module_get_interface = 334,
    /// Id of `emf_cbase_module_get_module_path`
    emf_cbase_fn_ptr_id_module_get_module_path = 335,
} emf_cbase_fn_ptr_id_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BASE_EMF_CBASE_FN_PTR_ID_T_H