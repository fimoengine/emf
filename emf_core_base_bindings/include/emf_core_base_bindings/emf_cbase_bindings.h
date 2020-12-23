#ifndef EMF_CORE_BINDINGS_EMF_CORE_BINDINGS_H
#define EMF_CORE_BINDINGS_EMF_CORE_BINDINGS_H

#include <emf_core_base/emf_cbase_fn_ptr_t.h>
#include <emf_core_base/emf_cbase_interface_t.h>
#include <emf_core_base/emf_cbase_macros.h>

#ifdef __cplusplus
#define EMF_CORE_BASE_TYPE(Type) EMF::CoreBase::C::Type
#else
#define EMF_CORE_BASE_TYPE(Type) Type
#endif // __cplusplus

#ifdef __cplusplus
namespace EMF::CoreBase::Bindings::C {
#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/// Initializes the bindings to the `emf-core-base` interface.
void EMF_CBASE_CALL_C emf_cbase_binding_initialize(EMF_CORE_BASE_TYPE(emf_cbase_t*) EMF_CBASE_MAYBE_NULL cbase,
    EMF_CORE_BASE_TYPE(emf_cbase_sys_get_function_fn_t) EMF_CBASE_NOT_NULL cbase_get_function_fn) EMF_CBASE_NOEXCEPT;

/// Binding interface.
extern const EMF_CORE_BASE_TYPE(emf_cbase_interface_t*) const EMF_CBASE_NOT_NULL emf_cbase_binding_interface;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BINDINGS_EMF_CORE_BINDINGS_H
