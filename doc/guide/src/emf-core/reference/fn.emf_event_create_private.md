# Function `emf_event_create_private`

```c
emf_event_handle_t emf_event_create_private(
    emf_event_handler_fn_t event_handler
);
```

Creates a new private event.

Private events can only be accessed by the handle.
An empty event can be created, by passing `NULL` to `event_handler`.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
