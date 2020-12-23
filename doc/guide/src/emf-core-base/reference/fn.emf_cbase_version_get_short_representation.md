# Function `emf_cbase_version_get_short_representation`

```c
emf_cbase_version_size_result_t emf_cbase_version_get_short_representation(
    const emf_cbase_version_t* version,
    emf_cbase_version_string_buffer_t* buffer
)
```

Represents the version as a string.

The string has the form "Major.Minor.Patch".

## Failure

The function can fail if `buffer` is too small.

## Undefined Behaviour

The caller must ensure that the following preconditions hold:

```c
ASSERT_NE(
   version,
   NULL
);
ASSERT_NE(
   buffer,
   NULL
);
ASSERT_NE(
   buffer->data,
   NULL
);
```
