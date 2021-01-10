///! # Introduction
///!
///! The `library` api is a collection of procedures that provide a platform agnostic interface
///! to loading shared libraries. The actual loading of a library is handled by a `library loader`.
///! Each `library loader` is associated to a `library type`.
///!
///! ## Loaders
///!
///! The job of a `library loader` is to manage the loading and unloading of libraries.
///! A `library loader` can be added by constructing a
///! [`emf_cbase_library_loader_interface_t`](./struct.emf_cbase_library_loader_interface_t.md) and then calling the
///! [`emf_cbase_library_register_loader()`](./fn.emf_cbase_library_register_loader.md) function.
///!
///! ## Library types
///!
///! The `library` api allows the loading of custom library formats.
///! Each format is identified by a [`emf_cbase_library_type_t`](./struct.emf_cbase_library_type_t.md) and is
///! associated to exactly one `library loader`.
///!
///! # Predefined Loaders
///!
///! Some `library loaders` are always present and can not be removed at runtime.
///!
///! ## Native
///!
///! The native `library loader` is able to load platform-specific libraries (e.g. dlopen()/LoadLibrary()).
///! It is associated to the [`EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME`](./constant.EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME.md)
///! `library type` and is reachable with the
///! [`EMF_CBASE_LIBRARY_LOADER_DEFAULT_HANDLE`](./constant.EMF_CBASE_LIBRARY_LOADER_DEFAULT_HANDLE.md) handle.
///!
///! On posix the `library loader` defaults to the `RTLD_LAZY` and `RTLD_LOCAL` flags. More controll of how to load a library can
///! be achieved by fetching a pointer to the interface with
///! [`emf_cbase_library_unsafe_get_loader_interface`](./fn.emf_cbase_library_unsafe_get_loader_interface.md), casting it to a
///! [`emf_cbase_native_library_loader_interface_t`](./struct.emf_cbase_native_library_loader_interface_t.md) and calling the
///! [`load_ext_fn`](.type.emf_cbase_native_library_loader_interface_load_ext_fn_t.md) function.
///! If the library has dependencies on other libraries, then it must specify them by specifying an `rpath` on posix or
///! embedding an `Activation Context manifest` into the library on Windows.
///!
///! # Example
///!
///! ```c
///! const emf_cbase_os_path_char_t* library_path = "./example_lib.so";
///!
///! emf_cbase_library_handle_result_t library_handle_res =
///!     emf_cbase_library_load(EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME, library_path);
///! if (library_handle_res.has_error) {
///!     emf_cbase_sys_panic("Unable to load the `./example_lib.so` library.");
///! }
///!
///! emf_cbase_library_handle_t library_handle = library_handle_res.result;
///!
///! emf_cbase_library_fn_symbol_result_t fn_sym_res =
///!     emf_cbase_library_get_function_symbol(library_handle, "example_fn");
///! if (fn_sym_res.has_error) {
///!     emf_cbase_sys_panic("Unable to load the `example_fn` function from the library.");
///! }
///!
///! emf_cbase_library_fn_symbol_t fn_sym = fn_sym_res.result;
///! void (*fn)(int, int) = (void(*)(int, int))fn_sym.symbol;
///! (*fn)(5, 7);
///!
///! emf_cbase_library_error_optional_t error_opt =
///!     emf_cbase_library_unload(library_handle);
///! if (error_opt.has_value) {
///!     emf_cbase_sys_panic("Unable to unload the `./example_lib.so` library.");
///! }
///! ```
#ifndef EMF_CORE_BASE_EMF_CBASE_LIBRARY_H
#define EMF_CORE_BASE_EMF_CBASE_LIBRARY_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_macros.h>
#include <emf_core_base/emf_cbase_version_t.h>

/// Max length of a library type name.
#define EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH 64

/// Name of the native library type.
#define EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME "emf::core_base::native"

