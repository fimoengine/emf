#ifndef EMF_CORE_EMF_FS_H
#define EMF_CORE_EMF_FS_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core/emf_bool_t.h>
#include <emf_core/emf_error_t.h>
#include <emf_core/emf_macros.h>
#include <emf_core/emf_version_t.h>

/// The maximum length of a path.
#define EMF_PATH_MAX 1024

/// The maximum length of a file type string.
#define EMF_FILE_TYPE_MAX_LENGTH 64

/// The file type understood by the default `File handler`.
#define EMF_NATIVE_FILE_HANDLER_FILE_TYPE_NAME "emf::core::native"

#ifdef __cplusplus
#define EMF_PATH_INIT(PATH)                                                                                                      \
    emf_path_t { PATH, strlen(PATH) }

/// The handle of default the `File handler`.
#define EMF_FILE_HANDLER_DEFAULT_HANDLE                                                                                          \
    emf_file_handler_t { EMF::Core::C::emf_fs_predefined_handles_default }
#else
#define EMF_PATH_INIT(PATH)                                                                                                      \
    (emf_path_t) { PATH, strlen(PATH) }

/// The handle of default the `File handler`.
#define EMF_FILE_HANDLER_DEFAULT_HANDLE                                                                                          \
    (emf_file_handler_t) { emf_fs_predefined_handles_default }
#endif // __cplusplus

#ifdef __cplusplus
namespace EMF::Core::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

#ifdef _WIN32
#define EMF_NATIVE_PATH(TEXT) L##TEXT
#define EMF_NATIVE_PATH_CHAR_T wchar_t
#else
#define EMF_NATIVE_PATH(TEXT) TEXT
#define EMF_NATIVE_PATH_CHAR_T char
#endif // _WIN32

/**
 * The character type used by the system to represent paths.
 */
typedef EMF_NATIVE_PATH_CHAR_T emf_native_path_char_t;

/**
 * A path.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_path_t, char, EMF_PATH_MAX)

/**
 * Handle to a file handler.
 */
typedef struct emf_file_handler_t {
    /// File handler id.
    int32_t id;
} emf_file_handler_t;

/**
 * Handle to a mount point.
 */
typedef struct emf_mount_id_t {
    /// Mount point id.
    int32_t id;
} emf_mount_id_t;

/**
 * Handle to a file stream.
 */
typedef struct emf_file_stream_t {
    /// Stream id.
    int32_t id;
} emf_file_stream_t;

/**
 * Internal handle to a mount point.
 */
typedef struct emf_file_handler_mount_id_t {
    /// Internal id.
    int32_t id;
} emf_file_handler_mount_id_t;

/**
 * Internal handle to a file stream.
 */
typedef struct emf_file_handler_stream_t {
    /// Internal id.
    int32_t id;
} emf_file_handler_stream_t;

/**
 * Type of a file.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_file_type_t, char, EMF_FILE_TYPE_MAX_LENGTH)

/**
 * An offset from one point in a file to an other point.
 */
typedef struct emf_off_t {
    /// Offset.
    int64_t off;
} emf_off_t;

/**
 * A position in a file stream.
 */
typedef struct emf_pos_t {
    /// Position.
    uint64_t pos;
} emf_pos_t;

/**
 * The size of an entry.
 */
typedef struct emf_entry_size_t {
    /// Entry size.
    uint64_t size;
} emf_entry_size_t;

/// The possible types of a fs entry node.
///
/// # Variants
///
/// | Name                              | Value | Description         |
/// | --------------------------------- | ----- | ------------------- |
/// | **emf_fs_entry_type_file**        | `0`   | A file node.        |
/// | **emf_fs_entry_type_link**        | `1`   | A link node.        |
/// | **emf_fs_entry_type_directory**   | `2`   | A directory node.   |
/// | **emf_fs_entry_type_mount_point** | `3`   | A mount point node. |
typedef enum emf_fs_entry_type_t : int32_t {
    /// A file node.
    emf_fs_entry_type_file = 0,
    /// A link node.
    emf_fs_entry_type_link = 1,
    /// A directory node.
    emf_fs_entry_type_directory = 2,
    /// A mount point node.
    emf_fs_entry_type_mount_point = 3
} emf_fs_entry_type_t;

/// The starting position from which a stream can be seeked.
///
/// # Variants
///
/// | Name                         | Value | Description                                   |
/// | ---------------------------- | ----- | --------------------------------------------- |
/// | **emf_fs_direction_begin**   | `0`   | Seek starting at the beginning of the stream. |
/// | **emf_fs_direction_current** | `1`   | Seek starting at the current position.        |
/// | **emf_fs_direction_end**     | `2`   | Seek starting at the end of the stream.       |
typedef enum emf_fs_direction_t : int32_t {
    /// Seek starting at the beginning of the stream.
    emf_fs_direction_begin = 0,
    /// Seek starting at the current position.
    emf_fs_direction_current = 1,
    /// Seek starting at the end of the stream.
    emf_fs_direction_end = 2
} emf_fs_direction_t;

/// The types of possible links.
///
/// # Variants
///
/// | Name                     | Value | Description               |
/// | ------------------------ | ----- | ------------------------- |
/// | **emf_fs_link_symlink**  | `0`   | A weak link.              |
/// | **emf_fs_link_hardlink** | `1`   | A reference counted link. |
typedef enum emf_fs_link_t : int32_t {
    /// A weak link.
    emf_fs_link_symlink = 0,
    /// A reference counted link.
    emf_fs_link_hardlink = 1
} emf_fs_link_t;

/// Modes in which a file can be opened.
///
/// # Variants
///
/// | Name                         | Value | Description            |
/// | ---------------------------- | ----- | ---------------------- |
/// | **emf_file_open_mode_begin** | `0`   | Open at the beginning. |
/// | **emf_file_open_mode_end**   | `1`   | Open at the end.       |
typedef enum emf_file_open_mode_t : int32_t {
    /// Open at the beginning.
    emf_file_open_mode_begin = 0,
    /// Open at the end.
    emf_file_open_mode_end = 1
} emf_file_open_mode_t;

