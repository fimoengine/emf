#include <emf_core/emf_fs.h>
#include <emf_core_bindings/emf_core_bindings.h>

using namespace EMF::Core::C;

namespace EMF::Core::Bindings::C {

extern "C" {

emf_file_handler_t EMF_CALL_C emf_fs_register_file_handler(const emf_file_handler_interface_t* EMF_NOT_NULL file_handler,
    const emf_file_type_span_t* EMF_NOT_NULL file_types) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(file_handler != nullptr, "emf_fs_register_file_handler()")
    EMF_ASSERT_ERROR(file_types != nullptr, "emf_fs_register_file_handler()")
    EMF_ASSERT_ERROR(file_types->data != nullptr, "emf_fs_register_file_handler()")
    EMF_ASSERT_ERROR(file_types->length > 0, "emf_fs_register_file_handler()")
    return emf_binding_interface->fs_register_file_handler_fn(file_handler, file_types);
}

void EMF_CALL_C emf_fs_remove_file_handler(emf_file_handler_t file_handler) EMF_NOEXCEPT
{
    emf_binding_interface->fs_remove_file_handler_fn(file_handler);
}

void EMF_CALL_C emf_fs_create_file(const emf_path_t* EMF_NOT_NULL filename, const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(filename != nullptr, "emf_fs_create_file()")
    EMF_ASSERT_ERROR(emf_fs_exists(filename) == emf_bool_false, "emf_fs_create_file()")

#ifdef EMF_ENABLE_ERROR_CHECKING
    auto parent { emf_fs_get_parent(filename) };
    EMF_ASSERT_ERROR(emf_fs_exists(&parent) == emf_bool_true, "emf_fs_create_file()")
    EMF_ASSERT_ERROR(emf_fs_is_virtual(&parent) == emf_bool_false, "emf_fs_create_file()")
    EMF_ASSERT_ERROR(emf_fs_get_access_mode(&parent) == emf_file_access_mode_write, "emf_fs_create_file()")
#endif

    emf_binding_interface->fs_create_file_fn(filename, options);
}

void EMF_CALL_C emf_fs_create_link(
    const emf_path_t* EMF_NOT_NULL source, const emf_path_t* EMF_NOT_NULL destination, emf_fs_link_t type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(source != nullptr, "emf_fs_create_link()")
    EMF_ASSERT_ERROR(destination != nullptr, "emf_fs_create_link()")
    EMF_ASSERT_ERROR(emf_fs_exists(source) == emf_bool_true, "emf_fs_create_link()")
    EMF_ASSERT_ERROR(emf_fs_exists(destination) == emf_bool_false, "emf_fs_create_link()")
    EMF_ASSERT_ERROR(emf_fs_is_virtual(source) == emf_bool_false, "emf_fs_create_link()")

#ifdef EMF_ENABLE_ERROR_CHECKING
    auto destination_parent { emf_fs_get_parent(destination) };
    EMF_ASSERT_ERROR(emf_fs_exists(&destination_parent) == emf_bool_true, "emf_fs_create_link()")
    EMF_ASSERT_ERROR(emf_fs_is_virtual(&destination_parent) == emf_bool_true, "emf_fs_create_link()")
    EMF_ASSERT_ERROR(emf_fs_get_access_mode(&destination_parent) == emf_file_access_mode_write, "emf_fs_create_link()")
#endif

    emf_binding_interface->fs_create_link_fn(source, destination, type);
}

void EMF_CALL_C emf_fs_create_directory(const emf_path_t* EMF_NOT_NULL path, const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_create_directory()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_false, "emf_fs_create_directory()")

#ifdef EMF_ENABLE_ERROR_CHECKING
    auto parent { emf_fs_get_parent(path) };
    EMF_ASSERT_ERROR(emf_fs_exists(&parent) == emf_bool_true, "emf_fs_create_directory()")
    EMF_ASSERT_ERROR(emf_fs_get_access_mode(&parent) == emf_file_access_mode_write, "emf_fs_create_directory()")
#endif

    emf_binding_interface->fs_create_directory_fn(path, options);
}

void EMF_CALL_C emf_fs_delete(const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_delete()")
    EMF_ASSERT_ERROR(emf_fs_can_delete(path, recursive) == emf_bool_true, "emf_fs_delete()")
    emf_binding_interface->fs_delete_fn(path, recursive);
}

