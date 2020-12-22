# Type definition `emf_file_handler_interface_can_mount_native_path_fn_t`

```c
typedef emf_bool_t(*emf_file_handler_interface_can_mount_native_path_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_native_path_char_t* path
);
```

Queries if a path can be mounted by the `File handler`.
