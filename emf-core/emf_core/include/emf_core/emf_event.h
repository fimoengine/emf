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

#define EMF_EVENT_NAME_MAX_LENGTH 64 /// Max length of an event name.

#ifdef __cplusplus
namespace EMF::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

/**
 * Event input.
 */
typedef void* emf_event_data_t;

/**
 * A handle to an event.
 */
typedef struct emf_event_handle_t {
    /// Handle id.
    int32_t id;
} emf_event_handle_t;

/**
 * Name of an event.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_event_name_t, char, EMF_EVENT_NAME_MAX_LENGTH)

/**
 * A span of event names.
 */
EMF_SPAN_TYPEDEF(emf_event_name_span_t, emf_event_name_t)

/**
 * A callback.
 */
EMF_FUNCTION_PTR_T(emf_event_handler, void, emf_event_data_t EMF_MAYBE_NULL data)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/**
 * @brief Creates a new public event.
 *
 * Creates a new event with the given name and handler.\n
 *
 * @note Requires synchronisation.
 * @note If <code>event_handler == NULL</code>, then an empty event will be created.
 * @note All names starting with "__" are reserved for the implementors of the "emf::core" module.
 * @note All names starting with "_Interface" are reserved for the implementors of the "Interface" interface.
 *
 * @pre <code>event_name</code> may not be <code>NULL</code>.
 * @pre <code>emf_event_name_exists(event_name) == emf_bool_false</code>.
 *
 * @post A new named event is created.
 *
 * @param event_name Name of the event.
 * @param event_handler Event handler.
 *
 * @return Event handle.
 */
emf_event_handle_t EMF_CALL_C emf_event_create(
    const emf_event_name_t* EMF_NOT_NULL event_name, emf_event_handler_fn_t EMF_MAYBE_NULL event_handler) EMF_NOEXCEPT;

/**
 * @brief Creates a new private event
 *
 * Creates a new private event with the given handler.
 *
 * @note Requires synchronisation.
 * @note If <code>event_handler == NULL</code>, then an empty event will be created.
 *
 * @post A new unnamed event is created.
 *
 * @param event_handler Event handler.
 */
EMF_NODISCARD emf_event_handle_t EMF_CALL_C emf_event_create_private(
    emf_event_handler_fn_t EMF_MAYBE_NULL event_handler) EMF_NOEXCEPT;

/**
 * @brief Destroys an event.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>emf_event_handle_exists(event_handle) == emf_bool_true</code>.
 *
 * @post The event is destroyed.
 * @post <code>event_handle</code> is invalidated.
 *
 * @param event_handle Event handle.
 */
void EMF_CALL_C emf_event_destroy(emf_event_handle_t event_handle) EMF_NOEXCEPT;

/**
 * @brief Makes an event public.
 *
 * Makes a private event visible with a certain name.
 *
 * @note Requires synchronisation.
 * @note A event handle may only have one name.
 * @note All names starting with "__" are reserved for the implementors of the "emf::core" module.
 * @note All names starting with "_Interface" are reserved for the implementors of the "Interface" interface.
 *
 * @pre <code>event_handle</code> has been acquired through emf_event_create_private().
 * @pre <code>event_name</code> may not be <code>NULL</code>.
 * @pre <code>emf_event_name_exists(event_name) == emf_bool_false</code>.
 *
 * @post The event is assigned a name.
 *
 * @param event_handle Handle.
 * @param event_name New name.
 */
void EMF_CALL_C emf_event_publish(emf_event_handle_t event_handle, const emf_event_name_t* EMF_NOT_NULL event_name) EMF_NOEXCEPT;

/**
 * @brief Get the number of public events.
 *
 * @note Requires synchronisation.
 *
 * @return Number of public events.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_event_get_num_public_events() EMF_NOEXCEPT;

/**
 * @brief Copies all public events into a buffer.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.length >= emf_event_get_num_public_events()</code>.
 * @pre <code>buffer.data != NULL</code>.
 *
 * @post <code>buffer</code> contains the event names.
 *
 * @param buffer Destination.
 *
 * @return Number of public events.
 */
size_t EMF_CALL_C emf_event_get_public_events(emf_event_name_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Get the event associated with a specific name.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>event_name</code> may not be <code>NULL</code>.
 * @pre <code>emf_event_name_exists(event_name) == emf_bool_true</code>.
 *
 * @param event_name Name.
 *
 * @return Event handle
 */
EMF_NODISCARD emf_event_handle_t EMF_CALL_C emf_event_get_event_handle(
    const emf_event_name_t* EMF_NOT_NULL event_name) EMF_NOEXCEPT;

/**
 * @brief Check if a handle exists.
 *
 * @note Requires synchronisation.
 *
 * @param event_handle Handle.
 *
 * @return <code>emf_bool_true</code> if the handle exists.
 * @return <code>emf_bool_false</code> if the handle does not exist.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_event_handle_exists(emf_event_handle_t event_handle) EMF_NOEXCEPT;

/**
 * @brief Check if the named event exists.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>event_name</code> may not be <code>NULL</code>
 *
 * @param event_name Name.
 *
 * @return <code>emf_bool_true</code> if the name exists.
 * @return <code>emf_bool_false</code> if the name does not exist or <code>event_name == NULL</code>.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_event_name_exists(const emf_event_name_t* EMF_NOT_NULL event_name) EMF_NOEXCEPT;

/******************************************************************************************************
*****************************************  Event operations  *****************************************
******************************************************************************************************/

/**
 * @brief Subscribe to an event.
 *
 * @note Requires synchronisation.
 * @note Appends the event_handler at the end of the call list.
 *
 * @pre <code>emf_event_handle_exists(event_handle) == emf_bool_true</code>.
 * @pre <code>event_handler</code> may not be <code>NULL</code>
 * @pre <code>event_handler</code> may not be already subscribed.
 *
 * @param event_handle Event handle.
 * @param event_handler Handler.
 */
void EMF_CALL_C emf_event_subscribe_handler(
    emf_event_handle_t event_handle, emf_event_handler_fn_t EMF_NOT_NULL event_handler) EMF_NOEXCEPT;

/**
 * @brief Unsubscribe from an event.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>emf_event_handle_exists(event_handle) == emf_bool_true</code>.
 * @pre <code>event_handler</code> may not be <code>NULL</code>
 * @pre <code>event_handler</code> must be subscribed.
 *
 * @param event_handle Event handle.
 * @param event_handler Handler.
 */
void EMF_CALL_C emf_event_unsubscribe_handler(
    emf_event_handle_t event_handle, emf_event_handler_fn_t EMF_NOT_NULL event_handler) EMF_NOEXCEPT;

/**
 * @brief Fire an event
 *
 * @note Requires synchronisation.
 *
 * @pre <code>emf_event_handle_exists(event_handle) == emf_bool_true</code>.
 *
 * @param event_handle Event handle.
 * @param event_data Data.
 */
void EMF_CALL_C emf_event_signal(emf_event_handle_t event_handle, emf_event_data_t EMF_MAYBE_NULL event_data) EMF_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_INTERFACE_C_EMF_EVENT_H
