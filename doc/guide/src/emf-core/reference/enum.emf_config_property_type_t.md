# Enum `emf_config_property_type_t`

```c
typedef enum emf_config_property_type_t : int32_t {
    emf_config_prop_type_bool = 0,
    emf_config_prop_type_integer = 1,
    emf_config_prop_type_real = 2,
    emf_config_prop_type_string = 3,
} emf_config_property_type_t;
```

An enum describing all possible property types.

## Variants

| Name                             | Value | Description          |
| -------------------------------- | ----- | -------------------- |
| **emf_config_prop_type_bool**    | `0`   | A boolean property.  |
| **emf_config_prop_type_integer** | `1`   | An integer property. |
| **emf_config_prop_type_real**    | `2`   | A real property.     |
| **emf_config_prop_type_string**  | `3`   | A string property.   |