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

typedef enum emf_cbase_fn_ptr_id_t : int32_t {
    emf_cbase_fn_ptr_id_sys_shutdown = 1,
    emf_cbase_fn_ptr_id_sys_panic = 2,
    emf_cbase_fn_ptr_id_sys_has_function = 3,
    emf_cbase_fn_ptr_id_sys_get_function = 4,
    emf_cbase_fn_ptr_id_sys_lock = 5,
    emf_cbase_fn_ptr_id_sys_try_lock = 6,
    emf_cbase_fn_ptr_id_sys_unlock = 7,
    emf_cbase_fn_ptr_id_sys_get_sync_handler = 8,
    emf_cbase_fn_ptr_id_sys_set_sync_handler = 9,

    emf_cbase_fn_ptr_id_version_new_short = 101,
    emf_cbase_fn_ptr_id_version_new_long = 102,
    emf_cbase_fn_ptr_id_version_new_full = 103,
    emf_cbase_fn_ptr_id_version_from_string = 104,
    emf_cbase_fn_ptr_id_version_string_length_short = 105,
    emf_cbase_fn_ptr_id_version_string_length_long = 106,
    emf_cbase_fn_ptr_id_version_string_length_full = 107,
    emf_cbase_fn_ptr_id_version_as_string_short = 108,
    emf_cbase_fn_ptr_id_version_as_string_long = 109,
    emf_cbase_fn_ptr_id_version_as_string_full = 110,
    emf_cbase_fn_ptr_id_version_string_is_valid = 111,
    emf_cbase_fn_ptr_id_version_compare = 112,
    emf_cbase_fn_ptr_id_version_compare_weak = 113,
    emf_cbase_fn_ptr_id_version_compare_strong = 114,
    emf_cbase_fn_ptr_id_version_is_compatible = 115,

    emf_cbase_fn_ptr_id_library_register_loader = 201,
    emf_cbase_fn_ptr_id_library_unregister_loader = 202,
    emf_cbase_fn_ptr_id_library_get_loader_interface = 203,
    emf_cbase_fn_ptr_id_library_get_loader_handle_from_type = 204,
    emf_cbase_fn_ptr_id_library_get_loader_handle_from_library = 205,
    emf_cbase_fn_ptr_id_library_get_num_loaders = 206,
    emf_cbase_fn_ptr_id_library_library_exists = 207,
    emf_cbase_fn_ptr_id_library_type_exists = 208,
    emf_cbase_fn_ptr_id_library_get_library_types = 209,
    emf_cbase_fn_ptr_id_library_create_library_handle = 210,
    emf_cbase_fn_ptr_id_library_remove_library_handle = 211,
    emf_cbase_fn_ptr_id_library_link_library = 212,
    emf_cbase_fn_ptr_id_library_get_internal_library_handle = 213,
    emf_cbase_fn_ptr_id_library_load = 214,
    emf_cbase_fn_ptr_id_library_unload = 215,
    emf_cbase_fn_ptr_id_library_get_data_symbol = 216,
    emf_cbase_fn_ptr_id_library_get_function_symbol = 217,

    emf_cbase_fn_ptr_id_module_register_loader = 301,
    emf_cbase_fn_ptr_id_module_unregister_loader = 302,
    emf_cbase_fn_ptr_id_module_get_loader_interface = 303,
    emf_cbase_fn_ptr_id_module_get_loader_handle_from_type = 304,
    emf_cbase_fn_ptr_id_module_get_loader_handle_from_module = 305,
    emf_cbase_fn_ptr_id_module_get_num_modules = 306,
    emf_cbase_fn_ptr_id_module_get_num_loaders = 307,
    emf_cbase_fn_ptr_id_module_get_num_exported_interfaces = 308,
    emf_cbase_fn_ptr_id_module_module_exists = 309,
    emf_cbase_fn_ptr_id_module_type_exists = 310,
    emf_cbase_fn_ptr_id_module_exported_interface_exists = 311,
    emf_cbase_fn_ptr_id_module_get_modules = 312,
    emf_cbase_fn_ptr_id_module_get_module_types = 313,
    emf_cbase_fn_ptr_id_module_get_exported_interfaces = 314,
    emf_cbase_fn_ptr_id_module_get_exported_interface_handle = 315,
    emf_cbase_fn_ptr_id_module_create_module_handle = 316,
    emf_cbase_fn_ptr_id_module_remove_module_handle = 317,
    emf_cbase_fn_ptr_id_module_link_module = 318,
    emf_cbase_fn_ptr_id_module_get_internal_module_handle = 319,
    emf_cbase_fn_ptr_id_module_add_module = 320,
    emf_cbase_fn_ptr_id_module_remove_module = 321,
    emf_cbase_fn_ptr_id_module_load = 322,
    emf_cbase_fn_ptr_id_module_unload = 323,
    emf_cbase_fn_ptr_id_module_initialize = 324,
    emf_cbase_fn_ptr_id_module_terminate = 325,
    emf_cbase_fn_ptr_id_module_add_dependency = 326,
    emf_cbase_fn_ptr_id_module_remove_dependency = 327,
    emf_cbase_fn_ptr_id_module_export_interface = 328,
    emf_cbase_fn_ptr_id_module_get_load_dependencies = 329,
    emf_cbase_fn_ptr_id_module_get_runtime_dependencies = 330,
    emf_cbase_fn_ptr_id_module_get_exportable_interfaces = 331,
    emf_cbase_fn_ptr_id_module_fetch_status = 332,
    emf_cbase_fn_ptr_id_module_get_module_path = 333,
    emf_cbase_fn_ptr_id_module_get_module_info = 334,
    emf_cbase_fn_ptr_id_module_get_interface = 335,
} emf_cbase_fn_ptr_id_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BASE_EMF_CBASE_FN_PTR_ID_T_H