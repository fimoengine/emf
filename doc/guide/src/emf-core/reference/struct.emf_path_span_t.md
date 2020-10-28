# Struct `emf_path_span_t`

```c
typedef struct emf_path_span_t {
    emf_path_t* data;
    size_t length;
} emf_path_span_t;
```

A span of paths.

## Fields

- **data**: [`emf_path_t*`](./struct.emf_path_t.md)

    Start of the span.

- **length**: `size_t`

    Length of the span.
