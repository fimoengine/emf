#ifndef EMF_CBASE_EMF_CBASE_SYS_H
#define EMF_CBASE_EMF_CBASE_SYS_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_bool_t.h>
#include <emf_core_base/emf_cbase_error_t.h>
#include <emf_core_base/emf_cbase_fn_ptr_id_t.h>
#include <emf_core_base/emf_cbase_macros.h>

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

typedef struct emf_cbase_t emf_cbase_t;

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_fn_t, void, void)
EMF_CBASE_OPTIONAL_TYPEDEF(emf_cbase_fn_optional_t, emf_cbase_fn_t EMF_CBASE_NOT_NULL)
EMF_CBASE_OPTIONAL_TYPEDEF(emf_cbase_sync_handler_interface_optional_t, emf_cbase_sync_handler_interface_t)

// sync handler interface
typedef struct emf_cbase_sync_handler_t emf_cbase_sync_handler_t;

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sync_handler_lock_fn_t, void, emf_cbase_sync_handler_t* EMF_CBASE_MAYBE_NULL sync_handler)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sync_handler_try_lock_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_sync_handler_t* EMF_CBASE_MAYBE_NULL sync_handler)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sync_handler_unlock_fn_t, void, emf_cbase_sync_handler_t* EMF_CBASE_MAYBE_NULL sync_handler)

typedef struct emf_cbase_sync_handler_interface_vtable_t {
    emf_cbase_sync_handler_lock_fn_t EMF_CBASE_NOT_NULL lock_fn;
    emf_cbase_sync_handler_try_lock_fn_t EMF_CBASE_NOT_NULL try_lock_fn;
    emf_cbase_sync_handler_unlock_fn_t EMF_CBASE_NOT_NULL unlock_fn;
} emf_cbase_sync_handler_interface_vtable_t;

EMF_CBASE_FAT_PTR_TYPEDEF(emf_cbase_sync_handler_interface_t, emf_cbase_sync_handler_t, emf_cbase_sync_handler_interface_vtable_t)

// sys api
// termination
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_shutdown_fn_t, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_sys_panic_fn_t, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_error_optional_t error)

// queries
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_has_function_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_fn_ptr_id_t fn_id)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_get_function_fn_t, EMF_CBASE_NODISCARD emf_cbase_fn_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_fn_ptr_id_t fn_id)

// synchronization
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_lock_fn_t, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_sys_try_lock_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_unlock_fn_t, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

// manual synchronization
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_get_sync_handler_fn_t, EMF_CBASE_NODISCARD emf_cbase_sync_handler_interface_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_set_sync_handler_fn_t, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_sync_handler_interface_optional_t sync_handler)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CBASE_EMF_CBASE_SYS_H
