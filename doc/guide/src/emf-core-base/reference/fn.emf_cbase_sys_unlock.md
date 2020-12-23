# Function `emf_cbase_sys_unlock`

```c
void emf_cbase_sys_unlock()
```

Unlocks the interface.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
