#ifndef EMF_INTERFACE_C_EMF_CORE_H
#define EMF_INTERFACE_C_EMF_CORE_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif // __cplusplus

#include <emf_core/emf_bool_t.h>
#include <emf_core/emf_error_t.h>
#include <emf_core/emf_fn_ptr_id_t.h>
#include <emf_core/emf_macros.h>

#define EMF_REQUIRE(Condition)                                                                                                   \
    if (!(Condition)) {                                                                                                          \
        emf_panic("Condition: " #Condition);                                                                                     \
    }

#define EMF_REQUIRE_ERROR(Condition, Error)                                                                                      \
    if (!(Condition)) {                                                                                                          \
        emf_panic("Condition: " #Condition " Error: " Error);                                                                    \
    }

#ifdef EMF_ENABLE_ERROR_CHECKING
#define EMF_ASSERT(Condition) EMF_REQUIRE(Condition)
#define EMF_ASSERT_ERROR(Condition, Error) EMF_REQUIRE_ERROR(Condition, Error)
#else
#define EMF_ASSERT(Condition)
#define EMF_ASSERT_ERROR(Condition, Error)
#endif // EMF_ENABLE_ERROR_CHECKING

#ifdef __cplusplus
namespace EMF::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf, void, void)

/*************************************  Synchronisation handler  *************************************/

EMF_FUNCTION_PTR_T(emf_sync_handler_lock, void, void)
EMF_FUNCTION_PTR_T(emf_sync_handler_try_lock, EMF_NODISCARD emf_bool_t, void)
EMF_FUNCTION_PTR_T(emf_sync_handler_unlock, void, void)

/**
 * The interface of a synchronisation handler.
 */
typedef struct emf_sync_handler_t {
    /// Lock function.
    emf_sync_handler_lock_fn_t EMF_NOT_NULL lock_fn;
    /// Try lock function.
    emf_sync_handler_try_lock_fn_t EMF_NOT_NULL try_lock_fn;
    /// Unlock function.
    emf_sync_handler_unlock_fn_t EMF_NOT_NULL unlock_fn;
} emf_sync_handler_t;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
********************************************  Operations  ********************************************
******************************************************************************************************/

/**
 * @brief Acquires a lock.
 *
 * @post The lock has been acquired.
 */
void EMF_CALL_C emf_lock() EMF_NOEXCEPT;

/**
 * @brief Tries to acquire a lock.
 *
 * @post The lock has been acquired or <code>emf_bool_false</code> has been returned.
 *
 * @return <code>emf_bool_true</code> if the lock could be acquired.
 * @return <code>emf_bool_false</code> if the lock could not be acquired.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_try_lock() EMF_NOEXCEPT;

/**
 * @brief Releases the lock.
 *
 * @pre The lock is acquired.
 * @post The lock has been released.
 */
void EMF_CALL_C emf_unlock() EMF_NOEXCEPT;

/**
 * @brief Terminates the program.
 *
 * @note Requires synchronisation.
 */
void EMF_CALL_C emf_shutdown() EMF_NOEXCEPT;

/**
 * @brief Logs an error and exits.
 *
 * Writes the error to a/several log(s) and exists without cleaning up.
 *
 * @note Requires synchronisation.
 *
 * @param error Error.
 */
EMF_NORETURN void EMF_CALL_C emf_panic(const char* EMF_MAYBE_NULL error) EMF_NOEXCEPT;

/**
 * @brief Checks if the current version implements a certain function.
 *
 * @note Requires synchronisation.
 *
 * @param fn_id Function id.
 *
 * @return <code>emf_bool_true</code> if exists.
 * @return <code>emf_bool_false</code> otherwise.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_has_function(emf_fn_ptr_id_t fn_id) EMF_NOEXCEPT;

/**
 * @brief Fetches a pointer to the specified function.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>emf_has_function(fn_id) ==  emf_bool_true</code>.
 *
 * @param fn_id Function id.
 *
 * @return Function pointer.
 */
EMF_NODISCARD emf_fn_t EMF_NOT_NULL EMF_CALL_C emf_get_function(emf_fn_ptr_id_t fn_id) EMF_NOEXCEPT;

/**
 * @brief Fetches the current synchronisation handler.
 *
 * @note Requires synchronisation.
 *
 * @return Current synchronisation handler.
 */
EMF_NODISCARD const emf_sync_handler_t* EMF_MAYBE_NULL EMF_CALL_C emf_get_sync_handler() EMF_NOEXCEPT;

/**
 * @brief Sets the new synchronisation handler.
 *
 * @note Requires synchronisation.
 * @note If <code>sync_handler == NULL</code>, then the default synchronisation handler is used.
 *
 * @post <code>sync_handler</code> is the new synchronisation handler.
 * @post The old synchronisation handler is unlocked and <code>sync_handler</code> is locked.
 *
 * @param sync_handler Synchronisation handler.
 */
void EMF_CALL_C emf_set_sync_handler(const emf_sync_handler_t* EMF_MAYBE_NULL sync_handler) EMF_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_INTERFACE_C_EMF_CORE_H