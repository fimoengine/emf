# Function `emf_cbase_sys_shutdown`

```c
_Noreturn void emf_cbase_sys_shutdown()
```

Sends a termination signal.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
