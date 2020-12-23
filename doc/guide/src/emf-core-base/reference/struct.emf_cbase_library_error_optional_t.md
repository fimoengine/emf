# Struct `emf_cbase_library_error_optional_t`

```c
typedef struct emf_cbase_library_error_optional_t {
    union {
        emf_cbase_library_error_t value;
        emf_cbase_bool_t _dummy;
    };
    emf_cbase_bool_t has_value;
} emf_cbase_library_error_optional_t;
```

An optional `emf_cbase_library_error_t` value

## Fields

- **value**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)

    The error value.

- **has_value**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)

    A boolean indicating if the optional contains a value.
