# Enum `emf_fs_predefined_handles_t`

```c
typedef enum emf_fs_predefined_handles_t : int32_t {
    emf_fs_predefined_handles_default = 0
} emf_fs_predefined_handles_t;
```

Predefined `File handler` handles.

> Note: The handles `0`-`99` are reserved.
> The handles `100`-`199` are implementation-defined.

## Variants

| Name                                  | Value | Description                         |
| ------------------------------------- | ----- | ----------------------------------- |
| **emf_fs_predefined_handles_default** | `0`   | Handle to the default file handler. |
