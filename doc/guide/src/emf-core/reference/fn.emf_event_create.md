# Function `emf_event_create`

```c
emf_event_handle_t emf_event_create(
    const emf_event_name_t* event_name,
    emf_event_handler_fn_t event_handler
);
```

Creates a new public event.

Creates a new public event with the name `event_name`. 
An empty event can be created, by passing `NULL` to `event_handler`.

## Naming convention

Events follow a similar naming convention to the one found in the `C` language:

- Names starting with `__` are reserved for the emf-core interface.
- Names starting with `_Interface` (where `Interface` is `I` followed by the name, e.g. `_Iemf::core`) are reserved for the corresponding interface.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
    event_name,
    NULL
);
ASSERT_EQ(
    emf_event_name_exists(event_name),
    emf_bool_false
);
```