#if defined(Win32) || defined(_WIN32)
/// Character used by the os to represent a path.
#define EMF_CBASE_OS_PATH_CHAR wchar_t
#else
/// Character used by the os to represent a path.
#define EMF_CBASE_OS_PATH_CHAR char
#endif // defined(Win32) || defined(_WIN32)

#ifdef __cplusplus
/// Handle to the default library loader.
#define EMF_CBASE_LIBRARY_LOADER_DEFAULT_HANDLE                                                                                  \
    emf_cbase_library_loader_handle_t { EMF::CoreBase::C::emf_cbase_library_predefined_handles_native }
#else
/// Handle to the default library loader.
#define EMF_CBASE_LIBRARY_LOADER_DEFAULT_HANDLE                                                                                  \
    (emf_cbase_library_loader_handle_t) { emf_cbase_library_predefined_handles_native }
#endif // __cplusplus

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

/// A type-erased function pointer.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase, void, void)

/// Character used by the os to represent a path.
typedef EMF_CBASE_OS_PATH_CHAR emf_cbase_os_path_char_t;

/// The handle to a library.
///
/// # Fields
///
/// - **id**: `int32_t`
///
///     Id of the library.
typedef struct emf_cbase_library_handle_t {
    /// Library id.
    int32_t id;
} emf_cbase_library_handle_t;

/// A data symbol contained in a library.
///
/// # Fields
///
/// - **symbol**: `void*`
///
///     A pointer to the symbol.
///     Is never `NULL`.
typedef struct emf_cbase_data_symbol_t {
    /// Symbol pointer.
    void* EMF_CBASE_NOT_NULL symbol;
} emf_cbase_data_symbol_t;

/// A function symbol contained in a library.
///
/// # Fields
///
/// - **symbol**: [`emf_cbase_fn_t`](./type.emf_cbase_fn_t.md)
///
///     A pointer to the symbol.
///     Is never `NULL`.
typedef struct emf_cbase_fn_symbol_t {
    /// Symbol pointer.
    emf_cbase_fn_t EMF_CBASE_NOT_NULL symbol;
} emf_cbase_fn_symbol_t;

/// The handle to a library loader.
///
/// # Fields
///
/// - **id**: `int32_t`
///
///     Id of the library loader.
typedef struct emf_cbase_library_loader_handle_t {
    /// Internal id.
    int32_t id;
} emf_cbase_library_loader_handle_t;

/// The internal handle to a library.
///
/// This handle is used inside of a library loader.
///
/// # Fields
///
/// - **id**: `intptr_t`
///
///     Id of the library.
typedef struct emf_cbase_library_loader_library_handle_t {
    /// Internal id.
    intptr_t id;
} emf_cbase_library_loader_library_handle_t;

/// The type of a library.
///
/// A library type is modelled as an `UTF-8` encoded string, without a `\0` terminator.
///
/// # Fields
///
/// - **data**: [`char[EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH]`](./constant.EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH.md)
///
///     The type string.
///
/// - **length**: `size_t`
///
///     Length of the string.
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_library_type_t, char, EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH)

/// An enum describing all predefined library loader handles.
///
/// The values `0-99` are reserved for future use.
///
/// # Variants
///
/// | Name                                            | Value | Description            |
/// | ----------------------------------------------- | ----- | ---------------------- |
/// | **emf_cbase_library_predefined_handles_native** | `0`   | The default handle.    |
typedef enum emf_cbase_library_predefined_handles_t : int32_t {
    /// Handle to the native library loader.
    emf_cbase_library_predefined_handles_native = 0,
} emf_cbase_library_predefined_handles_t;

