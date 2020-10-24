# Struct `emf_event_name_span_t`

```c
typedef struct emf_event_name_span_t {
    emf_event_name_t* data;
    size_t length;
} emf_event_name_span_t;
```

A span of event names.

## Fields

- **data**: [`emf_event_name_t*`](./struct.emf_event_name_t.md)

    The start of the span.

- **length**: `size_t`

    The length of the span.
