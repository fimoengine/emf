# Function `emf_config_add_property_string`

```c
void emf_config_add_property_string(
    const emf_config_namespace_t* group,
    const emf_config_property_t* property,
    size_t array_size,
    size_t string_length,
    const emf_config_string_t* default_value
);
```
Adds a string property to a namespace.

Adds a string property to the supplied namespace. The namespace `NULL` and the empty namespace refer to the global namespace.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)). <br>
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
    emf_config_property_exists(group),
    emf_bool_false
);
ASSERT(
    array_size >= 1
);
ASSERT(
    string_length >= 1
);
ASSERT_NE(
    default_value,
    NULL
);
```