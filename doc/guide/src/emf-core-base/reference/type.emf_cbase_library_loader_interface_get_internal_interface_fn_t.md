# Type definition `emf_cbase_library_loader_interface_get_internal_interface_fn_t`

```c
typedef const void* (*emf_cbase_library_loader_interface_get_internal_interface_fn_t)(void);
```

A function pointer to a `get_internal_interface` function.

The function fetches a pointer to the internal interface of the loader.
The function must be thread-safe.
