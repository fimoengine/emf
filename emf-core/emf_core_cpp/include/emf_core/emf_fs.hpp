#ifndef EMF_C_EMF_FS_HPP
#define EMF_C_EMF_FS_HPP

#ifdef __cplusplus

#include <emf_core/emf_fs.h>

#include <functional>
#include <optional>
#include <span>
#include <string_view>

namespace EMF::FS {

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/**
 * See emf_fs_register_file_handler()
 */
inline C::emf_file_handler_t register_file_handler(
    const C::emf_file_handler_interface_t& file_handler, std::span<const C::emf_file_type_t> file_types) noexcept
{
    const C::emf_file_type_span_t c_file_types { file_types.data(), file_types.size() };
    return C::emf_fs_register_file_handler(&file_handler, &c_file_types);
}

/**
 * See emf_fs_remove_file_handler()
 */
inline void remove_file_handler(C::emf_file_handler_t file_handler) noexcept { C::emf_fs_remove_file_handler(file_handler); }

/**
 * See emf_fs_create_file()
 */
template <typename T>
inline void create_file(
    const C::emf_path_t& filename, std::optional<std::reference_wrapper<const T>> options = std::nullopt) noexcept
{
    if (options) {
        auto options_ptr { static_cast<const void*>(&options->get()) };
        C::emf_fs_create_file(&filename, options_ptr);
    } else {
        C::emf_fs_create_file(&filename, nullptr);
    }
}

/**
 * See emf_fs_create_link()
 */
inline void create_link(const C::emf_path_t& source, const C::emf_path_t& destination, C::emf_fs_link_t type) noexcept
{
    C::emf_fs_create_link(&source, &destination, type);
}

/**
 * See emf_fs_create_directory()
 */
template <typename T>
inline void create_directory(
    const C::emf_path_t& path, std::optional<std::reference_wrapper<const T>> options = std::nullopt) noexcept
{
    if (options) {
        auto options_ptr { static_cast<const void*>(&options->get()) };
        C::emf_fs_create_directory(&path, options_ptr);
    } else {
        C::emf_fs_create_directory(&path, nullptr);
    }
}

/**
 * See emf_fs_delete()
 */
inline void delete_entry(const C::emf_path_t& path, bool recursive) noexcept
{
    C::emf_fs_delete(&path, static_cast<C::emf_bool_t>(recursive));
}

/**
 * See emf_fs_mount_memory_file()
 */
template <typename T>
inline C::emf_mount_id_t mount(C::emf_file_handler_t file_handler, std::span<const std::byte> file,
    C::emf_access_mode_t access_mode, const C::emf_path_t& mount_point,
    std::optional<std::reference_wrapper<const T>> options = std::nullopt) noexcept
{
    const C::emf_memory_span_t c_file { file.data(), file.size() };
    if (options) {
        auto options_ptr { static_cast<const void*>(&options->get()) };
        return C::emf_fs_mount_memory_file(file_handler, &c_file, access_mode, &mount_point, options_ptr);
    } else {
        return C::emf_fs_mount_memory_file(file_handler, &c_file, access_mode, &mount_point, nullptr);
    }
}

/**
 * See emf_fs_mount_native_path()
 */
template <typename T>
inline C::emf_mount_id_t mount(C::emf_file_handler_t file_handler, std::basic_string_view<C::emf_native_path_char_t> path,
    C::emf_access_mode_t access_mode, const C::emf_path_t& mount_point,
    std::optional<std::reference_wrapper<const T>> options = std::nullopt) noexcept
{
    if (options) {
        auto options_ptr { static_cast<const void*>(&options->get()) };
        return C::emf_fs_mount_native_path(file_handler, path.data(), access_mode, &mount_point, options_ptr);
    } else {
        return C::emf_fs_mount_native_path(file_handler, path.data(), access_mode, &mount_point, nullptr);
    }
}

/**
 * See emf_fs_unmount()
 */
EMF_NODISCARD inline bool unmount(C::emf_mount_id_t mount_id) noexcept { return C::emf_fs_unmount(mount_id); }

/**
 * See emf_fs_set_access_mode()
 */
inline void set_access_mode(const C::emf_path_t& path, C::emf_access_mode_t access_mode, bool recursive) noexcept
{
    C::emf_fs_set_access_mode(&path, access_mode, static_cast<C::emf_bool_t>(recursive));
}

/**
 * See emf_fs_get_access_mode()
 */
EMF_NODISCARD inline C::emf_access_mode_t get_access_mode(const C::emf_path_t& path) noexcept
{
    return C::emf_fs_get_access_mode(&path);
}

/**
 * See emf_fs_get_mount_id()
 */
EMF_NODISCARD inline C::emf_mount_id_t get_mount_id(const C::emf_path_t& path) noexcept { return C::emf_fs_get_mount_id(&path); }

/**
 * See emf_fs_can_access()
 */
EMF_NODISCARD inline bool can_access(const C::emf_path_t& path, C::emf_access_mode_t access_mode) noexcept
{
    return static_cast<bool>(C::emf_fs_can_access(&path, access_mode));
}

/**
 * See emf_fs_can_set_access_mode()
 */
EMF_NODISCARD inline bool can_set_access_mode(
    const C::emf_path_t& path, C::emf_access_mode_t access_mode, bool recursive) noexcept
{
    return static_cast<bool>(C::emf_fs_can_set_access_mode(&path, access_mode, static_cast<C::emf_bool_t>(recursive)));
}

/**
 * See emf_fs_is_virtual()
 */
EMF_NODISCARD inline bool is_virtual(const C::emf_path_t& path) noexcept
{
    return static_cast<bool>(C::emf_fs_is_virtual(&path));
}

/**
 * See emf_fs_can_delete()
 */
EMF_NODISCARD inline bool can_delete(const C::emf_path_t& path, bool recursive) noexcept
{
    return static_cast<bool>(C::emf_fs_can_delete(&path, static_cast<C::emf_bool_t>(recursive)));
}

/**
 * See emf_fs_can_mount_type()
 */
EMF_NODISCARD inline bool can_mount(const C::emf_file_handler_t file_handler, const C::emf_file_type_t& type) noexcept
{
    return static_cast<bool>(C::emf_fs_can_mount_type(file_handler, &type));
}

/**
 * See emf_fs_can_mount_native_path()
 */
EMF_NODISCARD inline bool can_mount(
    const C::emf_file_handler_t file_handler, std::basic_string_view<C::emf_native_path_char_t> path) noexcept
{
    return static_cast<bool>(C::emf_fs_can_mount_native_path(file_handler, path.data()));
}

/**
 * See emf_fs_get_num_entries()
 */
EMF_NODISCARD inline std::size_t get_num_entries(const C::emf_path_t& path, bool recursive) noexcept
{
    return C::emf_fs_get_num_entries(&path, static_cast<C::emf_bool_t>(recursive));
}

/**
 * See emf_fs_get_entries()
 */
inline std::size_t get_entries(const C::emf_path_t& path, bool recursive, std::span<C::emf_path_t> buffer) noexcept
{
    C::emf_path_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_fs_get_entries(&path, static_cast<C::emf_bool_t>(recursive), &c_buffer);
}

/**
 * See emf_fs_exists()
 */
EMF_NODISCARD inline bool exists(const C::emf_path_t& path) noexcept
{
    return static_cast<C::emf_bool_t>(C::emf_fs_exists(&path));
}

/**
 * See emf_fs_type_exists()
 */
EMF_NODISCARD inline bool type_exists(const C::emf_file_type_t& type) noexcept
{
    return static_cast<C::emf_bool_t>(C::emf_fs_type_exists(&type));
}

/**
 * See emf_fs_get_entry_type()
 */
EMF_NODISCARD inline C::emf_fs_entry_type_t get_entry_type(const C::emf_path_t& path) noexcept
{
    return C::emf_fs_get_entry_type(&path);
}

/**
 * See emf_fs_resolve_link()
 */
EMF_NODISCARD inline C::emf_path_t resolve_link(const C::emf_path_t& path) noexcept { return C::emf_fs_resolve_link(&path); }

/**
 * See emf_fs_get_link_type()
 */
EMF_NODISCARD inline C::emf_fs_link_t get_link_type(const C::emf_path_t& path) noexcept { return C::emf_fs_get_link_type(&path); }

/**
 * See emf_fs_get_size()
 */
EMF_NODISCARD inline C::emf_entry_size_t get_size(const C::emf_path_t& path) noexcept { return C::emf_fs_get_size(&path); }

/**
 * See emf_fs_get_native_path_length()
 */
EMF_NODISCARD inline std::size_t get_native_path_length(const C::emf_path_t& path) noexcept
{
    return C::emf_fs_get_native_path_length(&path);
}

/**
 * See emf_fs_get_native_path()
 */
inline std::size_t get_native_path(const C::emf_path_t& path, std::span<C::emf_native_path_char_t> buffer) noexcept
{
    C::emf_native_path_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_fs_get_native_path(&path, &c_buffer);
}

/**
 * See emf_fs_get_num_file_handlers()
 */
EMF_NODISCARD inline std::size_t get_num_file_handlers() noexcept { return C::emf_fs_get_num_file_handlers(); }

/**
 * See emf_fs_get_file_handlers()
 */
inline std::size_t get_file_handlers(std::span<C::emf_file_handler_t> buffer) noexcept
{
    C::emf_file_handler_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_fs_get_file_handlers(&c_buffer);
}

/**
 * See emf_fs_get_file_handler_from_type()
 */
EMF_NODISCARD inline C::emf_file_handler_t get_file_handler(const C::emf_file_type_t& type) noexcept
{
    return C::emf_fs_get_file_handler_from_type(&type);
}

/**
 * See emf_fs_get_num_file_types()
 */
EMF_NODISCARD inline std::size_t get_num_file_types() noexcept { return C::emf_fs_get_num_file_types(); }

/**
 * See emf_fs_get_file_types()
 */
inline std::size_t get_file_types(std::span<C::emf_file_type_t> buffer) noexcept
{
    C::emf_file_type_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_fs_get_file_types(&c_buffer);
}

/**
 * See emf_fs_get_num_handler_file_types()
 */
EMF_NODISCARD inline std::size_t get_num_file_types(C::emf_file_handler_t file_handler) noexcept
{
    return C::emf_fs_get_num_handler_file_types(file_handler);
}

/**
 * See emf_fs_get_handler_file_types()
 */
inline std::size_t get_file_types(C::emf_file_handler_t file_handler, std::span<C::emf_file_type_t> buffer) noexcept
{
    C::emf_file_type_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_fs_get_handler_file_types(file_handler, &c_buffer);
}

/**
 * See emf_fs_normalize()
 */
EMF_NODISCARD inline C::emf_path_t normalize(const C::emf_path_t& path) noexcept { return C::emf_fs_normalize(&path); }

/**
 * See emf_fs_get_parent()
 */
EMF_NODISCARD inline C::emf_path_t get_parent(const C::emf_path_t& path) noexcept { return C::emf_fs_get_parent(&path); }

/**
 * See emf_fs_join()
 */
EMF_NODISCARD inline C::emf_path_t join(const C::emf_path_t& lhs, const C::emf_path_t& rhs) noexcept
{
    return C::emf_fs_join(&lhs, &rhs);
}

namespace Unsafe {

