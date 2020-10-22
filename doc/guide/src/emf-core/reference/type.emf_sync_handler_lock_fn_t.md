# Type definition `emf_sync_handler_lock_fn_t`

```c
typedef void(*emf_sync_handler_lock_fn_t)(void);
```

A function pointer to a lock function.

The lock function must have the following properties:

- The `emf-core` interface must be locked exclusively.
- In case the interface is already locked, the thread must be stalled until a lock can occur.
- The `emf-core` interface must be unlockable with the associated unlock function.
