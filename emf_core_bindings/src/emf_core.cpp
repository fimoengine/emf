#include <cstdlib>

#include <emf_core/emf_core.h>
#include <emf_core_bindings/emf_core_bindings.h>

using namespace EMF::Core::C;

namespace EMF::Core::Bindings::C {

extern "C" {

void EMF_CALL_C emf_lock() EMF_NOEXCEPT { emf_binding_interface->lock_fn(); }

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_try_lock() EMF_NOEXCEPT { return emf_binding_interface->try_lock_fn(); }

void EMF_CALL_C emf_unlock() EMF_NOEXCEPT { emf_binding_interface->unlock_fn(); }

void EMF_CALL_C emf_shutdown() EMF_NOEXCEPT { emf_binding_interface->shutdown_fn(); }

EMF_NORETURN void EMF_CALL_C emf_panic(const char* EMF_MAYBE_NULL error) EMF_NOEXCEPT
{
    emf_binding_interface->panic_fn(error);
    std::abort(); // Will never be called.
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_has_function(emf_fn_ptr_id_t fn_id) EMF_NOEXCEPT
{
    return emf_binding_interface->has_function_fn(fn_id);
}

EMF_NODISCARD emf_fn_t EMF_NOT_NULL EMF_CALL_C emf_get_function(emf_fn_ptr_id_t fn_id) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(emf_has_function(fn_id) == emf_bool_true, "emf_get_function()")
    return emf_binding_interface->get_function_fn(fn_id);
}

EMF_NODISCARD const emf_sync_handler_t* EMF_MAYBE_NULL EMF_CALL_C emf_get_sync_handler() EMF_NOEXCEPT
{
    return emf_binding_interface->get_sync_handler_fn();
}

void EMF_CALL_C emf_set_sync_handler(const emf_sync_handler_t* EMF_MAYBE_NULL sync_handler) EMF_NOEXCEPT
{
    emf_binding_interface->set_sync_handler_fn(sync_handler);
}
}

}