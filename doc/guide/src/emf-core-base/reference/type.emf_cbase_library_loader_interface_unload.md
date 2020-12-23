# Type definition `emf_cbase_library_loader_interface_unload_fn_t`

```c
typedef emf_cbase_library_error_optional_t
(*emf_cbase_library_loader_interface_unload_fn_t)(
    emf_cbase_library_loader_t* library_loader,
    emf_cbase_library_loader_library_handle_t library_handle
);
```

A function pointer to a `unload` function.

The function unloads a library, that was loaded previously.
The function must be thread-safe.
