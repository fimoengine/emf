#ifndef EMF_CORE_EMF_BOOL_T_H
#define EMF_CORE_EMF_BOOL_T_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif // __cplusplus

#include <emf_core/emf_macros.h>

#ifdef __cplusplus
namespace EMF::Core::C {
#endif // __cplusplus

/**
 * Boolean.
 */
typedef enum emf_bool_t : int8_t {
    /// False.
    emf_bool_false = 0,
    /// True.
    emf_bool_true = 1
} emf_bool_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_EMF_BOOL_T_H
