# Type definition `emf_file_handler_interface_get_size_fn_t`

```c
typedef emf_entry_size_t(*emf_file_handler_interface_get_size_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path
);
```

Queries the size of an entry.

It is undefined behaviour to supply an invalid `path`.

> Note: The `path` is relative to the mounted path.
