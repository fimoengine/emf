# Function `emf_cbase_version_construct_from_string`

```c
emf_cbase_version_result_t emf_cbase_version_construct_from_string(
    const emf_cbase_version_const_string_buffer_t* version_string
)
```

Constructs a version from a string.

## Failure

The function fails if `version_string` is not of the form "Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?\+Build".

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
