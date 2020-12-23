# Function `emf_cbase_version_construct_long`

```c
emf_cbase_version_t emf_cbase_version_construct_long(
    int32_t major, 
    int32_t minor,
    int32_t patch, 
    emf_cbase_version_release_t release_type, 
    int8_t release_number
)
```

Constructs a new version.

Constructs a new version with `major`, `minor`, `patch`, `release_type` and `release_number` and sets the rest to `0`.
