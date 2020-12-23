# Type definition `emf_cbase_sync_handler_unlock_fn_t`

```c
typedef void(*emf_cbase_sync_handler_unlock_fn_t)(
    emf_cbase_sync_handler_t* sync_handler
);
```

A function pointer to an `unlock` function.

The unlock function must have the following properties:

- The `emf-core-base` interface must be unlocked if, at the time of calling, it is an a locked state.
