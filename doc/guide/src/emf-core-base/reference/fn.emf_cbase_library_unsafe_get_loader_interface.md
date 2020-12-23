# Function `emf_cbase_library_unsafe_get_loader_interface`

```c
emf_cbase_library_loader_interface_result_t emf_cbase_library_unsafe_get_loader_interface(
    emf_cbase_library_loader_handle_t loader_handle
)
```

Fetches the interface of a library loader.

## Failure

The function fails if `loader_handle` is invalid.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
