# Type definition `emf_file_handler_interface_create_directory_fn_t`

```c
typedef void(*emf_file_handler_interface_create_directory_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path,
    const void* options
);
```

Creates a new directory.

Creates a new directory at the specified path.
The directory can be created if no other entry exists at the same path.
A pointer to an implementation-defined structure, which controlls how the directory is created, can be passed.
If no pointer is supplied, the default options will be used.
By default, an empty directory with write permissions will be created.

> Note: The `path` is relative to the mounted path.
