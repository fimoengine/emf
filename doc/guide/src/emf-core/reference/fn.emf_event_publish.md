# Function `emf_event_publish`

```c
void emf_event_publish(
    emf_event_handle_t event_handle, 
    const emf_event_name_t* event_name
);
```

Converts a private event into a public event.

The conversion is applied, by assigning a name to the private event.
See [`emf_event_create()`](./fn.emf_event_create.md) for more information.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_EQ(
    emf_event_handle_exists(event_handle),
    emf_bool_true
);
ASSERT_NE(
    event_name,
    NULL
);
ASSERT_EQ(
    emf_event_name_exists(event_name),
    emf_bool_false
)
```
