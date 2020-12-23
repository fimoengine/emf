# Function `emf_cbase_version_representation_is_valid`

```c
emf_cbase_bool_t emf_cbase_version_representation_is_valid(
    const emf_cbase_version_const_string_buffer_t* version_string
)
```

Checks weather the version string is valid.

The string is valid if it has the form "Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?\+Build".

## Undefined Behaviour

The caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   version_string,
   NULL
);
ASSERT_NE(
   version_string->data,
   NULL
);
```