/// Access permissions of a node.
///
/// # Variants
///
/// | Name                           | Value | Description   |
/// | ------------------------------ | ----- | ------------- |
/// | **emf_file_access_mode_read**  | `0`   | Read access.  |
/// | **emf_file_access_mode_write** | `1`   | Write access. |
typedef enum emf_access_mode_t : int32_t {
    /// Read access.
    emf_file_access_mode_read = 0,
    /// Write access.
    emf_file_access_mode_write = 1
} emf_access_mode_t;

/// Predefined `File handler` handles.
///
/// > Note: The handles `0`-`99` are reserved.
/// > The handles `100`-`199` are implementation-defined.
///
/// # Variants
///
/// | Name                                  | Value | Description                         |
/// | ------------------------------------- | ----- | ----------------------------------- |
/// | **emf_fs_predefined_handles_default** | `0`   | Handle to the default file handler. |
typedef enum emf_fs_predefined_handles_t : int32_t {
    /// Handle to the default file handler.
    emf_fs_predefined_handles_default = 0,
} emf_fs_predefined_handles_t;

/**
 * A buffer of characters.
 */
EMF_SPAN_TYPEDEF(emf_fs_read_buffer_t, char)

/**
 * A buffer of characters.
 */
EMF_SPAN_TYPEDEF(emf_fs_write_buffer_t, const char)

/**
 * A memory buffer.
 */
EMF_SPAN_TYPEDEF(emf_memory_span_t, const void)

/**
 * A span of paths.
 */
EMF_SPAN_TYPEDEF(emf_path_span_t, emf_path_t)

/**
 * A span of file types.
 */
EMF_SPAN_TYPEDEF(emf_file_type_span_t, const emf_file_type_t)

/**
 * A span of file handlers.
 */
EMF_SPAN_TYPEDEF(emf_file_handler_span_t, emf_file_handler_t)

/**
 * A native path in span form.
 */
EMF_SPAN_TYPEDEF(emf_native_path_span_t, emf_native_path_char_t)

