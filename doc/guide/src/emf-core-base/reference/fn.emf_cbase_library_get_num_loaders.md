# Function `emf_cbase_library_get_num_loaders`

```c
size_t emf_cbase_library_get_num_loaders()
```

Fetches the number of registered loaders.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
