# Enum `emf_fs_link_t`

```c
typedef enum emf_fs_link_t : int32_t {
    emf_fs_link_symlink = 0,
    emf_fs_link_hardlink = 1
} emf_fs_link_t;
```

The types of possible links.

## Variants

| Name                     | Value | Description               |
| ------------------------ | ----- | ------------------------- |
| **emf_fs_link_symlink**  | `0`   | A weak link.              |
| **emf_fs_link_hardlink** | `1`   | A reference counted link. |
