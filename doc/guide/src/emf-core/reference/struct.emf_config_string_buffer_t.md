# Struct `emf_config_string_buffer_t`

```c
typedef struct emf_config_string_buffer_t {
    char* data;
    size_t length;
} emf_config_string_buffer_t;
```

A writable `UTF-8` string used by the `config` system.

The string is not teminated with the `\0` character.

## Fields

- **data**: `char*`

    Start of the string.

- **length**: `size_t`

    Length of the string.
