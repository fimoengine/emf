#ifndef EMF_CBASE_EXT_UNWIND_EMF_UNWIND_INTERNAL_H
#define EMF_CBASE_EXT_UNWIND_EMF_UNWIND_INTERNAL_H

#include <emf_core_base/emf_cbase_sys.h>

#define EMF_CBASE_EXT_UNWIND_INTERNAL_INTERFACE_NAME "emf::cbase::unwind_internal"

#define EMF_CBASE_EXT_UNWIND_INTERNAL_VERSION_MAJOR 0
#define EMF_CBASE_EXT_UNWIND_INTERNAL_VERSION_MINOR 1
#define EMF_CBASE_EXT_UNWIND_INTERNAL_VERSION_PATCH 0
#define EMF_CBASE_EXT_UNWIND_INTERNAL_VERSION_RELEASE_TYPE 0
#define EMF_CBASE_EXT_UNWIND_INTERNAL_VERSION_RELEASE_NUMBER 0
#define EMF_CBASE_EXT_UNWIND_INTERNAL_VERSION_BUILD 0

#define EMF_CBASE_EXT_UNWIND_INTERNAL_VERSION_STRING "0.1.0"

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

typedef struct emf_cbase_ext_unw_int_context_t emf_cbase_ext_unw_int_context_t;

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_ext_unw_int_shutdown_fn_t, void, emf_cbase_ext_unw_int_context_t* EMF_CBASE_MAYBE_NULL context)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_ext_unw_int_panic_fn_t, void, emf_cbase_ext_unw_int_context_t* EMF_CBASE_MAYBE_NULL context,
    const char* EMF_CBASE_MAYBE_NULL error)

// unwind internal api
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_ext_unw_int_set_context_fn_t, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_ext_unw_int_context_t* EMF_CBASE_MAYBE_NULL context)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_ext_unw_int_get_context_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_ext_unw_int_context_t* EMF_CBASE_MAYBE_NULL, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_ext_unw_int_set_shutdown_fn_fn_t, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_ext_unw_int_shutdown_fn_t EMF_CBASE_MAYBE_NULL shutdown_fn)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_ext_unw_int_get_shutdown_fn_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_ext_unw_int_shutdown_fn_t EMF_CBASE_MAYBE_NULL, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_ext_unw_int_set_panic_fn_fn_t, void, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_ext_unw_int_panic_fn_t EMF_CBASE_MAYBE_NULL panic_fn)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_ext_unw_int_get_panic_fn_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_ext_unw_int_panic_fn_t EMF_CBASE_MAYBE_NULL, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

typedef struct emf_cbase_ext_unw_int_interface_t {
    emf_cbase_ext_unw_int_set_context_fn_t EMF_CBASE_NOT_NULL set_context_fn;
    emf_cbase_ext_unw_int_get_context_fn_t EMF_CBASE_NOT_NULL get_context_fn;
    emf_cbase_ext_unw_int_set_shutdown_fn_fn_t EMF_CBASE_NOT_NULL set_shutdown_fn_fn;
    emf_cbase_ext_unw_int_get_shutdown_fn_fn_t EMF_CBASE_NOT_NULL get_shutdown_fn_fn;
    emf_cbase_ext_unw_int_set_panic_fn_fn_t EMF_CBASE_NOT_NULL set_panic_fn_fn;
    emf_cbase_ext_unw_int_get_panic_fn_fn_t EMF_CBASE_NOT_NULL get_panic_fn_fn;
} emf_cbase_ext_unw_int_interface_t;

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_ext_unw_int_get_unw_int_interface,
    EMF_CBASE_NODISCARD const emf_cbase_ext_unw_int_interface_t* EMF_CBASE_NOT_NULL,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CBASE_EXT_UNWIND_EMF_UNWIND_INTERNAL_H