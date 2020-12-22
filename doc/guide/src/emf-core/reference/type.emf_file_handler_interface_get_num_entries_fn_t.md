# Type definition `emf_file_handler_interface_get_num_entries_fn_t`

```c
typedef size_t(*emf_file_handler_interface_get_num_entries_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path,
    emf_bool_t recursive
);
```

Enumerates the entries within and including the path.

It is undefined behaviour to supply an invalid `path`.
The entries can be enumerated recursively by setting `recursive` to `emf_bool_true`.

> Note: The `path` is relative to the mounted path.
