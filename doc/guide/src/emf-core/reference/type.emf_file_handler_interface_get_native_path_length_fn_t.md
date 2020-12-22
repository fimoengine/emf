# Type definition `emf_file_handler_interface_get_native_path_length_fn_t`

```c
typedef size_t(*emf_file_handler_interface_get_native_path_length_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path
);
```

Computes the length of a native path.

It is undefined behaviour to supply an invalid `path`.

> Note: The `path` is relative to the mounted path.
