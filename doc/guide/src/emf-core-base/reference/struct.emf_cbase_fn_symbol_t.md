# Struct `emf_cbase_fn_symbol_t`

```c
typedef struct emf_cbase_fn_symbol_t {
    emf_cbase_fn_t symbol;
} emf_cbase_fn_symbol_t;
```

A function symbol contained in a library.

## Fields

- **symbol**: [`emf_cbase_fn_t`](./type.emf_cbase_fn_t.md)

    A pointer to the symbol.
    Is never `NULL`.
