# Function `emf_shutdown`

```c
void emf_shutdown();
```

Sends a termination signal.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
