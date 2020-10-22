# Function `emf_config_namespace_exists`

```c
emf_bool_t emf_config_namespace_exists(
    const emf_config_namespace_t* group
);
```

Check if a namespace exists.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
    group,
    NULL
);
```
