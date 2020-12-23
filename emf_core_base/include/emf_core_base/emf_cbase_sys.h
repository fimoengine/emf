//! # Introduction
//!
//! An interface to the core functionalities of the `emf-core-base` interface.
#ifndef EMF_CORE_BASE_EMF_CBASE_SYS_H
#define EMF_CORE_BASE_EMF_CBASE_SYS_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_bool_t.h>
#include <emf_core_base/emf_cbase_fn_ptr_id_t.h>
#include <emf_core_base/emf_cbase_macros.h>

#define EMF_CBASE_REQUIRE(Condition)                                                                                             \
    if (!(Condition)) {                                                                                                          \
        emf_cbase_sys_panic("Condition: " #Condition);                                                                           \
    }

#define EMF_CBASE_REQUIRE_ERROR(Condition, Error)                                                                                \
    if (!(Condition)) {                                                                                                          \
        emf_cbase_sys_panic("Condition: " #Condition " Error: " Error);                                                          \
    }

#ifdef EMF_ENABLE_DEBUG_ASSERTIONS
#define EMF_CBASE_ASSERT(Condition) EMF_CBASE_REQUIRE(Condition)
#define EMF_CBASE_ASSERT_ERROR(Condition, Error) EMF_CBASE_REQUIRE_ERROR(Condition, Error)
#else
#define EMF_ASSERT(Condition)
#define EMF_ASSERT_ERROR(Condition, Error)
#endif // EMF_ENABLE_DEBUG_ASSERTIONS

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

/// A type-erased function pointer.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase, void, void)

#ifndef EMF_CBASE_SYS_FN_OPTIONAL_T_DEF
#define EMF_CBASE_SYS_FN_OPTIONAL_T_DEF
/// An optional `emf_cbase_fn_t` value
///
/// # Fields
///
/// - **value**: [`emf_cbase_fn_t`](./type.emf_cbase_fn_t.md)
///
///     A pointer to a function.
///
/// - **has_value**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the optional contains a value.
EMF_CBASE_OPTIONAL_TYPEDEF(emf_cbase_sys_fn_optional_t, emf_cbase_fn_t EMF_CBASE_NOT_NULL)
#endif // !EMF_CBASE_SYS_FN_OPTIONAL_T_DEF

/*************************************  Synchronisation handler  *************************************/

/// An opaque structure representing a synchronisation handler.
typedef struct emf_cbase_sync_handler_t emf_cbase_sync_handler_t;

/// A function pointer to a `lock` function.
///
/// The lock function must have the following properties:
///
/// - The `emf-core-base` interface must be locked exclusively.
/// - In case the interface is already locked, the thread must be stalled until a lock can occur.
/// - The `emf-core-base` interface must be unlockable with the associated unlock function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sync_handler_lock, void, emf_cbase_sync_handler_t* EMF_CBASE_MAYBE_NULL sync_handler)

/// A function pointer to a `try-lock` function.
///
/// The try-lock function must have the following properties:
///
/// - The function must succeed if the interface is in an unlocked state and fail otherwise.
/// - On success, the `emf-core-base` interface must be locked exclusively and `emf_cbase_bool_true` must be returned.
/// - On failure, `emf_cbase_bool_false` must be returned.
/// - In case of failure, the calling thread may not be stalled.
/// - The `emf-core-base` interface must be unlockable with the associated unlock function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sync_handler_try_lock, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_sync_handler_t* EMF_CBASE_MAYBE_NULL sync_handler)

/// A function pointer to an `unlock` function.
///
/// The unlock function must have the following properties:
///
/// - The `emf-core-base` interface must be unlocked if, at the time of calling, it is an a locked state.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sync_handler_unlock, void, emf_cbase_sync_handler_t* EMF_CBASE_MAYBE_NULL sync_handler)

/// The interface of a synchronisation handler.
///
/// A synchronisation handler manages the concurrent access of the `emf-core-base` interface.
///
/// # Default handler
///
/// The default synchronisation handler models a non-recursive, unique lock.
/// Once locked, the caller has safe access to the whole interface.
/// Locking twice will result in a deadlock whereas unlocking twice is undefined behaviour.
///
/// # Fields
///
/// - **sync_handler**: [`emf_cbase_sync_handler_t*`](./struct.emf_cbase_sync_handler_t.md)
///
///     A pointer to the synchronisation handler.
///
/// - **lock_fn**: [`emf_cbase_sync_handler_lock_fn_t`](./type.emf_cbase_sync_handler_lock_fn_t.md)
///
///     The lock function of the synchronisation handler.
///     Is never `NULL`.
///
/// - **try_lock_fn**: [`emf_cbase_sync_handler_try_lock_fn_t`](./type.emf_cbase_sync_handler_try_lock_fn_t.md)
///
///     The try-lock function of the synchronisation handler.
///     Is never `NULL`.
///
/// - **unlock_fn**: [`emf_cbase_sync_handler_unlock_fn_t`](./type.emf_cbase_sync_handler_unlock_fn_t.md)
///
///     The unlock function of the synchronisation handler.
///     Is never `NULL`.
typedef struct emf_sync_handler_interface_t {
    /// Sync handler.
    emf_cbase_sync_handler_t* EMF_CBASE_MAYBE_NULL sync_handler;
    /// Lock function.
    emf_cbase_sync_handler_lock_fn_t EMF_CBASE_NOT_NULL lock_fn;
    /// Try lock function.
    emf_cbase_sync_handler_try_lock_fn_t EMF_CBASE_NOT_NULL try_lock_fn;
    /// Unlock function.
    emf_cbase_sync_handler_unlock_fn_t EMF_CBASE_NOT_NULL unlock_fn;
} emf_sync_handler_interface_t;

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
void EMF_CBASE_CALL_C emf_cbase_sys_lock() EMF_CBASE_NOEXCEPT;

/// Tries to lock the interface.
///
/// The function fails if another thread already holds the lock.
/// The result is `emf_cbase_bool_true` on success and `emf_cbase_bool_false` otherwise.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_sys_try_lock() EMF_CBASE_NOEXCEPT;

/// Unlocks the interface.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
void EMF_CBASE_CALL_C emf_cbase_sys_unlock() EMF_CBASE_NOEXCEPT;

/// Sends a termination signal.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NORETURN void EMF_CBASE_CALL_C emf_cbase_sys_shutdown() EMF_CBASE_NOEXCEPT;

/// Panics.
///
/// Execution of the program is stopped abruptly after the error is logged.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NORETURN void EMF_CBASE_CALL_C emf_cbase_sys_panic(const char* EMF_CBASE_MAYBE_NULL error) EMF_CBASE_NOEXCEPT;

/// Checks if a function is implemented.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_sys_has_function(emf_cbase_fn_ptr_id_t fn_id) EMF_CBASE_NOEXCEPT;

/// Retrieves the function pointer to the function.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_sys_fn_optional_t EMF_CBASE_CALL_C emf_cbase_sys_get_function(
    emf_cbase_fn_ptr_id_t fn_id) EMF_CBASE_NOEXCEPT;

/// Fetches the current synchronisation handler.
///
/// The result of this call will never be `NULL`.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD const emf_sync_handler_interface_t* EMF_CBASE_NOT_NULL EMF_CBASE_CALL_C emf_cbase_sys_get_sync_handler()
    EMF_CBASE_NOEXCEPT;

/// Sets a new synchronisation handler.
///
/// The default synchronisation handler is used, if `sync_handler` is `NULL`.
///
/// # Uses
///
/// This function can be used by modules, that want to provide a more complex
/// synchronisation mechanism than the one presented by the default handler.
///
/// # Swapping
///
/// The swapping occurs in three steps:
///
/// 1. The new synchronisation handler is locked.
/// 2. The new synchronisation handler is set as the main synchronisation handler.
/// 3. The old synchronisation handler is unlocked.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
///
/// # Warning
///
/// Changing the synchronisation handler may break some modules, if
/// they depend on a specific synchronisation handler.
void EMF_CBASE_CALL_C emf_cbase_sys_set_sync_handler(
    const emf_sync_handler_interface_t* EMF_CBASE_MAYBE_NULL sync_handler) EMF_CBASE_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BASE_EMF_CBASE_SYS_H