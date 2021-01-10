# Struct `emf_cbase_native_library_loader_interface_t`

```c
typedef struct emf_cbase_native_library_loader_interface_t {
    const emf_cbase_library_loader_interface_t* library_loader_interface;
    emf_cbase_native_library_loader_interface_load_ext_fn_t load_ext_fn;
} emf_cbase_native_library_loader_interface_t
```

Interface of the native library loader.

## Fields

- **library_loader_interface**: [`const emf_cbase_library_loader_interface_t*`](./struct.emf_cbase_library_loader_interface_t.md)

    The base library loader interface.

- **load_ext_fn**: [`emf_cbase_native_library_loader_interface_load_ext_fn_t`](./type.emf_cbase_native_library_loader_interface_load_ext_fn_t.md)

    The load_ext function of the module loader.
    May not be `NULL`.
