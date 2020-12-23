# Struct `emf_cbase_library_size_result_t`

```c
typedef struct emf_cbase_library_size_result_t {
    union {
        size_t result;
        emf_cbase_library_error_t error;
    };
    emf_cbase_bool_t has_error;
} emf_cbase_library_size_result_t;
```

A struct containing either a `size_t` or an `emf_cbase_library_error_t`

## Fields

- **result**: `size_t`

    The size.

- **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)

    The error.

- **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)

    A boolean indicating if the result contains an error.
