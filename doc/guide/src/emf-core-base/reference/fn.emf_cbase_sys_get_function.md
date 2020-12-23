# Function `emf_cbase_sys_get_function`

```c
emf_cbase_sys_fn_optional_t emf_cbase_sys_get_function(
    emf_cbase_fn_ptr_id_t fn_id
)
```

Retrieves the function pointer to the function.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