emf_mount_id_t EMF_CALL_C emf_fs_mount_memory_file(emf_file_handler_t file_handler, const emf_memory_span_t* EMF_NOT_NULL file,
    emf_access_mode_t access_mode, const emf_path_t* EMF_NOT_NULL mount_point, const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(file != nullptr, "emf_fs_mount_memory_file()")
    EMF_ASSERT_ERROR(mount_point != nullptr, "emf_fs_mount_memory_file()")
    EMF_ASSERT_ERROR(file->data != nullptr, "emf_fs_mount_memory_file()")
    EMF_ASSERT_ERROR(file->length > 0, "emf_fs_mount_memory_file()")
    EMF_ASSERT_ERROR(emf_fs_exists(mount_point) == emf_bool_false, "emf_fs_mount_memory_file()")

#ifdef EMF_ENABLE_ERROR_CHECKING
    auto mount_point_parent { emf_fs_get_parent(mount_point) };
    EMF_ASSERT_ERROR(emf_fs_exists(&mount_point_parent) == emf_bool_true, "emf_fs_mount_memory_file()")
    EMF_ASSERT_ERROR(emf_fs_is_virtual(&mount_point_parent) == emf_bool_true, "emf_fs_mount_memory_file()")
    EMF_ASSERT_ERROR(emf_fs_get_access_mode(&mount_point_parent) == emf_file_access_mode_write, "emf_fs_mount_memory_file()")
#endif

    return emf_binding_interface->fs_mount_memory_file_fn(file_handler, file, access_mode, mount_point, options);
}

emf_mount_id_t EMF_CALL_C emf_fs_mount_native_path(emf_file_handler_t file_handler,
    const emf_native_path_char_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, const emf_path_t* EMF_NOT_NULL mount_point,
    const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_mount_native_path()")
    EMF_ASSERT_ERROR(mount_point != nullptr, "emf_fs_mount_native_path()")
    EMF_ASSERT_ERROR(emf_fs_can_mount_native_path(file_handler, path) == emf_bool_true, "emf_fs_mount_native_path()")
    EMF_ASSERT_ERROR(emf_fs_exists(mount_point) == emf_bool_false, "emf_fs_mount_native_path()")

#ifdef EMF_ENABLE_ERROR_CHECKING
    auto mount_point_parent { emf_fs_get_parent(mount_point) };
    EMF_ASSERT_ERROR(emf_fs_exists(&mount_point_parent) == emf_bool_true, "emf_fs_mount_native_path()")
    EMF_ASSERT_ERROR(emf_fs_is_virtual(&mount_point_parent) == emf_bool_true, "emf_fs_mount_native_path()")
    EMF_ASSERT_ERROR(emf_fs_get_access_mode(&mount_point_parent) == emf_file_access_mode_write, "emf_fs_mount_native_path()")
#endif

    return emf_binding_interface->fs_mount_native_path_fn(file_handler, path, access_mode, mount_point, options);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_unmount(emf_mount_id_t mount_id) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_unmount_fn(mount_id);
}

void EMF_CALL_C emf_fs_set_access_mode(
    const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, emf_bool_t recursive) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_set_access_mode()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_set_access_mode()")
    EMF_ASSERT_ERROR(emf_fs_can_set_access_mode(path, access_mode, recursive) == emf_bool_true, "emf_fs_set_access_mode()")
    emf_binding_interface->fs_set_access_mode_fn(path, access_mode, recursive);
}

EMF_NODISCARD emf_access_mode_t EMF_CALL_C emf_fs_get_access_mode(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_access_mode()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_get_access_mode()")
    return emf_binding_interface->fs_get_access_mode_fn(path);
}

