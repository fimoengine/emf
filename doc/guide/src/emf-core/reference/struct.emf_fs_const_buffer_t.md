# Struct `emf_fs_const_buffer_t`

```c
typedef struct emf_fs_const_buffer_t {
    const uint8_t* data;
    size_t length;
} emf_fs_const_buffer_t;
```

A span of constant bytes.

## Fields

- **data**: `const uint8_t*`

    Start of the span.

- **length**: `size_t`

    Length of the span.
