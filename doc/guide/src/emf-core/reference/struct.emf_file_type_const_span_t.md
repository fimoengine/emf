# Struct `emf_file_type_const_span_t`

```c
typedef struct emf_file_type_const_span_t {
    const emf_file_type_t* data;
    size_t length;
} emf_file_type_const_span_t;
```

A span of constant file-type strings.

## Fields

- **data**: [`const emf_file_type_t*`](./struct.emf_file_type_t.md)

    Start of the span.

- **length**: `size_t`

    Length of the span.
