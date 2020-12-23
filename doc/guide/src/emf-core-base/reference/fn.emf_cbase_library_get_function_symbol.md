# Function `emf_cbase_library_get_function_symbol`

```c
emf_cbase_library_fn_symbol_result_t emf_cbase_library_get_function_symbol(
   emf_cbase_library_handle_t library_handle,
   const char* symbol_name
)
```

Fetches a data symbol from a library.

Some platforms may differentiate between a `function-pointer` and a `data-pointer`.
See [emf_cbase_library_get_data_symbol()](./fn.emf_cbase_library_get_data_symbol.md) when fetching some data.

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
