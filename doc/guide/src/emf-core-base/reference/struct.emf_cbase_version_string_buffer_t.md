# Struct `emf_cbase_version_string_buffer_t`

```c
typedef struct emf_cbase_version_string_buffer_t {
    char* data;
    size_t length;
} emf_cbase_version_string_buffer_t;
```

A buffer to store the string representation of a version.

The string contains only `ASCII` characters and is not terminated with a `\0`.

## Fields

- **data**: `char*`

    The start of the string.

- **length**: `size_t`

    The length of the string.
