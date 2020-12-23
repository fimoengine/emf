# Struct `emf_cbase_version_result_t`

```c
typedef struct emf_cbase_version_result_t {
    union {
        emf_cbase_version_t result;
        emf_cbase_version_error_t error;
    };
    emf_cbase_bool_t has_error;
} emf_cbase_version_result_t;
```

A struct containing either an `emf_cbase_version_t` or an `emf_cbase_version_error_t`

## Fields

- **result**: [`emf_cbase_version_t`](./struct.emf_cbase_version_t.md)

    The version.

- **error**: [`emf_cbase_version_error_t`](./enum.emf_cbase_version_error_t.md)

    The error.

- **has_error**: [`emf_cbase_bool_t`](./type.emf_cbase_bool_t.md)

    A boolean indicating if the result contains an error.