EMF_NODISCARD emf_mount_id_t EMF_CALL_C emf_fs_get_mount_id(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_mount_id()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_get_mount_id()")
    EMF_ASSERT_ERROR(emf_fs_is_virtual(path) == emf_bool_false || emf_fs_get_entry_type(path) == emf_fs_entry_type_mount_point,
        "emf_fs_get_mount_id()")
    return emf_binding_interface->fs_get_mount_id_fn(path);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_access(
    const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_can_access()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_can_access()")
    return emf_binding_interface->fs_can_access_fn(path, access_mode);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_set_access_mode(
    const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, emf_bool_t recursive) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_can_set_access_mode()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_can_set_access_mode()")
    return emf_binding_interface->fs_can_set_access_mode_fn(path, access_mode, recursive);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_is_virtual(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_is_virtual()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_is_virtual()")
    return emf_binding_interface->fs_is_virtual_fn(path);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_delete(const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_can_delete()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_can_delete()")
    return emf_binding_interface->fs_can_delete_fn(path, recursive);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_mount_type(
    emf_file_handler_t file_handler, const emf_file_type_t* EMF_NOT_NULL type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(type != nullptr, "emf_fs_can_mount_type()")
    return emf_binding_interface->fs_can_mount_type_fn(file_handler, type);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_mount_native_path(
    emf_file_handler_t file_handler, const emf_native_path_char_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_can_mount_native_path()")
    return emf_binding_interface->fs_can_mount_native_path_fn(file_handler, path);
}

EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_num_entries(const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_num_entries()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_get_num_entries()")
    return emf_binding_interface->fs_get_num_entries_fn(path, recursive);
}

size_t EMF_CALL_C emf_fs_get_entries(
    const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive, emf_path_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_entries()")
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_fs_get_entries()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_get_entries()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_fs_get_entries()")
    EMF_ASSERT_ERROR(buffer->length >= emf_fs_get_num_entries(path, recursive), "emf_fs_get_entries()")
    return emf_binding_interface->fs_get_entries_fn(path, recursive, buffer);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_exists(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_exists()")
    return emf_binding_interface->fs_exists_fn(path);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_type_exists(const emf_file_type_t* EMF_NOT_NULL type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(type != nullptr, "emf_fs_exists()")
    return emf_binding_interface->fs_type_exists_fn(type);
}

EMF_NODISCARD emf_fs_entry_type_t EMF_CALL_C emf_fs_get_entry_type(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_entry_type()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_get_entry_type()")
    return emf_binding_interface->fs_get_entry_type_fn(path);
}

EMF_NODISCARD emf_path_t EMF_CALL_C emf_fs_resolve_link(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_resolve_link()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_resolve_link()")
    EMF_ASSERT_ERROR(emf_fs_get_entry_type(path) == emf_fs_entry_type_link, "emf_fs_resolve_link()")
    return emf_binding_interface->fs_resolve_link_fn(path);
}

EMF_NODISCARD emf_fs_link_t EMF_CALL_C emf_fs_get_link_type(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_link_type()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_get_link_type()")
    EMF_ASSERT_ERROR(emf_fs_get_entry_type(path) == emf_fs_entry_type_link, "emf_fs_get_link_type()")
    return emf_binding_interface->fs_get_link_type_fn(path);
}

EMF_NODISCARD emf_entry_size_t EMF_CALL_C emf_fs_get_size(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_size()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_get_size()")
    return emf_binding_interface->fs_get_size_fn(path);
}

EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_native_path_length(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_native_path_length()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_get_native_path_length()")
    EMF_ASSERT_ERROR(emf_fs_is_virtual(path) == emf_bool_false, "emf_fs_get_native_path_length()")
    return emf_binding_interface->fs_get_native_path_length_fn(path);
}

size_t EMF_CALL_C emf_fs_get_native_path(
    const emf_path_t* EMF_NOT_NULL path, emf_native_path_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_native_path()")
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_fs_get_native_path()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_get_native_path()")
    EMF_ASSERT_ERROR(emf_fs_is_virtual(path) == emf_bool_false, "emf_fs_get_native_path()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_fs_get_native_path()")
    EMF_ASSERT_ERROR(buffer->length >= emf_fs_get_native_path_length(path), "emf_fs_get_native_path()")
    return emf_binding_interface->fs_get_native_path_fn(path, buffer);
}

EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_num_file_handlers() EMF_NOEXCEPT
{
    return emf_binding_interface->fs_get_num_file_handlers_fn();
}

size_t EMF_CALL_C emf_fs_get_file_handlers(emf_file_handler_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_fs_get_file_handlers()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_fs_get_file_handlers()")
    EMF_ASSERT_ERROR(buffer->length >= emf_fs_get_num_file_handlers(), "emf_fs_get_file_handlers()")
    return emf_binding_interface->fs_get_file_handlers_fn(buffer);
}

EMF_NODISCARD emf_file_handler_t EMF_CALL_C emf_fs_get_file_handler_from_type(
    const emf_file_type_t* EMF_NOT_NULL type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(type != nullptr, "emf_fs_get_file_handler_from_type()")
    EMF_ASSERT_ERROR(emf_fs_type_exists(type) == emf_bool_true, "emf_fs_get_file_handler_from_type()")
    return emf_binding_interface->fs_get_file_handler_from_type_fn(type);
}

EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_num_file_types() EMF_NOEXCEPT
{
    return emf_binding_interface->fs_get_num_file_types_fn();
}

size_t EMF_CALL_C emf_fs_get_file_types(emf_file_type_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_fs_get_file_types()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_fs_get_file_types()")
    EMF_ASSERT_ERROR(buffer->length >= emf_fs_get_num_file_types(), "emf_fs_get_file_types()")
    return emf_binding_interface->fs_get_file_types_fn(buffer);
}

EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_num_handler_file_types(emf_file_handler_t file_handler) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_get_num_handler_file_types_fn(file_handler);
}

size_t EMF_CALL_C emf_fs_get_handler_file_types(
    emf_file_handler_t file_handler, emf_file_type_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_fs_get_file_types()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_fs_get_file_types()")
    EMF_ASSERT_ERROR(buffer->length >= emf_fs_get_num_handler_file_types(file_handler), "emf_fs_get_file_types()")
    return emf_binding_interface->fs_get_handler_file_types_fn(file_handler, buffer);
}

EMF_NODISCARD emf_path_t EMF_CALL_C emf_fs_normalize(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_normalize()")
    return emf_binding_interface->fs_normalize_fn(path);
}

EMF_NODISCARD emf_path_t EMF_CALL_C emf_fs_get_parent(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_get_parent()")
    return emf_binding_interface->fs_get_parent_fn(path);
}

EMF_NODISCARD emf_path_t EMF_CALL_C emf_fs_join(
    const emf_path_t* EMF_NOT_NULL lhs, const emf_path_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(lhs != nullptr, "emf_fs_join()")
    EMF_ASSERT_ERROR(rhs != nullptr, "emf_fs_join()")
    return emf_binding_interface->fs_join_fn(lhs, rhs);
}

EMF_NODISCARD emf_mount_id_t EMF_CALL_C emf_fs_unsafe_create_mount_id(const emf_path_t* EMF_NOT_NULL mount_point) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(mount_point != nullptr, "emf_fs_unsafe_create_mount_id()")
    EMF_ASSERT_ERROR(emf_fs_exists(mount_point) == emf_bool_false, "emf_fs_unsafe_create_mount_id()")

#ifdef EMF_ENABLE_ERROR_CHECKING
    auto mount_point_parent { emf_fs_get_parent(mount_point) };
    EMF_ASSERT_ERROR(emf_fs_exists(&mount_point_parent) == emf_bool_true, "emf_fs_unsafe_create_mount_id()")
    EMF_ASSERT_ERROR(emf_fs_get_access_mode(&mount_point_parent) == emf_file_access_mode_write, "emf_fs_unsafe_create_mount_id()")
#endif

    return emf_binding_interface->fs_unsafe_create_mount_id_fn(mount_point);
}

void EMF_CALL_C emf_fs_unsafe_remove_mount_id(emf_mount_id_t mount_id) EMF_NOEXCEPT
{
    emf_binding_interface->fs_unsafe_remove_mount_id_fn(mount_id);
}

void EMF_CALL_C emf_fs_unsafe_unmount_force(emf_mount_id_t mount_id) EMF_NOEXCEPT
{
    emf_binding_interface->fs_unsafe_unmount_force_fn(mount_id);
}

void EMF_CALL_C emf_fs_unsafe_link_mount_point(
    emf_mount_id_t mount_id, emf_file_handler_t file_handler, emf_file_handler_mount_id_t file_handler_mount_id) EMF_NOEXCEPT
{
    emf_binding_interface->fs_unsafe_link_mount_point_fn(mount_id, file_handler, file_handler_mount_id);
}

EMF_NODISCARD emf_file_stream_t EMF_CALL_C emf_fs_unsafe_create_file_stream() EMF_NOEXCEPT
{
    return emf_binding_interface->fs_unsafe_create_file_stream_fn();
}

void EMF_CALL_C emf_fs_unsafe_remove_file_stream(emf_file_stream_t file_stream) EMF_NOEXCEPT
{
    emf_binding_interface->fs_unsafe_remove_file_stream_fn(file_stream);
}

void EMF_CALL_C emf_fs_unsafe_link_file_stream(
    emf_file_stream_t file_stream, emf_file_handler_t file_handler, emf_file_handler_stream_t file_handler_stream) EMF_NOEXCEPT
{
    emf_binding_interface->fs_unsafe_link_file_stream_fn(file_stream, file_handler, file_handler_stream);
}

EMF_NODISCARD emf_file_handler_t EMF_CALL_C emf_fs_unsafe_get_file_handler_handle_from_stream(
    emf_file_stream_t stream) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_unsafe_get_file_handler_handle_from_stream_fn(stream);
}

EMF_NODISCARD emf_file_handler_t EMF_CALL_C emf_fs_unsafe_get_file_handler_handle_from_path(
    const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(path != nullptr, "emf_fs_unsafe_get_file_handler_handle_from_path()")
    EMF_ASSERT_ERROR(emf_fs_exists(path) == emf_bool_true, "emf_fs_unsafe_get_file_handler_handle_from_path()")
    EMF_ASSERT_ERROR(emf_fs_is_virtual(path) == emf_bool_false || emf_fs_get_entry_type(path) == emf_fs_entry_type_mount_point,
        "emf_fs_unsafe_get_file_handler_handle_from_path()")
    return emf_binding_interface->fs_unsafe_get_file_handler_handle_from_path_fn(path);
}

EMF_NODISCARD emf_file_handler_stream_t EMF_CALL_C emf_fs_unsafe_get_file_handler_stream(
    emf_file_stream_t file_stream) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_unsafe_get_file_handler_stream_fn(file_stream);
}

EMF_NODISCARD emf_file_handler_mount_id_t EMF_CALL_C emf_fs_unsafe_get_file_handler_mount_id(emf_mount_id_t mount_id) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_unsafe_get_file_handler_mount_id_fn(mount_id);
}

EMF_NODISCARD emf_file_handler_interface_t EMF_CALL_C emf_fs_unsafe_get_file_handler(emf_file_handler_t file_handler) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_unsafe_get_file_handler_fn(file_handler);
}

EMF_NODISCARD emf_file_stream_t EMF_CALL_C emf_fs_stream_open(const emf_path_t* EMF_NOT_NULL filename,
    emf_file_open_mode_t open_mode, emf_access_mode_t access_mode, const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(filename != nullptr, "emf_fs_stream_open()")
    EMF_ASSERT_ERROR(emf_fs_get_entry_type(filename) == emf_fs_entry_type_file, "emf_fs_stream_open()")
    EMF_ASSERT_ERROR(emf_fs_can_access(filename, access_mode) == emf_bool_true, "emf_fs_stream_open()")
    return emf_binding_interface->fs_stream_open_fn(filename, open_mode, access_mode, options);
}

void EMF_CALL_C emf_fs_stream_close(emf_file_stream_t stream) EMF_NOEXCEPT { emf_binding_interface->fs_stream_close_fn(stream); }

void EMF_CALL_C emf_fs_stream_flush(emf_file_stream_t stream) EMF_NOEXCEPT { emf_binding_interface->fs_stream_flush_fn(stream); }

size_t EMF_CALL_C emf_fs_stream_read(
    emf_file_stream_t stream, emf_fs_buffer_t* EMF_NOT_NULL buffer, size_t read_count) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_fs_stream_read()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_fs_stream_read()")
    EMF_ASSERT_ERROR(buffer->length >= read_count, "emf_fs_stream_read()")
    return emf_binding_interface->fs_stream_read_fn(stream, buffer, read_count);
}

