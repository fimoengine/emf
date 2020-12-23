# Struct `emf_cbase_library_type_t`

```c
typedef struct emf_cbase_library_type_t {
    char data[EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH];
    size_t length;
} emf_cbase_library_type_t;
```

The type of a library.

A library type is modelled as an `UTF-8` encoded string, without a `\0` terminator.

## Fields

- **data**: [`char[EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH]`](./constant.EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH.md)

    The type string.

- **length**: `size_t`

    Length of the string.
