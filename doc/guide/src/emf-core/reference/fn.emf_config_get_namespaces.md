# Function `emf_config_get_namespaces`

```c
size_t emf_config_get_namespaces(
    const emf_config_namespace_t* group,
    emf_bool_t recursive,
    emf_config_namespace_span_t* buffer
);
```
Copies all namespaces into a buffer.

Copies every namespace inside (and including) the supplied namespace into the supplied `buffer`. The namespaces can be copied recursively by setting `recursive` to `emf_bool_true`. The namespace `NULL` and the empty namespace refer to the global namespace.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)). <br>
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT(
    group == NULL ||
    emf_config_namespace_exists(group) == emf_bool_true
);
ASSERT_NE(
    buffer,
    NULL
);
ASSERT_NE(
    buffer->data,
    NULL
);
ASSERT(
    buffer->length >= emf_config_get_num_namespaces(group, recursive)
);
```