# Type definition `emf_file_handler_interface_get_native_path_fn_t`

```c
typedef size_t(*emf_file_handler_interface_get_native_path_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path,
    emf_native_path_string_t* buffer
);
```

Converts the virtual path into a native path.

Converts `path` into a native resource identifier.
It is undefined behaviour to supply an invalid path or a
buffer that is not big enough to contain the path.

> Note: The `path` is relative to the mounted path.