size_t EMF_CALL_C emf_fs_stream_write(
    emf_file_stream_t stream, const emf_fs_buffer_t* EMF_NOT_NULL buffer, size_t write_count) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_fs_stream_write()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_fs_stream_write()")
    EMF_ASSERT_ERROR(buffer->length >= write_count, "emf_fs_stream_write()")
    EMF_ASSERT_ERROR(emf_fs_stream_can_write(stream) == emf_bool_true, "emf_fs_stream_write()")
    return emf_binding_interface->fs_stream_write_fn(stream, buffer, write_count);
}

EMF_NODISCARD emf_pos_t EMF_CALL_C emf_fs_stream_get_pos(emf_file_stream_t stream) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_stream_get_pos_fn(stream);
}

emf_off_t EMF_CALL_C emf_fs_stream_set_pos(emf_file_stream_t stream, emf_pos_t position) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_stream_set_pos_fn(stream, position);
}

emf_off_t EMF_CALL_C emf_fs_stream_move_pos(emf_file_stream_t stream, emf_off_t offset, emf_fs_direction_t direction) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_stream_move_pos_fn(stream, offset, direction);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_stream_can_write(emf_file_stream_t stream) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_stream_can_write_fn(stream);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_stream_can_grow(emf_file_stream_t stream, size_t size) EMF_NOEXCEPT
{
    return emf_binding_interface->fs_stream_can_grow_fn(stream, size);
}
}

}