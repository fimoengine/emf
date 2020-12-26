# Version API

## Introduction

The `version` api implements the versioning scheme as specified in the [conventions](../../conventions.md#versions).

## Example

```c
emf_cbase_version_t v1 = emf_cbase_version_construct_short(1, 2, 3);

const char* v2_string = "1.2.3-rc.5+54845652";
emf_cbase_version_const_string_buffer_t v2_string_buff = {
    .data = v2_string, 
    .length = strlen(v2_string)
};
emf_cbase_version_result_t v2_res = emf_cbase_version_construct_from_string(
    &v2_string_buff
);
if (v2_res.has_error) {
    emf_cbase_sys_lock();
    emf_cbase_sys_panic("Could not construct version from string.");
    emf_cbase_sys_unlock()
}
emf_cbase_version_t v2 = v2_res.result;

if (emf_cbase_version_compare_weak(&v1, &v2) != 0) {
    emf_cbase_sys_lock();
    emf_cbase_sys_panic("Should not happen.");
    emf_cbase_sys_unlock();
}
```

## Enums

- [`emf_cbase_version_error_t`](../reference/enum.emf_cbase_version_error_t.md)
- [`emf_cbase_version_release_t`](../reference/enum.emf_cbase_version_release_t.md)

## Structs

- [`emf_cbase_version_const_string_buffer_t`](../reference/struct.emf_cbase_version_const_string_buffer_t.md)
- [`emf_cbase_version_result_t`](../reference/struct.emf_cbase_version_result_t.md)
- [`emf_cbase_version_size_result_t`](../reference/struct.emf_cbase_version_size_result_t.md)
- [`emf_cbase_version_string_buffer_t`](../reference/struct.emf_cbase_version_string_buffer_t.md)
- [`emf_cbase_version_t`](../reference/struct.emf_cbase_version_t.md)

## Functions

- [`emf_cbase_version_compare_strong`](../reference/fn.emf_cbase_version_compare_strong.md)
- [`emf_cbase_version_compare_weak`](../reference/fn.emf_cbase_version_compare_weak.md)
- [`emf_cbase_version_compare`](../reference/fn.emf_cbase_version_compare.md)
- [`emf_cbase_version_construct_from_string`](../reference/fn.emf_cbase_version_construct_from_string.md)
- [`emf_cbase_version_construct_full`](../reference/fn.emf_cbase_version_construct_full.md)
- [`emf_cbase_version_construct_long`](../reference/fn.emf_cbase_version_construct_long.md)
- [`emf_cbase_version_construct_short`](../reference/fn.emf_cbase_version_construct_short.md)
- [`emf_cbase_version_get_full_representation_length`](../reference/fn.emf_cbase_version_get_full_representation_length.md)
- [`emf_cbase_version_get_full_representation`](../reference/fn.emf_cbase_version_get_full_representation.md)
- [`emf_cbase_version_get_long_representation_length`](../reference/fn.emf_cbase_version_get_long_representation_length.md)
- [`emf_cbase_version_get_long_representation`](../reference/fn.emf_cbase_version_get_long_representation.md)
- [`emf_cbase_version_get_short_representation_length`](../reference/fn.emf_cbase_version_get_short_representation_length.md)
- [`emf_cbase_version_get_short_representation`](../reference/fn.emf_cbase_version_get_short_representation.md)
- [`emf_cbase_version_is_compatible`](../reference/fn.emf_cbase_version_is_compatible.md)
- [`emf_cbase_version_representation_is_valid`](../reference/fn.emf_cbase_version_representation_is_valid.md)
