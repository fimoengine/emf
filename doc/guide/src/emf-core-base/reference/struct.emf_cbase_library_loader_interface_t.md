# Struct `emf_cbase_library_loader_interface_t`

```c
typedef struct emf_cbase_library_loader_interface_t {
    emf_cbase_library_loader_t* library_loader;
    emf_cbase_library_loader_interface_load_fn_t load_fn;
    emf_cbase_library_loader_interface_unload_fn_t unload_fn;
    emf_cbase_library_loader_interface_get_data_symbol_fn_t get_data_symbol_fn;
    emf_cbase_library_loader_interface_get_function_symbol_fn_t get_function_fn;
    emf_cbase_library_loader_interface_get_internal_interface_fn_t get_internal_interface_fn;
} emf_cbase_library_loader_interface_t;
```

Interface of a library loader.

## Fields

- **library_loader**: [`emf_cbase_library_loader_t`](./struct.emf_cbase_library_loader_t.md)

    A pointer to the library loader.

- **load_fn**: [`emf_cbase_library_loader_interface_load_fn_t`](./type.emf_cbase_library_loader_interface_load_fn_t.md)

    The load function of the library loader.
    May not be `NULL`.

- **unload_fn**: [`emf_cbase_library_loader_interface_unload_fn_t`](./type.emf_cbase_library_loader_interface_unload_fn_t.md)

    The unload function of the library loader.
    May not be `NULL`.

- **get_data_symbol_fn**: [`emf_cbase_library_loader_interface_get_data_symbol_fn_t`](./type.emf_cbase_library_loader_interface_get_data_symbol_fn_t.md)

    The get_data_symbol function of the library loader.
    May not be `NULL`.

- **get_function_fn**: [`emf_cbase_library_loader_interface_get_function_symbol_fn_t`](./type.emf_cbase_library_loader_interface_get_function_symbol_fn_t.md)

    The get_function function of the library loader.
    May not be `NULL`.

- **get_internal_interface_fn**: [`emf_cbase_library_loader_interface_get_internal_interface_fn_t`](./type.emf_cbase_library_loader_interface_get_internal_interface_fn_t.md)

    The get_internal_interface function of the library loader.
    May not be `NULL`.
