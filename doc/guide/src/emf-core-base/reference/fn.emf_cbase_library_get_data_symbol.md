# Function `emf_cbase_os_path_char_t`

```c
emf_cbase_library_data_symbol_result_t emf_cbase_library_get_data_symbol(
    emf_cbase_library_handle_t library_handle,
    const char* symbol_name
)
```

Fetches a data symbol from a library.

Some platforms may differentiate between a `function-pointer` and a `data-pointer`.
See [emf_cbase_library_get_function_symbol()](./fn.emf_cbase_library_get_function_symbol.md) when fetching a function.

## Failure

The function fails if `library_handle` is invalid or library does not contain `symbol_name`.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   symbol_name,
   NULL
);
```
