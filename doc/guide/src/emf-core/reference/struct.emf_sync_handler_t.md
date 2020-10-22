# Struct `emf_sync_handler_t`

```c
typedef struct emf_sync_handler_t {
    emf_sync_handler_lock_fn_t lock_fn;
    emf_sync_handler_try_lock_fn_t try_lock_fn;
    emf_sync_handler_unlock_fn_t unlock_fn;
} emf_sync_handler_t;
```

The interface of a synchronisation handler.

A synchronisation handler manages the concurrent access of the `emf-core` interface.

## Default handler

The default synchronisation handler modells a non-recursive, unique lock. Once locked, the caller has safe access to the whole interface. Locking twice will result in a deadlock whereas unlocking twice is undefined behaviour.

## Fields

- **lock_fn**: [`emf_sync_handler_lock_fn_t`](./type.emf_sync_handler_lock_fn_t.md)

    The lock function of the synchronisation handler.
    Is never `NULL`.

- **try_lock_fn**: [`emf_sync_handler_try_lock_fn_t`](./type.emf_sync_handler_try_lock_fn_t.md)

    The try-lock function of the synchronisation handler.
    Is never `NULL`.

- **unlock_fn**: [`emf_sync_handler_unlock_fn_t`](./type.emf_sync_handler_unlock_fn_t.md)

    The unlock function of the synchronisation handler.
    Is never `NULL`.
