#ifndef EMF_CBASE_EMF_CBASE_VERSION_T_H
#define EMF_CBASE_EMF_CBASE_VERSION_T_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_bool_t.h>
#include <emf_core_base/emf_cbase_error_t.h>
#include <emf_core_base/emf_cbase_macros.h>

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

typedef struct emf_cbase_t emf_cbase_t;

#ifdef EMF_CBASE_USE_ENUMS
typedef enum emf_cbase_version_release_t : int8_t {
    emf_cbase_version_release_stable = 0,
    emf_cbase_version_release_unstable = 1,
    emf_cbase_version_release_beta = 2,
} emf_cbase_version_release_t;
#else
typedef int8_t emf_cbase_version_release_t;

#define emf_cbase_version_release_stable (emf_cbase_version_release_t)0
#define emf_cbase_version_release_unstable (emf_cbase_version_release_t)1
#define emf_cbase_version_release_beta (emf_cbase_version_release_t)2
#endif // EMF_CBASE_USE_ENUMS

typedef struct emf_cbase_version_t {
    int32_t major;
    int32_t minor;
    int32_t patch;
    int64_t build_number;
    int8_t release_number;
    emf_cbase_version_release_t release_type;
} emf_cbase_version_t;

EMF_CBASE_SPAN_TYPEDEF(emf_cbase_version_string_buffer_t, char)
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_version_const_string_buffer_t, const char)
EMF_CBASE_ERROR_RESULT_TYPEDEF(emf_cbase_version_size_result_t, size_t)
EMF_CBASE_ERROR_RESULT_TYPEDEF(emf_cbase_version_result_t, emf_cbase_version_t)

// version api
// construction
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_new_short_fn_t, EMF_CBASE_NODISCARD emf_cbase_version_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, int32_t major, int32_t minor, int32_t patch)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_new_long_fn_t, EMF_CBASE_NODISCARD emf_cbase_version_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, int32_t major, int32_t minor, int32_t patch,
    emf_cbase_version_release_t release_type, int8_t release_number)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_new_full_fn_t, EMF_CBASE_NODISCARD emf_cbase_version_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, int32_t major, int32_t minor, int32_t patch,
    emf_cbase_version_release_t release_type, int8_t release_number, int64_t build)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_from_string_fn_t, EMF_CBASE_NODISCARD emf_cbase_version_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_version_const_string_buffer_t* EMF_CBASE_NOT_NULL version_string)

// strings
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_string_length_short_fn_t, EMF_CBASE_NODISCARD size_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_string_length_long_fn_t, EMF_CBASE_NODISCARD size_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_string_length_full_fn_t, EMF_CBASE_NODISCARD size_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_as_string_short_fn_t, EMF_CBASE_NODISCARD emf_cbase_version_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_as_string_long_fn_t, EMF_CBASE_NODISCARD emf_cbase_version_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_as_string_full_fn_t, EMF_CBASE_NODISCARD emf_cbase_version_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_string_is_valid_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_version_const_string_buffer_t* EMF_CBASE_NOT_NULL version_string)

// comparisons
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_compare_fn_t, EMF_CBASE_NODISCARD int32_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs,
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_compare_weak_fn_t, EMF_CBASE_NODISCARD int32_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs,
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_compare_strong_fn_t, EMF_CBASE_NODISCARD int32_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs,
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_version_is_compatible_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs,
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CBASE_EMF_CBASE_VERSION_T_H
