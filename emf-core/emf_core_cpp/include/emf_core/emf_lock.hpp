#ifndef EMF_C_EMF_LOCK_HPP
#define EMF_C_EMF_LOCK_HPP

#ifdef __cplusplus

#include <mutex>

#include <emf_core/emf_core.hpp>

namespace EMF {

class emf_lock_t {
    emf_lock_t() noexcept = default;
    emf_lock_t(const emf_lock_t& lock) = delete;
    emf_lock_t(emf_lock_t&& lock) noexcept = default;
    ~emf_lock_t() = default;

    emf_lock_t& operator=(const emf_lock_t& lock) = delete;
    emf_lock_t& operator=(emf_lock_t&& lock) noexcept = default;

    void lock() { Core::lock(); }

    bool try_lock() { return Core::try_lock(); }

    void unlock() { Core::lock(); }
};

}

#endif // __cplusplus

#endif // ! EMF_C_EMF_LOCK_HPP
