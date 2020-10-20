# Struct `emf_config_property_info_t`

```c
typedef struct emf_config_property_info_t {
    emf_config_namespace_t group;
    emf_config_property_t property;
    emf_config_property_type_t property_type;
    size_t size;
} emf_config_property_info_t;
```

Information of a property.

## Fields

- **group**: [`emf_config_namespace_t`](./struct.emf_config_namespace_t.md)

    The identifier of the namespace.

- **property**: [`emf_config_property_t`](./struct.emf_config_property_t.md)

    The identifier of the property.

- **property_type**: [`emf_config_property_type_t`](./enum.emf_config_property_type_t.md)

    The type of the property.

- **size**: `size_t`

    Array size of the property.
