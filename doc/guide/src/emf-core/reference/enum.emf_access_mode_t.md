# Enum `emf_access_mode_t`

```c
typedef enum emf_access_mode_t : int32_t {
    emf_file_access_mode_read = 0,
    emf_file_access_mode_write = 1
} emf_access_mode_t;
```

Access permissions of a node.

## Variants

| Name                           | Value | Description   |
| ------------------------------ | ----- | ------------- |
| **emf_file_access_mode_read**  | `0`   | Read access.  |
| **emf_file_access_mode_write** | `1`   | Write access. |
