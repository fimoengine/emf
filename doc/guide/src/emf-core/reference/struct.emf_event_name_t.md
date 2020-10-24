# Struct `emf_event_name_t`

```c
typedef struct emf_event_name_t {
    char data[EMF_EVENT_NAME_MAX_LENGTH];
    size_t length;
} emf_event_name_t;
```

An event name.

A `UTF-8` string describing the name of an event.
The string is not terminated with a `\0` character.

## Fields

- **data**: [`char[EMF_EVENT_NAME_MAX_LENGTH]`](./constant.EMF_EVENT_NAME_MAX_LENGTH.md)

    Name string.

- **length**: `size_t`

    Length of the string.
