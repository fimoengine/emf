#include <emf_core/emf_event.h>
#include <emf_core_bindings/emf_core_bindings.h>

using namespace EMF::Core::C;

namespace EMF::Core::Bindings::C {

extern "C" {

emf_event_handle_t EMF_CALL_C emf_event_create(
    const emf_event_name_t* EMF_NOT_NULL event_name, emf_event_handler_fn_t EMF_MAYBE_NULL event_handler) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(event_name != nullptr, "emf_event_create()")
    EMF_ASSERT_ERROR(emf_event_name_exists(event_name) == emf_bool_false, "emf_event_create()")
    return emf_binding_interface->event_create_fn(event_name, event_handler);
}

EMF_NODISCARD emf_event_handle_t EMF_CALL_C emf_event_create_private(
    emf_event_handler_fn_t EMF_MAYBE_NULL event_handler) EMF_NOEXCEPT
{
    return emf_binding_interface->event_create_private_fn(event_handler);
}

void EMF_CALL_C emf_event_destroy(emf_event_handle_t event_handle) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(emf_event_handle_exists(event_handle) == emf_bool_true, "emf_event_destroy()")
    emf_binding_interface->event_destroy_fn(event_handle);
}

void EMF_CALL_C emf_event_publish(emf_event_handle_t event_handle, const emf_event_name_t* EMF_NOT_NULL event_name) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(event_name != nullptr, "emf_event_publish()")
    EMF_ASSERT_ERROR(emf_event_name_exists(event_name) == emf_bool_false, "emf_event_publish()")
    emf_binding_interface->event_publish_fn(event_handle, event_name);
}

EMF_NODISCARD size_t EMF_CALL_C emf_event_get_num_public_events() EMF_NOEXCEPT
{
    return emf_binding_interface->event_get_num_public_events_fn();
}

size_t EMF_CALL_C emf_event_get_public_events(emf_event_name_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_event_get_public_events()")
    EMF_ASSERT_ERROR(buffer->length >= emf_event_get_num_public_events(), "emf_event_get_public_events()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_event_get_public_events()")
    return emf_binding_interface->event_get_public_events_fn(buffer);
}

EMF_NODISCARD emf_event_handle_t EMF_CALL_C emf_event_get_event_handle(
    const emf_event_name_t* EMF_NOT_NULL event_name) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(event_name != nullptr, "emf_event_get_event_handle()")
    EMF_ASSERT_ERROR(emf_event_name_exists(event_name) == emf_bool_true, "emf_event_get_event_handle()")
    return emf_binding_interface->event_get_event_handle_fn(event_name);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_event_handle_exists(emf_event_handle_t event_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->event_handle_exists_fn(event_handle);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_event_name_exists(const emf_event_name_t* EMF_NOT_NULL event_name) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(event_name != nullptr, "emf_event_name_exists()")
    return emf_binding_interface->event_name_exists_fn(event_name);
}

void EMF_CALL_C emf_event_subscribe_handler(
    emf_event_handle_t event_handle, emf_event_handler_fn_t EMF_NOT_NULL event_handler) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(emf_event_handle_exists(event_handle) == emf_bool_true, "emf_event_subscribe_handler()")
    EMF_ASSERT_ERROR(event_handler != nullptr, "emf_event_subscribe_handler()")
    emf_binding_interface->event_subscribe_handler_fn(event_handle, event_handler);
}

void EMF_CALL_C emf_event_unsubscribe_handler(
    emf_event_handle_t event_handle, emf_event_handler_fn_t EMF_NOT_NULL event_handler) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(emf_event_handle_exists(event_handle) == emf_bool_true, "emf_event_unsubscribe_handler()")
    EMF_ASSERT_ERROR(event_handler != nullptr, "emf_event_unsubscribe_handler()")
    emf_binding_interface->event_unsubscribe_handler_fn(event_handle, event_handler);
}

void EMF_CALL_C emf_event_signal(emf_event_handle_t event_handle, emf_event_data_t EMF_MAYBE_NULL event_data) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(emf_event_handle_exists(event_handle) == emf_bool_true, "emf_event_signal()")
    emf_binding_interface->event_signal_fn(event_handle, event_data);
}
}

}
