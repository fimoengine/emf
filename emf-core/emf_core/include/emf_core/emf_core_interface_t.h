#ifndef EMF_INTERFACE_C_EMF_CORE_INTERFACE_T_H
#define EMF_INTERFACE_C_EMF_CORE_INTERFACE_T_H

#include <emf_core/emf_fn_ptr_t.h>
#include <emf_core/emf_macros.h>
#include <emf_core/emf_version_t.h>

#define EMF_CORE_INTERFACE_NAME "emf::core"

#ifdef __cplusplus
namespace EMF::C {
#endif // __cplusplus

/**
 * EMF::Core exported interface.
 */
typedef struct emf_core_interface_t {
    emf_version_t interface_version;

    emf_lock_fn_t EMF_NOT_NULL lock_fn;
    emf_try_lock_fn_t EMF_NOT_NULL try_lock_fn;
    emf_unlock_fn_t EMF_NOT_NULL unlock_fn;
    emf_shutdown_fn_t EMF_NOT_NULL shutdown_fn;
    emf_panic_fn_t EMF_NOT_NULL panic_fn;
    emf_has_function_fn_t EMF_NOT_NULL has_function_fn;
    emf_get_function_fn_t EMF_NOT_NULL get_function_fn;
    emf_get_sync_handler_fn_t EMF_NOT_NULL get_sync_handler_fn;
    emf_set_sync_handler_fn_t EMF_NOT_NULL set_sync_handler_fn;

    emf_version_construct_short_fn_t EMF_NOT_NULL version_construct_short_fn;
    emf_version_construct_long_fn_t EMF_NOT_NULL version_construct_long_fn;
    emf_version_construct_full_fn_t EMF_NOT_NULL version_construct_full_fn;
    emf_version_construct_from_string_fn_t EMF_NOT_NULL version_construct_from_string_fn;
    emf_version_representation_is_valid_fn_t EMF_NOT_NULL version_representation_is_valid_fn;
    emf_version_get_short_representation_fn_t EMF_NOT_NULL version_get_short_representation_fn;
    emf_version_get_short_representation_size_fn_t EMF_NOT_NULL version_get_short_representation_size_fn;
    emf_version_get_long_representation_fn_t EMF_NOT_NULL version_get_long_representation_fn;
    emf_version_get_long_representation_size_fn_t EMF_NOT_NULL version_get_long_representation_size_fn;
    emf_version_get_full_representation_fn_t EMF_NOT_NULL version_get_full_representation_fn;
    emf_version_get_full_representation_size_fn_t EMF_NOT_NULL version_get_full_representation_size_fn;
    emf_version_compare_fn_t EMF_NOT_NULL version_compare_fn;
    emf_version_compare_weak_fn_t EMF_NOT_NULL version_compare_weak_fn;
    emf_version_compare_strong_fn_t EMF_NOT_NULL version_compare_strong_fn;
    emf_version_is_compatible_fn_t EMF_NOT_NULL version_is_compatible_fn;

    emf_event_create_fn_t EMF_NOT_NULL event_create_fn;
    emf_event_create_private_fn_t EMF_NOT_NULL event_create_private_fn;
    emf_event_destroy_fn_t EMF_NOT_NULL event_destroy_fn;
    emf_event_publish_fn_t EMF_NOT_NULL event_publish_fn;
    emf_event_get_num_public_events_fn_t EMF_NOT_NULL event_get_num_public_events_fn;
    emf_event_get_public_events_fn_t EMF_NOT_NULL event_get_public_events_fn;
    emf_event_get_event_handle_fn_t EMF_NOT_NULL event_get_event_handle_fn;
    emf_event_handle_exists_fn_t EMF_NOT_NULL event_handle_exists_fn;
    emf_event_name_exists_fn_t EMF_NOT_NULL event_name_exists_fn;
    emf_event_subscribe_handler_fn_t EMF_NOT_NULL event_subscribe_handler_fn;
    emf_event_unsubscribe_handler_fn_t EMF_NOT_NULL event_unsubscribe_handler_fn;
    emf_event_signal_fn_t EMF_NOT_NULL event_signal_fn;

    emf_fs_register_file_handler_fn_t EMF_NOT_NULL fs_register_file_handler_fn;
    emf_fs_remove_file_handler_fn_t EMF_NOT_NULL fs_remove_file_handler_fn;
    emf_fs_create_file_fn_t EMF_NOT_NULL fs_create_file_fn;
    emf_fs_create_link_fn_t EMF_NOT_NULL fs_create_link_fn;
    emf_fs_create_directory_fn_t EMF_NOT_NULL fs_create_directory_fn;
    emf_fs_delete_fn_t EMF_NOT_NULL fs_delete_fn;
    emf_fs_mount_memory_file_fn_t EMF_NOT_NULL fs_mount_memory_file_fn;
    emf_fs_mount_native_path_fn_t EMF_NOT_NULL fs_mount_native_path_fn;
    emf_fs_unmount_fn_t EMF_NOT_NULL fs_unmount_fn;
    emf_fs_set_access_mode_fn_t EMF_NOT_NULL fs_set_access_mode_fn;
    emf_fs_get_access_mode_fn_t EMF_NOT_NULL fs_get_access_mode_fn;
    emf_fs_get_mount_id_fn_t EMF_NOT_NULL fs_get_mount_id_fn;
    emf_fs_can_access_fn_t EMF_NOT_NULL fs_can_access_fn;
    emf_fs_can_set_access_mode_fn_t EMF_NOT_NULL fs_can_set_access_mode_fn;
    emf_fs_is_virtual_fn_t EMF_NOT_NULL fs_is_virtual_fn;
    emf_fs_can_delete_fn_t EMF_NOT_NULL fs_can_delete_fn;
    emf_fs_can_mount_type_fn_t EMF_NOT_NULL fs_can_mount_type_fn;
    emf_fs_can_mount_native_path_fn_t EMF_NOT_NULL fs_can_mount_native_path_fn;
    emf_fs_get_num_entries_fn_t EMF_NOT_NULL fs_get_num_entries_fn;
    emf_fs_get_entries_fn_t EMF_NOT_NULL fs_get_entries_fn;
    emf_fs_exists_fn_t EMF_NOT_NULL fs_exists_fn;
    emf_fs_type_exists_fn_t EMF_NOT_NULL fs_type_exists_fn;
    emf_fs_get_entry_type_fn_t EMF_NOT_NULL fs_get_entry_type_fn;
    emf_fs_resolve_link_fn_t EMF_NOT_NULL fs_resolve_link_fn;
    emf_fs_get_link_type_fn_t EMF_NOT_NULL fs_get_link_type_fn;
    emf_fs_get_size_fn_t EMF_NOT_NULL fs_get_size_fn;
    emf_fs_get_native_path_length_fn_t EMF_NOT_NULL fs_get_native_path_length_fn;
    emf_fs_get_native_path_fn_t EMF_NOT_NULL fs_get_native_path_fn;
    emf_fs_get_num_file_handlers_fn_t EMF_NOT_NULL fs_get_num_file_handlers_fn;
    emf_fs_get_file_handlers_fn_t EMF_NOT_NULL fs_get_file_handlers_fn;
    emf_fs_get_file_handler_from_type_fn_t EMF_NOT_NULL fs_get_file_handler_from_type_fn;
    emf_fs_get_num_file_types_fn_t EMF_NOT_NULL fs_get_num_file_types_fn;
    emf_fs_get_file_types_fn_t EMF_NOT_NULL fs_get_file_types_fn;
    emf_fs_get_num_handler_file_types_fn_t EMF_NOT_NULL fs_get_num_handler_file_types_fn;
    emf_fs_get_handler_file_types_fn_t EMF_NOT_NULL fs_get_handler_file_types_fn;
    emf_fs_normalize_fn_t EMF_NOT_NULL fs_normalize_fn;
    emf_fs_get_parent_fn_t EMF_NOT_NULL fs_get_parent_fn;
    emf_fs_join_fn_t EMF_NOT_NULL fs_join_fn;
    emf_fs_unsafe_create_mount_id_fn_t EMF_NOT_NULL fs_unsafe_create_mount_id_fn;
    emf_fs_unsafe_remove_mount_id_fn_t EMF_NOT_NULL fs_unsafe_remove_mount_id_fn;
    emf_fs_unsafe_unmount_force_fn_t EMF_NOT_NULL fs_unsafe_unmount_force_fn;
    emf_fs_unsafe_link_mount_point_fn_t EMF_NOT_NULL fs_unsafe_link_mount_point_fn;
    emf_fs_unsafe_create_file_stream_fn_t EMF_NOT_NULL fs_unsafe_create_file_stream_fn;
    emf_fs_unsafe_remove_file_stream_fn_t EMF_NOT_NULL fs_unsafe_remove_file_stream_fn;
    emf_fs_unsafe_link_file_stream_fn_t EMF_NOT_NULL fs_unsafe_link_file_stream_fn;
    emf_fs_unsafe_get_file_handler_handle_from_stream_fn_t EMF_NOT_NULL fs_unsafe_get_file_handler_handle_from_stream_fn;
    emf_fs_unsafe_get_file_handler_handle_from_path_fn_t EMF_NOT_NULL fs_unsafe_get_file_handler_handle_from_path_fn;
    emf_fs_unsafe_get_file_handler_stream_fn_t EMF_NOT_NULL fs_unsafe_get_file_handler_stream_fn;
    emf_fs_unsafe_get_file_handler_mount_id_fn_t EMF_NOT_NULL fs_unsafe_get_file_handler_mount_id_fn;
    emf_fs_unsafe_get_file_handler_fn_t EMF_NOT_NULL fs_unsafe_get_file_handler_fn;
    emf_fs_stream_open_fn_t EMF_NOT_NULL fs_stream_open_fn;
    emf_fs_stream_close_fn_t EMF_NOT_NULL fs_stream_close_fn;
    emf_fs_stream_flush_fn_t EMF_NOT_NULL fs_stream_flush_fn;
    emf_fs_stream_read_fn_t EMF_NOT_NULL fs_stream_read_fn;
    emf_fs_stream_write_fn_t EMF_NOT_NULL fs_stream_write_fn;
    emf_fs_stream_get_pos_fn_t EMF_NOT_NULL fs_stream_get_pos_fn;
    emf_fs_stream_set_pos_fn_t EMF_NOT_NULL fs_stream_set_pos_fn;
    emf_fs_stream_move_pos_fn_t EMF_NOT_NULL fs_stream_move_pos_fn;
    emf_fs_stream_can_write_fn_t EMF_NOT_NULL fs_stream_can_write_fn;
    emf_fs_stream_can_grow_fn_t EMF_NOT_NULL fs_stream_can_grow_fn;

    emf_library_register_loader_fn_t EMF_NOT_NULL library_register_loader_fn;
    emf_library_unregister_loader_fn_t EMF_NOT_NULL library_unregister_loader_fn;
    emf_library_get_num_loaders_fn_t EMF_NOT_NULL library_get_num_loaders_fn;
    emf_library_get_library_types_fn_t EMF_NOT_NULL library_get_library_types_fn;
    emf_library_get_loader_handle_fn_t EMF_NOT_NULL library_get_loader_handle_fn;
    emf_library_type_exists_fn_t EMF_NOT_NULL library_type_exists_fn;
    emf_library_library_exists_fn_t EMF_NOT_NULL library_library_exists_fn;
    emf_library_unsafe_create_library_handle_fn_t EMF_NOT_NULL library_unsafe_create_library_handle_fn;
    emf_library_unsafe_remove_library_handle_fn_t EMF_NOT_NULL library_unsafe_remove_library_handle_fn;
    emf_library_unsafe_link_library_fn_t EMF_NOT_NULL library_unsafe_link_library_fn;
    emf_library_unsafe_get_loader_library_handle_fn_t EMF_NOT_NULL library_unsafe_get_loader_library_handle_fn;
    emf_library_unsafe_get_loader_fn_t EMF_NOT_NULL library_unsafe_get_loader_fn;
    emf_library_load_fn_t EMF_NOT_NULL library_load_fn;
    emf_library_unload_fn_t EMF_NOT_NULL library_unload_fn;
    emf_library_get_symbol_fn_t EMF_NOT_NULL library_get_symbol_fn;
    emf_library_get_function_symbol_fn_t EMF_NOT_NULL library_get_function_symbol_fn;

    emf_module_register_loader_fn_t EMF_NOT_NULL module_register_loader_fn;
    emf_module_unregister_loader_fn_t EMF_NOT_NULL module_unregister_loader_fn;
    emf_module_get_num_loaders_fn_t EMF_NOT_NULL module_get_num_loaders_fn;
    emf_module_get_module_types_fn_t EMF_NOT_NULL module_get_module_types_fn;
    emf_module_get_num_modules_fn_t EMF_NOT_NULL module_get_num_modules_fn;
    emf_module_get_modules_fn_t EMF_NOT_NULL module_get_modules_fn;
    emf_module_get_num_public_interfaces_fn_t EMF_NOT_NULL module_get_num_public_interfaces_fn;
    emf_module_get_public_interfaces_fn_t EMF_NOT_NULL module_get_public_interfaces_fn;
    emf_module_get_loader_handle_fn_t EMF_NOT_NULL module_get_loader_handle_fn;
    emf_module_type_exists_fn_t EMF_NOT_NULL module_type_exists_fn;
    emf_module_module_exists_fn_t EMF_NOT_NULL module_module_exists_fn;
    emf_module_get_interface_handle_fn_t EMF_NOT_NULL module_get_interface_handle_fn;
    emf_module_interface_exists_fn_t EMF_NOT_NULL module_interface_exists_fn;
    emf_module_unsafe_create_module_handle_fn_t EMF_NOT_NULL module_unsafe_create_module_handle_fn;
    emf_module_unsafe_remove_module_handle_fn_t EMF_NOT_NULL module_unsafe_remove_module_handle_fn;
    emf_module_unsafe_link_module_fn_t EMF_NOT_NULL module_unsafe_link_module_fn;
    emf_module_unsafe_get_loader_module_handle_fn_t EMF_NOT_NULL module_unsafe_get_loader_module_handle_fn;
    emf_module_unsafe_get_loader_fn_t EMF_NOT_NULL module_unsafe_get_loader_fn;
    emf_module_load_fn_t EMF_NOT_NULL module_load_fn;
    emf_module_unload_fn_t EMF_NOT_NULL module_unload_fn;
    emf_module_initialize_fn_t EMF_NOT_NULL module_initialize_fn;
    emf_module_terminate_fn_t EMF_NOT_NULL module_terminate_fn;
    emf_module_get_module_info_fn_t EMF_NOT_NULL module_get_module_info_fn;
    emf_module_get_exported_interfaces_fn_t EMF_NOT_NULL module_get_exported_interfaces_fn;
    emf_module_get_imported_interfaces_fn_t EMF_NOT_NULL module_get_imported_interfaces_fn;
    emf_module_get_interface_fn_t EMF_NOT_NULL module_get_interface_fn;

    emf_config_add_namespace_fn_t EMF_NOT_NULL config_add_namespace_fn;
    emf_config_remove_namespace_fn_t EMF_NOT_NULL config_remove_namespace_fn;
    emf_config_add_property_boolean_fn_t EMF_NOT_NULL config_add_property_boolean_fn;
    emf_config_add_property_integer_fn_t EMF_NOT_NULL config_add_property_integer_fn;
    emf_config_add_property_real_fn_t EMF_NOT_NULL config_add_property_real_fn;
    emf_config_add_property_string_fn_t EMF_NOT_NULL config_add_property_string_fn;
    emf_config_remove_property_fn_t EMF_NOT_NULL config_remove_property_fn;
    emf_config_get_num_namespaces_fn_t EMF_NOT_NULL config_get_num_namespaces_fn;
    emf_config_get_namespaces_fn_t EMF_NOT_NULL config_get_namespaces_fn;
    emf_config_get_num_properties_fn_t EMF_NOT_NULL config_get_num_properties_fn;
    emf_config_get_properties_fn_t EMF_NOT_NULL config_get_properties_fn;
    emf_config_namespace_exists_fn_t EMF_NOT_NULL config_namespace_exists_fn;
    emf_config_property_exists_fn_t EMF_NOT_NULL config_property_exists_fn;
    emf_config_get_property_type_fn_t EMF_NOT_NULL config_get_property_type_fn;
    emf_config_get_property_array_size_fn_t EMF_NOT_NULL config_get_property_array_size_fn;
    emf_config_get_property_string_size_fn_t EMF_NOT_NULL config_get_property_string_size_fn;
    emf_config_get_property_string_max_size_fn_t EMF_NOT_NULL config_get_property_string_max_size_fn;
    emf_config_property_read_bool_fn_t EMF_NOT_NULL config_property_read_bool_fn;
    emf_config_property_read_integer_fn_t EMF_NOT_NULL config_property_read_integer_fn;
    emf_config_property_read_real_fn_t EMF_NOT_NULL config_property_read_real_fn;
    emf_config_property_read_string_fn_t EMF_NOT_NULL config_property_read_string_fn;
    emf_config_property_write_bool_fn_t EMF_NOT_NULL config_property_write_bool_fn;
    emf_config_property_write_integer_fn_t EMF_NOT_NULL config_property_write_integer_fn;
    emf_config_property_write_real_fn_t EMF_NOT_NULL config_property_write_real_fn;
    emf_config_property_write_string_fn_t EMF_NOT_NULL config_property_write_string_fn;
} emf_core_interface_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_INTERFACE_C_EMF_CORE_INTERFACE_T_H
