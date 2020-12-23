#include <cstdlib>

#include <emf_core_base/emf_cbase_sys.h>
#include <emf_core_base_bindings/emf_cbase_bindings.h>

using namespace EMF::CoreBase::C;

namespace EMF::CoreBase::Bindings::C {

extern "C" {

void EMF_CBASE_CALL_C emf_cbase_sys_lock() EMF_CBASE_NOEXCEPT
{
    emf_cbase_binding_interface->sys_lock_fn(emf_cbase_binding_interface->cbase);
}

EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_sys_try_lock() EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->sys_try_lock_fn(emf_cbase_binding_interface->cbase);
}

void EMF_CBASE_CALL_C emf_cbase_sys_unlock() EMF_CBASE_NOEXCEPT
{
    emf_cbase_binding_interface->sys_unlock_fn(emf_cbase_binding_interface->cbase);
}

EMF_CBASE_NORETURN void EMF_CBASE_CALL_C emf_cbase_sys_shutdown() EMF_CBASE_NOEXCEPT
{
    emf_cbase_binding_interface->sys_shutdown_fn(emf_cbase_binding_interface->cbase);
    std::abort(); // Will never be called.
}

EMF_CBASE_NORETURN void EMF_CBASE_CALL_C emf_cbase_sys_panic(const char* EMF_CBASE_MAYBE_NULL error) EMF_CBASE_NOEXCEPT
{
    emf_cbase_binding_interface->sys_panic_fn(emf_cbase_binding_interface->cbase, error);
    std::abort(); // Will never be called.
}

EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_sys_has_function(emf_cbase_fn_ptr_id_t fn_id) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->sys_has_function_fn(emf_cbase_binding_interface->cbase, fn_id);
}

EMF_CBASE_NODISCARD emf_cbase_sys_fn_optional_t EMF_CBASE_CALL_C emf_cbase_sys_get_function(
    emf_cbase_fn_ptr_id_t fn_id) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->sys_get_function_fn(emf_cbase_binding_interface->cbase, fn_id);
}

EMF_CBASE_NODISCARD const emf_sync_handler_interface_t* EMF_CBASE_NOT_NULL EMF_CBASE_CALL_C emf_cbase_sys_get_sync_handler()
    EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->sys_get_sync_handler_fn(emf_cbase_binding_interface->cbase);
}

void EMF_CBASE_CALL_C emf_cbase_sys_set_sync_handler(
    const emf_sync_handler_interface_t* EMF_CBASE_MAYBE_NULL sync_handler) EMF_CBASE_NOEXCEPT
{
    emf_cbase_binding_interface->sys_set_sync_handler_fn(emf_cbase_binding_interface->cbase, sync_handler);
}
}

}