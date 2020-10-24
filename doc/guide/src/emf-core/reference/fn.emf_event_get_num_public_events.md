# Function `emf_event_get_num_public_events`

```c
size_t emf_event_get_num_public_events();
```

Returns the number of public events.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
