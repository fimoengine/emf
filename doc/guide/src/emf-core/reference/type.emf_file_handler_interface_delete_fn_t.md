# Type definition `emf_file_handler_interface_delete_fn_t`

```c
typedef void(*emf_file_handler_interface_delete_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path,
    emf_bool_t recursive
);
```

Deletes a path.

It is undefined behaviour to delete a path that can not be deleted.

> Note: The `path` is relative to the mounted path.
