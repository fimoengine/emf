# Enum `emf_fs_direction_t`

```c
typedef enum emf_fs_direction_t : int32_t {
    emf_fs_direction_begin = 0,
    emf_fs_direction_current = 1,
    emf_fs_direction_end = 2
} emf_fs_direction_t;
```

The starting position from which a stream can be seeked.

## Variants

| Name                         | Value | Description                                   |
| ---------------------------- | ----- | --------------------------------------------- |
| **emf_fs_direction_begin**   | `0`   | Seek starting at the beginning of the stream. |
| **emf_fs_direction_current** | `1`   | Seek starting at the current position.        |
| **emf_fs_direction_end**     | `2`   | Seek starting at the end of the stream.       |
