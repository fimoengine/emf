# Function `emf_cbase_library_unsafe_create_library_handle`

```c
emf_cbase_library_handle_t emf_cbase_library_unsafe_create_library_handle()
```

Creates a new unlinked library handle.

## Warning

The handle must be linked before use (See
[emf_cbase_library_unsafe_link_library()](./fn.emf_cbase_library_unsafe_link_library.md)).

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
