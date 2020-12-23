# Struct `emf_cbase_library_fn_symbol_result_t`

```c
typedef struct emf_cbase_library_fn_symbol_result_t {
    union {
        emf_cbase_fn_symbol_t result;
        emf_cbase_library_error_t error;
    };
    emf_cbase_bool_t has_error;
} emf_cbase_library_fn_symbol_result_t;
```

A struct containing either an `emf_cbase_fn_symbol_t` or an `emf_cbase_library_error_t`

## Fields

- **result**: [`emf_cbase_fn_symbol_t`](./struct.emf_cbase_fn_symbol_t.md)

    The symbol.

- **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)

    The error.

- **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)

    A boolean indicating if the result contains an error.
