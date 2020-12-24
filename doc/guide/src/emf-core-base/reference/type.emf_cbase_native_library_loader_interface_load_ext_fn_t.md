# Type definition `emf_cbase_native_library_loader_interface_load_ext_fn_t`

```c
#if defined(Win32) || defined(_WIN32)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_library_loader_interface_load_ext,
    emf_cbase_library_loader_library_handle_result_t,
    emf_cbase_library_loader_t* library_loader,
    const emf_cbase_os_path_char_t* library_path, 
    void* hFile, 
    uint32_t flags
)
#else
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_library_loader_interface_load_ext,
    emf_cbase_library_loader_library_handle_result_t,
    emf_cbase_library_loader_t* library_loader,
    const emf_cbase_os_path_char_t* library_path, 
    int flags
)
#endif // defined(Win32) || defined(_WIN32)
```

A function pointer to a `load_ext` function.

The function loads the library, which is located at `library_path`, and returns its handle.
Passes through its arguments to the platform dependent library loading utilities.
