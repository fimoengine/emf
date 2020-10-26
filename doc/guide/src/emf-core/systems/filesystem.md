# FileSystem system

## Introduction

The `FS` system specifies a customizable virtual file system,
that is consistent across multiple platform.

The fs is realized in two parts, a `virtual` fs-graph
which contains multiple `physical` fs-trees.
Every node contains access permissions, is reference counted and
is of the type `file`, `directory`, `link` or `mount point`.
The fs can be extended with `File handlers`.

### Entries

As mentioned above, the `entries` are modelled as `nodes` of the `graph` / `tree`.
They can have the following types:

- `file`: A file.
- `directory`: A directory.
- `link`: A link.
  - `soft link`: A symbolik link to a node. The link can be invalidated.
  - `hard link`: A strong link to a node. The creation of such a link increases the reference count of the node it points to. Linking to a `physical` node also increases the reference count of the corresponding `mount point`.
- `mount point`: A link between the `virtual` graph and a `physical` tree.

### The `virtual` graph

The first part of the fs is the `virtual` graph. This graph can contain cycles and is not tied to a real fs.
It consists of `directories`, `links` and `mount points`, and as such, does not contain any resource.

### The `physical` tree

The rest of the fs is modelled as `trees`. They consist of `files` and `directories`.
Those `trees` are tied to a physical fs and are implemented with `File handlers`.

### `File handlers`

`File handlers` contain the actual logic of the fs. They implement common procedures,
like creating files, mounting a fs or opening streams. Those procedures can be tuned to a specifiy fs by defining custom input structures, but sane defaults are specified. A `File handler` can assume that any modification of a mounted fs occurs through it self and that any resource is contained in only one `physical` fs. Mounting a path or sub-paths multiple times and any modification of the `physical` fs which does not occur by the `File handler` that mounted the path, may result in an erroneous state.

### `Streams`

A `stream` is a handle to an opened file. Their interface is similar to the `C File-API`.
Multiple `streams` to one file can exist. Concurrent read and write operations on one file are thread-safe, as long
as the `streams` are not shared, and they do not overlap.

## Example

```c
const char file_path_str = "/test";
emf_path_t file_path;
memset(&file_path, 0, sizeof(emf_path_t));

// Populate the event name.
// Bounds checking is omitted for brevity.
file_path.length = strlen(file_path_str);
memcpy(&file_path.data, file_path_str, file_path.length);

// Create a buffer.
char buffer[1024];
emf_fs_buffer_t fs_buffer = { buffer, 1024 };

emf_lock();

emf_file_stream_t stream = emf_fs_stream_open(&file_path,
    emf_file_open_mode_begin, emf_file_access_mode_read, NULL, 1024);

// Read up to 1024 bytes from the stream.
size_t read_bytes = emf_fs_stream_read(stream, &fs_buffer, 1024);

emf_fs_stream_close(stream);

emf_unlock();
```

## Constants

- [EMF_FILE_HANDLER_DEFAULT_HANDLE](../reference/constant.EMF_FILE_HANDLER_DEFAULT_HANDLE.md)
- [EMF_FILE_TYPE_MAX_LENGTH](../reference/constant.EMF_FILE_TYPE_MAX_LENGTH.md)
- [EMF_NATIVE_FILE_HANDLER_FILE_TYPE_NAME](../reference/constant.EMF_NATIVE_FILE_HANDLER_FILE_TYPE_NAME.md)
- [EMF_PATH_MAX](../reference/constant.EMF_PATH_MAX.md)

## Enums

- [emf_access_mode_t](../reference/enum.emf_access_mode_t.md)
- [emf_file_open_mode_t](../reference/enum.emf_file_open_mode_t.md)
- [emf_fs_direction_t](../reference/enum.emf_fs_direction_t.md)
- [emf_fs_entry_type_t](../reference/enum.emf_fs_entry_type_t.md)
- [emf_fs_link_t](../reference/enum.emf_fs_link_t.md)
- [emf_fs_predefined_handles_t](../reference/enum.emf_fs_predefined_handles_t.md)

