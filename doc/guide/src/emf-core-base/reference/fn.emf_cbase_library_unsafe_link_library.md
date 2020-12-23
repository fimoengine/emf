# Function `emf_cbase_library_unsafe_link_library`

```c
emf_cbase_library_error_optional_t emf_cbase_library_unsafe_link_library(
    emf_cbase_library_handle_t library_handle, 
    emf_cbase_library_loader_handle_t loader_handle,
    emf_cbase_library_loader_library_handle_t loader_library_handle
)
```

Links a library handle to an internal library handle.

Overrides the internal link of the library handle by setting it to the new library loader and internal handle.

## Failure

The function fails if `library_handle` or `loader_handle` are invalid.

## Warning

Incorrect usage can lead to dangling handles or use-after-free errors.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