/******************************************************************************************************
*********************************************  Interface  *********************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf_file_handler_interface_create_file, void, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, const void* EMF_MAYBE_NULL options)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_create_directory, void, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, const void* EMF_MAYBE_NULL options)

EMF_FUNCTION_PTR_T(emf_file_handler_interface_delete, void, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_can_delete, EMF_NODISCARD emf_bool_t, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive)

EMF_FUNCTION_PTR_T(
    emf_file_handler_interface_can_mount_native_path, EMF_NODISCARD emf_bool_t, const emf_native_path_char_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_mount_memory_file, EMF_NODISCARD emf_file_handler_mount_id_t,
    const emf_memory_span_t* EMF_NOT_NULL file, emf_access_mode_t access_mode, const void* EMF_MAYBE_NULL options)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_mount_native_path, EMF_NODISCARD emf_file_handler_mount_id_t,
    const emf_native_path_char_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, const void* EMF_MAYBE_NULL options)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_unmount, void, emf_file_handler_mount_id_t mount_id)

EMF_FUNCTION_PTR_T(emf_file_handler_interface_set_access_mode, void, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_get_access_mode, EMF_NODISCARD emf_access_mode_t,
    emf_file_handler_mount_id_t mount_id, const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_can_access, EMF_NODISCARD emf_bool_t, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_can_set_access_mode, EMF_NODISCARD emf_bool_t, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, emf_bool_t recursive)

EMF_FUNCTION_PTR_T(emf_file_handler_interface_get_num_entries, EMF_NODISCARD size_t, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_get_entries, size_t, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive, emf_path_span_t* EMF_NOT_NULL buffer)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_get_size, EMF_NODISCARD emf_entry_size_t, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_exists, EMF_NODISCARD emf_bool_t, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path)

EMF_FUNCTION_PTR_T(emf_file_handler_interface_get_native_path_length, EMF_NODISCARD size_t, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_get_native_path, size_t, emf_file_handler_mount_id_t mount_id,
    const emf_path_t* EMF_NOT_NULL path, emf_native_path_span_t* EMF_NOT_NULL buffer)

EMF_FUNCTION_PTR_T(emf_file_handler_interface_stream_open, EMF_NODISCARD emf_file_handler_stream_t,
    emf_file_handler_mount_id_t mount_id, const emf_path_t* EMF_NOT_NULL path, emf_file_open_mode_t open_mode,
    emf_access_mode_t access_mode, const void* EMF_MAYBE_NULL options)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_stream_close, void, emf_file_handler_stream_t stream)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_stream_flush, void, emf_file_handler_stream_t stream)

EMF_FUNCTION_PTR_T(emf_file_handler_interface_stream_read, size_t, emf_file_handler_stream_t stream,
    emf_fs_read_buffer_t* EMF_NOT_NULL buffer, size_t read_count)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_stream_write, size_t, emf_file_handler_stream_t stream,
    const emf_fs_write_buffer_t* EMF_NOT_NULL buffer, size_t write_count)

EMF_FUNCTION_PTR_T(emf_file_handler_interface_stream_get_pos, EMF_NODISCARD emf_pos_t, emf_file_handler_stream_t stream)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_stream_set_pos, emf_off_t, emf_file_handler_stream_t stream, emf_pos_t position)
EMF_FUNCTION_PTR_T(emf_file_handler_interface_stream_move_pos, emf_off_t, emf_file_handler_stream_t stream, emf_off_t offset,
    emf_fs_direction_t direction)

EMF_FUNCTION_PTR_T(emf_file_handler_interface_stream_can_write, EMF_NODISCARD emf_bool_t, emf_file_handler_stream_t stream)
EMF_FUNCTION_PTR_T(
    emf_file_handler_interface_stream_can_grow, EMF_NODISCARD emf_bool_t, emf_file_handler_stream_t stream, size_t size)

typedef struct emf_file_handler_interface_t {
    /// Interface version.
    emf_version_t interface_version;

    /// Create file function.
    emf_file_handler_interface_create_file_fn_t EMF_NOT_NULL create_file_fn;
    /// Create directory function.
    emf_file_handler_interface_create_directory_fn_t EMF_NOT_NULL create_directory_fn;

    /// Delete function.
    emf_file_handler_interface_delete_fn_t EMF_NOT_NULL delete_fn;
    /// Can delete function.
    emf_file_handler_interface_can_delete_fn_t EMF_NOT_NULL can_delete_fn;

    /// Can mount native path function.
    emf_file_handler_interface_can_mount_native_path_fn_t EMF_NOT_NULL can_mount_native_path_fn;
    /// Mount memory file function.
    emf_file_handler_interface_mount_memory_file_fn_t EMF_NOT_NULL mount_memory_file_fn;
    /// Mount native path function.
    emf_file_handler_interface_mount_native_path_fn_t EMF_NOT_NULL mount_native_path_fn;
    /// Unmount function.
    emf_file_handler_interface_unmount_fn_t EMF_NOT_NULL unmount_fn;

    /// Set access mode function.
    emf_file_handler_interface_set_access_mode_fn_t EMF_NOT_NULL set_access_mode_fn;
    /// Get access mode function.
    emf_file_handler_interface_get_access_mode_fn_t EMF_NOT_NULL get_access_mode_fn;
    /// Can access function.
    emf_file_handler_interface_can_access_fn_t EMF_NOT_NULL can_access_fn;
    /// Can set access mode function.
    emf_file_handler_interface_can_set_access_mode_fn_t EMF_NOT_NULL can_set_access_mode_fn;

    /// Get num entries function.
    emf_file_handler_interface_get_num_entries_fn_t EMF_NOT_NULL get_num_entries_fn;
    /// Get entries function.
    emf_file_handler_interface_get_entries_fn_t EMF_NOT_NULL get_entries_fn;
    /// Get size function.
    emf_file_handler_interface_get_size_fn_t EMF_NOT_NULL get_size_fn;
    /// Exists function.
    emf_file_handler_interface_exists_fn_t EMF_NOT_NULL exists_fn;

    /// Get native path length function.
    emf_file_handler_interface_get_native_path_length_fn_t EMF_NOT_NULL get_native_path_length_fn;
    /// Get native path function.
    emf_file_handler_interface_get_native_path_fn_t EMF_NOT_NULL get_native_path_fn;

    /// Open stream function.
    emf_file_handler_interface_stream_open_fn_t EMF_NOT_NULL stream_open_fn;
    /// Close stream function.
    emf_file_handler_interface_stream_close_fn_t EMF_NOT_NULL stream_close_fn;
    /// Flush stream function.
    emf_file_handler_interface_stream_flush_fn_t EMF_NOT_NULL stream_flush_fn;

    /// Read from stream function.
    emf_file_handler_interface_stream_read_fn_t EMF_NOT_NULL stream_read_fn;
    /// Write to stream function.
    emf_file_handler_interface_stream_write_fn_t EMF_NOT_NULL stream_write_fn;

    /// Get position of the stream function.
    emf_file_handler_interface_stream_get_pos_fn_t EMF_NOT_NULL stream_get_pos_fn;
    /// Set position of the stream function.
    emf_file_handler_interface_stream_set_pos_fn_t EMF_NOT_NULL stream_set_pos_fn;
    /// Move stream function.
    emf_file_handler_interface_stream_move_pos_fn_t EMF_NOT_NULL stream_move_pos_fn;

    /// Can write to stream function.
    emf_file_handler_interface_stream_can_write_fn_t EMF_NOT_NULL stream_can_write_fn;
    /// Stream can grow function.
    emf_file_handler_interface_stream_can_grow_fn_t EMF_NOT_NULL stream_can_grow_fn;
} emf_file_handler_interface_t;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/**
 * @brief Registers a new file handler.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>file_handler</code> may not be <code>NULL</code>.
 * @pre <code>file_types</code> may not be <code>NULL</code>.
 * @pre <code>file_types.data != NULL && file_types.length > 0</code>.
 *
 * @post A new file handler is registered.
 *
 * @param file_handler File handler interface.
 * @param file_types Supported file types.
 *
 * @return A handle to the file handler.
 */
emf_file_handler_t EMF_CALL_C emf_fs_register_file_handler(const emf_file_handler_interface_t* EMF_NOT_NULL file_handler,
    const emf_file_type_span_t* EMF_NOT_NULL file_types) EMF_NOEXCEPT;

/**
 * @brief Removes the file handler from the system.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 *
 * @post The file handler is removed.
 * @post All streams opened with the file_handler will be closed.
 * @post All paths mounted with the file_handler will be unmounted.
 * @post <code>file_handler</code> is invalidated.
 *
 * @param file_handler File handler.
 */
void EMF_CALL_C emf_fs_remove_file_handler(emf_file_handler_t file_handler) EMF_NOEXCEPT;

/**
 * @brief Creates an empty file.
 *
 * @note Requires synchronisation.
 * @note The file has write permissions.
 *
 * @pre The paths must be normalized.
 * @pre <code>filename</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(filename) == emf_bool_false</code>.
 * @pre <code>emf_fs_exists(&emf_fs_get_parent(filename)) == emf_bool_true</code>.
 * @pre <code>emf_fs_is_virtual(&emf_fs_get_parent(filename)) == emf_bool_false</code>.
 * @pre <code>emf_fs_get_access_mode(&emf_fs_get_parent(filename)) == emf_file_access_mode_write</code>.
 *
 * @post A new file is created.
 *
 * @param filename File path.
 * @param options Creation options.
 */
