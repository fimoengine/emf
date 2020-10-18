# Struct `emf_config_property_info_span_t`

```c
typedef struct emf_config_property_info_span_t {
    emf_config_property_info_t* data;
    size_t length;
} emf_config_property_info_span_t;
```

A span of property infos.

## Fields

- **data**: [`emf_config_property_info_t`](./struct.emf_config_property_info_t.md)
    
    The start of the span.

- **length**: `size_t`

    The length of the span.