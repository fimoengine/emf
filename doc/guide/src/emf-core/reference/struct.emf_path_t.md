# Struct `emf_path_t`

```c
typedef struct emf_path_t {
    char data[EMF_PATH_MAX];
    size_t length
} emf_path_t;
```

A `UTF-8` string that describes a path.

## Fields

- **data**: [`char[EMF_PATH_MAX]`](./constant.EMF_PATH_MAX.md)

    Start of the string.

- **length**: `size_t`

    Length of the string.
