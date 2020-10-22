# Function `emf_get_sync_handler`

```c
const emf_sync_handler_t* emf_get_sync_handler();
```

Fetches the current synchronisation handler.

The result of this call will never be `NULL`.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
