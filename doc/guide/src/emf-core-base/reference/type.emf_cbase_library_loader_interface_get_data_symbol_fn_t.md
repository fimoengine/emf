# Type definition `emf_cbase_library_loader_interface_get_data_symbol_fn_t`

```c
typedef emf_cbase_library_data_symbol_result_t
(*emf_cbase_library_loader_interface_get_data_symbol_fn_t)(
    emf_cbase_library_loader_t* library_loader,
    emf_cbase_library_loader_library_handle_t library_handle, 
    const char* symbol_name
);
```

A function pointer to a `get_data_symbol` function.

The function fetches a pointer to the symbol `symbol_name` from the library.
The function must be thread-safe.
