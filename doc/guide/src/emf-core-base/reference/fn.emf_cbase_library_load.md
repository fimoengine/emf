# Function `emf_cbase_library_load`

```c
emf_cbase_library_handle_result_t emf_cbase_library_load(
    emf_cbase_library_loader_handle_t loader_handle,
    const emf_cbase_os_path_char_t* library_path
)
```

Loads a library.

The resulting handle is unique.

## Failure

The function fails if `loader_handle` or `library_path` is invalid or the type of the library can not be loaded by the loader.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   library_path,
   NULL
);
```