    /**
     * See emf_fs_unsafe_create_mount_id()
     */
    EMF_NODISCARD inline C::emf_mount_id_t create_mount_id(const C::emf_path_t& path) noexcept
    {
        return C::emf_fs_unsafe_create_mount_id(&path);
    }

    /**
     * See emf_fs_unsafe_remove_mount_id()
     */
    inline void remove_mount_id(C::emf_mount_id_t mount_id) noexcept { C::emf_fs_unsafe_remove_mount_id(mount_id); }

    /**
     * See emf_fs_unsafe_unmount_force()
     */
    inline void unmount_force(C::emf_mount_id_t mount_id) noexcept { C::emf_fs_unsafe_unmount_force(mount_id); }

    /**
     * See emf_fs_unsafe_link_mount_point()
     */
    inline void link_mount_point(C::emf_mount_id_t mount_id, C::emf_file_handler_t file_handler,
        C::emf_file_handler_mount_id_t file_handler_mount_id) noexcept
    {
        C::emf_fs_unsafe_link_mount_point(mount_id, file_handler, file_handler_mount_id);
    }

    /**
     * See emf_fs_unsafe_create_file_stream()
     */
    EMF_NODISCARD inline C::emf_file_stream_t create_file_stream() noexcept { return C::emf_fs_unsafe_create_file_stream(); }