/// An enum describing all defined error values.
///
/// The values `0-99` are reserved for future use.
///
/// # Variants
///
/// | Name                                                       | Value | Description                             |
/// | ---------------------------------------------------------- | ----- | --------------------------------------- |
/// | **emf_cbase_library_error_library_path_not_found**         | `0`   | A path could not be found.              |
/// | **emf_cbase_library_error_library_handle_invalid**         | `1`   | The library handle is invalid.          |
/// | **emf_cbase_library_error_loader_handle_invalid**          | `2`   | The loader handle is invalid.           |
/// | **emf_cbase_library_error_loader_library_handle_invalid**  | `3`   | The internal library handle is invalid. |
/// | **emf_cbase_library_error_library_type_invalid**           | `4`   | The library type is invalid.            |
/// | **emf_cbase_library_error_library_type_not_found**         | `5`   | The library type could not be found.    |
/// | **emf_cbase_library_error_duplicate_library_type**         | `6`   | The library type already exists.        |
/// | **emf_cbase_library_error_symbol_not_found**               | `7`   | A symbol could not be found.            |
/// | **emf_cbase_library_error_buffer_overflow**                | `8`   | The buffer is too small.                |
typedef enum emf_cbase_library_error_t : int32_t {
    emf_cbase_library_error_library_path_not_found = 0,
    emf_cbase_library_error_library_handle_invalid = 1,
    emf_cbase_library_error_loader_handle_invalid = 2,
    emf_cbase_library_error_loader_library_handle_invalid = 3,
    emf_cbase_library_error_library_type_invalid = 4,
    emf_cbase_library_error_library_type_not_found = 5,
    emf_cbase_library_error_duplicate_library_type = 6,
    emf_cbase_library_error_symbol_not_found = 7,
    emf_cbase_library_error_buffer_overflow = 8,
} emf_cbase_library_error_t;

/// A span of library types.
///
/// # Fields
///
/// - **data**: [`emf_cbase_library_type_t*`](./struct.emf_cbase_library_type_t.md)
///
///     The start of the span.
///
/// - **length**: `size_t`
///
///     The length of the span.
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_library_type_span_t, emf_cbase_library_type_t)

/// An optional `emf_cbase_library_error_t` value
///
/// # Fields
///
/// - **value**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)
///
///     The error value.
///
/// - **has_value**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the optional contains a value.
EMF_CBASE_OPTIONAL_TYPEDEF(emf_cbase_library_error_optional_t, emf_cbase_library_error_t)

/// A struct containing either a `size_t` or an `emf_cbase_library_error_t`
///
/// # Fields
///
/// - **result**: `size_t`
///
///     The size.
///
/// - **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_size_result_t, size_t, emf_cbase_library_error_t)

/// A struct containing either an `emf_cbase_library_handle_t` or an `emf_cbase_library_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_library_handle_t`](./struct.emf_cbase_library_handle_t.md)
///
///     The library handle.
///
/// - **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_handle_result_t, emf_cbase_library_handle_t, emf_cbase_library_error_t)

/// A struct containing either an `emf_cbase_library_loader_handle_t` or an `emf_cbase_library_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_library_loader_handle_t`](./struct.emf_cbase_library_loader_handle_t.md)
///
///     The loader handle.
///
/// - **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_loader_handle_result_t, emf_cbase_library_loader_handle_t, emf_cbase_library_error_t)

/// A struct containing either an `emf_cbase_library_loader_library_handle_t` or an `emf_cbase_library_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_library_loader_library_handle_t`](./struct.emf_cbase_library_loader_library_handle_t.md)
///
///     The library handle.
///
/// - **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_library_loader_library_handle_result_t, emf_cbase_library_loader_library_handle_t, emf_cbase_library_error_t)

/// A struct containing either an `emf_cbase_data_symbol_t` or an `emf_cbase_library_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_data_symbol_t`](./struct.emf_cbase_data_symbol_t.md)
///
///     The symbol.
///
/// - **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_data_symbol_result_t, emf_cbase_data_symbol_t, emf_cbase_library_error_t)

/// A struct containing either an `emf_cbase_fn_symbol_t` or an `emf_cbase_library_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_fn_symbol_t`](./struct.emf_cbase_fn_symbol_t.md)
///
///     The symbol.
///
/// - **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_fn_symbol_result_t, emf_cbase_fn_symbol_t, emf_cbase_library_error_t)

