# Struct `emf_cbase_library_type_span_t`

```c
typedef struct emf_cbase_library_type_span_t {
    emf_cbase_library_type_t data;
    size_t length;
} emf_cbase_library_type_span_t;
```

A span of library types.

## Fields

- **data**: [`emf_cbase_library_type_t*`](./struct.emf_cbase_library_type_t.md)

    The start of the span.

- **length**: `size_t`

    The length of the span.
