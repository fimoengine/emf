# Type definition `emf_file_handler_interface_mount_native_path_fn_t`

```c
typedef emf_file_handler_mount_id_t(*emf_file_handler_interface_mount_native_path_fn_t)(
    const emf_native_path_char_t* path,
    emf_access_mode_t access_mode,
    const void* options
);
```

Mounts a native path.
