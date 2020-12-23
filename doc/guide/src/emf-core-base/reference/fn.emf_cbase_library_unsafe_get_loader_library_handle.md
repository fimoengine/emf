# Function `emf_cbase_library_unsafe_get_loader_library_handle`

```c
emf_cbase_library_loader_library_handle_result_t emf_cbase_library_unsafe_get_loader_library_handle(
    emf_cbase_library_handle_t library_handle
)
```

Fetches the internal handle linked with the library handle.

## Failure

The function fails if `library_handle` is invalid.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
