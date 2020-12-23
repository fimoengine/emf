# Struct `emf_cbase_sys_fn_optional_t`

```c
typedef struct emf_cbase_sys_fn_optional_t {
    union {
        emf_cbase_fn_t value;
        emf_cbase_bool_t _dummy;
    };
    emf_cbase_bool_t has_value;
} emf_cbase_sys_fn_optional_t;
```

An optional `emf_cbase_fn_t` value

## Fields

- **value**: [`emf_cbase_fn_t`](./type.emf_cbase_fn_t.md)

    A pointer to a function.

- **has_value**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)

    A boolean indicating if the optional contains a value.
