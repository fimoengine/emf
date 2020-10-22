# Function `emf_unlock`

```c
void emf_unlock();
```

Unlocks the interface.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
