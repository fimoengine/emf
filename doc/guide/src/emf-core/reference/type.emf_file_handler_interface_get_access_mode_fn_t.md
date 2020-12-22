# Type definition `emf_file_handler_interface_get_access_mode_fn_t`

```c
typedef emf_access_mode_t(*emf_file_handler_interface_get_access_mode_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path
);
```

Queries the permissions of a path.

It is undefined bahaviour to supply a path that does not exist.

> Note: The `path` is relative to the mounted path.
