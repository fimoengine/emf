#ifndef EMF_INTERFACE_C_EMF_LIBRARY_H
#define EMF_INTERFACE_C_EMF_LIBRARY_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core/emf_error_t.h>
#include <emf_core/emf_fs.h>
#include <emf_core/emf_macros.h>

#define EMF_LIBRARY_LOADER_TYPE_MAX_LENGTH 64 /// Max length of a library type name length.

#define EMF_NATIVE_LIBRARY_TYPE_NAME "emf::core::native" /// Name of the native library type.

#ifdef __cplusplus
#define EMF_LIBRARY_LOADER_DEFAULT_HANDLE                                                                                        \
    emf_library_loader_handle_t { EMF::C::emf_library_predefined_handles_native }
#else
#define EMF_LIBRARY_LOADER_DEFAULT_HANDLE                                                                                        \
    (emf_library_loader_handle_t) { emf_library_predefined_handles_native }
#endif // __cplusplus

#ifdef __cplusplus
namespace EMF::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf, void, void)

/**
 * The handle to a library.
 */
typedef struct emf_library_handle_t {
    /// Library id.
    int32_t id;
} emf_library_handle_t;

/**
 * Symbol of a library.
 */
typedef struct emf_symbol_t {
    /// Symbol pointer.
    void* EMF_MAYBE_NULL symbol;
} emf_symbol_t;

/**
 * Function symbol of a library.
 */
typedef struct emf_fn_symbol_t {
    /// Symbol pointer.
    emf_fn_t EMF_MAYBE_NULL symbol;
} emf_fn_symbol_t;

/**
 * Handle to a library loader.
 */
typedef struct emf_library_loader_handle_t {
    /// Internal id.
    int32_t id;
} emf_library_loader_handle_t;

/**
 * Internal handle to a library.
 */
typedef struct emf_library_loader_library_handle_t {
    /// Internal id.
    intptr_t id;
} emf_library_loader_library_handle_t;

/**
 * Type of a library.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_library_type_t, char, EMF_LIBRARY_LOADER_TYPE_MAX_LENGTH)

/**
 * Predefined handles.
 *
 * @note The handles 0-99 are reserved for the specification.
 * @note The handles 100-199 are reserved for the implementation.
 */
typedef enum emf_library_predefined_handles_t : int32_t {
    /// Handle to the native library loader.
    emf_library_predefined_handles_native = 0,
} emf_library_predefined_handles_t;

/**
 * Span of library types.
 */
EMF_SPAN_TYPEDEF(emf_library_type_span_t, emf_library_type_t)

/******************************************************************************************************
*********************************************  Interface  *********************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf_library_loader_interface_load, EMF_NODISCARD emf_library_loader_library_handle_t,
    const emf_path_t* EMF_NOT_NULL library_path)
EMF_FUNCTION_PTR_T(emf_library_loader_interface_unload, void, emf_library_loader_library_handle_t library_handle)
EMF_FUNCTION_PTR_T(emf_library_loader_interface_get_symbol, EMF_NODISCARD emf_error_t,
    emf_library_loader_library_handle_t library_handle, const char* EMF_NOT_NULL symbol_name, emf_symbol_t* EMF_NOT_NULL symbol)
EMF_FUNCTION_PTR_T(emf_library_loader_interface_get_function_symbol, EMF_NODISCARD emf_error_t,
    emf_library_loader_library_handle_t library_handle, const char* EMF_NOT_NULL symbol_name,
    emf_fn_symbol_t* EMF_NOT_NULL symbol)

/**
 * Interface of a library loader.
 */
typedef struct emf_library_loader_interface_t {
    /// Interface version.
    emf_version_t interface_version;

    /// Load function.
    emf_library_loader_interface_load_fn_t EMF_NOT_NULL load_fn;
    /// Unload function.
    emf_library_loader_interface_unload_fn_t EMF_NOT_NULL unload_fn;
    /// Get symbol function.
    emf_library_loader_interface_get_symbol_fn_t EMF_NOT_NULL get_symbol_fn;
    /// Get function function.
    emf_library_loader_interface_get_function_symbol_fn_t EMF_NOT_NULL get_function_fn;
} emf_library_loader_interface_t;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/**
 * @brief Registers a new loader.
 *
 * Registers a new loader, that can load libraries of the type <code>library_type</code>.
 *
 * @note Requires synchronisation.
 * @note All names starting with "__" are reserved for the implementors of the "emf::core" module.
 * @note All names starting with "_Interface" are reserved for the implementors of the respective interface.
 *
 * @pre <code>loader_interface</code> may not be <code>NULL</code>.
 * @pre <code>library_type</code> may not be <code>NULL</code>.
 * @pre <code>emf_library_type_exists(library_type) == emf_bool_false</code>.
 *
 * @post The loader is registered.
 *
 * @param loader_interface Interface to the loader.
 * @param library_type Type of libraries it can load.
 *
 * @return Loader handle.
 */
