# Type definition `emf_file_handler_interface_get_entries_fn_t`

```c
typedef size_t(*emf_file_handler_interface_get_entries_fn_t)(
    emf_file_handler_mount_id_t mount_id,
    const emf_path_t* path,
    emf_bool_t recursive,
    emf_path_span_t* buffer
);
```

Fetches the paths of all entries contained inside and including `path`.

Returns the number of entries it fetched and copies their paths inside `buffer`.
It is undefined bahaviour to supply a path that does not exist.
The `File handler` can assume, that `buffer` is valid and big enough.

> Note: The `path` and the path of the entries are relative to the mounted path.