void EMF_CALL_C emf_fs_create_file(const emf_path_t* EMF_NOT_NULL filename, const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT;

/**
 * @brief Creates a link from one path to another.
 *
 * @note Requires synchronisation.
 * @note In this context emf_fs_link_symlink can be thought of as a pointer.
 * @note In this context emf_fs_link_hardlink can be thought of as a reference counted pointer.
 *
 * @pre The paths must be normalized.
 * @pre <code>source</code> may not be <code>NULL</code>.
 * @pre <code>destination</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(source) == emf_bool_true</code>.
 * @pre <code>emf_fs_exists(destination) == emf_bool_false</code>.
 * @pre <code>emf_fs_exists(&emf_fs_get_parent(destination)) == emf_bool_true</code>.
 * @pre <code>emf_fs_is_virtual(source) == emf_bool_false</code>.
 * @pre <code>emf_fs_is_virtual(&emf_fs_get_parent(destination)) == emf_bool_true</code>.
 * @pre <code>emf_fs_get_access_mode(&emf_fs_get_parent(destination)) == emf_file_access_mode_write</code>.
 *
 * @post A new virtual link is created.
 *
 * @param source Where the link will point to.
 * @param destination Path of the link.
 * @param type Link type.
 */
void EMF_CALL_C emf_fs_create_link(
    const emf_path_t* EMF_NOT_NULL source, const emf_path_t* EMF_NOT_NULL destination, emf_fs_link_t type) EMF_NOEXCEPT;

/**
 * @brief Created a directory.
 *
 * @note Requires synchronisation.
 * @note The directory has write permissions.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_false</code>.
 * @pre <code>emf_fs_exists(&emf_fs_get_parent(path)) == emf_bool_true</code>.
 * @pre <code>emf_fs_get_access_mode(&emf_fs_get_parent(path)) == emf_file_access_mode_write</code>.
 *
 * @post A new directory is created.
 *
 * @param path Directory path.
 * @param options Directory creation options.
 */
void EMF_CALL_C emf_fs_create_directory(const emf_path_t* EMF_NOT_NULL path, const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT;

/**
 * @brief Deletes a path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_can_delete(path, recursive) == emf_bool_true</code>.
 *
 * @post The path is deleted.
 *
 * @param path Path to delete.
 * @param recursive Delete recursively.
 */
void EMF_CALL_C emf_fs_delete(const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive) EMF_NOEXCEPT;

/**
 * @brief Mounts a part of memory to a path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 * @pre <code>file_handler</code> must be able to mount the type of the content.
 * @pre <code>file</code> may not be <code>NULL</code>.
 * @pre <code>mount_point</code> may not be <code>NULL</code>.
 * @pre <code>file.data != NULL & file.length > 0</code>.
 * @pre <code>emf_fs_exists(mount_point) == emf_bool_false</code>.
 * @pre <code>emf_fs_exists(&emf_fs_get_parent(mount_point)) == emf_bool_true</code>.
 * @pre <code>emf_fs_is_virtual(&emf_fs_get_parent(mount_point)) == emf_bool_true</code>.
 * @pre <code>emf_fs_get_access_mode(&emf_fs_get_parent(mount_point)) == emf_file_access_mode_write</code>.
 *
 * @post The memory is mounted.
 *
 * @param file_handler File handler.
 * @param file Memory.
 * @param access_mode File read/write permissions.
 * @param mount_point Mount path.
 * @param options Mount options.
 *
 * @return Mount id.
 */
emf_mount_id_t EMF_CALL_C emf_fs_mount_memory_file(emf_file_handler_t file_handler, const emf_memory_span_t* EMF_NOT_NULL file,
    emf_access_mode_t access_mode, const emf_path_t* EMF_NOT_NULL mount_point, const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT;

/**
 * @brief Mounts a native path to a path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 * @pre <code>file_handler</code> must be able to mount the type of the content.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>mount_point</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_can_mount_native_path(file_handler, path) == emf_bool_true</code>.
 * @pre <code>emf_fs_exists(mount_point) == emf_bool_false</code>.
 * @pre <code>emf_fs_exists(&emf_fs_get_parent(mount_point)) == emf_bool_true</code>.
 * @pre <code>emf_fs_is_virtual(&emf_fs_get_parent(mount_point)) == emf_bool_true</code>.
 * @pre <code>emf_fs_get_access_mode(&emf_fs_get_parent(mount_point)) == emf_file_access_mode_write</code>.
 *
 * @post The path is mounted.
 *
 * @param file_handler File handler.
 * @param path Native path.
 * @param access_mode File read/write permissions.
 * @param mount_point Mount path.
 * @param options Mount options.
 *
 * @return Mount id.
 */
emf_mount_id_t EMF_CALL_C emf_fs_mount_native_path(emf_file_handler_t file_handler,
    const emf_native_path_char_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, const emf_path_t* EMF_NOT_NULL mount_point,
    const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT;

/**
 * @brief Tries to unmount a previously mounted path.
 *
 * @note Requires synchronisation.
 * @note Can only unmount a path if no hardlinks referring into the mount point exist.
 *
 * @pre <code>mount_id</code> must be acquired by a call to emf_fs_mount_memory_file(), emf_fs_mount_native_path(),
 * emf_fs_get_mount_id() or emf_fs_unsafe_create_mount_id().
 *
 * @post The mount point is unmounted or nothing changes.
 * @post <code>mount_id</code> is invalidated.
 *
 * @return <code>emf_bool_true</code> if successful.
 * @return <code>emf_bool_false</code> otherwise.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_unmount(emf_mount_id_t mount_id) EMF_NOEXCEPT;

/**
 * @brief Changes the read/write permissions of a path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 * @pre <code>emf_fs_can_set_access_mode(path, access_mode, recursive) == emf_bool_true</code>.
 *
 * @post The read/write permissions of the path are changed.
 *
 * @param path Path to change.
 * @param access_mode New permissions.
 * @param recursive Apply recursively.
 */
void EMF_CALL_C emf_fs_set_access_mode(
    const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, emf_bool_t recursive) EMF_NOEXCEPT;

/**
 * @brief Gets the read/write permissions of a path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 *
 * @param path Path to check.
 *
 * @return <code>emf_file_access_mode_read</code> if the path has only read permissions.
 * @return <code>emf_file_access_mode_write</code> if the path has read/write permissions.
 */
EMF_NODISCARD emf_access_mode_t EMF_CALL_C emf_fs_get_access_mode(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Gets the id of the mount point.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 * @pre <code>emf_fs_is_virtual(path) == emf_bool_false || emf_fs_get_entry_type(path) == emf_fs_entry_type_mount_point</code>.
 *
 * @param path Path.
 *
 * @return Mount id.
 */
EMF_NODISCARD emf_mount_id_t EMF_CALL_C emf_fs_get_mount_id(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Checks if the path can be accessed with the selected permissions.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 *
 * @param path Path to check.
 * @param access_mode Permissions.
 *
 * @return <code>emf_bool_true</code> if the path can be accessed with the selected permissions.
 * @return <code>emf_bool_false</code> if the path can not be accessed with the selected permissions.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_access(
    const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode) EMF_NOEXCEPT;

/**
 * @brief Checks if the permissions of a path can be set to the new ones.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 *
 * @param path Path to check.
 * @param access_mode Permissions.
 * @param recursive Apply recursively.
 *
 * @return <code>emf_bool_true</code> if the permissions can be set.
 * @return <code>emf_bool_false</code> if the permissions can not be set.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_set_access_mode(
    const emf_path_t* EMF_NOT_NULL path, emf_access_mode_t access_mode, emf_bool_t recursive) EMF_NOEXCEPT;

/**
 * @brief Checks if the path is virtual.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 *
 * @param path Path to check.
 *
 * @return <code>emf_bool_true</code> if the path is virtual.
 * @return <code>emf_bool_false</code> if the path is not virtual.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_is_virtual(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Checks if a path is safe to delete.
 *
 * @note Requires synchronisation.
 * @note A path is safe to delete, if there are no open files.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 *
 * @param path Path to check.
 * @param recursive Check recursively.
 *
 * @return <code>emf_bool_true</code> if the path can be deleted.
 * @return <code>emf_bool_false</code> if the path can be not deleted.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_delete(const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive) EMF_NOEXCEPT;

/**
 * @brief Checks if a file handler can mount a file type.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 * @pre <code>type</code> may not be <code>NULL</code>.
 *
 * @param file_handler File handler.
 * @param type File type.
 *
 * @return <code>emf_bool_true</code> if the file handler can mount the type.
 * @return <code>emf_bool_false</code> if the file handler can not mount the type.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_mount_type(
    emf_file_handler_t file_handler, const emf_file_type_t* EMF_NOT_NULL type) EMF_NOEXCEPT;

/**
 * @brief Checks if a file handler can mount a path.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 *
 * @param file_handler File handler.
 * @param path Path to check.
 *
 * @return <code>emf_bool_true</code> if the file handler can mount the path.
 * @return <code>emf_bool_false</code> if the file handler can not mount the path.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_can_mount_native_path(
    emf_file_handler_t file_handler, const emf_native_path_char_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Gets the number of the entries in a path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 *
 * @param path Path to check.
 * @param recursive Check recursively.
 *
 * @return Number of entries.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_num_entries(const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive) EMF_NOEXCEPT;

/**
 * @brief Gets the entries in a path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 * @pre <code>buffer.data != NULL && buffer.length >= emf_fs_get_num_entries(path, recursive)</code>.
 *
 * @post The entries are written into <code>buffer</code>.
 *

 * @param path Path to fetch from.
 * @param recursive Fetch recursively.
 * @param buffer Output.
 *
 * @return Number of written entries.
 */
size_t EMF_CALL_C emf_fs_get_entries(
    const emf_path_t* EMF_NOT_NULL path, emf_bool_t recursive, emf_path_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Checks if a path exists.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 *
 * @param path Path to check.
 *
 * @return <code>emf_bool_true</code> if the path exists.
 * @return <code>emf_bool_false</code> if the path does not exists.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_exists(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Checks if a file type exists.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>type</code> may not be <code>NULL</code>.
 *
 * @param type File type.
 *
 * @return <code>emf_bool_true</code> if the file type exists.
 * @return <code>emf_bool_false</code> if the file type does not exists.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_type_exists(const emf_file_type_t* EMF_NOT_NULL type) EMF_NOEXCEPT;

/**
 * @brief Gets the type of an entry.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 *
 * @param path Path to check.
 *
 * @return <code>emf_fs_entry_type_file</code> if the path is a file.
 * @return <code>emf_fs_entry_type_link</code> if the path is a link.
 * @return <code>emf_fs_entry_type_directory</code> if the path is a directory.
 */
EMF_NODISCARD emf_fs_entry_type_t EMF_CALL_C emf_fs_get_entry_type(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Resolves the path from a link.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 * @pre <code>emf_fs_get_entry_type(path) == emf_fs_entry_type_link</code>.
 *
 * @param path Link path.
 *
 * @return Resolved path.
 */
EMF_NODISCARD emf_path_t EMF_CALL_C emf_fs_resolve_link(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Gets the link type of the entry.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 * @pre <code>emf_fs_get_entry_type(path) == emf_fs_entry_type_link</code>.
 *
 * @param path Link path.
 *
 * @return <code>emf_fs_link_symlink</code> if the link is a symlink.
 * @return <code>emf_fs_link_hardlink</code> if the link is a hardlink.
 */
EMF_NODISCARD emf_fs_link_t EMF_CALL_C emf_fs_get_link_type(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Get the size of the contents of a path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 *
 * @param path Path.
 *
 * @return Size of the contents.
 */
EMF_NODISCARD emf_entry_size_t EMF_CALL_C emf_fs_get_size(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Gets the length of the resolved native path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 * @pre <code>emf_fs_is_virtual(path) == emf_bool_false</code>.
 *
 * @param path Path.
 *
 * @return Length of the native path.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_native_path_length(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Resolves the native path of an entry.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 * @pre <code>emf_fs_is_virtual(path) == emf_bool_false</code>.
 * @pre <code>buffer.data != NULL && buffer.length >= emf_fs_get_native_path_length(path)</code>.
 *
 * @post <code>buffer</code> contains the native path.
 *
 * @param path Path.
 * @param buffer Buffer.
 *
 * @return Number of written bytes.
 */
size_t EMF_CALL_C emf_fs_get_native_path(
    const emf_path_t* EMF_NOT_NULL path, emf_native_path_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Returns the number of file handlers.
 *
 * @note Requires synchronisation.
 *
 * @return Number of file handlers.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_num_file_handlers() EMF_NOEXCEPT;

/**
 * @brief Copies all file handlers.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.data != NULL && buffer.length >= emf_fs_get_num_file_handlers()</code>.
 *
 * @post <code>buffer</code> contains all file handlers.
 *
 * @param buffer Buffer.
 *
 * @return Number of written file handlers.
 */
size_t EMF_CALL_C emf_fs_get_file_handlers(emf_file_handler_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Gets the file handler that can mount a certain file type.
 *
 * @note Requires synchronisation.
 * @note Returns the first file handler that registered the file type.
 *
 * @pre <code>type</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_type_exists(type) == emf_bool_true</code>.
 *
 * @param type File type.
 *
 * @return File handler.
 */
EMF_NODISCARD emf_file_handler_t EMF_CALL_C emf_fs_get_file_handler_from_type(
    const emf_file_type_t* EMF_NOT_NULL type) EMF_NOEXCEPT;

/**
 * @brief Gets the number of file types.
 *
 * @note Requires synchronisation.
 *
 * @return Number of file types.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_num_file_types() EMF_NOEXCEPT;

/**
 * @brief Gets all file types.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.data != NULL && buffer.length >= emf_fs_get_num_file_types()</code>.
 *
 * @post <code>buffer</code> contains all file types.
 *
 * @param buffer Buffer.
 *
 * @return Number of written file types.
 */
size_t EMF_CALL_C emf_fs_get_file_types(emf_file_type_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Gets the number of file types a file handler can manage.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 *
 * @param file_handler File handler.
 *
 * @return Number of file types.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_fs_get_num_handler_file_types(emf_file_handler_t file_handler) EMF_NOEXCEPT;

/**
 * @brief Gets all file types a file handler can manage.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.data != NULL && buffer.length >= emf_fs_get_num_handler_file_types(file_handler)</code>.
 *
 * @post <code>buffer</code> contains all file types.
 *
 * @param file_handler File handler.
 * @param buffer Buffer.
 *
 * @return Number of written file types.
 */
size_t EMF_CALL_C emf_fs_get_handler_file_types(
    emf_file_handler_t file_handler, emf_file_type_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Normalizes and condenses slashes.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 *
 * @param path Path.
 *
 * @return Normalized path.
 */
EMF_NODISCARD emf_path_t EMF_CALL_C emf_fs_normalize(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Gets the parent of a path.
 *
 * @note The parent of a file or directory is the directory that contains them.
 * @note The parent of the root directory is the root directory itself.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 *
 * @param path Path.
 *
 * @return Parent directory.
 */
EMF_NODISCARD emf_path_t EMF_CALL_C emf_fs_get_parent(const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Joins two paths.
 *
 * @note Computes the absolute path after joining.
 *
 * @pre The paths must be normalized.
 * @pre <code>lhs</code> may not be <code>NULL</code>.
 * @pre <code>rhs</code> may not be <code>NULL</code>.
 *
 * @param lhs First path.
 * @param rhs Second path.
 *
 * @return Joined path.
 */
EMF_NODISCARD emf_path_t EMF_CALL_C emf_fs_join(
    const emf_path_t* EMF_NOT_NULL lhs, const emf_path_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT;

/******************************************************************************************************
*************************************  Unsafe system operations  *************************************
******************************************************************************************************/

/**
 * @brief Creates a new unlinked mount id.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>mount_point</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(mount_point) == emf_bool_false</code>.
 * @pre <code>emf_fs_exists(&emf_fs_get_parent(mount_point)) == emf_bool_true</code>.
 * @pre <code>emf_fs_get_access_mode(&emf_fs_get_parent(mount_point)) == emf_file_access_mode_write</code>.
 *
 * @post A new unlinked mount id is created.
 *
 * @warning Using this id without a call to emf_fs_unsafe_link_mount_point() will result in the termination of the program.
 *
 * @param mount_point Mount point.
 *
 * @return Mount id.
 */
EMF_NODISCARD emf_mount_id_t EMF_CALL_C emf_fs_unsafe_create_mount_id(const emf_path_t* EMF_NOT_NULL mount_point) EMF_NOEXCEPT;

/**
 * @brief Removes a mount id without an unmount.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>mount_id</code> must be acquired by a call to emf_fs_mount_memory_file(), emf_fs_mount_native_path(),
 * emf_fs_get_mount_id() or emf_fs_unsafe_create_mount_id().
 *
 * @post The mount point is removed.
 * @post <code>mount_id</code> is invalidated.
 *
 * @warning Does not unmount the mount point.
 *
 * @param mount_id Mount id.
 */
void EMF_CALL_C emf_fs_unsafe_remove_mount_id(emf_mount_id_t mount_id) EMF_NOEXCEPT;

/**
 * @brief Unmount a mount point.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>mount_id</code> must be acquired by a call to emf_fs_mount_memory_file(), emf_fs_mount_native_path(),
 * emf_fs_get_mount_id() or emf_fs_unsafe_create_mount_id().
 *
 * @post The mount point is unmounted.
 * @post <code>mount_id</code> is invalidated.
 *
 * @warning Does not check if any links refer to the mount point.
 *
 * @param mount_id Mount id.
 */
void EMF_CALL_C emf_fs_unsafe_unmount_force(emf_mount_id_t mount_id) EMF_NOEXCEPT;

/**
 * Links the provided mount id to a file handler and its internal id.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>mount_id</code> must be acquired by a call to emf_fs_mount_memory_file(), emf_fs_mount_native_path(),
 * emf_fs_get_mount_id() or emf_fs_unsafe_create_mount_id().
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 *
 * @warning Overwrites existing link, if it exists.
 * @warning Unsafe if <code>mount_id</code> was not acquired by a call to emf_fs_unsafe_create_mount_id().
 * @warning Unsafe if <code>file_handler_mount_id</code> was acquired by a call to emf_fs_unsafe_get_file_handler_mount_id().
 * @warning The uniqueness of the pair <code>file_handler</code>, <code>file_handler_mount_id</code> must be ensured before a call
 * to emf_fs_unmount().
 *
 * @param mount_id Mount id.
 * @param file_handler File handler.
 * @param file_handler_mount_id Internal mount id.
 */
void EMF_CALL_C emf_fs_unsafe_link_mount_point(
    emf_mount_id_t mount_id, emf_file_handler_t file_handler, emf_file_handler_mount_id_t file_handler_mount_id) EMF_NOEXCEPT;

/**
 * @brief Creates a new unlinked file stream.
 *
 * @note Requires synchronisation.
 *
 * @post A new unlinked file stream is created.
 *
 * @warning Using this handle without a call to emf_fs_unsafe_link_file_stream() will result in the termination of the program.
 *
 * @return Unlinked file stream.
 */
EMF_NODISCARD emf_file_stream_t EMF_CALL_C emf_fs_unsafe_create_file_stream() EMF_NOEXCEPT;

/**
 * @brief Removes a file stream from the system.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>file_stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @post The stream is removed from the system.
 *
 * @warning Removing the stream does not close it.
 *
 * @param file_stream File stream.
 */
void EMF_CALL_C emf_fs_unsafe_remove_file_stream(emf_file_stream_t file_stream) EMF_NOEXCEPT;

/**
 * Links the provided file stream to a file handler and its internal stream.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 * @pre <code>file_stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @warning Overwrites existing link, if it exists.
 * @warning Unsafe if <code>stream</code> was not acquired by a call to emf_fs_unsafe_create_file_stream().
 * @warning Unsafe if <code>file_handler_stream</code> was acquired by a call to emf_fs_unsafe_get_file_handler_stream().
 * @warning The uniqueness of the pair <code>file_handler</code>, <code>file_handler_stream</code> must be ensured before a call
 * to emf_fs_stream_close().
 *
 * @param file_stream File stream.
 * @param file_handler File handler.
 * @param file_handler_stream Internal file stream.
 */
void EMF_CALL_C emf_fs_unsafe_link_file_stream(
    emf_file_stream_t file_stream, emf_file_handler_t file_handler, emf_file_handler_stream_t file_handler_stream) EMF_NOEXCEPT;

/**
 * @brief Gets the file handler manages the stream.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @param stream File stream.
 *
 * @return File handler.
 */
EMF_NODISCARD emf_file_handler_t EMF_CALL_C emf_fs_unsafe_get_file_handler_handle_from_stream(
    emf_file_stream_t stream) EMF_NOEXCEPT;

/**
 * @brief Gets the file handler associated with the path.
 *
 * @note Requires synchronisation.
 *
 * @pre The paths must be normalized.
 * @pre <code>path</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_exists(path) == emf_bool_true</code>.
 * @pre <code>emf_fs_is_virtual(path) == emf_bool_false || emf_fs_get_entry_type(path) == emf_fs_entry_type_mount_point</code>.
 *
 * @param path Path.
 *
 * @return File handler.
 */
EMF_NODISCARD emf_file_handler_t EMF_CALL_C emf_fs_unsafe_get_file_handler_handle_from_path(
    const emf_path_t* EMF_NOT_NULL path) EMF_NOEXCEPT;

/**
 * @brief Gets the internal stream of a file handler.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @param file_stream File stream.
 *
 * @return Internal stream.
 */
EMF_NODISCARD emf_file_handler_stream_t EMF_CALL_C emf_fs_unsafe_get_file_handler_stream(
    emf_file_stream_t file_stream) EMF_NOEXCEPT;

/**
 * @brief Gets the internal mount id of a file handler.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>mount_id</code> must be acquired by a call to emf_fs_mount_memory_file(), emf_fs_mount_native_path(),
 * emf_fs_get_mount_id() or emf_fs_unsafe_create_mount_id().
 *
 * @param mount_id Mount id.
 *
 * @return Internal mount id.
 */
EMF_NODISCARD emf_file_handler_mount_id_t EMF_CALL_C emf_fs_unsafe_get_file_handler_mount_id(
    emf_mount_id_t mount_id) EMF_NOEXCEPT;

/**
 * @brief Get the interface to the file handler.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>file_handler</code> must be acquired by a call to emf_fs_register_file_handler(),
 * emf_fs_get_file_handler_from_type(), emf_fs_unsafe_get_file_handler_handle_from_stream() or
 * emf_fs_unsafe_get_file_handler_handle_from_path().
 *
 * @warning The usage of the interface is safe as long as emf_unlock() has not been called. Otherwise the interface may have been
 * unregistered.
 *
 * @param file_handler File handler.
 * @return Interface of the file handler.
 */
EMF_NODISCARD emf_file_handler_interface_t EMF_CALL_C emf_fs_unsafe_get_file_handler(
    emf_file_handler_t file_handler) EMF_NOEXCEPT;

/******************************************************************************************************
**************************************  File stream operations  **************************************
******************************************************************************************************/

/**
 * @brief Opens a stream to a file.
 *
 * @note Requires synchronisation.
 * @note A default buffer is used, if <code>io_buffer == NULL</code>.
 * @note A file handler may choose to disregard  <code>max_size</code>.
 *
 * @pre <code>filename</code> may not be <code>NULL</code>.
 * @pre <code>emf_fs_get_entry_type(filename) == emf_fs_entry_type_file</code>.
 * @pre <code>emf_fs_can_access(filename, access_mode) == emf_bool_true</code>.
 *
 * @post A new file stream is created.
 *
 * @param filename File path.
 * @param open_mode Open mode.
 * @param access_mode Access mode.
 * @param options File open options.
 *
 * @return File stream.
 */
EMF_NODISCARD emf_file_stream_t EMF_CALL_C emf_fs_stream_open(const emf_path_t* EMF_NOT_NULL filename,
    emf_file_open_mode_t open_mode, emf_access_mode_t access_mode, const void* EMF_MAYBE_NULL options) EMF_NOEXCEPT;

/**
 * @brief Closes a file stream.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @post The stream is closed.
 * @post <code>stream</code> is invalidated.
 *
 * @param stream File stream.
 */
void EMF_CALL_C emf_fs_stream_close(emf_file_stream_t stream) EMF_NOEXCEPT;

/**
 * @brief Flushes the io buffer to the file.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @post The buffer is flushed.
 *
 * @param stream File stream.
 */
void EMF_CALL_C emf_fs_stream_flush(emf_file_stream_t stream) EMF_NOEXCEPT;

/**
 * @brief Reads up to <code>read_count</code> number of bytes from a stream.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.data != NULL && buffer.length >= read_count</code>.
 *
 * @post Position of the stream moves forward by the number of read bytes.
 * @post The output is written into <code>buffer</code>.
 *
 * @param stream File stream.
 * @param buffer Destination.
 * @param read_count Number of bytes to read.
 *
 * @return Number of read bytes.
 */
size_t EMF_CALL_C emf_fs_stream_read(
    emf_file_stream_t stream, emf_fs_read_buffer_t* EMF_NOT_NULL buffer, size_t read_count) EMF_NOEXCEPT;

/**
 * @brief Writes up to <code>write_count</code> number of bytes to a stream.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre The stream must be opened with <code>emf_file_access_mode_write</code>.
 * @pre <code>emf_fs_stream_can_write(stream) == emf_bool_true</code>.
 * @pre <code>buffer.data != NULL && buffer.length >= write_count</code>.
 *
 * @post Position of the stream moves forward by the number of read bytes.
 * @post The output is written into the stream.
 *
 * @param stream File stream.
 * @param buffer Source.
 * @param write_count Number of bytes to write.
 *
 * @return Number of written bytes.
 */
size_t EMF_CALL_C emf_fs_stream_write(
    emf_file_stream_t stream, const emf_fs_write_buffer_t* EMF_NOT_NULL buffer, size_t write_count) EMF_NOEXCEPT;

/**
 * @brief Get the current position of the stream.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @param stream
 *
 * @return Position of the stream.
 */
EMF_NODISCARD emf_pos_t EMF_CALL_C emf_fs_stream_get_pos(emf_file_stream_t stream) EMF_NOEXCEPT;

/**
 * @brief Set the position of the stream.
 *
 * @note Requires synchronisation.
 * @note This operation is guaranteed to work if <code>position</code> was acquired by a call to emf_fs_get_pos().
 * @note May fail if the position is out of bounds.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @post The stream is set to the provided position.
 *
 * @param stream File stream.
 * @param position Position to move to.
 *
 * @return Offset from the old position to the new one.
 */
emf_off_t EMF_CALL_C emf_fs_stream_set_pos(emf_file_stream_t stream, emf_pos_t position) EMF_NOEXCEPT;

/**
 * @brief Moves the position by a offset in the specified direction.
 *
 * @note Requires synchronisation.
 * @note This operation is guaranteed to work if <code>offset</code> was acquired by a call to emf_fs_get_pos() and the
 * appropriate direction is selected.
 * @note May fail if the offset would result out of bounds.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @param stream File stream.
 * @param offset Offset to move by.
 * @param direction Direction to move in.
 *
 * @return Offset from the old position to the new one relative to the direction.
 */
emf_off_t EMF_CALL_C emf_fs_stream_move_pos(
    emf_file_stream_t stream, emf_off_t offset, emf_fs_direction_t direction) EMF_NOEXCEPT;

/**
 * @brief Checks if a stream can be written to.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @param stream File stream.
 *
 * @return <code>emf_bool_true</code> if the stream can be written to.
 * @return <code>emf_bool_false</code> if the stream can not be written to.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_stream_can_write(emf_file_stream_t stream) EMF_NOEXCEPT;

/**
 * @brief Checks if <code>size</code> number of bytes can be written to the stream without failure.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>stream</code> must be acquired by a call to emf_fs_open() or emf_fs_unsafe_create_file_stream().
 *
 * @param stream File stream.
 * @param size Number of bytes.
 *
 * @return <code>emf_bool_true</code> if the stream can write the requested size.
 * @return <code>emf_bool_false</code> if the stream can not write the requested size.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_fs_stream_can_grow(emf_file_stream_t stream, size_t size) EMF_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_EMF_FS_H
