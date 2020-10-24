# Function `emf_event_signal`

```c
void emf_event_signal(
    emf_event_handle_t event_handle, 
    emf_event_data_t event_data
);
```

Fires an event.

## Event input

The parameter `event_data` is passed to every handler in the event. The creator of the event should define the structure, mutability and valid operations of the input.

See [`emf_event_subscribe_handler()`](./fn.emf_event_subscribe_handler.md) for more information.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_EQ(
    emf_event_handle_exists(event_handle),
    emf_bool_true
);
```
