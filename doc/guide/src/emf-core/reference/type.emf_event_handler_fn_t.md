# Type definition `emf_event_handler_fn_t`

```c
typedef void(*emf_event_handler_fn_t)(emf_event_data_t data);
```

An event handler.

The function signature of an event handler accepts an optional [`emf_event_data_t`](./type.emf_event_data_t.md) parameter. This parameter represents a type erased pointer and is supplied when the event is dispatched.
