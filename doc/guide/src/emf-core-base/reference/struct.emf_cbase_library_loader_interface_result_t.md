# Struct `emf_cbase_library_loader_interface_result_t`

```c
typedef struct emf_cbase_library_loader_interface_result_t {
    union {
        const emf_cbase_library_loader_interface_t* result;
        emf_cbase_library_error_t error;
    };
    emf_cbase_bool_t has_error;
} emf_cbase_library_loader_interface_result_t;
```

A struct containing either an `const emf_cbase_library_loader_interface_t*` or an `emf_cbase_library_error_t`

## Fields

- **result**: [`const emf_cbase_library_loader_interface_t*`](./struct.emf_cbase_library_loader_interface_t.md)

    The pointer to the interface.
    Is never `NULL`.

- **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)

    The error.

- **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)

    A boolean indicating if the result contains an error.
