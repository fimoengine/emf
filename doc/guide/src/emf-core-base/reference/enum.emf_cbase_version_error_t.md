# Enum `emf_cbase_version_error_t`

```c
typedef enum emf_cbase_version_error_t : int32_t {
    emf_cbase_version_error_invalid_string = 0,
    emf_cbase_version_error_buffer_overflow = 1,
} emf_cbase_version_error_t;
```

An enum describing the possible error values of the `version` api.

The values `0-99` are reserved for future use.

## Variants

| Name                                        | Value | Description              |
| ------------------------------------------- | ----- | ------------------------ |
| **emf_cbase_version_error_invalid_string**  | `0`   | The string is invalid.   |
| **emf_cbase_version_error_buffer_overflow** | `1`   | The buffer is too small. |
