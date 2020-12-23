# Function `emf_cbase_library_unload`

```c
emf_cbase_library_error_optional_t emf_cbase_library_unload(
    emf_cbase_library_handle_t library_handle
)
```

Unloads a library.

## Failure

The function fails if `library_handle` is invalid.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
