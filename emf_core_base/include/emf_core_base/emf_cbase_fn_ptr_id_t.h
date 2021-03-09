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

#ifdef EMF_CBASE_USE_ENUMS
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

    emf_cbase_fn_ptr_id_ext_get_unwind_internal_interface = 51,
} emf_cbase_fn_ptr_id_t;
#else
typedef int32_t emf_cbase_fn_ptr_id_t;

#define emf_cbase_fn_ptr_id_sys_shutdown (emf_cbase_fn_ptr_id_t)1
#define emf_cbase_fn_ptr_id_sys_panic (emf_cbase_fn_ptr_id_t)2
#define emf_cbase_fn_ptr_id_sys_has_function (emf_cbase_fn_ptr_id_t)3
#define emf_cbase_fn_ptr_id_sys_get_function (emf_cbase_fn_ptr_id_t)4
#define emf_cbase_fn_ptr_id_sys_lock (emf_cbase_fn_ptr_id_t)5
#define emf_cbase_fn_ptr_id_sys_try_lock (emf_cbase_fn_ptr_id_t)6
#define emf_cbase_fn_ptr_id_sys_unlock (emf_cbase_fn_ptr_id_t)7
#define emf_cbase_fn_ptr_id_sys_get_sync_handler (emf_cbase_fn_ptr_id_t)8
#define emf_cbase_fn_ptr_id_sys_set_sync_handler (emf_cbase_fn_ptr_id_t)9

#define emf_cbase_fn_ptr_id_version_new_short (emf_cbase_fn_ptr_id_t)101
#define emf_cbase_fn_ptr_id_version_new_long (emf_cbase_fn_ptr_id_t)102
#define emf_cbase_fn_ptr_id_version_new_full (emf_cbase_fn_ptr_id_t)103
#define emf_cbase_fn_ptr_id_version_from_string (emf_cbase_fn_ptr_id_t)104
#define emf_cbase_fn_ptr_id_version_string_length_short (emf_cbase_fn_ptr_id_t)105
#define emf_cbase_fn_ptr_id_version_string_length_long (emf_cbase_fn_ptr_id_t)106
#define emf_cbase_fn_ptr_id_version_string_length_full (emf_cbase_fn_ptr_id_t)107
#define emf_cbase_fn_ptr_id_version_as_string_short (emf_cbase_fn_ptr_id_t)108
#define emf_cbase_fn_ptr_id_version_as_string_long (emf_cbase_fn_ptr_id_t)109
#define emf_cbase_fn_ptr_id_version_as_string_full (emf_cbase_fn_ptr_id_t)110
#define emf_cbase_fn_ptr_id_version_string_is_valid (emf_cbase_fn_ptr_id_t)111
#define emf_cbase_fn_ptr_id_version_compare (emf_cbase_fn_ptr_id_t)112
#define emf_cbase_fn_ptr_id_version_compare_weak (emf_cbase_fn_ptr_id_t)113
#define emf_cbase_fn_ptr_id_version_compare_strong (emf_cbase_fn_ptr_id_t)114
#define emf_cbase_fn_ptr_id_version_is_compatible (emf_cbase_fn_ptr_id_t)115

#define emf_cbase_fn_ptr_id_library_register_loader (emf_cbase_fn_ptr_id_t)201
#define emf_cbase_fn_ptr_id_library_unregister_loader (emf_cbase_fn_ptr_id_t)202
#define emf_cbase_fn_ptr_id_library_get_loader_interface (emf_cbase_fn_ptr_id_t)203
#define emf_cbase_fn_ptr_id_library_get_loader_handle_from_type (emf_cbase_fn_ptr_id_t)204
#define emf_cbase_fn_ptr_id_library_get_loader_handle_from_library (emf_cbase_fn_ptr_id_t)205
#define emf_cbase_fn_ptr_id_library_get_num_loaders (emf_cbase_fn_ptr_id_t)206
#define emf_cbase_fn_ptr_id_library_library_exists (emf_cbase_fn_ptr_id_t)207
#define emf_cbase_fn_ptr_id_library_type_exists (emf_cbase_fn_ptr_id_t)208
#define emf_cbase_fn_ptr_id_library_get_library_types (emf_cbase_fn_ptr_id_t)209
#define emf_cbase_fn_ptr_id_library_create_library_handle (emf_cbase_fn_ptr_id_t)210
#define emf_cbase_fn_ptr_id_library_remove_library_handle (emf_cbase_fn_ptr_id_t)211
#define emf_cbase_fn_ptr_id_library_link_library (emf_cbase_fn_ptr_id_t)212
#define emf_cbase_fn_ptr_id_library_get_internal_library_handle (emf_cbase_fn_ptr_id_t)213
#define emf_cbase_fn_ptr_id_library_load (emf_cbase_fn_ptr_id_t)214
#define emf_cbase_fn_ptr_id_library_unload (emf_cbase_fn_ptr_id_t)215
#define emf_cbase_fn_ptr_id_library_get_data_symbol (emf_cbase_fn_ptr_id_t)216
#define emf_cbase_fn_ptr_id_library_get_function_symbol (emf_cbase_fn_ptr_id_t)217