/******************************************************************************************************
*********************************************  Interface  *********************************************
******************************************************************************************************/

/// An opaque structure representing a library loader.
typedef struct emf_cbase_library_loader_t emf_cbase_library_loader_t;

/// A function pointer to a `load` function.
///
/// The function loads the library, which is located at `library_path`, and returns its handle.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_loader_interface_load,
    EMF_CBASE_NODISCARD emf_cbase_library_loader_library_handle_result_t,
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path)

/// A function pointer to a `unload` function.
///
/// The function unloads a library, that was loaded previously.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_loader_interface_unload, EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t,
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader, emf_cbase_library_loader_library_handle_t library_handle)

/// A function pointer to a `get_data_symbol` function.
///
/// The function fetches a pointer to the symbol `symbol_name` from the library.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_loader_interface_get_data_symbol,
    EMF_CBASE_NODISCARD emf_cbase_library_data_symbol_result_t, emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    emf_cbase_library_loader_library_handle_t library_handle, const char* EMF_CBASE_NOT_NULL symbol_name)

/// A function pointer to a `get_function_symbol` function.
///
/// The function fetches a pointer to the function symbol `symbol_name` from the library.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_loader_interface_get_function_symbol,
    EMF_CBASE_NODISCARD emf_cbase_library_fn_symbol_result_t, emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    emf_cbase_library_loader_library_handle_t library_handle, const char* EMF_CBASE_NOT_NULL symbol_name)

/// A function pointer to a `get_internal_interface` function.
///
/// The function fetches a pointer to the internal interface of the loader.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_library_loader_interface_get_internal_interface, EMF_CBASE_NODISCARD const void* EMF_CBASE_NOT_NULL, void)

/// Interface of a library loader.
///
/// # Fields
///
/// - **library_loader**: [`emf_cbase_library_loader_t`](./struct.emf_cbase_library_loader_t.md)
///
///     A pointer to the library loader.
///
/// - **load_fn**: [`emf_cbase_library_loader_interface_load_fn_t`](./type.emf_cbase_library_loader_interface_load_fn_t.md)
///
///     The load function of the library loader.
///     May not be `NULL`.
///
/// - **unload_fn**: [`emf_cbase_library_loader_interface_unload_fn_t`](./type.emf_cbase_library_loader_interface_unload_fn_t.md)
///
///     The unload function of the library loader.
///     May not be `NULL`.
///
/// - **get_data_symbol_fn**:
/// [`emf_cbase_library_loader_interface_get_data_symbol_fn_t`](./type.emf_cbase_library_loader_interface_get_data_symbol_fn_t.md)
///
///     The get_data_symbol function of the library loader.
///     May not be `NULL`.
///
/// - **get_function_fn**:
/// [`emf_cbase_library_loader_interface_get_function_symbol_fn_t`](./type.emf_cbase_library_loader_interface_get_function_symbol_fn_t.md)
///
///     The get_function function of the library loader.
///     May not be `NULL`.
///
/// - **get_internal_interface_fn**:
/// [`emf_cbase_library_loader_interface_get_internal_interface_fn_t`](./type.emf_cbase_library_loader_interface_get_internal_interface_fn_t.md)
///
///     The get_internal_interface function of the library loader.
///     May not be `NULL`.
typedef struct emf_cbase_library_loader_interface_t {
    /// Library loader.
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader;
    /// Load function.
    emf_cbase_library_loader_interface_load_fn_t EMF_CBASE_NOT_NULL load_fn;
    /// Unload function.
    emf_cbase_library_loader_interface_unload_fn_t EMF_CBASE_NOT_NULL unload_fn;
    /// Get symbol function.
    emf_cbase_library_loader_interface_get_data_symbol_fn_t EMF_CBASE_NOT_NULL get_data_symbol_fn;
    /// Get function function.
    emf_cbase_library_loader_interface_get_function_symbol_fn_t EMF_CBASE_NOT_NULL get_function_fn;
    /// Get internal interface function.
    emf_cbase_library_loader_interface_get_internal_interface_fn_t EMF_CBASE_NOT_NULL get_internal_interface_fn;
} emf_cbase_library_loader_interface_t;

