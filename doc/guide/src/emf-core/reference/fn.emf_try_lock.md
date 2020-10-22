# Function `emf_try_lock`

```c
emf_bool_t emf_try_lock();
```

Tries to lock the interface.

The function fails if another thread already holds the lock.
The result is `emf_bool_true` on success and `emf_bool_false` otherwise.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
