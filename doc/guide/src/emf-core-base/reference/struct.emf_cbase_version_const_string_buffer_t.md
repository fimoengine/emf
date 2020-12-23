# Struct `emf_cbase_version_const_string_buffer_t`

```c
typedef struct emf_cbase_version_const_string_buffer_t {
    const char* data;
    size_t length;
} emf_cbase_version_const_string_buffer_t;
```

A buffer containing a constant string representation of a version.

The string contains only `ASCII` characters and is not terminated with a `\0`.

## Fields

- **data**: `const char*`

    The start of the string.

- **length**: `size_t`

    The length of the string.