/// A struct containing either an `const emf_cbase_library_loader_interface_t*` or an `emf_cbase_library_error_t`
///
/// # Fields
///
/// - **result**: [`const emf_cbase_library_loader_interface_t*`](./struct.emf_cbase_library_loader_interface_t.md)
///
///     The pointer to the interface.
///     Is never `NULL`.
///
/// - **error**: [`emf_cbase_library_error_t`](./enum.emf_cbase_library_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_loader_interface_result_t,
    const emf_cbase_library_loader_interface_t* EMF_CBASE_NOT_NULL, emf_cbase_library_error_t)

/**************************************  Native Library Loader **************************************/

#if defined(Win32) || defined(_WIN32)
/// A function pointer to a `load_ext` function.
///
/// The function loads the library, which is located at `library_path`, and returns its handle.
/// Directly matches the win32 `LoadLibraryExW` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_library_loader_interface_load_ext,
    EMF_CBASE_NODISCARD emf_cbase_library_loader_library_handle_result_t,
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path, void* EMF_CBASE_MAYBE_NULL hFile, uint32_t flags)
#else
/// A function pointer to a `load_ext` function.
///
/// The function loads the library, which is located at `library_path`, and returns its handle.
/// Directly matches the posix `dlopen` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_library_loader_interface_load_ext,
    EMF_CBASE_NODISCARD emf_cbase_library_loader_library_handle_result_t,
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path, int flags)
#endif // defined(Win32) || defined(_WIN32)

/// Interface of the native library loader.
///
/// # Fields
///
/// - **library_loader_interface**:
/// [`const emf_cbase_library_loader_interface_t*`](./struct.emf_cbase_library_loader_interface_t.md)
///
///     The base library loader interface.
///
/// - **load_ext_fn**:
/// [`emf_cbase_native_library_loader_interface_load_ext_fn_t`](./type.emf_cbase_native_library_loader_interface_load_ext_fn_t.md)
///
///     The load_ext function of the module loader.
///     May not be `NULL`.
typedef struct emf_cbase_native_library_loader_interface_t {
    const emf_cbase_library_loader_interface_t* EMF_CBASE_NOT_NULL library_loader_interface;
    emf_cbase_native_library_loader_interface_load_ext_fn_t EMF_CBASE_NOT_NULL load_ext_fn;
} emf_cbase_native_library_loader_interface_t;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/// Registers a new loader.
///
/// The loader can load libraries of the type `library_type`.
///
/// # Failure
///
/// The function fails if the library type already exists.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    loader_interface,
///    NULL
/// );
/// ASSERT_NE(
///    library_type,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_library_register_loader(
    const emf_cbase_library_loader_interface_t* EMF_CBASE_NOT_NULL loader_interface,
    const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type) EMF_CBASE_NOEXCEPT;

/// Unregisters an existing loader.
///
/// # Failure
///
/// The function fails if `loader_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t EMF_CBASE_CALL_C emf_cbase_library_unregister_loader(
    emf_cbase_library_loader_handle_t loader_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the number of registered loaders.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_library_get_num_loaders() EMF_CBASE_NOEXCEPT;

/// Copies the strings of the registered library types into a buffer.
///
/// Returns the number of copied elements.
///
/// # Failure
///
/// The function fails if `buffer` is smaller than `emf_cbase_library_get_num_loaders()`.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    buffer,
///    NULL
/// );
/// ASSERT_NE(
///    buffer->data,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_library_size_result_t EMF_CBASE_CALL_C emf_cbase_library_get_library_types(
    emf_cbase_library_type_span_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT;

/// Fetches the loader handle associated with the library type.
///
/// # Failure
///
/// The function fails if `library_type` is not registered.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    library_type,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_library_get_loader_handle(
    const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type) EMF_CBASE_NOEXCEPT;

