# Struct `emf_memory_span_t`

```c
typedef struct emf_memory_span_t {
    const void* data;
    size_t length;
} emf_memory_span_t;
```

A region of memory.

## Fields

- **data**: `const void*`

    Start of the region.

- **length**: `size_t`

    Length of the region.
