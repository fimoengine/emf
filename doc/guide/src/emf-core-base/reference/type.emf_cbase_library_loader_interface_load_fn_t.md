# Type definition `emf_cbase_library_loader_interface_get_function_symbol_fn_t`

```c
typedef emf_cbase_library_loader_library_handle_result_t
(*emf_cbase_library_loader_interface_load_fn_t)(
    emf_cbase_library_loader_t* library_loader,
    const emf_cbase_os_path_char_t* library_path
);
```

A function pointer to a `load` function.

The function loads the library, which is located at `library_path`, and returns its handle.
The function must be thread-safe.