/// Checks if a library type exists.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    library_type,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_library_type_exists(
    const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type) EMF_CBASE_NOEXCEPT;

/// Checks if a the library handle is valid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_library_library_exists(
    emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT;

/******************************************************************************************************
*************************************  Unsafe system operations  *************************************
******************************************************************************************************/

/// Creates a new unlinked library handle.
///
/// # Warning
///
/// The handle must be linked before use (See
/// [emf_cbase_library_unsafe_link_library()](./fn.emf_cbase_library_unsafe_link_library.md)).
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_library_handle_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_create_library_handle()
    EMF_CBASE_NOEXCEPT;

/// Removes an existing library handle.
///
/// # Failure
///
/// The function fails if `library_handle` is invalid.
///
/// # Warning
///
/// Removing the handle does not unload the library.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_remove_library_handle(
    emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT;

/// Links a library handle to an internal library handle.
///
/// Overrides the internal link of the library handle by setting it to the new library loader and internal handle.
///
/// # Failure
///
/// The function fails if `library_handle` or `loader_handle` are invalid.
///
/// # Warning
///
/// Incorrect usage can lead to dangling handles or use-after-free errors.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_link_library(
    emf_cbase_library_handle_t library_handle, emf_cbase_library_loader_handle_t loader_handle,
    emf_cbase_library_loader_library_handle_t loader_library_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the internal handle linked with the library handle.
///
/// # Failure
///
/// The function fails if `library_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_library_loader_library_handle_result_t EMF_CBASE_CALL_C
emf_cbase_library_unsafe_get_loader_library_handle(emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the loader handle linked with the library handle.
///
/// # Failure
///
/// The function fails if `library_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_get_loader_handle(
    emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the interface of a library loader.
///
/// # Failure
///
/// The function fails if `loader_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_library_loader_interface_result_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_get_loader_interface(
    emf_cbase_library_loader_handle_t loader_handle) EMF_CBASE_NOEXCEPT;

/******************************************************************************************************
*****************************************  Loader operations  *****************************************
******************************************************************************************************/

/// Loads a library.
///
/// The resulting handle is unique.
///
/// # Failure
///
/// The function fails if `loader_handle` or `library_path` is invalid or the type of the library can not be loaded by the loader.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    library_path,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_library_handle_result_t EMF_CBASE_CALL_C emf_cbase_library_load(
    emf_cbase_library_loader_handle_t loader_handle,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path) EMF_CBASE_NOEXCEPT;

/// Unloads a library.
///
/// # Failure
///
/// The function fails if `library_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t EMF_CBASE_CALL_C emf_cbase_library_unload(
    emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT;

/// Fetches a data symbol from a library.
///
/// Some platforms may differentiate between a `function-pointer` and a `data-pointer`.
/// See [emf_cbase_library_get_function_symbol()](./fn.emf_cbase_library_get_function_symbol.md) when fetching a function.
///
/// # Failure
///
/// The function fails if `library_handle` is invalid or library does not contain `symbol_name`.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    symbol_name,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_library_data_symbol_result_t EMF_CBASE_CALL_C emf_cbase_library_get_data_symbol(
    emf_cbase_library_handle_t library_handle, const char* EMF_CBASE_NOT_NULL symbol_name) EMF_CBASE_NOEXCEPT;

/// Fetches a data symbol from a library.
///
/// Some platforms may differentiate between a `function-pointer` and a `data-pointer`.
/// See [emf_cbase_library_get_data_symbol()](./fn.emf_cbase_library_get_data_symbol.md) when fetching some data.
///
/// # Failure
///
/// The function fails if `library_handle` is invalid or library does not contain `symbol_name`.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    symbol_name,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_library_fn_symbol_result_t EMF_CBASE_CALL_C emf_cbase_library_get_function_symbol(
    emf_cbase_library_handle_t library_handle, const char* EMF_CBASE_NOT_NULL symbol_name) EMF_CBASE_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BASE_EMF_CBASE_LIBRARY_H
