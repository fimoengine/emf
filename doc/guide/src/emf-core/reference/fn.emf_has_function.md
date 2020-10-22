# Function `emf_has_function`

```c
emf_bool_t emf_has_function(emf_fn_ptr_id_t fn_id);
```

Checks if a function is implemented.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
