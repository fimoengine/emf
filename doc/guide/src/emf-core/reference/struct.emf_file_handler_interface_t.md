# Struct `emf_file_handler_interface_t`

```c
typedef struct emf_file_handler_interface_t {
    emf_file_handler_interface_create_file_fn_t create_file_fn;
    emf_file_handler_interface_create_directory_fn_t create_directory_fn;
    emf_file_handler_interface_delete_fn_t delete_fn;
    emf_file_handler_interface_can_delete_fn_t can_delete_fn;
    emf_file_handler_interface_can_mount_native_path_fn_t can_mount_native_path_fn;
    emf_file_handler_interface_mount_memory_file_fn_t mount_memory_file_fn;
    emf_file_handler_interface_mount_native_path_fn_t mount_native_path_fn;

    emf_file_handler_interface_unmount_fn_t unmount_fn;
    emf_file_handler_interface_set_access_mode_fn_t set_access_mode_fn;
    emf_file_handler_interface_get_access_mode_fn_t get_access_mode_fn;
    emf_file_handler_interface_can_access_fn_t can_access_fn;
    emf_file_handler_interface_can_set_access_mode_fn_t can_set_access_mode_fn;
    emf_file_handler_interface_get_num_entries_fn_t get_num_entries_fn;
    emf_file_handler_interface_get_entries_fn_t get_entries_fn;
    emf_file_handler_interface_get_size_fn_t get_size_fn;
    emf_file_handler_interface_exists_fn_t exists_fn;
    emf_file_handler_interface_get_native_path_length_fn_t get_native_path_length_fn;
    emf_file_handler_interface_get_native_path_fn_t get_native_path_fn;
    emf_file_handler_interface_stream_open_fn_t stream_open_fn;
    emf_file_handler_interface_stream_close_fn_t stream_close_fn;
    emf_file_handler_interface_stream_flush_fn_t stream_flush_fn;
    emf_file_handler_interface_stream_read_fn_t stream_read_fn;
    emf_file_handler_interface_stream_write_fn_t stream_write_fn;
    emf_file_handler_interface_stream_get_pos_fn_t stream_get_pos_fn;
    emf_file_handler_interface_stream_set_pos_fn_t stream_set_pos_fn;
    emf_file_handler_interface_stream_move_pos_fn_t stream_move_pos_fn;
    emf_file_handler_interface_stream_can_write_fn_t stream_can_write_fn;
    emf_file_handler_interface_stream_can_grow_fn_t stream_can_grow_fn;
} emf_file_handler_interface_t;
```

The interface of a `File handler`.

## Fields

- **create_file_fn**: [`emf_file_handler_interface_create_file_fn_t`](./type.emf_file_handler_interface_create_file_fn_t.md)

    A function for creating files.

- **create_directory_fn**: [`emf_file_handler_interface_create_directory_fn_t`](./type.emf_file_handler_interface_create_directory_fn_t.md)

    A function for creating directories.

- **delete_fn**: [`emf_file_handler_interface_delete_fn_t`](./type.emf_file_handler_interface_delete_fn_t.md)

    A function for deleting entries.

- **can_delete_fn**: [`emf_file_handler_interface_can_delete_fn_t`](./type.emf_file_handler_interface_can_delete_fn_t.md)

    A function for querying if a entry can be deleted.

- **can_mount_native_path_fn**: [`emf_file_handler_interface_can_mount_native_path_fn_t`](./type.emf_file_handler_interface_can_mount_native_path_fn_t.md)

    A function for querying if a native path can be mounted.

- **mount_memory_file_fn**: [`emf_file_handler_interface_mount_memory_file_fn_t`](./type.emf_file_handler_interface_mount_memory_file_fn_t.md)

    A function for mounting a memory range.

- **mount_native_path_fn**: [`emf_file_handler_interface_mount_native_path_fn_t`](./type.emf_file_handler_interface_mount_native_path_fn_t.md)

    A function for mounting a path.

- **unmount_fn**: [`emf_file_handler_interface_unmount_fn_t`](./type.emf_file_handler_interface_unmount_fn_t.md)

    A function for unmounting a previously mounted path/memory region.

