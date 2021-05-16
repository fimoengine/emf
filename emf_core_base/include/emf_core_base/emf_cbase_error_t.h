#ifndef EMF_CBASE_EMF_CBASE_ERROR_T_H
#define EMF_CBASE_EMF_CBASE_ERROR_T_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_macros.h>

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

EMF_CBASE_SPAN_TYPEDEF(emf_cbase_error_string_t, char);

typedef struct emf_cbase_error_info_data_t emf_cbase_error_info_data_t;

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_error_info_vtable_cleanup_fn, void, emf_cbase_error_info_data_t* EMF_CBASE_MAYBE_NULL data)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_error_info_vtable_clone_fn,
    EMF_CBASE_NODISCARD emf_cbase_error_info_data_t* EMF_CBASE_MAYBE_NULL,
    const emf_cbase_error_info_data_t* EMF_CBASE_MAYBE_NULL data)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_error_info_vtable_as_str_fn, EMF_CBASE_NODISCARD emf_cbase_error_string_t,
    const emf_cbase_error_info_data_t* EMF_CBASE_MAYBE_NULL data)

typedef struct emf_cbase_error_info_vtable_t {
    emf_cbase_error_info_vtable_cleanup_fn EMF_CBASE_NOT_NULL cleanup_fn;
    emf_cbase_error_info_vtable_clone_fn EMF_CBASE_NOT_NULL clone_fn;
    emf_cbase_error_info_vtable_as_str_fn EMF_CBASE_NOT_NULL as_str_fn;
} emf_cbase_error_info_vtable_t;

typedef struct emf_cbase_error_info_t {
    emf_cbase_error_info_data_t* EMF_CBASE_MAYBE_NULL data;
    const emf_cbase_error_info_vtable_t* EMF_CBASE_NOT_NULL vtable;
} emf_cbase_error_info_t;

typedef struct emf_cbase_error_data_t emf_cbase_error_data_t;
typedef struct emf_cbase_error_vtable_t emf_cbase_error_vtable_t;

typedef struct emf_cbase_error_t {
    emf_cbase_error_info_data_t* EMF_CBASE_MAYBE_NULL data;
    const emf_cbase_error_vtable_t* EMF_CBASE_NOT_NULL vtable;
} emf_cbase_error_t;

typedef struct emf_cbase_error_ref_t {
    const emf_cbase_error_info_data_t* EMF_CBASE_MAYBE_NULL data;
    const emf_cbase_error_vtable_t* EMF_CBASE_NOT_NULL vtable;
} emf_cbase_error_ref_t;

EMF_CBASE_OPTIONAL_TYPEDEF(emf_cbase_error_optional_t, emf_cbase_error_t)
EMF_CBASE_OPTIONAL_TYPEDEF(emf_cbase_error_ref_optional_t, emf_cbase_error_ref_t)

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_error_vtable_cleanup_fn, void, emf_cbase_error_data_t* EMF_CBASE_MAYBE_NULL data)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_error_vtable_source_fn, EMF_CBASE_NODISCARD emf_cbase_error_ref_optional_t,
    const emf_cbase_error_data_t* EMF_CBASE_MAYBE_NULL data)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_error_vtable_display_info_fn, EMF_CBASE_NODISCARD emf_cbase_error_info_t,
    const emf_cbase_error_data_t* EMF_CBASE_MAYBE_NULL data)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_error_vtable_debug_info_fn, EMF_CBASE_NODISCARD emf_cbase_error_info_t,
    const emf_cbase_error_data_t* EMF_CBASE_MAYBE_NULL data)

typedef struct emf_cbase_error_vtable_t {
    emf_cbase_error_info_vtable_cleanup_fn EMF_CBASE_NOT_NULL cleanup_fn;
    emf_cbase_error_vtable_source_fn EMF_CBASE_NOT_NULL source_fn;
    emf_cbase_error_vtable_display_info_fn EMF_CBASE_NOT_NULL display_info_fn;
    emf_cbase_error_vtable_debug_info_fn EMF_CBASE_NOT_NULL debug_info_fn;
} emf_cbase_error_vtable_t;

#define EMF_CBASE_ERROR_RESULT_TYPEDEF(Name, ResT) EMF_CBASE_RESULT_TYPEDEF(Name, ResT, emf_cbase_error_t)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CBASE_EMF_CBASE_ERROR_T_H