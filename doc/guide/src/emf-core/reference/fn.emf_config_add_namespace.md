# Function `emf_config_add_namespace`

```c
void emf_config_add_namespace(const emf_config_namespace_t* group);
```

Creates a new namespace.

Creates a new namespace, which can hold properties. Multiple namespaces can be nested inside each other.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
    group,
    NULL
);
ASSERT_EQ(
    emf_config_namespace_exists(group),
    emf_bool_false
);
```