- **set_access_mode_fn**: [`emf_file_handler_interface_set_access_mode_fn_t`](./type.emf_file_handler_interface_set_access_mode_fn_t.md)

    A function for changing the access mode of a tree.

- **get_access_mode_fn**: [`emf_file_handler_interface_get_access_mode_fn_t`](./type.emf_file_handler_interface_get_access_mode_fn_t.md)

    A function for getting the access mode of a node.

- **can_access_fn**: [`emf_file_handler_interface_can_access_fn_t`](./type.emf_file_handler_interface_can_access_fn_t.md)

    A function for querying if a node can be accessed with a specific permission.

- **can_set_access_mode_fn**: [`emf_file_handler_interface_can_set_access_mode_fn_t`](./type.emf_file_handler_interface_can_set_access_mode_fn_t.md)

    A function for querying if a access permission of a node can be set.

- **get_num_entries_fn**: [`emf_file_handler_interface_get_num_entries_fn_t`](./type.emf_file_handler_interface_get_num_entries_fn_t.md)

    A function for enumerating the number of entries of a tree.

- **get_entries_fn**: [`emf_file_handler_interface_get_entries_fn_t`](./type.emf_file_handler_interface_get_entries_fn_t.md)

    A function for copying the path of all entries of the tree into a buffer.

- **get_size_fn**: [`emf_file_handler_interface_get_size_fn_t`](./type.emf_file_handler_interface_get_size_fn_t.md)

    A function for querying the size of an entry.

- **exists_fn**: [`emf_file_handler_interface_exists_fn_t`](./type.emf_file_handler_interface_exists_fn_t.md)

    A function for querying the existance of an entry.

- **get_native_path_length_fn**: [`emf_file_handler_interface_get_native_path_length_fn_t`](./type.emf_file_handler_interface_get_native_path_length_fn_t.md)

    A function for querying the length of the path represented as a native path string.

- **get_native_path_fn**: [`emf_file_handler_interface_get_native_path_fn_t`](./type.emf_file_handler_interface_get_native_path_fn_t.md)

    A function for converting a path into a native path representation.

- **stream_open_fn**: [`emf_file_handler_interface_stream_open_fn_t`](./type.emf_file_handler_interface_stream_open_fn_t.md)

    A function for opening a file as a stream.

- **stream_close_fn**: [`emf_file_handler_interface_stream_close_fn_t`](./type.emf_file_handler_interface_stream_close_fn_t.md)

    A function for closing a stream.

- **stream_flush_fn**: [`emf_file_handler_interface_stream_flush_fn_t`](./type.emf_file_handler_interface_stream_flush_fn_t.md)

    A function for flushing a stream.

- **stream_read_fn**: [`emf_file_handler_interface_stream_read_fn_t`](./type.emf_file_handler_interface_stream_read_fn_t.md)

    A function for reading from a stream.

- **stream_write_fn**: [`emf_file_handler_interface_stream_write_fn_t`](./type.emf_file_handler_interface_stream_write_fn_t.md)

    A function for writing to a stream.

- **stream_get_pos_fn**: [`emf_file_handler_interface_stream_get_pos_fn_t`](./type.emf_file_handler_interface_stream_get_pos_fn_t.md)

    A function for getting the position of a stream.

- **stream_set_pos_fn**: [`emf_file_handler_interface_stream_set_pos_fn_t`](./type.emf_file_handler_interface_stream_set_pos_fn_t.md)

    A function for setting the position of a stream.

- **stream_move_pos_fn**: [`emf_file_handler_interface_stream_move_pos_fn_t`](./type.emf_file_handler_interface_stream_move_pos_fn_t.md)

    A function for moving a stream.

- **stream_can_write_fn**: [`emf_file_handler_interface_stream_can_write_fn_t`](./type.emf_file_handler_interface_stream_can_write_fn_t.md)

    A function for querying if a stream has write permissions.

- **stream_can_grow_fn**: [`emf_file_handler_interface_stream_can_grow_fn_t`](./type.emf_file_handler_interface_stream_can_grow_fn_t.md)

    A function for querying if a stream can write a certain amount of bytes.