## Structs

- [emf_entry_size_t](../reference/struct.emf_entry_size_t.md)
- [emf_file_handler_interface_t](../reference/struct.emf_file_handler_interface_t.md)
- [emf_file_handler_mount_id_t](../reference/struct.emf_file_handler_mount_id_t.md)
- [emf_file_handler_span_t](../reference/struct.emf_file_handler_span_t.md)
- [emf_file_handler_stream_t](../reference/struct.emf_file_handler_stream_t.md)
- [emf_file_handler_t](../reference/struct.emf_file_handler_t.md)
- [emf_file_stream_t](../reference/struct.emf_file_stream_t.md)
- [emf_file_type_span_t](../reference/struct.emf_file_type_span_t.md)
- [emf_file_type_t](../reference/struct.emf_file_type_t.md)
- [emf_fs_read_buffer_t](../reference/struct.emf_fs_read_buffer_t.md)
- [emf_fs_write_buffer_t](../reference/struct.emf_fs_write_buffer_t.md)
- [emf_memory_span_t](../reference/struct.emf_memory_span_t.md)
- [emf_mount_id_t](../reference/struct.emf_mount_id_t.md)
- [emf_native_path_span_t](../reference/struct.emf_native_path_span_t.md)
- [emf_off_t](../reference/struct.emf_off_t.md)
- [emf_path_span_t](../reference/struct.emf_path_span_t.md)
- [emf_path_t](../reference/struct.emf_path_t.md)
- [emf_pos_t](../reference/struct.emf_pos_t.md)

## Type definitions

- [EMF_NATIVE_PATH_CHAR_T](../reference/type.EMF_NATIVE_PATH_CHAR_T_.md)
- [emf_file_handler_interface_can_access_fn_t](../reference/type.emf_file_handler_interface_can_access_fn_t.md)
- [emf_file_handler_interface_can_delete_fn_t](../reference/type.emf_file_handler_interface_can_delete_fn_t.md)
- [emf_file_handler_interface_can_mount_native_path_fn_t](../reference/type.emf_file_handler_interface_can_mount_native_path_fn_t.md)
- [emf_file_handler_interface_can_set_access_mode_fn_t](../reference/type.emf_file_handler_interface_can_set_access_mode_fn_t.md)
- [emf_file_handler_interface_create_directory_fn_t](../reference/type.emf_file_handler_interface_create_directory_fn_t.md)
- [emf_file_handler_interface_create_file_fn_t](../reference/type.emf_file_handler_interface_create_file_fn_t.md)
- [emf_file_handler_interface_delete_fn_t](../reference/type.emf_file_handler_interface_delete_fn_t.md)
- [emf_file_handler_interface_exists_fn_t](../reference/type.emf_file_handler_interface_exists_fn_t.md)
- [emf_file_handler_interface_get_access_mode_fn_t](../reference/type.emf_file_handler_interface_get_access_mode_fn_t.md)
- [emf_file_handler_interface_get_entries_fn_t](../reference/type.emf_file_handler_interface_get_entries_fn_t.md)
- [emf_file_handler_interface_get_native_path_fn_t](../reference/type.emf_file_handler_interface_get_native_path_fn_t.md)
- [emf_file_handler_interface_get_native_path_length_fn_t](../reference/type.emf_file_handler_interface_get_native_path_length_fn_t.md)
- [emf_file_handler_interface_get_num_entries_fn_t](../reference/type.emf_file_handler_interface_get_num_entries_fn_t.md)
- [emf_file_handler_interface_get_size_fn_t](../reference/type.emf_file_handler_interface_get_size_fn_t.md)
- [emf_file_handler_interface_mount_memory_file_fn_t](../reference/type.emf_file_handler_interface_mount_memory_file_fn_t.md)
- [emf_file_handler_interface_mount_native_path_fn_t](../reference/type.emf_file_handler_interface_mount_native_path_fn_t.md)
- [emf_file_handler_interface_set_access_mode_fn_t](../reference/type.emf_file_handler_interface_set_access_mode_fn_t.md)
- [emf_file_handler_interface_stream_can_grow_fn_t](../reference/type.emf_file_handler_interface_stream_can_grow_fn_t.md)
- [emf_file_handler_interface_stream_can_write_fn_t](../reference/type.emf_file_handler_interface_stream_can_write_fn_t.md)
- [emf_file_handler_interface_stream_close_fn_t](../reference/type.emf_file_handler_interface_stream_close_fn_t.md)
- [emf_file_handler_interface_stream_flush_fn_t](../reference/type.emf_file_handler_interface_stream_flush_fn_t.md)
- [emf_file_handler_interface_stream_get_pos_fn_t](../reference/type.emf_file_handler_interface_stream_get_pos_fn_t.md)
- [emf_file_handler_interface_stream_move_pos_fn_t](../reference/type.emf_file_handler_interface_stream_move_pos_fn_t.md)
- [emf_file_handler_interface_stream_open_fn_t](../reference/type.emf_file_handler_interface_stream_open_fn_t.md)
- [emf_file_handler_interface_stream_read_fn_t](../reference/type.emf_file_handler_interface_stream_read_fn_t.md)
- [emf_file_handler_interface_stream_set_pos_fn_t](../reference/type.emf_file_handler_interface_stream_set_pos_fn_t.md)
- [emf_file_handler_interface_stream_write_fn_t](../reference/type.emf_file_handler_interface_stream_write_fn_t.md)
- [emf_file_handler_interface_unmount_fn_t](../reference/type.emf_file_handler_interface_unmount_fn_t.md)
- [emf_native_path_char_t](../reference/type.emf_native_path_char_t.md)

