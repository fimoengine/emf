# Struct `emf_file_handler_span_t`

```c
typedef struct emf_file_handler_span_t {
    emf_file_handler_t* data;
    size_t length;
} emf_file_handler_span_t;
```

A span of `File handler` handles.

## Fields

- **data**: [`emf_file_handler_t*`](./struct.emf_file_handler_t.md)

    The start of the span.

- **length**: `size_t`

    Number of handles in the span.
