# Function `emf_event_name_exists`

```c
emf_bool_t emf_event_name_exists(
    const emf_event_name_t* event_name
);
```

Checks for the existence of a name.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
    event_name,
    NULL
);
```
