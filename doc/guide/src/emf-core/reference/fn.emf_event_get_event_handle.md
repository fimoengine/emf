# Function `emf_event_get_event_handle`

```c
emf_event_handle_t emf_event_get_event_handle(
    const emf_event_name_t* event_name
);
```

Fetches the handle of a public event.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
    event_name,
    NULL
);
ASSERT_EQ(
    emf_event_name_exists(event_name),
    emf_bool_true
);
```
