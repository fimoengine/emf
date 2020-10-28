# Struct `emf_file_type_t`

```c
typedef struct emf_file_type_t {
    char data[EMF_FILE_TYPE_MAX_LENGTH];
    size_t length;
} emf_file_type_t;
```

A `UTF-8` string that describes the type of a file.

## Fields

- **data**: [`char[EMF_FILE_TYPE_MAX_LENGTH]`](./constant.EMF_FILE_TYPE_MAX_LENGTH.md)

    Start of the string.

- **length**: `size_t`

    Length of the string.
