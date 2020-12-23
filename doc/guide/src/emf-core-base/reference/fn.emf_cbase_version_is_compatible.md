# Function `emf_cbase_version_is_compatible`

```c
emf_cbase_bool_t emf_cbase_version_is_compatible(
    const emf_cbase_version_t* lhs,
    const emf_cbase_version_t* rhs
)
```

Compares weather two versions are compatible.

Compatibility of versions is not commutative.

## Return value

Returns `emf_cbase_bool_false` if `lhs` and `rhs` are incompatible.
Returns `emf_cbase_bool_true` if `lhs` is compatible with `rhs`.

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
