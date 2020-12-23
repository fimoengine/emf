# Function `emf_cbase_library_library_exists`

```c
emf_cbase_bool_t emf_cbase_library_library_exists(
    emf_cbase_library_handle_t library_handle
)
```

Checks if a the library handle is valid.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
