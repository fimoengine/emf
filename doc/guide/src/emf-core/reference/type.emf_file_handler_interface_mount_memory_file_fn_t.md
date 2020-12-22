# Type definition `emf_file_handler_interface_mount_memory_file_fn_t`

```c
typedef emf_file_handler_mount_id_t(*emf_file_handler_interface_mount_memory_file_fn_t)(
    const emf_memory_span_t* file,
    emf_access_mode_t access_mode,
    const void* options
);
```

Mounts a region of memory.
