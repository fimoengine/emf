# Function `emf_cbase_library_type_exists`

```c
emf_cbase_bool_t emf_cbase_library_type_exists(
    const emf_cbase_library_type_t* library_type
)
```

Checks if a library type exists.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   library_type,
   NULL
);
```
