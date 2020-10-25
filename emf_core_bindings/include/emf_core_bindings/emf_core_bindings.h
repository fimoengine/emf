#ifndef EMF_CORE_BINDINGS_EMF_CORE_BINDINGS_H
#define EMF_CORE_BINDINGS_EMF_CORE_BINDINGS_H

#include <emf_core/emf_core_interface_t.h>
#include <emf_core/emf_fn_ptr_t.h>
#include <emf_core/emf_macros.h>

#ifdef __cplusplus
#define EMF_CORE_TYPE(Type) EMF::Core::C::Type
#else
#define EMF_CORE_TYPE(Type) Type
#endif // __cplusplus

#ifdef __cplusplus
namespace EMF::Core::Bindings::C {
#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Initializes the binding to the interface.
 *
 * @pre <code>get_function_fn</code> may not be <code>NULL</code>.
 *
 * @post The interface can be used.
 *
 * @param get_function_fn Get function function pointer.
 */
void EMF_CALL_C emf_binding_initialize(EMF_CORE_TYPE(emf_get_function_fn_t) EMF_NOT_NULL get_function_fn) EMF_NOEXCEPT;

/// Binding interface.
extern const EMF_CORE_TYPE(emf_core_interface_t*) const EMF_NOT_NULL emf_binding_interface;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BINDINGS_EMF_CORE_BINDINGS_H
