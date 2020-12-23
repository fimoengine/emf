# Enum `emf_cbase_library_error_t`

```c
typedef enum emf_cbase_library_error_t : int32_t {
    emf_cbase_library_error_library_path_not_found = 0,
    emf_cbase_library_error_library_handle_invalid = 1,
    emf_cbase_library_error_loader_handle_invalid = 2,
    emf_cbase_library_error_loader_library_handle_invalid = 3,
    emf_cbase_library_error_library_type_invalid = 4,
    emf_cbase_library_error_library_type_not_found = 5,
    emf_cbase_library_error_duplicate_library_type = 6,
    emf_cbase_library_error_symbol_not_found = 7,
    emf_cbase_library_error_buffer_overflow = 8,
} emf_cbase_library_error_t;
```

An enum describing all defined error values.

The values `0-99` are reserved for future use.

## Variants

| Name                                                      | Value | Description                             |
| --------------------------------------------------------- | ----- | --------------------------------------- |
| **emf_cbase_library_error_library_path_not_found**        | `0`   | A path could not be found.              |
| **emf_cbase_library_error_library_handle_invalid**        | `1`   | The library handle is invalid.          |
| **emf_cbase_library_error_loader_handle_invalid**         | `2`   | The loader handle is invalid.           |
| **emf_cbase_library_error_loader_library_handle_invalid** | `3`   | The internal library handle is invalid. |
| **emf_cbase_library_error_library_type_invalid**          | `4`   | The library type is invalid.            |
| **emf_cbase_library_error_library_type_not_found**        | `5`   | The library type could not be found.    |
| **emf_cbase_library_error_duplicate_library_type**        | `6`   | The library type already exists.        |
| **emf_cbase_library_error_symbol_not_found**              | `7`   | A symbol could not be found.            |
| **emf_cbase_library_error_buffer_overflow**               | `8`   | The buffer is too small.                |
