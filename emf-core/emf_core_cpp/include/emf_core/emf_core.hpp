#ifndef EMF_C_EMF_CORE_HPP
#define EMF_C_EMF_CORE_HPP

#ifdef __cplusplus

#include <emf_core/emf_core.h>

#include <functional>
#include <optional>
#include <string_view>

namespace EMF::Core {

/**
 * See emf_lock()
 */
inline void lock() noexcept { C::emf_lock(); }

/**
 * See emf_try_lock()
 */
inline bool try_lock() noexcept { return static_cast<bool>(C::emf_try_lock()); }

/**
 * See emf_unlock()
 */
inline void unlock() noexcept { C::emf_unlock(); }

/**
 * See emf_shutdown()
 */
inline void shutdown() noexcept { C::emf_shutdown(); }

/**
 * See emf_panic()
 */
EMF_NORETURN inline void panic(std::string_view error) noexcept { C::emf_panic(error.data()); }

/**
 * See emf_has_function()
 */
EMF_NODISCARD inline bool has_function(C::emf_fn_ptr_id_t fn_id) noexcept
{
    return static_cast<bool>(C::emf_has_function(fn_id));
}

/**
 * See emf_get_function()
 */
EMF_NODISCARD inline C::emf_fn_t get_function(C::emf_fn_ptr_id_t fn_id) noexcept { return C::emf_get_function(fn_id); }

/**
 * See emf_get_sync_handler()
 */
EMF_NODISCARD inline std::optional<std::reference_wrapper<const C::emf_sync_handler_t>> get_sync_handler() noexcept
{
    auto handler { C::emf_get_sync_handler() };
    if (handler != nullptr) {
        return { *handler };
    } else {
        return std::nullopt;
    }
}

/**
 * See emf_set_sync_handler()
 */
inline void set_sync_handler(std::optional<std::reference_wrapper<const C::emf_sync_handler_t>> sync_handler) noexcept
{
    if (sync_handler) {
        C::emf_set_sync_handler(&sync_handler.value().get());
    } else {
        C::emf_set_sync_handler(nullptr);
    }
}

}

#endif // __cplusplus

#endif // ! EMF_C_EMF_CORE_HPP
