# Type definition `emf_file_handler_interface_can_delete_fn_t`

```c
typedef emf_bool_t(*emf_file_handler_interface_can_delete_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path,
    emf_bool_t recursive
);
```

Queries if a path can be deleted.

A path can be deleted if no open files are contained within it.
A non empty directory can only be deleted if `recursive` is set to `emf_bool_true`.

> Note: The `path` is relative to the mounted path.
