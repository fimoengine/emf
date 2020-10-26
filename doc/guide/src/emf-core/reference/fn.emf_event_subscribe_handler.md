# Function `emf_event_subscribe_handler`

```c
void emf_event_subscribe_handler(
    emf_event_handle_t event_handle,
    emf_event_handler_fn_t event_handler
);
```

Subscribes to an event.

The `event_handler` is added to the end of the call list.

## Event input

Not every `event_handler` is compatible with an event.
The creator of an event must define how the input will be interpreted.
Incorrect usage of an event may lead errors that are difficult to find.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
A event handler may not subscribe twice to the same event.  
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
