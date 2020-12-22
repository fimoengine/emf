# Type definition `emf_file_handler_interface_can_access_fn_t`

```c
typedef emf_bool_t(*emf_file_handler_interface_can_access_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path,
    emf_access_mode_t access_mode
);
```

Queries if the path can be accessed with the provided `access_mode`.

> Note: The `path` is relative to the mounted path.
