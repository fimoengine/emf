# Function `emf_set_sync_handler`

```c
void emf_set_sync_handler(const emf_sync_handler_t* sync_handler);
```

Sets a new synchronisation handler.

The default synchronisation handler is used, if `sync_handler` is `NULL`.

## Uses

This function can be used by modules, that want to provide a more complex synchronisation mechanism than the one presented by the default handler.

## Swapping

The swapping occurs in three steps:

1. The new synchronisation handler is locked.
2. The new synchronisation handler is set as the main synchronisation handler.
3. The old synchronisation handler is unlocked.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).

## Warning

Changing the synchronisation handler may break some modules, if they depend on a specific synchronisation handler.