#define emf_cbase_fn_ptr_id_module_register_loader (emf_cbase_fn_ptr_id_t)301
#define emf_cbase_fn_ptr_id_module_unregister_loader (emf_cbase_fn_ptr_id_t)302
#define emf_cbase_fn_ptr_id_module_get_loader_interface (emf_cbase_fn_ptr_id_t)303
#define emf_cbase_fn_ptr_id_module_get_loader_handle_from_type (emf_cbase_fn_ptr_id_t)304
#define emf_cbase_fn_ptr_id_module_get_loader_handle_from_module (emf_cbase_fn_ptr_id_t)305
#define emf_cbase_fn_ptr_id_module_get_num_modules (emf_cbase_fn_ptr_id_t)306
#define emf_cbase_fn_ptr_id_module_get_num_loaders (emf_cbase_fn_ptr_id_t)307
#define emf_cbase_fn_ptr_id_module_get_num_exported_interfaces (emf_cbase_fn_ptr_id_t)308
#define emf_cbase_fn_ptr_id_module_module_exists (emf_cbase_fn_ptr_id_t)309
#define emf_cbase_fn_ptr_id_module_type_exists (emf_cbase_fn_ptr_id_t)310
#define emf_cbase_fn_ptr_id_module_exported_interface_exists (emf_cbase_fn_ptr_id_t)311
#define emf_cbase_fn_ptr_id_module_get_modules (emf_cbase_fn_ptr_id_t)312
#define emf_cbase_fn_ptr_id_module_get_module_types (emf_cbase_fn_ptr_id_t)313
#define emf_cbase_fn_ptr_id_module_get_exported_interfaces (emf_cbase_fn_ptr_id_t)314
#define emf_cbase_fn_ptr_id_module_get_exported_interface_handle (emf_cbase_fn_ptr_id_t)315
#define emf_cbase_fn_ptr_id_module_create_module_handle (emf_cbase_fn_ptr_id_t)316
#define emf_cbase_fn_ptr_id_module_remove_module_handle (emf_cbase_fn_ptr_id_t)317
#define emf_cbase_fn_ptr_id_module_link_module (emf_cbase_fn_ptr_id_t)318
#define emf_cbase_fn_ptr_id_module_get_internal_module_handle (emf_cbase_fn_ptr_id_t)319
#define emf_cbase_fn_ptr_id_module_add_module (emf_cbase_fn_ptr_id_t)320
#define emf_cbase_fn_ptr_id_module_remove_module (emf_cbase_fn_ptr_id_t)321
#define emf_cbase_fn_ptr_id_module_load (emf_cbase_fn_ptr_id_t)322
#define emf_cbase_fn_ptr_id_module_unload (emf_cbase_fn_ptr_id_t)323
#define emf_cbase_fn_ptr_id_module_initialize (emf_cbase_fn_ptr_id_t)324
#define emf_cbase_fn_ptr_id_module_terminate (emf_cbase_fn_ptr_id_t)325
#define emf_cbase_fn_ptr_id_module_add_dependency (emf_cbase_fn_ptr_id_t)326
#define emf_cbase_fn_ptr_id_module_remove_dependency (emf_cbase_fn_ptr_id_t)327
#define emf_cbase_fn_ptr_id_module_export_interface (emf_cbase_fn_ptr_id_t)328
#define emf_cbase_fn_ptr_id_module_get_load_dependencies (emf_cbase_fn_ptr_id_t)329
#define emf_cbase_fn_ptr_id_module_get_runtime_dependencies (emf_cbase_fn_ptr_id_t)330
#define emf_cbase_fn_ptr_id_module_get_exportable_interfaces (emf_cbase_fn_ptr_id_t)331
#define emf_cbase_fn_ptr_id_module_fetch_status (emf_cbase_fn_ptr_id_t)332
#define emf_cbase_fn_ptr_id_module_get_module_path (emf_cbase_fn_ptr_id_t)333
#define emf_cbase_fn_ptr_id_module_get_module_info (emf_cbase_fn_ptr_id_t)334
#define emf_cbase_fn_ptr_id_module_get_interface (emf_cbase_fn_ptr_id_t)335

#define emf_cbase_fn_ptr_id_ext_get_unwind_internal_interface (emf_cbase_fn_ptr_id_t)51
#endif // EMF_CBASE_USE_ENUMS

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BASE_EMF_CBASE_FN_PTR_ID_T_H