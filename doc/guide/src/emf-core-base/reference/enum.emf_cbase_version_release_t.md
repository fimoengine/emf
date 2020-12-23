# Enum `emf_cbase_version_release_t`

```c
typedef enum emf_cbase_version_release_t : int8_t {
    emf_cbase_version_release_gold = 0,
    emf_cbase_version_release_pre_alpha = 1,
    emf_cbase_version_release_alpha = 2,
    emf_cbase_version_release_beta = 3,
    emf_cbase_version_release_rc = 4,
} emf_cbase_version_release_t;
```

An enum describing the release type of a version.

## Variants

| Name                                    | Value | Description          |
| --------------------------------------- | ----- | -------------------- |
| **emf_cbase_version_release_gold**      | `0`   | A gold release.      |
| **emf_cbase_version_release_pre_alpha** | `1`   | A pre-alpha release. |
| **emf_cbase_version_release_alpha**     | `2`   | An alpha release.    |
| **emf_cbase_version_release_beta**      | `3`   | A beta release.      |
| **emf_cbase_version_release_rc**        | `4`   | A release candidate. |
