#ifndef EMF_CORE_EMF_FN_PTR_ID_T_H
#define EMF_CORE_EMF_FN_PTR_ID_T_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif // __cplusplus

#ifdef __cplusplus
namespace EMF::Core::C {
#endif // __cplusplus

/**
 * Id's of the exposed functions.
 */
typedef enum emf_fn_ptr_id_t : int32_t {
    // EMF_CORE_H
    /// Id of emf_lock()
    emf_fn_ptr_id_lock = 1,
    /// Id of emf_try_lock()
    emf_fn_ptr_id_try_lock = 2,
    /// Id of emf_unlock()
    emf_fn_ptr_id_unlock = 3,
    /// Id of emf_shutdown()
    emf_fn_ptr_id_shutdown = 4,
    /// Id of emf_panic()
    emf_fn_ptr_id_panic = 5,
    /// Id of emf_has_function()
    emf_fn_ptr_id_has_function = 6,
    /// Id of emf_get_function()
    emf_fn_ptr_id_get_function = 7,
    /// Id of emf_get_sync_handler()
    emf_fn_ptr_id_get_sync_handler = 8,
    /// Id of emf_set_sync_handler()
    emf_fn_ptr_id_set_sync_handler = 9,

    // EMF_VERSION_T_H
    /// Id of emf_version_construct_short()
    emf_fn_ptr_id_version_construct_short = 101,
    /// Id of emf_version_construct_long()
    emf_fn_ptr_id_version_construct_long = 102,
    /// Id of emf_version_construct_full()
    emf_fn_ptr_id_version_construct_full = 103,
    /// Id of emf_version_construct_from_string()
    emf_fn_ptr_id_version_construct_from_string = 104,
    /// Id of emf_version_representation_is_valid()
    emf_fn_ptr_id_version_representation_is_valid = 105,
    /// Id of emf_version_get_short_representation()
    emf_fn_ptr_id_version_get_short_representation = 106,
    /// Id of emf_version_get_short_representation_size()
    emf_fn_ptr_id_version_get_short_representation_size = 107,
    /// Id of emf_version_get_long_representation()
    emf_fn_ptr_id_version_get_long_representation = 108,
    /// Id of emf_version_get_long_representation_size()
    emf_fn_ptr_id_version_get_long_representation_size = 109,
    /// Id of emf_version_get_full_representation()
    emf_fn_ptr_id_version_get_full_representation = 110,
    /// Id of emf_version_get_full_representation_size()
    emf_fn_ptr_id_version_get_full_representation_size = 111,
    /// Id of emf_version_compare()
    emf_fn_ptr_id_version_compare = 112,
    /// Id of emf_version_compare_weak()
    emf_fn_ptr_id_version_compare_weak = 113,
    /// Id of emf_version_compare_strong()
    emf_fn_ptr_id_version_compare_strong = 114,
    /// Id of emf_version_is_compatible()
    emf_fn_ptr_id_version_is_compatible = 115,

    // EMF_EVENT_H
    /// Id of emf_event_create()
    emf_fn_ptr_id_event_create = 201,
    /// Id of emf_event_create_private()
    emf_fn_ptr_id_event_create_private = 202,
    /// Id of emf_event_destroy()
    emf_fn_ptr_id_event_destroy = 203,
    /// Id of emf_event_publish()
    emf_fn_ptr_id_event_publish = 204,
    /// Id of emf_event_get_num_public_events()
    emf_fn_ptr_id_event_get_num_public_events = 205,
    /// Id of emf_event_get_public_events()
    emf_fn_ptr_id_event_get_public_events = 206,
    /// Id of emf_event_get_event_handle()
    emf_fn_ptr_id_event_get_event_handle = 207,
    /// Id of emf_event_handle_exists()
    emf_fn_ptr_id_event_handle_exists = 208,
    /// Id of emf_event_name_exists()
    emf_fn_ptr_id_event_name_exists = 209,
    /// Id of emf_event_subscribe_handler()
    emf_fn_ptr_id_event_subscribe_handler = 210,
    /// Id of emf_event_unsubscribe_handler()
    emf_fn_ptr_id_event_unsubscribe_handler = 211,
    /// Id of emf_event_signal()
    emf_fn_ptr_id_event_signal = 212,

    // EMF_FS_H
    /// Id of emf_fs_register_file_handler()
    emf_fn_ptr_id_fs_register_file_handler = 301,
    /// Id of emf_fs_remove_file_handler()
    emf_fn_ptr_id_fs_remove_file_handler = 302,
    /// Id of emf_fs_create_file()
    emf_fn_ptr_id_fs_create_file = 303,
    /// Id of emf_fs_create_link()
    emf_fn_ptr_id_fs_create_link = 304,
    /// Id of emf_fs_create_directory()
    emf_fn_ptr_id_fs_create_directory = 305,
    /// Id of emf_fs_delete()
    emf_fn_ptr_id_fs_delete = 306,
    /// Id of emf_fs_mount_memory_file()
    emf_fn_ptr_id_fs_mount_memory_file = 307,
    /// Id of emf_fs_mount_native_path()
    emf_fn_ptr_id_fs_mount_native_path = 308,
    /// Id of emf_fs_unmount()
    emf_fn_ptr_id_fs_unmount = 309,
    /// Id of emf_fs_set_access_mode()
    emf_fn_ptr_id_fs_set_access_mode = 310,
    /// Id of emf_fs_get_access_mode()
    emf_fn_ptr_id_fs_get_access_mode = 311,
    /// Id of emf_fs_get_mount_id()
    emf_fn_ptr_id_fs_get_mount_id = 312,
    /// Id of emf_fs_can_access()
    emf_fn_ptr_id_fs_can_access = 313,
    /// Id of emf_fs_can_set_access_mode()
    emf_fn_ptr_id_fs_can_set_access_mode = 314,
    /// Id of emf_fs_is_virtual()
    emf_fn_ptr_id_fs_is_virtual = 315,
    /// Id of emf_fs_can_delete()
    emf_fn_ptr_id_fs_can_delete = 316,
    /// Id of emf_fs_can_mount_type()
    emf_fn_ptr_id_fs_can_mount_type = 317,
    /// Id of emf_fs_can_mount_native_path()
    emf_fn_ptr_id_fs_can_mount_native_path = 318,
    /// Id of emf_fs_get_num_entries()
    emf_fn_ptr_id_fs_get_num_entries = 319,
    /// Id of emf_fs_get_entries()
    emf_fn_ptr_id_fs_get_entries = 320,
    /// Id of emf_fs_exists()
    emf_fn_ptr_id_fs_exists = 321,
    /// Id of emf_fs_type_exists()
    emf_fn_ptr_id_fs_type_exists = 322,
    /// Id of emf_fs_get_entry_type()
    emf_fn_ptr_id_fs_get_entry_type = 323,
    /// Id of emf_fs_resolve_link()
    emf_fn_ptr_id_fs_resolve_link = 324,
    /// Id of emf_fs_get_link_type()
    emf_fn_ptr_id_fs_get_link_type = 325,
    /// Id of emf_fs_get_size()
    emf_fn_ptr_id_fs_get_size = 326,
    /// Id of emf_fs_get_native_path_length()
    emf_fn_ptr_id_fs_get_native_path_length = 327,
    /// Id of emf_fs_get_native_path()
    emf_fn_ptr_id_fs_get_native_path = 328,
    /// Id of emf_fs_get_num_file_handlers()
    emf_fn_ptr_id_fs_get_num_file_handlers = 329,
    /// Id of emf_fs_get_file_handlers()
    emf_fn_ptr_id_fs_get_file_handlers = 330,
    /// Id of emf_fs_get_file_handler_from_type()
    emf_fn_ptr_id_fs_get_file_handler_from_type = 331,
    /// Id of emf_fs_get_num_file_types()
    emf_fn_ptr_id_fs_get_num_file_types = 332,
    /// Id of emf_fs_get_file_types()
    emf_fn_ptr_id_fs_get_file_types = 333,
    /// Id of emf_fs_get_num_handler_file_types()
    emf_fn_ptr_id_fs_get_num_handler_file_types = 334,
    /// Id of emf_fs_get_handler_file_types()
    emf_fn_ptr_id_fs_get_handler_file_types = 335,
    /// Id of emf_fs_normalize()
    emf_fn_ptr_id_fs_normalize = 336,
    /// Id of emf_fs_get_parent()
    emf_fn_ptr_id_fs_get_parent = 337,
    /// Id of emf_fs_join()
    emf_fn_ptr_id_fs_join = 338,
    /// Id of emf_fs_unsafe_create_mount_id()
    emf_fn_ptr_id_fs_unsafe_create_mount_id = 339,
    /// Id of emf_fs_unsafe_remove_mount_id()
    emf_fn_ptr_id_fs_unsafe_remove_mount_id = 340,
    /// Id of emf_fs_unsafe_unmount_force()
    emf_fn_ptr_id_fs_unsafe_unmount_force = 341,
    /// Id of emf_fs_unsafe_link_mount_point()
    emf_fn_ptr_id_fs_unsafe_link_mount_point = 342,
    /// Id of emf_fs_unsafe_create_file_stream()
    emf_fn_ptr_id_fs_unsafe_create_file_stream = 343,
    /// Id of emf_fs_unsafe_remove_file_stream()
    emf_fn_ptr_id_fs_unsafe_remove_file_stream = 344,
    /// Id of emf_fs_unsafe_link_file_stream()
    emf_fn_ptr_id_fs_unsafe_link_file_stream = 345,
    /// Id of emf_fs_unsafe_get_file_handler_handle_from_stream()
    emf_fn_ptr_id_fs_unsafe_get_file_handler_from_stream = 346,
    /// Id of emf_fs_unsafe_get_file_handler_handle_from_path()
    emf_fn_ptr_id_fs_unsafe_get_file_handler_from_path = 347,
    /// Id of emf_fs_unsafe_get_file_handler_stream()
    emf_fn_ptr_id_fs_unsafe_get_file_handler_stream = 348,
    /// Id of emf_fs_unsafe_get_file_handler_mount_id()
    emf_fn_ptr_id_fs_unsafe_get_file_handler_mount_id = 349,
    /// Id of emf_fs_unsafe_get_file_handler()
    emf_fn_ptr_id_fs_unsafe_get_file_handler = 350,
    /// Id of emf_fs_stream_open()
    emf_fn_ptr_id_fs_stream_open = 351,
    /// Id of emf_fs_stream_close()
    emf_fn_ptr_id_fs_stream_close = 352,
    /// Id of emf_fs_stream_flush()
    emf_fn_ptr_id_fs_stream_flush = 353,
    /// Id of emf_fs_stream_read()
    emf_fn_ptr_id_fs_stream_read = 354,
    /// Id of emf_fs_stream_write()
    emf_fn_ptr_id_fs_stream_write = 355,
    /// Id of emf_fs_stream_get_pos()
    emf_fn_ptr_id_fs_stream_get_pos = 356,
    /// Id of emf_fs_stream_set_pos()
    emf_fn_ptr_id_fs_stream_set_pos = 357,
    /// Id of emf_fs_stream_move_pos()
    emf_fn_ptr_id_fs_stream_move_pos = 358,
    /// Id of emf_fs_stream_can_write()
    emf_fn_ptr_id_fs_stream_can_write = 359,
    /// Id of emf_fs_stream_can_grow()
    emf_fn_ptr_id_fs_stream_can_grow = 360,

    // EMF_LIBRARY_H
    /// Id of emf_library_register_loader()
    emf_fn_ptr_id_library_register_loader = 401,
    /// Id of emf_library_unregister_loader()
    emf_fn_ptr_id_library_unregister_loader = 402,
    /// Id of emf_library_get_num_loaders()
    emf_fn_ptr_id_library_get_num_loaders = 403,
    /// Id of emf_library_get_library_types()
    emf_fn_ptr_id_library_get_library_types = 404,
    /// Id of emf_library_get_loader_handle
    emf_fn_ptr_id_library_get_loader_handle = 405,
    /// Id of emf_library_type_exists()
    emf_fn_ptr_id_library_type_exists = 406,
    /// Id of emf_library_library_exists()
    emf_fn_ptr_id_library_library_exists = 407,
    /// Id of emf_library_unsafe_create_library_handle()
    emf_fn_ptr_id_library_unsafe_create_library_handle = 408,
    /// Id of emf_library_unsafe_remove_library_handle()
    emf_fn_ptr_id_library_unsafe_remove_library_handle = 409,
    /// Id of emf_library_unsafe_link_library()
    emf_fn_ptr_id_library_unsafe_link_library = 410,
    /// Id of emf_library_unsafe_get_loader_library_handle()
    emf_fn_ptr_id_library_unsafe_get_loader_library_handle = 411,
    /// Id of emf_library_unsafe_get_loader()
    emf_fn_ptr_id_library_unsafe_get_loader = 412,
    /// Id of emf_library_load()
    emf_fn_ptr_id_library_load = 413,
    /// Id of emf_library_unload()
    emf_fn_ptr_id_library_unload = 414,
    /// Id of emf_library_get_symbol()
    emf_fn_ptr_id_library_get_symbol = 415,
    /// Id of emf_library_get_function_symbol()
    emf_fn_ptr_id_library_get_function_symbol = 416,

    // EMF_MODULE_H
    /// Id of emf_module_register_loader()
    emf_fn_ptr_id_module_register_loader = 501,
    /// Id of emf_module_unregister_loader()
    emf_fn_ptr_id_module_unregister_loader = 502,
    /// Id of emf_module_get_num_loaders()
    emf_fn_ptr_id_module_get_num_loaders = 503,
    /// Id of emf_module_get_module_types()
    emf_fn_ptr_id_module_get_module_types = 504,
    /// Id of emf_module_get_num_modules()
    emf_fn_ptr_id_module_get_num_modules = 505,
    /// Id of emf_module_get_modules()
    emf_fn_ptr_id_module_get_modules = 506,
    /// Id of emf_module_get_num_public_interfaces()
    emf_fn_ptr_id_module_get_num_public_interfaces = 507,
    /// Id of emf_module_get_public_interfaces()
    emf_fn_ptr_id_module_get_public_interfaces = 508,
    /// Id of emf_module_get_loader_handle()
    emf_fn_ptr_id_module_get_loader_handle = 509,
    /// Id of emf_module_type_exists()
    emf_fn_ptr_id_module_type_exists = 510,
    /// Id of emf_module_module_exists()
    emf_fn_ptr_id_module_module_exists = 511,
    /// Id of emf_module_get_interface_handle()
    emf_fn_ptr_id_module_get_interface_handle = 512,
    /// Id of emf_module_interface_exists()
    emf_fn_ptr_id_module_interface_exists = 513,
    /// Id of emf_module_unsafe_create_module_handle()
    emf_fn_ptr_id_module_unsafe_create_module_handle = 514,
    /// Id of emf_module_unsafe_remove_module_handle()
    emf_fn_ptr_id_module_unsafe_remove_module_handle = 515,
    /// Id of emf_module_unsafe_link_module()
    emf_fn_ptr_id_module_unsafe_link_module = 516,
    /// Id of emf_module_unsafe_get_loader_module_handle()
    emf_fn_ptr_id_module_unsafe_get_loader_module_handle = 517,
    /// Id of emf_module_unsafe_get_loader()
    emf_fn_ptr_id_module_unsafe_get_loader = 518,
    /// Id of emf_module_load()
    emf_fn_ptr_id_module_load = 519,
    /// Id of emf_module_unload()
    emf_fn_ptr_id_module_unload = 520,
    /// Id of emf_module_initialize()
    emf_fn_ptr_id_module_initialize = 521,
    /// Id of emf_module_terminate()
    emf_fn_ptr_id_module_terminate = 522,
    /// Id of emf_module_get_module_info()
    emf_fn_ptr_id_module_get_module_info = 523,
    /// Id of emf_module_get_exported_interfaces()
    emf_fn_ptr_id_module_get_exported_interfaces = 524,
    /// Id of emf_module_get_imported_interfaces()
    emf_fn_ptr_id_module_get_imported_interfaces = 525,
    /// Id of emf_module_get_interface()
    emf_fn_ptr_id_module_get_interface = 526,

    // EMF_CONFIG_H
    /// Id of emf_config_add_namespace()
    emf_fn_ptr_id_config_add_namespace = 601,
    /// Id of emf_config_remove_namespace()
    emf_fn_ptr_id_config_remove_namespace = 602,
    /// Id of emf_config_add_property_boolean()
    emf_fn_ptr_id_config_add_property_boolean = 603,
    /// Id of emf_config_add_property_integer()
    emf_fn_ptr_id_config_add_property_integer = 604,
    /// Id of emf_config_add_property_real()
    emf_fn_ptr_id_config_add_property_real = 605,
    /// Id of emf_config_add_property_string()
    emf_fn_ptr_id_config_add_property_string = 606,
    /// Id of emf_config_remove_property()
    emf_fn_ptr_id_config_remove_property = 607,
    /// Id of emf_config_get_num_namespaces()
    emf_fn_ptr_id_config_get_num_namespaces = 608,
    /// Id of emf_config_get_namespaces()
    emf_fn_ptr_id_config_get_namespaces = 609,
    /// Id of emf_config_get_num_properties()
    emf_fn_ptr_id_config_get_num_properties = 610,
    /// Id of emf_config_get_properties()
    emf_fn_ptr_id_config_get_properties = 611,
    /// Id of emf_config_namespace_exists()
    emf_fn_ptr_id_config_namespace_exists = 612,
    /// Id of emf_config_property_exists()
    emf_fn_ptr_id_config_property_exists = 613,
    /// Id of emf_config_get_property_type()
    emf_fn_ptr_id_config_get_property_type = 614,
    /// Id of emf_config_get_property_array_size()
    emf_fn_ptr_id_config_get_property_array_size = 615,
    /// Id of emf_config_get_property_string_size()
    emf_fn_ptr_id_config_get_property_string_size = 616,
    /// Id of emf_config_get_property_string_max_size()
    emf_fn_ptr_id_config_get_property_string_max_size = 617,
    /// Id of emf_config_property_read_bool()
    emf_fn_ptr_id_config_property_read_bool = 618,
    /// Id of emf_config_property_read_integer()
    emf_fn_ptr_id_config_property_read_integer = 619,
    /// Id of emf_config_property_read_real()
    emf_fn_ptr_id_config_property_read_real = 620,
    /// Id of emf_config_property_read_string()
    emf_fn_ptr_id_config_property_read_string = 621,
    /// Id of emf_config_property_write_bool()
    emf_fn_ptr_id_config_property_write_bool = 622,
    /// Id of emf_config_property_write_integer()
    emf_fn_ptr_id_config_property_write_integer = 623,
    /// Id of emf_config_property_write_real()
    emf_fn_ptr_id_config_property_write_real = 624,
    /// Id of emf_config_property_write_string()
    emf_fn_ptr_id_config_property_write_string = 625,
} emf_fn_ptr_id_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_EMF_FN_PTR_ID_T_H