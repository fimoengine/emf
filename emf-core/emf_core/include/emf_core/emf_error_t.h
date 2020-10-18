#ifndef EMF_INTERFACE_C_EMF_ERROR_T_H
#define EMF_INTERFACE_C_EMF_ERROR_T_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif // __cplusplus

#include <emf_core/emf_macros.h>

#ifdef __cplusplus
namespace EMF::C {
#endif // __cplusplus

/**
 * EMF::Core error codes.
 */
typedef enum emf_error_t : int32_t {
    /// No error.
    emf_error_none = 0,
    /// Action would result in an invalid state.
    emf_error_contract_violation,
    /// Action not permitted.
    emf_error_not_permitted,
    /// Not found error.
    emf_error_not_found,
    /// End of file reached.
    emf_error_fs_end_of_file
} emf_error_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_INTERFACE_C_EMF_ERROR_T_H