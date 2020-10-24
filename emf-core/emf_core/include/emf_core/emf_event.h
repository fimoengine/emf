//! # Introduction
//! 
//! The `event` system provides an interface to the creation and management of events.
//! 
//! ## Events
//! 
//! Events come in two varieties:
//! 
//! - Public (named).
//! - Private (unnamed).
//! 
//! ## Example
//! 
//! ```c
//! const char* event_name_str = "example_event";
//! emf_event_name_t g_event_name;
//! memset(&g_event_name, 0, sizeof(emf_event_name_t));
//! 
//! // Populate the event name.
//! // Bounds checking is omitted for brevity.
//! g_event_name.length = strlen(event_name_str);
//! memcpy(&g_event_name.data, event_name_str, g_event_name.length);
//! 
//! emf_lock();
//! 
//! emf_event_handle_t g_event = emf_event_create(&g_event_name, NULL);
//! emf_event_handle_t p_event = emf_event_create_private(&foo);
//! 
//! emf_event_subscribe_handler(g_event, &foo);
//! emf_event_signal(g_event, NULL);
//! 
//! emf_unlock();
//! ```
#ifndef EMF_INTERFACE_C_EMF_EVENT_H
#define EMF_INTERFACE_C_EMF_EVENT_H

#ifdef __cplusplus
#include <cstddef>
#else
#include <stddef.h>
#endif // __cplusplus

#include <emf_core/emf_bool_t.h>
#include <emf_core/emf_error_t.h>
#include <emf_core/emf_macros.h>

/// The maximum length of an event name.
#define EMF_EVENT_NAME_MAX_LENGTH 64

#ifdef __cplusplus
namespace EMF::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

/// The input to an event.
typedef void* emf_event_data_t;

/// A handle to an existing event.
/// 
/// # Fields
/// 
/// - **id**: `int32_t`
/// 
///     The id of the event.
typedef struct emf_event_handle_t {
    /// The id of the event.
    int32_t id;
} emf_event_handle_t;

/// An event name.
/// 
/// A `UTF-8` string describing the name of an event.
/// The string is not terminated with a `\0` character.
/// 
/// # Fields
/// 
/// - **data**: [`char[EMF_EVENT_NAME_MAX_LENGTH]`](./constant.EMF_EVENT_NAME_MAX_LENGTH.md)
/// 
///     Name string.
/// 
/// - **length**: `size_t`
/// 
///     Length of the string.
EMF_FIXED_BUFFER_TYPEDEF(emf_event_name_t, char, EMF_EVENT_NAME_MAX_LENGTH)

/// A span of event names.
/// 
/// # Fields
/// 
/// - **data**: [`emf_event_name_t*`](./struct.emf_event_name_t.md)
/// 
///     The start of the span.
/// 
/// - **length**: `size_t`
/// 
///     The length of the span.
EMF_SPAN_TYPEDEF(emf_event_name_span_t, emf_event_name_t)

/// An event handler.
/// 
/// The function signature of an event handler accepts an optional 
/// [`emf_event_data_t`](./type.emf_event_data_t.md) parameter. 
/// This parameter represents a type erased pointer and is supplied when the event is dispatched.
EMF_FUNCTION_PTR_T(emf_event_handler, void, emf_event_data_t EMF_MAYBE_NULL data)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/// Creates a new public event.
/// 
/// Creates a new public event with the name `event_name`. 
/// An empty event can be created, by passing `NULL` to `event_handler`.
/// 
/// # Naming convention
/// 
/// Events follow a similar naming convention to the one found in the `C` language:
/// 
/// - Names starting with `__` are reserved for the emf-core interface.
/// - Names starting with `_Interface` (where `Interface` is `I` followed by the name, e.g. `_Iemf::core`) 
///   are reserved for the corresponding interface.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_NE(
///     event_name,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_event_name_exists(event_name),
///     emf_bool_false
/// );
/// ```
emf_event_handle_t EMF_CALL_C emf_event_create(
    const emf_event_name_t* EMF_NOT_NULL event_name, emf_event_handler_fn_t EMF_MAYBE_NULL event_handler) EMF_NOEXCEPT;

