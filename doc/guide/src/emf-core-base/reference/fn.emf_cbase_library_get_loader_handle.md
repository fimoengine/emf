# Function `emf_cbase_library_get_loader_handle`

```c
emf_cbase_library_loader_handle_result_t emf_cbase_library_get_loader_handle(
    const emf_cbase_library_type_t* library_type
)
```

Fetches the loader handle associated with the library type.

## Failure

The function fails if `library_type` is not registered.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   library_type,
   NULL
);
```
