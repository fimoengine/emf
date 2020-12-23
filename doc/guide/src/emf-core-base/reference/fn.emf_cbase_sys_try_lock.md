# Function `emf_cbase_sys_try_lock`

```c
emf_cbase_bool_t emf_cbase_sys_try_lock()
```

Tries to lock the interface.

The function fails if another thread already holds the lock.
The result is `emf_cbase_bool_true` on success and `emf_cbase_bool_false` otherwise.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
