#ifndef EMF_CORE_EMF_FN_PTR_T_H
#define EMF_CORE_EMF_FN_PTR_T_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core/emf_bool_t.h>
#include <emf_core/emf_config.h>
#include <emf_core/emf_core.h>
#include <emf_core/emf_error_t.h>
#include <emf_core/emf_event.h>
#include <emf_core/emf_fn_ptr_id_t.h>
#include <emf_core/emf_fs.h>
#include <emf_core/emf_library.h>
#include <emf_core/emf_macros.h>
#include <emf_core/emf_module.h>
#include <emf_core/emf_version_t.h>

#ifdef __cplusplus
namespace EMF::Core::C {
#endif // __cplusplus

EMF_FUNCTION_PTR_T(emf, void, void)

/******************************************************************************************************
********************************************  EMF_CORE_H  ********************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf_lock, void, void)
EMF_FUNCTION_PTR_T(emf_try_lock, EMF_NODISCARD emf_bool_t, void)
EMF_FUNCTION_PTR_T(emf_unlock, void, void)
EMF_FUNCTION_PTR_T(emf_shutdown, void, void)
EMF_FUNCTION_PTR_T(emf_panic, void, const char* EMF_MAYBE_NULL error)
EMF_FUNCTION_PTR_T(emf_has_function, EMF_NODISCARD emf_bool_t, emf_fn_ptr_id_t fn_id)
EMF_FUNCTION_PTR_T(emf_get_function, EMF_NODISCARD emf_fn_t EMF_NOT_NULL, emf_fn_ptr_id_t fn_id)
EMF_FUNCTION_PTR_T(emf_get_sync_handler, EMF_NODISCARD const emf_sync_handler_t* EMF_MAYBE_NULL, void)
EMF_FUNCTION_PTR_T(emf_set_sync_handler, void, const emf_sync_handler_t* EMF_MAYBE_NULL sync_handler)

/******************************************************************************************************
******************************************  EMF_VERSION_T_H  ******************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf_version_construct_short, EMF_NODISCARD emf_version_t, int32_t major, int32_t minor, int32_t patch)
EMF_FUNCTION_PTR_T(emf_version_construct_long, EMF_NODISCARD emf_version_t, int32_t major, int32_t minor, int32_t patch,
    emf_version_release_t release_type, int8_t release_number)
EMF_FUNCTION_PTR_T(emf_version_construct_full, EMF_NODISCARD emf_version_t, int32_t major, int32_t minor, int32_t patch,
    emf_version_release_t release_type, int8_t release_number, int64_t build)
EMF_FUNCTION_PTR_T(emf_version_construct_from_string, EMF_NODISCARD emf_version_t, const char* EMF_NOT_NULL version_string)
EMF_FUNCTION_PTR_T(emf_version_representation_is_valid, EMF_NODISCARD emf_bool_t, const char* EMF_NOT_NULL version_string)
EMF_FUNCTION_PTR_T(emf_version_get_short_representation, size_t, const emf_version_t* EMF_NOT_NULL version,
    emf_version_representation_buffer_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_version_get_short_representation_size, EMF_NODISCARD size_t, const emf_version_t* EMF_NOT_NULL version)
EMF_FUNCTION_PTR_T(emf_version_get_long_representation, size_t, const emf_version_t* EMF_NOT_NULL version,
    emf_version_representation_buffer_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_version_get_long_representation_size, EMF_NODISCARD size_t, const emf_version_t* EMF_NOT_NULL version)
EMF_FUNCTION_PTR_T(emf_version_get_full_representation, size_t, const emf_version_t* EMF_NOT_NULL version,
    emf_version_representation_buffer_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_version_get_full_representation_size, EMF_NODISCARD size_t, const emf_version_t* EMF_NOT_NULL version)
EMF_FUNCTION_PTR_T(
    emf_version_compare, EMF_NODISCARD int32_t, const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs)
EMF_FUNCTION_PTR_T(
    emf_version_compare_weak, EMF_NODISCARD int32_t, const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs)
EMF_FUNCTION_PTR_T(emf_version_compare_strong, EMF_NODISCARD int32_t, const emf_version_t* EMF_NOT_NULL lhs,
    const emf_version_t* EMF_NOT_NULL rhs)
EMF_FUNCTION_PTR_T(emf_version_is_compatible, EMF_NODISCARD emf_bool_t, const emf_version_t* EMF_NOT_NULL lhs,
    const emf_version_t* EMF_NOT_NULL rhs)

/******************************************************************************************************
********************************************  EMF_EVENT_H  ********************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf_event_create, emf_event_handle_t, const emf_event_name_t* EMF_NOT_NULL event_name,
    emf_event_handler_fn_t EMF_MAYBE_NULL event_handler)
EMF_FUNCTION_PTR_T(
    emf_event_create_private, EMF_NODISCARD emf_event_handle_t, emf_event_handler_fn_t EMF_MAYBE_NULL event_handler)
EMF_FUNCTION_PTR_T(emf_event_destroy, void, emf_event_handle_t event_handle)
EMF_FUNCTION_PTR_T(emf_event_publish, void, emf_event_handle_t event_handle, const emf_event_name_t* EMF_NOT_NULL event_name)
EMF_FUNCTION_PTR_T(emf_event_get_num_public_events, EMF_NODISCARD size_t, void)
EMF_FUNCTION_PTR_T(emf_event_get_public_events, size_t, emf_event_name_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_event_get_event_handle, EMF_NODISCARD emf_event_handle_t, const emf_event_name_t* EMF_NOT_NULL event_name)
EMF_FUNCTION_PTR_T(emf_event_handle_exists, EMF_NODISCARD emf_bool_t, emf_event_handle_t event_handle)
EMF_FUNCTION_PTR_T(emf_event_name_exists, EMF_NODISCARD emf_bool_t, const emf_event_name_t* EMF_NOT_NULL event_name)
EMF_FUNCTION_PTR_T(
    emf_event_subscribe_handler, void, emf_event_handle_t event_handle, emf_event_handler_fn_t EMF_NOT_NULL event_handler)
EMF_FUNCTION_PTR_T(
    emf_event_unsubscribe_handler, void, emf_event_handle_t event_handle, emf_event_handler_fn_t EMF_NOT_NULL event_handler)
EMF_FUNCTION_PTR_T(emf_event_signal, void, emf_event_handle_t event_handle, emf_event_data_t EMF_MAYBE_NULL event_data)

/******************************************************************************************************
*********************************************  EMF_FS_H  *********************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf_fs_register_file_handler, emf_file_handler_t,
    const emf_file_handler_interface_t* EMF_NOT_NULL file_handler, const emf_file_type_const_span_t* EMF_NOT_NULL file_types)
EMF_FUNCTION_PTR_T(emf_fs_remove_file_handler, void, emf_file_handler_t file_handler)
EMF_FUNCTION_PTR_T(emf_fs_create_file, void, const emf_path_t* EMF_NOT_NULL filename, const void* EMF_MAYBE_NULL options)
EMF_FUNCTION_PTR_T(emf_fs_create_link, void, const emf_path_t* EMF_NOT_NULL source, const emf_path_t* EMF_NOT_NULL destination,
    emf_fs_link_t type)
EMF_FUNCTION_PTR_T(emf_fs_create_directory, void, const emf_path_t* EMF_NOT_NULL path, const void* EMF_MAYBE_NULL options)
EMF_FUNCTION_PTR_T(emf_fs_delete, void, const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(emf_fs_mount_memory_file, emf_mount_id_t, emf_file_handler_t file_handler,
    const emf_memory_span_t* EMF_NOT_NULL file, emf_access_mode_t access_mode, const emf_path_t* EMF_NOT_NULL mount_point,
    const void* EMF_MAYBE_NULL options)
EMF_FUNCTION_PTR_T(emf_fs_mount_native_path, emf_mount_id_t, emf_file_handler_t file_handler,
    const emf_native_path_char_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, const emf_path_t* EMF_NOT_NULL mount_point,
    const void* EMF_MAYBE_NULL options)
EMF_FUNCTION_PTR_T(emf_fs_unmount, EMF_NODISCARD emf_bool_t, emf_mount_id_t mount_id)
EMF_FUNCTION_PTR_T(
    emf_fs_set_access_mode, void, const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(emf_fs_get_access_mode, EMF_NODISCARD emf_access_mode_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_get_mount_id, EMF_NODISCARD emf_mount_id_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(
    emf_fs_can_access, EMF_NODISCARD emf_bool_t, const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode)
EMF_FUNCTION_PTR_T(emf_fs_can_set_access_mode, EMF_NODISCARD emf_bool_t, const emf_path_t* EMF_NOT_NULL path,
    emf_access_mode_t access_mode, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(emf_fs_is_virtual, EMF_NODISCARD emf_bool_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_can_delete, EMF_NODISCARD emf_bool_t, const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(
    emf_fs_can_mount_type, EMF_NODISCARD emf_bool_t, emf_file_handler_t file_handler, const emf_file_type_t* EMF_NOT_NULL type)
EMF_FUNCTION_PTR_T(emf_fs_can_mount_native_path, EMF_NODISCARD emf_bool_t, emf_file_handler_t file_handler,
    const emf_native_path_char_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_get_num_entries, EMF_NODISCARD size_t, const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(
    emf_fs_get_entries, size_t, const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive, emf_path_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_fs_exists, EMF_NODISCARD emf_bool_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_type_exists, EMF_NODISCARD emf_bool_t, const emf_file_type_t* EMF_NOT_NULL type)
EMF_FUNCTION_PTR_T(emf_fs_get_entry_type, EMF_NODISCARD emf_fs_entry_type_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_resolve_link, EMF_NODISCARD emf_path_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_get_link_type, EMF_NODISCARD emf_fs_link_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_get_size, EMF_NODISCARD emf_entry_size_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_get_native_path_length, EMF_NODISCARD size_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(
    emf_fs_get_native_path, size_t, const emf_path_t* EMF_NOT_NULL path, emf_native_path_string_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_fs_get_num_file_handlers, EMF_NODISCARD size_t, void)
EMF_FUNCTION_PTR_T(emf_fs_get_file_handlers, size_t, emf_file_handler_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_fs_get_file_handler_from_type, EMF_NODISCARD emf_file_handler_t, const emf_file_type_t* EMF_NOT_NULL type)
EMF_FUNCTION_PTR_T(emf_fs_get_num_file_types, EMF_NODISCARD size_t, void)
EMF_FUNCTION_PTR_T(emf_fs_get_file_types, size_t, emf_file_type_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_fs_get_num_handler_file_types, EMF_NODISCARD size_t, emf_file_handler_t file_handler)
EMF_FUNCTION_PTR_T(
    emf_fs_get_handler_file_types, size_t, emf_file_handler_t file_handler, emf_file_type_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_fs_normalize, EMF_NODISCARD emf_path_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_get_parent, EMF_NODISCARD emf_path_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_join, EMF_NODISCARD emf_path_t, const emf_path_t* EMF_NOT_NULL lhs, const emf_path_t* EMF_NOT_NULL rhs)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_create_mount_id, EMF_NODISCARD emf_mount_id_t, const emf_path_t* EMF_NOT_NULL mount_point)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_remove_mount_id, void, emf_mount_id_t mount_id)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_unmount_force, void, emf_mount_id_t mount_id)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_link_mount_point, void, emf_mount_id_t mount_id, emf_file_handler_t file_handler,
    emf_file_handler_mount_id_t file_handler_mount_id)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_create_file_stream, EMF_NODISCARD emf_file_stream_t, void)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_remove_file_stream, void, emf_file_stream_t file_stream)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_link_file_stream, void, emf_file_stream_t file_stream, emf_file_handler_t file_handler,
    emf_file_handler_stream_t file_handler_stream)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_get_file_handler_handle_from_stream, EMF_NODISCARD emf_file_handler_t, emf_file_stream_t stream)
EMF_FUNCTION_PTR_T(
    emf_fs_unsafe_get_file_handler_handle_from_path, EMF_NODISCARD emf_file_handler_t, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_get_file_handler_stream, EMF_NODISCARD emf_file_handler_stream_t, emf_file_stream_t file_stream)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_get_file_handler_mount_id, EMF_NODISCARD emf_file_handler_mount_id_t, emf_mount_id_t mount_id)
EMF_FUNCTION_PTR_T(emf_fs_unsafe_get_file_handler, EMF_NODISCARD emf_file_handler_interface_t, emf_file_handler_t file_handler)
EMF_FUNCTION_PTR_T(emf_fs_stream_open, EMF_NODISCARD emf_file_stream_t, const emf_path_t* EMF_NOT_NULL filename,
    emf_file_open_mode_t open_mode, emf_access_mode_t access_mode, const void* EMF_MAYBE_NULL options)
EMF_FUNCTION_PTR_T(emf_fs_stream_close, void, emf_file_stream_t stream)
EMF_FUNCTION_PTR_T(emf_fs_stream_flush, void, emf_file_stream_t stream)
EMF_FUNCTION_PTR_T(
    emf_fs_stream_read, size_t, emf_file_stream_t stream, emf_fs_read_buffer_t* EMF_NOT_NULL buffer, size_t read_count)
EMF_FUNCTION_PTR_T(
    emf_fs_stream_write, size_t, emf_file_stream_t stream, const emf_fs_const_buffer_t* EMF_NOT_NULL buffer, size_t write_count)
EMF_FUNCTION_PTR_T(emf_fs_stream_get_pos, EMF_NODISCARD emf_pos_t, emf_file_stream_t stream)
EMF_FUNCTION_PTR_T(emf_fs_stream_set_pos, emf_off_t, emf_file_stream_t stream, emf_pos_t position)
EMF_FUNCTION_PTR_T(emf_fs_stream_move_pos, emf_off_t, emf_file_stream_t stream, emf_off_t offset, emf_fs_direction_t direction)
EMF_FUNCTION_PTR_T(emf_fs_stream_can_write, EMF_NODISCARD emf_bool_t, emf_file_stream_t stream)
EMF_FUNCTION_PTR_T(emf_fs_stream_can_grow, EMF_NODISCARD emf_bool_t, emf_file_stream_t stream, size_t size)

/******************************************************************************************************
*******************************************  EMF_LIBRARY_H  *******************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf_library_register_loader, emf_library_loader_handle_t,
    const emf_library_loader_interface_t* EMF_NOT_NULL loader_interface, const emf_library_type_t* EMF_NOT_NULL library_type)
EMF_FUNCTION_PTR_T(emf_library_unregister_loader, void, emf_library_loader_handle_t loader_handle)
EMF_FUNCTION_PTR_T(emf_library_get_num_loaders, EMF_NODISCARD size_t, void)
EMF_FUNCTION_PTR_T(emf_library_get_library_types, size_t, emf_library_type_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(
    emf_library_get_loader_handle, EMF_NODISCARD emf_library_loader_handle_t, const emf_library_type_t* EMF_NOT_NULL library_type)
EMF_FUNCTION_PTR_T(emf_library_type_exists, EMF_NODISCARD emf_bool_t, const emf_library_type_t* EMF_NOT_NULL library_type)
EMF_FUNCTION_PTR_T(emf_library_library_exists, EMF_NODISCARD emf_bool_t, emf_library_handle_t library_handle)
EMF_FUNCTION_PTR_T(emf_library_unsafe_create_library_handle, EMF_NODISCARD emf_library_handle_t, void)
EMF_FUNCTION_PTR_T(emf_library_unsafe_remove_library_handle, void, emf_library_handle_t library_handle)
EMF_FUNCTION_PTR_T(emf_library_unsafe_link_library, void, emf_library_handle_t library_handle,
    emf_library_loader_handle_t loader_handle, emf_library_loader_library_handle_t loader_library_handle)
EMF_FUNCTION_PTR_T(emf_library_unsafe_get_loader_library_handle, EMF_NODISCARD emf_library_loader_library_handle_t,
    emf_library_handle_t library_handle)
EMF_FUNCTION_PTR_T(
    emf_library_unsafe_get_loader, EMF_NODISCARD emf_library_loader_interface_t, emf_library_loader_handle_t loader_handle)
EMF_FUNCTION_PTR_T(emf_library_load, EMF_NODISCARD emf_library_handle_t, emf_library_loader_handle_t loader_handle,
    const emf_path_t* EMF_NOT_NULL library_path)
EMF_FUNCTION_PTR_T(emf_library_unload, void, emf_library_handle_t library_handle)
EMF_FUNCTION_PTR_T(emf_library_get_symbol, EMF_NODISCARD emf_error_t, emf_library_handle_t library_handle,
    const char* EMF_NOT_NULL symbol_name, emf_symbol_t* EMF_NOT_NULL symbol)
EMF_FUNCTION_PTR_T(emf_library_get_function_symbol, EMF_NODISCARD emf_error_t, emf_library_handle_t library_handle,
    const char* EMF_NOT_NULL symbol_name, emf_fn_symbol_t* EMF_NOT_NULL symbol)

/******************************************************************************************************
*******************************************  EMF_MODULE_H  *******************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf_module_register_loader, emf_module_loader_handle_t,
    const emf_module_loader_interface_t* EMF_NOT_NULL loader_interface, const emf_module_type_t* EMF_NOT_NULL module_type)
EMF_FUNCTION_PTR_T(emf_module_unregister_loader, void, emf_module_loader_handle_t loader_handle)
EMF_FUNCTION_PTR_T(emf_module_get_num_loaders, EMF_NODISCARD size_t, void)
EMF_FUNCTION_PTR_T(emf_module_get_module_types, size_t, emf_module_type_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_module_get_num_modules, EMF_NODISCARD size_t, void)
EMF_FUNCTION_PTR_T(emf_module_get_modules, size_t, emf_module_info_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_module_get_num_public_interfaces, EMF_NODISCARD size_t, void)
EMF_FUNCTION_PTR_T(emf_module_get_public_interfaces, size_t, emf_interface_descriptor_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(
    emf_module_get_loader_handle, EMF_NODISCARD emf_module_loader_handle_t, const emf_module_type_t* EMF_NOT_NULL module_type)
EMF_FUNCTION_PTR_T(emf_module_type_exists, EMF_NODISCARD emf_bool_t, const emf_module_type_t* EMF_NOT_NULL module_type)
EMF_FUNCTION_PTR_T(emf_module_module_exists, EMF_NODISCARD emf_bool_t, emf_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(
    emf_module_get_interface_handle, EMF_NODISCARD emf_module_handle_t, const emf_interface_info_t* EMF_NOT_NULL interface)
EMF_FUNCTION_PTR_T(emf_module_interface_exists, EMF_NODISCARD emf_bool_t, const emf_interface_info_t* EMF_NOT_NULL interface)
EMF_FUNCTION_PTR_T(emf_module_unsafe_create_module_handle, EMF_NODISCARD emf_module_handle_t, void)
EMF_FUNCTION_PTR_T(emf_module_unsafe_remove_module_handle, void, emf_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_unsafe_link_module, void, emf_module_handle_t module_handle,
    emf_module_loader_handle_t loader_handle, emf_module_loader_module_handle_t loader_module_handle,
    const emf_interface_info_span_t* EMF_MAYBE_NULL public_interfaces)
EMF_FUNCTION_PTR_T(emf_module_unsafe_get_loader_module_handle, EMF_NODISCARD emf_module_loader_module_handle_t,
    emf_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(
    emf_module_unsafe_get_loader, EMF_NODISCARD emf_module_loader_interface_t, emf_module_loader_handle_t loader_handle)
EMF_FUNCTION_PTR_T(emf_module_load, EMF_NODISCARD emf_module_handle_t, emf_module_loader_handle_t loader_handle,
    const emf_interface_info_span_t* EMF_MAYBE_NULL public_interfaces, const emf_path_t* EMF_NOT_NULL module_path)
EMF_FUNCTION_PTR_T(emf_module_unload, void, emf_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_initialize, void, emf_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_terminate, void, emf_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(
    emf_module_get_module_info, EMF_NODISCARD const emf_module_info_t* EMF_NOT_NULL, emf_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_get_exported_interfaces, EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL,
    emf_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_get_imported_interfaces, EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL,
    emf_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_get_interface, EMF_NODISCARD emf_error_t, emf_module_handle_t module_handle,
    const emf_interface_info_t* EMF_NOT_NULL interface_info, emf_interface_t* EMF_NOT_NULL interface)

/******************************************************************************************************
*******************************************  EMF_CONFIG_H  *******************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf_config_add_namespace, void, const emf_config_namespace_t* EMF_NOT_NULL group)
EMF_FUNCTION_PTR_T(emf_config_remove_namespace, void, const emf_config_namespace_t* EMF_NOT_NULL group)
EMF_FUNCTION_PTR_T(emf_config_add_property_boolean, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, emf_bool_t default_value)
EMF_FUNCTION_PTR_T(emf_config_add_property_integer, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, int64_t default_value)
EMF_FUNCTION_PTR_T(emf_config_add_property_real, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, double default_value)
EMF_FUNCTION_PTR_T(emf_config_add_property_string, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, size_t string_length,
    const emf_config_string_t* EMF_NOT_NULL default_value)
EMF_FUNCTION_PTR_T(emf_config_remove_property, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property)
EMF_FUNCTION_PTR_T(
    emf_config_get_num_namespaces, EMF_NODISCARD size_t, const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(emf_config_get_namespaces, size_t, const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive,
    emf_config_namespace_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(
    emf_config_get_num_properties, EMF_NODISCARD size_t, const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(emf_config_get_properties, size_t, const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive,
    emf_config_property_info_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_config_namespace_exists, EMF_NODISCARD emf_bool_t, const emf_config_namespace_t* EMF_NOT_NULL group)
EMF_FUNCTION_PTR_T(emf_config_property_exists, EMF_NODISCARD emf_bool_t, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property)
EMF_FUNCTION_PTR_T(emf_config_get_property_type, EMF_NODISCARD emf_config_property_type_t,
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property)
EMF_FUNCTION_PTR_T(emf_config_get_property_array_size, EMF_NODISCARD size_t, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property)
EMF_FUNCTION_PTR_T(emf_config_get_property_string_size, EMF_NODISCARD size_t, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index)
EMF_FUNCTION_PTR_T(emf_config_get_property_string_max_size, EMF_NODISCARD size_t,
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property)
EMF_FUNCTION_PTR_T(emf_config_property_read_bool, EMF_NODISCARD emf_bool_t, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index)
EMF_FUNCTION_PTR_T(emf_config_property_read_integer, EMF_NODISCARD int64_t, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index)
EMF_FUNCTION_PTR_T(emf_config_property_read_real, EMF_NODISCARD double, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index)
EMF_FUNCTION_PTR_T(emf_config_property_read_string, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, emf_config_string_buffer_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_config_property_write_bool, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, emf_bool_t value)
EMF_FUNCTION_PTR_T(emf_config_property_write_integer, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, int64_t value)
EMF_FUNCTION_PTR_T(emf_config_property_write_real, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, double value)
EMF_FUNCTION_PTR_T(emf_config_property_write_string, void, const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, const emf_config_string_t* EMF_NOT_NULL buffer)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_EMF_FN_PTR_T_H
