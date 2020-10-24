# Function `emf_event_get_public_events`

```c
size_t emf_event_get_public_events(
    emf_event_name_span_t* buffer
);
```

Copies all public events into a buffer.

The names of all public events are copied into `buffer`.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
    buffer,
    NULL
);
ASSERT_NE(
    buffer->data,
    NULL
);
ASSERT(
    buffer->length >= emf_event_get_num_public_events()
);
```