## Functions

- [emf_fs_can_access](../reference/fn.emf_fs_can_access.md)
- [emf_fs_can_delete](../reference/fn.emf_fs_can_delete.md)
- [emf_fs_can_mount_native_path](../reference/fn.emf_fs_can_mount_native_path.md)
- [emf_fs_can_mount_type](../reference/fn.emf_fs_can_mount_type.md)
- [emf_fs_can_set_access_mode](../reference/fn.emf_fs_can_set_access_mode.md)
- [emf_fs_create_directory](../reference/fn.emf_fs_create_directory.md)
- [emf_fs_create_file](../reference/fn.emf_fs_create_file.md)
- [emf_fs_create_link](../reference/fn.emf_fs_create_link.md)
- [emf_fs_delete](../reference/fn.emf_fs_delete.md)
- [emf_fs_exists](../reference/fn.emf_fs_exists.md)
- [emf_fs_get_access_mode](../reference/fn.emf_fs_get_access_mode.md)
- [emf_fs_get_entries](../reference/fn.emf_fs_get_entries.md)
- [emf_fs_get_entry_type](../reference/fn.emf_fs_get_entry_type.md)
- [emf_fs_get_file_handler_from_type](../reference/fn.emf_fs_get_file_handler_from_type.md)
- [emf_fs_get_file_handlers](../reference/fn.emf_fs_get_file_handlers.md)
- [emf_fs_get_file_types](../reference/fn.emf_fs_get_file_types.md)
- [emf_fs_get_handler_file_types](../reference/fn.emf_fs_get_handler_file_types.md)
- [emf_fs_get_link_type](../reference/fn.emf_fs_get_link_type.md)
- [emf_fs_get_mount_id](../reference/fn.emf_fs_get_mount_id.md)
- [emf_fs_get_native_path](../reference/fn.emf_fs_get_native_path.md)
- [emf_fs_get_native_path_length](../reference/fn.emf_fs_get_native_path_length.md)
- [emf_fs_get_num_entries](../reference/fn.emf_fs_get_num_entries.md)
- [emf_fs_get_num_file_handlers](../reference/fn.emf_fs_get_num_file_handlers.md)
- [emf_fs_get_num_file_types](../reference/fn.emf_fs_get_num_file_types.md)
- [emf_fs_get_num_handler_file_types](../reference/fn.emf_fs_get_num_handler_file_types.md)
- [emf_fs_get_parent](../reference/fn.emf_fs_get_parent.md)
- [emf_fs_get_size](../reference/fn.emf_fs_get_size.md)
- [emf_fs_is_virtual](../reference/fn.emf_fs_is_virtual.md)
- [emf_fs_join](../reference/fn.emf_fs_join.md)
- [emf_fs_mount_memory_file](../reference/fn.emf_fs_mount_memory_file.md)
- [emf_fs_mount_native_path](../reference/fn.emf_fs_mount_native_path.md)
- [emf_fs_normalize](../reference/fn.emf_fs_normalize.md)
- [emf_fs_register_file_handler](../reference/fn.emf_fs_register_file_handler.md)
- [emf_fs_remove_file_handler](../reference/fn.emf_fs_remove_file_handler.md)
- [emf_fs_resolve_link](../reference/fn.emf_fs_resolve_link.md)
- [emf_fs_set_access_mode](../reference/fn.emf_fs_set_access_mode.md)
- [emf_fs_stream_can_grow](../reference/fn.emf_fs_stream_can_grow.md)
- [emf_fs_stream_can_write](../reference/fn.emf_fs_stream_can_write.md)
- [emf_fs_stream_close](../reference/fn.emf_fs_stream_close.md)
- [emf_fs_stream_flush](../reference/fn.emf_fs_stream_flush.md)
- [emf_fs_stream_get_pos](../reference/fn.emf_fs_stream_get_pos.md)
- [emf_fs_stream_move_pos](../reference/fn.emf_fs_stream_move_pos.md)
- [emf_fs_stream_open](../reference/fn.emf_fs_stream_open.md)
- [emf_fs_stream_read](../reference/fn.emf_fs_stream_read.md)
- [emf_fs_stream_set_pos](../reference/fn.emf_fs_stream_set_pos.md)
- [emf_fs_stream_write](../reference/fn.emf_fs_stream_write.md)
- [emf_fs_type_exists](../reference/fn.emf_fs_type_exists.md)
- [emf_fs_unmount](../reference/fn.emf_fs_unmount.md)
- [emf_fs_unsafe_create_file_stream](../reference/fn.emf_fs_unsafe_create_file_stream.md)
- [emf_fs_unsafe_create_mount_id](../reference/fn.emf_fs_unsafe_create_mount_id.md)
- [emf_fs_unsafe_get_file_handler](../reference/fn.emf_fs_unsafe_get_file_handler.md)
- [emf_fs_unsafe_get_file_handler_handle_from_path](../reference/fn.emf_fs_unsafe_get_file_handler_handle_from_path.md)
- [emf_fs_unsafe_get_file_handler_handle_from_stream](../reference/fn.emf_fs_unsafe_get_file_handler_handle_from_stream.md)
- [emf_fs_unsafe_get_file_handler_mount_id](../reference/fn.emf_fs_unsafe_get_file_handler_mount_id.md)
- [emf_fs_unsafe_get_file_handler_stream](../reference/fn.emf_fs_unsafe_get_file_handler_stream.md)
- [emf_fs_unsafe_link_file_stream](../reference/fn.emf_fs_unsafe_link_file_stream.md)
- [emf_fs_unsafe_link_mount_point](../reference/fn.emf_fs_unsafe_link_mount_point.md)
- [emf_fs_unsafe_remove_file_stream](../reference/fn.emf_fs_unsafe_remove_file_stream.md)
- [emf_fs_unsafe_remove_mount_id](../reference/fn.emf_fs_unsafe_remove_mount_id.md)
- [emf_fs_unsafe_unmount_force](../reference/fn.emf_fs_unsafe_unmount_force.md)
