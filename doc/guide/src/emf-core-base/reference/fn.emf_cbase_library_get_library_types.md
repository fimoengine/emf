# Function `emf_cbase_library_get_library_types`

```c
emf_cbase_library_size_result_t emf_cbase_library_get_library_types(
    emf_cbase_library_type_span_t* buffer
)
```

Copies the strings of the registered library types into a buffer.

Returns the number of copied elements.

## Failure

The function fails if `buffer` is smaller than `emf_cbase_library_get_num_loaders()`.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   buffer,
   NULL
);
ASSERT_NE(
   buffer->data,
   NULL
);
```
