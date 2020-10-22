# Function `emf_lock`

```c
void emf_lock();
```

Locks the interface.

The calling thread is stalled until the lock can be acquired. Only one thread can hold the lock at a time.

## Deadlock

Calling this function while the calling thread holds a lock may result in a deadlock.
