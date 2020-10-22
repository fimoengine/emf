# Type definition `emf_sync_handler_try_lock_fn_t`

```c
typedef emf_bool_t(*emf_sync_handler_try_lock_fn_t)(void);
```

A function pointer to a try-lock function.

The try-lock function must have the following properties:

- The function must succeed if the interface is in an unlocked state and fail otherwise.
- On success, the `emf-core` interface must be locked exclusively and `emf_bool_true` must be returned.
- On failure,  `emf_bool_false` must be returned.
- In case of failure, the calling thread may not be stalled.
- The `emf-core` interface must be unlockable with the associated unlock function.
