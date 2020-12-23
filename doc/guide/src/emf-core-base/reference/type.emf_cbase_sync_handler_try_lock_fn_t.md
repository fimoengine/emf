# Type definition `emf_cbase_sync_handler_try_lock_fn_t`

```c
typedef emf_cbase_bool_t(*emf_cbase_sync_handler_try_lock_fn_t)(
    emf_cbase_sync_handler_t* sync_handler
);
```

A function pointer to a `try-lock` function.

The try-lock function must have the following properties:

- The function must succeed if the interface is in an unlocked state and fail otherwise.
- On success, the `emf-core-base` interface must be locked exclusively and `emf_cbase_bool_true` must be returned.
- On failure, `emf_cbase_bool_false` must be returned.
- In case of failure, the calling thread may not be stalled.
- The `emf-core-base` interface must be unlockable with the associated unlock function.
