//! # Introduction
//!
//! The `core` system provides an interface to the core functionalities of the `emf-core` interface.
#ifndef EMF_CORE_EMF_CORE_H
#define EMF_CORE_EMF_CORE_H

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
namespace EMF::Core::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf, void, void)

/*************************************  Synchronisation handler  *************************************/

/// A function pointer to a lock function.
///
/// The lock function must have the following properties:
///
/// - The `emf-core` inteface must be locked exclusively.
/// - In case the interface is already locked, the thread must be stalled until a lock can occur.
/// - The `emf-core` interface must be unlockable with the associated unlock function.
EMF_FUNCTION_PTR_T(emf_sync_handler_lock, void, void)

/// A function pointer to a try-lock function.
///
/// The try-lock function must have the following properties:
///
/// - The function must succeed if the interface is in an unlocked state and fail otherwise.
/// - On success, the `emf-core` inteface must be locked exclusively and `emf_bool_true` must be returned.
/// - On failure,  `emf_bool_false` must be returned.
/// - In case of failure, the calling thread may not be stalled.
/// - The `emf-core` interface must be unlockable with the associated unlock function.
EMF_FUNCTION_PTR_T(emf_sync_handler_try_lock, EMF_NODISCARD emf_bool_t, void)

/// A function pointer to an unlock function.
///
/// The unlock function must have the following properties:
///
/// - The `emf-core` inteface must be unlocked if, at the time of calling, it is an a locked state.
EMF_FUNCTION_PTR_T(emf_sync_handler_unlock, void, void)

/// The interface of a synchronisation handler.
///
/// A synchronisation handler manages the concurrent access of the `emf-core` interface.
///
/// # Default handler
///
/// The default synchronisation handler modells a non-recursive, unique lock.
/// Once locked, the caller has safe access to the whole interface.
/// Locking twice will result in a deadlock whereas unlocking twice is undefined behaviour.
///
/// # Fields
///
/// - **lock_fn**: [`emf_sync_handler_lock_fn_t`](./type.emf_sync_handler_lock_fn_t.md)
///
///     The lock function of the synchronisation handler.
///     Is never `NULL`.
///
/// - **try_lock_fn**: [`emf_sync_handler_try_lock_fn_t`](./type.emf_sync_handler_try_lock_fn_t.md)
///
///     The try-lock function of the synchronisation handler.
///     Is never `NULL`.
///
/// - **unlock_fn**: [`emf_sync_handler_unlock_fn_t`](./type.emf_sync_handler_unlock_fn_t.md)
///
///     The unlock function of the synchronisation handler.
///     Is never `NULL`.
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

/// Locks the interface.
///
/// The calling thread is stalled until the lock can be acquired.
/// Only one thread can hold the lock at a time.
///
/// # Deadlock
///
/// Calling this function while the calling thread holds a lock may result in a deadlock.
void EMF_CALL_C emf_lock() EMF_NOEXCEPT;

/// Tries to lock the interface.
///
/// The function fails if another thread already holds the lock.
/// The result is `emf_bool_true` on success and `emf_bool_false` otherwise.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_try_lock() EMF_NOEXCEPT;

/// Unlocks the interface.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
void EMF_CALL_C emf_unlock() EMF_NOEXCEPT;

/// Sends a termination signal.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
void EMF_CALL_C emf_shutdown() EMF_NOEXCEPT;

/// Panics.
///
/// Execution of the program is stopped abruptly after the error is logged.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
EMF_NORETURN void EMF_CALL_C emf_panic(const char* EMF_MAYBE_NULL error) EMF_NOEXCEPT;

/// Checks if a function is implemented.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_has_function(emf_fn_ptr_id_t fn_id) EMF_NOEXCEPT;

/// Retrieves the function pointer of the supplied function.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_EQ(
///     emf_has_function(fn_id),
///     emf_bool_true
/// );
/// ```
EMF_NODISCARD emf_fn_t EMF_NOT_NULL EMF_CALL_C emf_get_function(emf_fn_ptr_id_t fn_id) EMF_NOEXCEPT;

/// Fetches the current synchronisation handler.
///
/// The result of this call will never be `NULL`.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
EMF_NODISCARD const emf_sync_handler_t* EMF_MAYBE_NULL EMF_CALL_C emf_get_sync_handler() EMF_NOEXCEPT;

/// Sets a new synchronisation handler.
///
/// The default synchronisation handler is used, if `sync_handler` is `NULL`.
///
/// # Uses
///
/// This function can be used by modules, that want to provide a more complex
/// synchronisation mechanism than the one presented by the default handler.
///
/// ## Swapping
///
/// The swapping occurs in three steps:
///
/// 1. The new synchronisation handler is locked.
/// 2. The new synchronisation handler is set as the main synchronisation handler.
/// 3. The old synchronisation handler is unlocked.
///
/// ## Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).
///
/// ## Warning
///
/// Changing the synchronisation handler may break some modules, if
/// they depend on a specific synchronisation handler.
void EMF_CALL_C emf_set_sync_handler(const emf_sync_handler_t* EMF_MAYBE_NULL sync_handler) EMF_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_EMF_CORE_H