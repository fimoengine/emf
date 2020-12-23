#ifndef EMF_CORE_BASE_EMF_CBASE_BOOL_T_H
#define EMF_CORE_BASE_EMF_CBASE_BOOL_T_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_macros.h>

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

/// An enum describing a boolean value.
///
/// ## Variants
///
/// | Name                     | Value | Description  |
/// | ------------------------ | ----- | ------------ |
/// | **emf_cbase_bool_false** | `0`   | False value. |
/// | **emf_cbase_bool_true**  | `1`   | True value.  |
typedef enum emf_cbase_bool_t : int8_t {
    /// False.
    emf_cbase_bool_false = 0,
    /// True.
    emf_cbase_bool_true = 1
} emf_cbase_bool_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BASE_EMF_BOOL_T_H
