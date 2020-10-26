# Function `emf_event_unsubscribe_handler`

```c
void emf_event_unsubscribe_handler(
    emf_event_handle_t event_handle,
    emf_event_handler_fn_t event_handler
);
```

Unsubscribes from an event.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
The event handler must already be subscribed.  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_EQ(
    emf_event_handle_exists(event_handle),
    emf_bool_true
);
ASSERT_NE(
    event_handler,
    NULL
);
```
