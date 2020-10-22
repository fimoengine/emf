# Function `emf_config_remove_namespace`

```c
void emf_config_remove_namespace(
    const emf_config_namespace_t* group
);
```

Removes an existing namespace.

Removes a namespace, its properties and its child-namespaces.

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
    emf_bool_true
);
```
