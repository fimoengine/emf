# Enum `emf_fs_entry_type_t`

```c
typedef enum emf_fs_entry_type_t : int32_t {
    emf_fs_entry_type_file = 0,
    emf_fs_entry_type_link = 1,
    emf_fs_entry_type_directory = 2,
    emf_fs_entry_type_mount_point = 3
} emf_fs_entry_type_t;
```

The possible types of a fs entry node.

## Variants

| Name                              | Value | Description         |
| --------------------------------- | ----- | ------------------- |
| **emf_fs_entry_type_file**        | `0`   | A file node.        |
| **emf_fs_entry_type_link**        | `1`   | A link node.        |
| **emf_fs_entry_type_directory**   | `2`   | A directory node.   |
| **emf_fs_entry_type_mount_point** | `3`   | A mount point node. |
