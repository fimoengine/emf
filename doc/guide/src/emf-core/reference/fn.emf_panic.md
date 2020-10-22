# Function `emf_panic`

```c
_Noreturn void emf_panic(const char* error);
```

Panics.

Execution of the program is stopped abruptly after the error is logged.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
