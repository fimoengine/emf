# Function `emf_cbase_version_get_short_representation_length`

```c
size_t emf_cbase_version_get_short_representation_length(
    const emf_cbase_version_t* version
)
```

Computes the length of the version string.

Computes the minimum length a string of the form "Major.Minor.Patch" needs.

## Undefined Behaviour

The caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   version,
   NULL
);
```
