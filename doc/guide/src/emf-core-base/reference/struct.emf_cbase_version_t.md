# Struct `emf_cbase_version_t`

```c
typedef struct emf_cbase_version_t {
    int32_t major;
    int32_t minor;
    int32_t patch;
    int64_t build_number;
    int8_t release_number;
    emf_cbase_version_release_t release_type;
} emf_cbase_version_t;
```

A version.

## Invariants

If `release_type == emf_cbase_version_release_gold` then `release_number == 0`.

## Fields

- **major**: `int32_t`

    The major version number.

- **minor**: `int32_t`

    The minor version number.

- **patch**: `int32_t`

    The patch version number.

- **build_number**: `int64_t`

    The build number.

- **release_number**: `int8_t`

    The version release number.

- **release_type**: [`emf_cbase_version_release_t`](enum.emf_cbase_version_release_t.md)

    The version release type.
