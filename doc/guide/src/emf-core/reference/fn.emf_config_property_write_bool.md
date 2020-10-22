# Function `emf_config_property_write_bool`

```c
void emf_config_property_write_bool(
    const emf_config_namespace_t* group,
    const emf_config_property_t* property,
    size_t index,
    emf_bool_t value
);
```

Writes a value into a bool property member.

The namespace `NULL` and the empty namespace refer to the global namespace.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT(
    group == NULL ||
    emf_config_namespace_exists(group) == emf_bool_true
);
ASSERT_NE(
    property,
    NULL
);
ASSERT_EQ(
    emf_config_property_exists(group, property),
    emf_bool_true
);
ASSERT_EQ(
    emf_config_get_property_type(group, property),
    emf_config_prop_type_bool
);
ASSERT(
    index < emf_config_get_property_array_size(group, property)
);
```
