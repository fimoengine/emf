# Function `emf_cbase_library_unregister_loader`

```c
emf_cbase_library_error_optional_t emf_cbase_library_unregister_loader(
    emf_cbase_library_loader_handle_t loader_handle
)
```

Unregisters an existing loader.

## Failure

The function fails if `loader_handle` is invalid.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
