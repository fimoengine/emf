# Struct `emf_config_namespace_t`

```c
typedef struct emf_config_namespace_t {
    char data[EMF_CONFIG_NAMESPACE_MAX_LENGTH];
    size_t length;
} emf_config_namespace_t;
```

The name of a namespace.

## Fields

- **data**: [`char[EMF_CONFIG_NAMESPACE_MAX_LENGTH]`](./constant.EMF_CONFIG_NAMESPACE_MAX_LENGTH.md)

    The identifier of the namespace.

- **length**: `size_t`

    Length of the identifier.