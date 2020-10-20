# Function `emf_config_get_properties`

```c
size_t emf_config_get_properties(
    const emf_config_namespace_t* group,
    emf_bool_t recursive,
    emf_config_property_info_span_t* buffer
);
```

Copies all properties into a buffer.

Copies the properties inside the supplied namespace into `buffer`.
The properties can be copied recursively by setting `recursive` to `emf_bool_true`.
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
    buffer->data,
    NULL
);
ASSERT(
    buffer->length >= emf_config_get_num_properties(group, recursive)
)
```
