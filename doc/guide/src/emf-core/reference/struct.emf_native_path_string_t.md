# Struct `emf_native_path_string_t`

```c
typedef struct emf_native_path_string_t {
    emf_native_path_char_t* data;
    size_t length;
} emf_native_path_string_t;
```

A native path string.

## Fields

- **data**: [`emf_native_path_char_t*`](./type.emf_native_path_char_t.md)

    Start of the string.

- **length**: `size_t`

    Length of the string.