    /**
     * See emf_fs_unsafe_remove_file_stream()
     */
    inline void remove_file_stream(C::emf_file_stream_t file_stream) noexcept
    {
        C::emf_fs_unsafe_remove_file_stream(file_stream);
    }

    /**
     * See emf_fs_unsafe_link_file_stream()
     */
    inline void link_file_stream(C::emf_file_stream_t file_stream, C::emf_file_handler_t file_handler,
        C::emf_file_handler_stream_t file_handler_stream) noexcept
    {
        C::emf_fs_unsafe_link_file_stream(file_stream, file_handler, file_handler_stream);
    }

    /**
     * See emf_fs_unsafe_get_file_handler_handle_from_stream()
     */
    EMF_NODISCARD inline C::emf_file_handler_t get_file_handler(C::emf_file_stream_t file_stream) noexcept
    {
        return C::emf_fs_unsafe_get_file_handler_handle_from_stream(file_stream);
    }

    /**
     * See emf_fs_unsafe_get_file_handler_handle_from_path()
     */
    EMF_NODISCARD inline C::emf_file_handler_t get_file_handler(const C::emf_path_t& path) noexcept
    {
        return C::emf_fs_unsafe_get_file_handler_handle_from_path(&path);
    }

    /**
     * See emf_fs_unsafe_get_file_handler_stream()
     */
    EMF_NODISCARD inline C::emf_file_handler_stream_t get_file_handler_stream(C::emf_file_stream_t file_stream) noexcept
    {
        return C::emf_fs_unsafe_get_file_handler_stream(file_stream);
    }

