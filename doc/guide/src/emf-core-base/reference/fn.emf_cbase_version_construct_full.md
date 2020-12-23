# Function `emf_cbase_version_construct_full`

```c
emf_cbase_version_t emf_cbase_version_construct_full(
    int32_t major, 
    int32_t minor,
    int32_t patch, 
    emf_cbase_version_release_t release_type, 
    int8_t release_number, 
    int64_t build
)
```

Constructs a new version.

Constructs a new version with `major`, `minor`, `patch`, `release_type`, `release_number` and `build`.
