# Type definition `emf_file_handler_interface_can_set_access_mode_fn_t`

```c
typedef emf_bool_t(*emf_file_handler_interface_can_set_access_mode_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path,
    emf_access_mode_t access_mode,
    emf_bool_t recurisve
);
```

Queries if the permissions of a path can be changed.

> Note: The `path` is relative to the mounted path.
