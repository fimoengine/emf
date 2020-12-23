# Type definition `emf_cbase_sync_handler_lock_fn_t`

```c
typedef void(*emf_cbase_sync_handler_lock_fn_t)(
    emf_cbase_sync_handler_t* sync_handler
);
```

A function pointer to a `lock` function.

The lock function must have the following properties:

- The `emf-core-base` interface must be locked exclusively.
- In case the interface is already locked, the thread must be stalled until a lock can occur.
- The `emf-core-base` interface must be unlockable with the associated unlock function.
