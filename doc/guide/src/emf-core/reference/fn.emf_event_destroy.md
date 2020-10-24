# Function `emf_event_destroy`

```c
void emf_event_destroy(
    emf_event_handle_t event_handle
);
```

Destroys an event.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_EQ(
    emf_event_name_exists(event_name),
    emf_bool_true
);
```
