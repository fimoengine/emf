# Function `emf_cbase_library_unsafe_remove_library_handle`

```c
emf_cbase_library_error_optional_t emf_cbase_library_unsafe_remove_library_handle(
    emf_cbase_library_handle_t library_handle
)
```

Removes an existing library handle.

## Failure

The function fails if `library_handle` is invalid.

## Warning

Removing the handle does not unload the library.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
