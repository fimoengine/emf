# Function `emf_cbase_sys_panic`

```c
_Noreturn void emf_cbase_sys_panic(const char* error)
```

Panics.

Execution of the program is stopped abruptly after the error is logged.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
