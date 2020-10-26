# Enum `emf_file_open_mode_t`

```c
typedef enum emf_file_open_mode_t : int32_t {
    emf_file_open_mode_begin = 0,
    emf_file_open_mode_end = 1
} emf_file_open_mode_t;
```

Modes in which a file can be opened.

## Variants

| Name                         | Value | Description            |
| ---------------------------- | ----- | ---------------------- |
| **emf_file_open_mode_begin** | `0`   | Open at the beginning. |
| **emf_file_open_mode_end**   | `1`   | Open at the end.       |
