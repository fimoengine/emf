#ifndef EMF_C_EMF_EVENT_HPP
#define EMF_C_EMF_EVENT_HPP

#ifdef __cplusplus

#include <emf_core/emf_event.h>

#include <functional>
#include <span>
#include <variant>

namespace EMF::Event {

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/**
 * See emf_event_create()
 */
inline C::emf_event_handle_t create(
    const C::emf_event_name_t& event_name, C::emf_event_handler_fn_t EMF_MAYBE_NULL event_handler) noexcept
{
    return C::emf_event_create(&event_name, event_handler);
}

/**
 * See emf_event_create_private()
 */
EMF_NODISCARD inline C::emf_event_handle_t create(C::emf_event_handler_fn_t EMF_MAYBE_NULL event_handler) noexcept
{
    return C::emf_event_create_private(event_handler);
}

/**
 * See emf_event_destroy()
 */
inline void destroy(C::emf_event_handle_t event_handle) noexcept { C::emf_event_destroy(event_handle); }

/**
 * See emf_event_publish()
 */
inline void publish(C::emf_event_handle_t event_handle, const C::emf_event_name_t& event_name) noexcept
{
    C::emf_event_publish(event_handle, &event_name);
}

/**
 * See emf_event_get_num_public_events()
 */
EMF_NODISCARD inline std::size_t get_num_public_events() noexcept { return C::emf_event_get_num_public_events(); }

/**
 * See emf_event_get_public_events()
 */
inline std::size_t get_public_events(std::span<C::emf_event_name_t> buffer) noexcept
{
    C::emf_event_name_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_event_get_public_events(&c_buffer);
}

/**
 * See emf_event_get_event_handle()
 */
EMF_NODISCARD inline C::emf_event_handle_t get_handle(const C::emf_event_name_t& event_name) noexcept
{
    return C::emf_event_get_event_handle(&event_name);
}

/**
 * See emf_event_handle_exists()
 */
EMF_NODISCARD inline bool handle_exists(C::emf_event_handle_t event_handle) noexcept
{
    return static_cast<bool>(C::emf_event_handle_exists(event_handle));
}

/**
 * See emf_event_name_exists()
 */
EMF_NODISCARD inline bool name_exists(const C::emf_event_name_t& event_name) noexcept
{
    return static_cast<bool>(C::emf_event_name_exists(&event_name));
}

/**
 * See emf_event_subscribe_handler()
 */
inline void subscribe(C::emf_event_handle_t event_handle, C::emf_event_handler_fn_t EMF_NOT_NULL event_handler) noexcept
{
    C::emf_event_subscribe_handler(event_handle, event_handler);
}

/**
 * See emf_event_unsubscribe_handler()
 */
inline void unsubscribe(C::emf_event_handle_t event_handle, C::emf_event_handler_fn_t EMF_NOT_NULL event_handler) noexcept
{
    C::emf_event_unsubscribe_handler(event_handle, event_handler);
}

/**
 * See emf_event_signal()
 */
inline void signal(C::emf_event_handle_t event_handle, C::emf_event_data_t EMF_MAYBE_NULL event_data) noexcept
{
    C::emf_event_signal(event_handle, event_data);
}

}

#endif // __cplusplus

#endif // !EMF_C_EMF_EVENT_HPP
