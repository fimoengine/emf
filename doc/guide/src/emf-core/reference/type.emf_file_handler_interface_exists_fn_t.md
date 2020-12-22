# Type definition `emf_file_handler_interface_exists_fn_t`

```c
typedef emf_bool_t(*emf_file_handler_interface_exists_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path
);
```

Checks if a path exists.

> Note: The `path` is relative to the mounted path.
