# Type definition `emf_sync_handler_unlock_fn_t`

```c
typedef void(*emf_sync_handler_unlock_fn_t)(void);
```

A function pointer to an unlock function.

The unlock function must have the following properties:

- The `emf-core` interface must be unlocked if, at the time of calling, it is an a locked state.
