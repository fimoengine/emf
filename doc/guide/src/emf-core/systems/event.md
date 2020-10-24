# Event system

## Introduction

The `event` system provides an interface to the creation and management of events.

### Events

Events come in two varieties:

- Public (named).
- Private (unnamed).

### Example

```c
const char* event_name_str = "example_event";
emf_event_name_t g_event_name;
memset(&g_event_name, 0, sizeof(emf_event_name_t));

// Populate the event name.
// Bounds checking is omitted for brevity.
g_event_name.length = strlen(event_name_str);
memcpy(&g_event_name.data, event_name_str, g_event_name.length);

emf_lock();

emf_event_handle_t g_event = emf_event_create(&g_event_name, NULL);
emf_event_handle_t p_event = emf_event_create_private(&foo);

emf_event_subscribe_handler(g_event, &foo);
emf_event_signal(g_event, NULL);

emf_unlock();
```

## Constants

- [EMF_EVENT_NAME_MAX_LENGTH](../reference/constant.EMF_EVENT_NAME_MAX_LENGTH.md)
 
## Structs

- [emf_event_handle_t](../reference/struct.emf_event_handle_t.md)
- [emf_event_name_span_t](../reference/struct.emf_event_name_span_t.md)
- [emf_event_name_t](../reference/struct.emf_event_name_t.md)

## Type definitions

- [emf_event_data_t](../reference/type.emf_event_data_t.md)
- [emf_event_handler_fn_t](../reference/type.emf_event_handler_fn_t.md)

## Functions

- [emf_event_create](../reference/fn.emf_event_create.md)
- [emf_event_create_private](../reference/fn.emf_event_create_private.md)
- [emf_event_destroy](../reference/fn.emf_event_destroy.md)
- [emf_event_get_event_handle](../reference/fn.emf_event_get_event_handle.md)
- [emf_event_get_num_public_events](../reference/fn.emf_event_get_num_public_events.md)
- [emf_event_get_public_events](../reference/fn.emf_event_get_public_events.md)
- [emf_event_handle_exists](../reference/fn.emf_event_handle_exists.md)
- [emf_event_name_exists](../reference/fn.emf_event_name_exists.md)
- [emf_event_publish](../reference/fn.emf_event_publish.md)
- [emf_event_signal](../reference/fn.emf_event_signal.md)
- [emf_event_subscribe_handler](../reference/fn.emf_event_subscribe_handler.md)
- [emf_event_unsubscribe_handler](../reference/fn.emf_event_unsubscribe_handler.md)