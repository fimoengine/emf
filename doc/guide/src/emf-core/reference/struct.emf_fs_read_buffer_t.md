# Struct `emf_fs_read_buffer_t`

```c
typedef struct emf_fs_read_buffer_t {
    uint8_t* data;
    size_t length;
} emf_fs_read_buffer_t;
```

A span of bytes.

## Fields

- **data**: `uint8_t*`

    Start of the span.

- **length**: `size_t`

    Length of the span.