    /**
     * See emf_fs_unsafe_get_file_handler_mount_id()
     */
    EMF_NODISCARD inline C::emf_file_handler_mount_id_t get_file_handler_mount_id(C::emf_mount_id_t mount_id) noexcept
    {
        return C::emf_fs_unsafe_get_file_handler_mount_id(mount_id);
    }

    /**
     * See emf_fs_unsafe_get_file_handler()
     */
    EMF_NODISCARD inline C::emf_file_handler_interface_t get_file_handler(C::emf_file_handler_t file_handler) noexcept
    {
        return C::emf_fs_unsafe_get_file_handler(file_handler);
    }

}

/**
 * See emf_fs_stream_open()
 */
template <typename T>
EMF_NODISCARD inline C::emf_file_stream_t stream_open(const C::emf_path_t& filename, C::emf_file_open_mode_t open_mode,
    C::emf_access_mode_t access_mode, std::optional<std::reference_wrapper<const T>> options = std::nullopt) noexcept
{
    if (options) {
        auto options_ptr { static_cast<const void*>(&options->get()) };
        return C::emf_fs_stream_open(&filename, open_mode, access_mode, options_ptr);
    } else {
        return C::emf_fs_stream_open(&filename, open_mode, access_mode, nullptr);
    }
}

/**
 * See emf_fs_stream_close()
 */
inline void stream_close(C::emf_file_stream_t stream) noexcept { C::emf_fs_stream_close(stream); }

/**
 * See emf_fs_stream_flush()
 */
inline void stream_flush(C::emf_file_stream_t stream) noexcept { C::emf_fs_stream_flush(stream); }

/**
 * See emf_fs_stream_read()
 */
inline std::size_t stream_read(C::emf_file_stream_t stream, std::span<char> buffer, std::size_t read_count) noexcept
{
    C::emf_fs_buffer_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_fs_stream_read(stream, &c_buffer, read_count);
}

/**
 * See emf_fs_stream_write()
 */
inline std::size_t stream_write(C::emf_file_stream_t stream, std::span<const char> buffer, std::size_t write_count) noexcept
{
    const C::emf_fs_buffer_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_fs_stream_write(stream, &c_buffer, write_count);
}

/**
 * See emf_fs_stream_get_pos()
 */
EMF_NODISCARD inline C::emf_pos_t stream_get_pos(C::emf_file_stream_t stream) noexcept
{
    return C::emf_fs_stream_get_pos(stream);
}

/**
 * See emf_fs_stream_set_pos()
 */
inline C::emf_off_t stream_set_pos(C::emf_file_stream_t stream, C::emf_pos_t pos) noexcept
{
    return C::emf_fs_stream_set_pos(stream, pos);
}

/**
 * See emf_fs_stream_move_pos()
 */
inline C::emf_off_t stream_move_pos(C::emf_file_stream_t stream, C::emf_off_t offset, C::emf_fs_direction_t direction) noexcept
{
    return C::emf_fs_stream_move_pos(stream, offset, direction);
}

/**
 * See emf_fs_stream_can_write()
 */
EMF_NODISCARD inline bool stream_can_write(C::emf_file_stream_t stream) noexcept
{
    return static_cast<bool>(C::emf_fs_stream_can_write(stream));
}

/**
 * See emf_fs_stream_can_grow()
 */
EMF_NODISCARD inline bool stream_can_write(C::emf_file_stream_t stream, std::size_t size) noexcept
{
    return static_cast<bool>(C::emf_fs_stream_can_grow(stream, size));
}

}

#endif // __cplusplus

#endif // !EMF_C_EMF_FS_HPP
