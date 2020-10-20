# Function emf_config_get_num_properties

```c
size_t emf_config_get_num_properties(
    const emf_config_namespace_t* group,
    emf_bool_t recursive
);
```

Retrieves the number of properties in a namespace.

Returns the number of properties inside the supplied namespace.
The properties can be counted recursively by setting `recursive` to `emf_bool_true`.
The namespace `NULL` and the empty namespace refer to the global namespace.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT(
    group == NULL ||
    emf_config_namespace_exists(group) == emf_bool_true
);
```
