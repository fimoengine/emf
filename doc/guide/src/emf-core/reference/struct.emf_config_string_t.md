# Struct `emf_config_string_t`

```c
typedef struct emf_config_string_t {
    const char* data;
    size_t length;
} emf_config_string_t;
```

A `UTF-8` string used by the `config` system.

The string is not teminated with the `\0` character.

## Fields

- **data**: `const char*`

    Start of the string.

- **length**: `size_t`

    Length of the string.
