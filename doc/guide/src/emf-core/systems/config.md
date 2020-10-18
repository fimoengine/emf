# Config system

## Introduction
The `config` system consists of namespaces and properties. Namespaces can contain properties and other namespaces. Properties are homogenous arrays of values. A namespace- or property-name must be a `UTF-8` string. All Namespaces are implicitly nested inside the global namespace.

### Properties
Properties can have the following types:

- Bool ([`emf_bool_t`](../reference/type.emf_bool_t.md))
- Integer (`int64_t`)
- Reals (`double`)
- String (`char*`)

Strings are treated as a sized blob of data, and as such can contain values other than strings. Unless stated otherwise, a string property represents a `UTF-8` string without a terminating `\0` character.

The array length of a property can not be changed after it's construction. Additionally, String properties are assigned a maximum length at construction.

## Example

### JSON

```json
{
    "str": "test",
    "test_namespace": {
        "double": 0.57,
        "arr": [5, 5],
        "nested_namespace": {
            "bool": true
        }
    }
}
```

### Equivalent

```c
emf_config_namespace_t ns1 = { "test_namespace" };
emf_config_namespace_t ns2 = { "test_namespace::nested_namespace" };

emf_config_property_t g_str = { "str" };
emf_config_property_t ns1_double = { "double" };
emf_config_property_t ns1_arr = { "arr" };
emf_config_property_t ns2_bool = { "bool" };

emf_config_string_t g_str_val = { "test", strlen("test") + 1 };

emf_lock();

emf_config_add_namespace(&ns1);
emf_config_add_namespace(&ns2);

emf_config_add_property_string(NULL, &g_str, 1, 256, &g_str_val);
emf_config_add_property_real(&ns1, &ns1_double, 1, 0.57);
emf_config_add_property_integer(&ns1, &ns1_arr, 2, 5);
emf_config_add_property_boolean(&ns2, &ns2_bool, 1, true);

emf_unlock();
```

## Constants

- [EMF_CONFIG_NAMESPACE_MAX_LENGTH](../reference/constant.EMF_CONFIG_NAMESPACE_MAX_LENGTH.md)
- [EMF_CONFIG_PROPERTY_MAX_LENGTH](../reference/constant.EMF_CONFIG_PROPERTY_MAX_LENGTH.md)

## Enums

- [emf_config_property_type_t](../reference/enum.emf_config_property_type_t.md)

## Structs

- [emf_config_namespace_span_t](../reference/struct.emf_config_namespace_span_t.md)
- [emf_config_namespace_t](../reference/struct.emf_config_namespace_t.md)
- [emf_config_property_info_span_t](../reference/struct.emf_config_property_info_span_t.md)
- [emf_config_property_info_t](../reference/struct.emf_config_property_info_t.md)
- [emf_config_property_t](../reference/struct.emf_config_property_t.md)
- [emf_config_string_buffer_t](../reference/struct.emf_config_string_buffer_t.md)
- [emf_config_string_t](../reference/struct.emf_config_string_t.md)

## Functions

- [emf_config_add_namespace](../reference/fn.emf_config_add_namespace.md)
- [emf_config_add_property_boolean](../reference/fn.emf_config_add_property_boolean.md)
- [emf_config_add_property_integer](../reference/fn.emf_config_add_property_integer.md)
- [emf_config_add_property_real](../reference/fn.emf_config_add_property_real.md)
- [emf_config_add_property_string](../reference/fn.emf_config_add_property_string.md)
- [emf_config_get_namespaces](../reference/fn.emf_config_get_namespaces.md)
- [emf_config_get_num_namespaces](../reference/fn.emf_config_get_num_namespaces.md)
- [emf_config_get_num_properties](../reference/fn.emf_config_get_num_properties.md)
- [emf_config_get_properties](../reference/fn.emf_config_get_properties.md)
- [emf_config_get_property_array_size](../reference/fn.emf_config_get_property_array_size.md)
- [emf_config_get_property_string_max_size](../reference/fn.emf_config_get_property_string_max_size.md)
- [emf_config_get_property_string_size](../reference/fn.emf_config_get_property_string_size.md)
- [emf_config_get_property_type](../reference/fn.emf_config_get_property_type.md)
- [emf_config_namespace_exists](../reference/fn.emf_config_namespace_exists.md)
- [emf_config_property_exists](../reference/fn.emf_config_property_exists.md)
- [emf_config_property_read_bool](../reference/fn.emf_config_property_read_bool.md)
- [emf_config_property_read_integer](../reference/fn.emf_config_property_read_integer.md)
- [emf_config_property_read_real](../reference/fn.emf_config_property_read_real.md)
- [emf_config_property_read_string](../reference/fn.emf_config_property_read_string.md)
- [emf_config_property_write_bool](../reference/fn.emf_config_property_write_bool.md)
- [emf_config_property_write_integer](../reference/fn.emf_config_property_write_integer.md)
- [emf_config_property_write_real](../reference/fn.emf_config_property_write_real.md)
- [emf_config_property_write_string](../reference/fn.emf_config_property_write_string.md)
- [emf_config_remove_namespace](../reference/fn.emf_config_remove_namespace.md)
- [emf_config_remove_property](../reference/fn.emf_config_remove_property.md)