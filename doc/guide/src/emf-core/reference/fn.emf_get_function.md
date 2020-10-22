# Function `emf_get_function`

```c
emf_fn_t emf_get_function(emf_fn_ptr_id_t fn_id);
```

Retrieves the function pointer of the supplied function.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_EQ(
    emf_has_function(fn_id),
    emf_bool_true
);
```