emf_library_loader_handle_t EMF_CALL_C emf_library_register_loader(
    const emf_library_loader_interface_t* EMF_NOT_NULL loader_interface,
    const emf_library_type_t* EMF_NOT_NULL library_type) EMF_NOEXCEPT;

/**
 * @brief Unregisters a loader.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>loader_handle</code> must be acquired by a call to emf_library_register_loader() or emf_library_get_loader_handle().
 *
 * @post All libraries associated with the loader are unloaded.
 * @post The loader is unregistered.
 * @post <code>loader_handle</code> is invalidated.
 *
 * @param loader_handle Loader handle.
 */
void EMF_CALL_C emf_library_unregister_loader(emf_library_loader_handle_t loader_handle) EMF_NOEXCEPT;

/**
 * @brief Get the number of loaders.
 *
 * @note Requires synchronisation.
 *
 * @return Number of loaders.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_library_get_num_loaders() EMF_NOEXCEPT;

/**
 * @brief Copy the library types able to be loaded.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.length >= emf_library_get_num_loaders()</code>.
 * @pre <code>buffer.data != NULL</code>.
 *
 * @post <code>buffer</code> contains all library types.
 *
 * @param buffer Destination
 *
 * @return Number of library types.
 */
size_t EMF_CALL_C emf_library_get_library_types(emf_library_type_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Get the handle of a loader by the library type it can load.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>library_type</code> may not be <code>NULL</code>.
 * @pre <code>emf_library_type_exists(library_type) == emf_bool_true</code>.
 *
 * @param library_type Library type.
 *
 * @return Handle to the loader.
 */
EMF_NODISCARD emf_library_loader_handle_t EMF_CALL_C emf_library_get_loader_handle(
    const emf_library_type_t* EMF_NOT_NULL library_type) EMF_NOEXCEPT;

/**
 * @brief Checks if a library type can be loaded.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>library_type</code> may not be <code>NULL</code>.
 *
 * @param library_type Library type.
 *
 * @return <code>emf_bool_true</code> if the library type can be loaded.
 * @return <code>emf_bool_false</code> if library type can not be loaded.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_library_type_exists(const emf_library_type_t* EMF_NOT_NULL library_type) EMF_NOEXCEPT;

/**
 * @brief Checks if a library is loaded.
 *
 * @note Requires synchronisation.
 *
 * @param library_handle Library handle.
 *
 * @return <code>emf_bool_true</code> if the library is loaded.
 * @return <code>emf_bool_false</code> if library is not loaded.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_library_library_exists(emf_library_handle_t library_handle) EMF_NOEXCEPT;

/******************************************************************************************************
*************************************  Unsafe system operations  *************************************
******************************************************************************************************/

/**
 * @brief Creates a new unlinked library handle.
 *
 * @note Requires synchronisation.
 *
 * @post A new unlinked library handle is created.
 *
 * @warning Using this handle without a call to emf_library_unsafe_link_library() will result in the termination of the program.
 *
 * @return Library handle.
 */
EMF_NODISCARD emf_library_handle_t EMF_CALL_C emf_library_unsafe_create_library_handle() EMF_NOEXCEPT;

/**
 * @brief Removes a library handle from the system.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>library_handle</code> must be acquired by a call to emf_library_load() or
 * emf_library_unsafe_create_library_handle().
 *
 * @post The handle is removed from the system.
 *
 * @warning Removing the handle does not unload the library.
 *
 * @param library_handle Library handle.
 */
void EMF_CALL_C emf_library_unsafe_remove_library_handle(emf_library_handle_t library_handle) EMF_NOEXCEPT;

/**
 * @brief Links the provided library handle to a loader and its handle.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>library_handle</code> must be acquired by a call to emf_library_load() or
 * emf_library_unsafe_create_library_handle().
 * @pre <code>loader_handle</code> must be acquired by a call to emf_library_register_loader() or emf_library_get_loader_handle().
 *
 * @post <code>library_handle</code> refers to the internal library <code>loader_library_handle</code> from the loader
 * <code>loader_handle</code>.
 *
 * @warning Overwrites existing link, if it exists.
 * @warning Unsafe if <code>library_handle</code> was not acquired by a call to emf_library_unsafe_create_library_handle().
 * @warning Unsafe if <code>loader_library_handle</code> was acquired by a call to emf_library_unsafe_get_loader_library_handle().
 * @warning The uniqueness of the pair <code>loader_handle</code>, <code>loader_library_handle</code> must be ensured before a
 * call to emf_library_unload().
 *
 * @param library_handle Library handle.
 * @param loader_handle Loader handle.
 * @param loader_library_handle Internal library handle.
 */
void EMF_CALL_C emf_library_unsafe_link_library(emf_library_handle_t library_handle, emf_library_loader_handle_t loader_handle,
    emf_library_loader_library_handle_t loader_library_handle) EMF_NOEXCEPT;

/**
 * @brief Get the internal handle of a library.
 *
 * @note Requires synchronisation.
 *
 * @pre The library has been obtained through a call to emf_library_load() or has been manually linked by calling
 * emf_library_unsafe_link_library().
 *
 * @param library_handle Library handle.
 *
 * @return Internal library handle.
 */
EMF_NODISCARD emf_library_loader_library_handle_t EMF_CALL_C emf_library_unsafe_get_loader_library_handle(
    emf_library_handle_t library_handle) EMF_NOEXCEPT;

/**
 * @brief Get the interface to a loader.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>loader_handle</code> must be acquired by a call to emf_library_register_loader() or emf_library_get_loader_handle().
 *
 * @warning The usage of the interface is safe as long emf_unlock() has not been called. Otherwise the interface may have been
 * unregistered.
 *
 * @param loader_handle Loader handle.
 *
 * @return Interface of the loader.
 */
EMF_NODISCARD emf_library_loader_interface_t EMF_CALL_C emf_library_unsafe_get_loader(
    emf_library_loader_handle_t loader_handle) EMF_NOEXCEPT;

/******************************************************************************************************
*****************************************  Loader operations  *****************************************
******************************************************************************************************/

/**
 * @brief Loads a library.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>loader_handle</code> must be acquired by a call to emf_library_register_loader() or emf_library_get_loader_handle().
 * @pre <code>library_path</code> may not be <code>NULL</code>.
 * @pre <code>The</code> library pointed to by the path <code>library_path</code> must be of a type that is loadable by
 * <code>loader_handle</code>.
 *
 * @post A new library is loaded.
 *
 * @param loader_handle Handle of the used loader.
 * @param library_path Path of the library.
 *
 * @return Library handle.
 */
EMF_NODISCARD emf_library_handle_t EMF_CALL_C emf_library_load(
    emf_library_loader_handle_t loader_handle, const emf_path_t* EMF_NOT_NULL library_path) EMF_NOEXCEPT;

/**
 * @brief Unloads a library.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>library_handle</code> must be acquired by a call to emf_library_load() or
 * emf_library_unsafe_create_library_handle().
 *
 * @post The library is unloaded.
 * @post <code>library_handle</code> is invalidated.
 *
 * @param library_handle Handle of the library.
 */
void EMF_CALL_C emf_library_unload(emf_library_handle_t library_handle) EMF_NOEXCEPT;

/**
 * @brief Retrieves a symbol from a library.
 *
 * @note Requires synchronisation.
 *
 * @note May return <code>NULL</code>
 *
 * @pre <code>library_handle</code> must be acquired by a call to emf_library_load() or
 * emf_library_unsafe_create_library_handle().
 * @pre <code>symbol_name</code> may not be <code>NULL</code>.
 * @pre <code>symbol</code> may not be <code>NULL</code>.
 *
 * @post Symbol is written to <code>symbol.symbol</code>.
 *
 * @param library_handle Library.
 * @param symbol_name Name of the symbol.
 * @param symbol Symbol.
 *
 * @return <code>emf_error_none</code> if the symbol exists.
 * @return <code>emf_error_not_found</code> if the symbol does not exist.
 */
EMF_NODISCARD emf_error_t EMF_CALL_C emf_library_get_symbol(
    emf_library_handle_t library_handle, const char* EMF_NOT_NULL symbol_name, emf_symbol_t* EMF_NOT_NULL symbol) EMF_NOEXCEPT;

/**
 * @brief Retrieves a function from a library.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>library_handle</code> must be acquired by a call to emf_library_load() or
 * emf_library_unsafe_create_library_handle().
 * @pre <code>symbol_name</code> may not be <code>NULL</code>.
 * @pre <code>symbol</code> may not be <code>NULL</code>.
 *
 * @post Symbol is written to <code>symbol.symbol</code>.
 *
 * @param library_handle Library.
 * @param symbol_name Name of the symbol.
 * @param symbol Symbol.
 *
 * @return <code>emf_error_none</code> if the symbol exists.
 * @return <code>emf_error_not_found</code> if the symbol does not exist.
 */
EMF_NODISCARD emf_error_t EMF_CALL_C emf_library_get_function_symbol(
    emf_library_handle_t library_handle, const char* EMF_NOT_NULL symbol_name, emf_fn_symbol_t* EMF_NOT_NULL symbol) EMF_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_INTERFACE_C_EMF_LIBRARY_H
