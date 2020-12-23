# Function `emf_cbase_version_compare_strong`

```c
int32_t emf_cbase_version_compare_strong(
    const emf_cbase_version_t* lhs,
    const emf_cbase_version_t* rhs
)
```

Compares two versions.

Compares two versions using their major-,minor- and patch version, release type, release number and build number.

## Return value

Returns `-1` if `lhs > rhs`.
Returns `0` if `lhs == rhs`.
Returns `1` if `lhs < rhs`.

## Undefined Behaviour

The caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   lhs,
   NULL
);
ASSERT_NE(
   rhs,
   NULL
);
```
