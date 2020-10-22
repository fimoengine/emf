# Function `emf_config_property_exists`

```c
emf_bool_t emf_config_property_exists(
    const emf_config_namespace_t* group,
    const emf_config_property_t* property
);
```

Checks if a property exists.

Checks if the property is present inside the supplied namespace. The namespace `NULL` and the empty namespace refer to the global namespace.

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
```
