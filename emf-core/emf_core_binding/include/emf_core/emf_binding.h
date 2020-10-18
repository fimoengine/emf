#ifndef EMF_C_EMF_BINDING_H
#define EMF_C_EMF_BINDING_H

#ifdef EMF_C_BINDINGS

#include <emf_core/emf_core_interface_t.h>
#include <emf_core/emf_fn_ptr_t.h>
#include <emf_core/emf_macros.h>

#ifdef __cplusplus
namespace EMF::C {
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
void EMF_CALL_C emf_binding_initialize(emf_get_function_fn_t EMF_NOT_NULL get_function_fn) EMF_NOEXCEPT;

/// Binding interface.
extern const emf_core_interface_t* const EMF_NOT_NULL emf_binding_interface;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EMF_C_BINDINGS

#endif // !EMF_C_EMF_BINDING_H
