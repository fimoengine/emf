# Struct `emf_config_property_t`

```c
typedef struct emf_config_property_t {
    char data[EMF_CONFIG_PROPERTY_MAX_LENGTH];
    size_t length;
} emf_config_property_t;
```

The name of a property.

## Fields

- **data**: [`char[EMF_CONFIG_PROPERTY_MAX_LENGTH]`](./constant.EMF_CONFIG_PROPERTY_MAX_LENGTH.md)

    The identifier of the property.

- **length**: `size_t`

    Length of the identifier.