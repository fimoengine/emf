# Function `emf_cbase_sys_has_function`

```c
emf_cbase_bool_t emf_cbase_sys_has_function(emf_cbase_fn_ptr_id_t fn_id)
```

Checks if a function is implemented.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
