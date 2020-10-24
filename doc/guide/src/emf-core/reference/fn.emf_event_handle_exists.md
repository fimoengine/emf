# Function `emf_event_handle_exists`

```c
emf_bool_t emf_event_handle_exists(
    emf_event_handle_t event_handle
);
```

Checks for the existence of a handle.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