/// Creates a new private event.
/// 
/// Private events can only be accessed by the handle. 
/// An empty event can be created, by passing `NULL` to `event_handler`.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
EMF_NODISCARD emf_event_handle_t EMF_CALL_C emf_event_create_private(
    emf_event_handler_fn_t EMF_MAYBE_NULL event_handler) EMF_NOEXCEPT;

/// Destroys an event.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_EQ(
///     emf_event_name_exists(event_name),
///     emf_bool_true
/// );
/// ```
void EMF_CALL_C emf_event_destroy(emf_event_handle_t event_handle) EMF_NOEXCEPT;

/// Converts a private event into a public event.
/// 
/// The conversion is applied, by assigning a name to the private event.
/// See [`emf_event_create()`](./fn.emf_event_create.md) for more information.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_EQ(
///     emf_event_handle_exists(event_handle),
///     emf_bool_true
/// );
/// ASSERT_NE(
///     event_name,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_event_name_exists(event_name),
///     emf_bool_false
/// )
/// ```
void EMF_CALL_C emf_event_publish(emf_event_handle_t event_handle, const emf_event_name_t* EMF_NOT_NULL event_name) EMF_NOEXCEPT;

/// Returns the number of public events.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
EMF_NODISCARD size_t EMF_CALL_C emf_event_get_num_public_events() EMF_NOEXCEPT;

/// Copies all public events into a buffer.
/// 
/// The names of all public events are copied into `buffer`.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_NE(
///     buffer,
///     NULL
/// );
/// ASSERT_NE(
///     buffer->data,
///     NULL
/// );
/// ASSERT(
///     buffer->length >= emf_event_get_num_public_events()
/// );
/// ```
size_t EMF_CALL_C emf_event_get_public_events(emf_event_name_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/// Fetches the handle of a public event.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_NE(
///     event_name,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_event_name_exists(event_name),
///     emf_bool_true
/// );
/// ```
EMF_NODISCARD emf_event_handle_t EMF_CALL_C emf_event_get_event_handle(
    const emf_event_name_t* EMF_NOT_NULL event_name) EMF_NOEXCEPT;

/// Checks for the existence of a handle.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_event_handle_exists(emf_event_handle_t event_handle) EMF_NOEXCEPT;

/// Checks for the existence of a name.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_NE(
///     event_name,
///     NULL
/// );
/// ```
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_event_name_exists(const emf_event_name_t* EMF_NOT_NULL event_name) EMF_NOEXCEPT;

/******************************************************************************************************
*****************************************  Event operations  *****************************************
******************************************************************************************************/

/// Subscribes to an event.
/// 
/// The `event_handler` is added to the end of the call list.
/// 
/// # Event input
/// 
/// Not every `event_handler` is compatible with an event. 
/// The creator of an event must define how the input will be interpreted. 
/// Incorrect usage of an event may lead errors that are difficult to find.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// A event handler may not subscribe twice to the same event.  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_EQ(
///     emf_event_handle_exists(event_handle),
///     emf_bool_true
/// );
/// ASSERT_NE(
///     event_handler,
///     NULL
/// );
/// ```
void EMF_CALL_C emf_event_subscribe_handler(
    emf_event_handle_t event_handle, emf_event_handler_fn_t EMF_NOT_NULL event_handler) EMF_NOEXCEPT;

/// Unsubscribes from an event.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// The event handler must already be subscribed.  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_EQ(
///     emf_event_handle_exists(event_handle),
///     emf_bool_true
/// );
/// ASSERT_NE(
///     event_handler,
///     NULL
/// );
/// ```
void EMF_CALL_C emf_event_unsubscribe_handler(
    emf_event_handle_t event_handle, emf_event_handler_fn_t EMF_NOT_NULL event_handler) EMF_NOEXCEPT;

/// Fires an event.
/// 
/// # Event input
/// 
/// The parameter `event_data` is passed to every handler in the event. 
/// The creator of an event should define the structure, mutability and valid operations of the input.
/// 
/// See [`emf_event_subscribe_handler()`](./fn.emf_event_subscribe_handler.md) for more information.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_EQ(
///     emf_event_handle_exists(event_handle),
///     emf_bool_true
/// );
/// ```
void EMF_CALL_C emf_event_signal(emf_event_handle_t event_handle, emf_event_data_t EMF_MAYBE_NULL event_data) EMF_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_INTERFACE_C_EMF_EVENT_H
