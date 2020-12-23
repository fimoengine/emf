# Function `emf_cbase_library_register_loader`

```c
emf_cbase_library_loader_handle_result_t emf_cbase_library_register_loader(
    const emf_cbase_library_loader_interface_t* loader_interface,
    const emf_cbase_library_type_t* library_type
)
```

Registers a new loader.

The loader can load libraries of the type `library_type`.

## Failure

The function fails if the library type already exists.

## Undefined Behaviour

The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
Furthermore, the caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   loader_interface,
   NULL
);
ASSERT_NE(
   library_type,
   NULL
);
```
