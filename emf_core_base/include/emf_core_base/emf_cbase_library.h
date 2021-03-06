#ifndef EMF_CBASE_EMF_CBASE_LIBRARY_H
#define EMF_CBASE_EMF_CBASE_LIBRARY_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_bool_t.h>
#include <emf_core_base/emf_cbase_macros.h>

#define EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH 64

#define EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME "emf::core_base::native"

#define EMF_CBASE_LIBRARY_LOADER_DEFAULT_HANDLE                                                                                  \
    (emf_cbase_library_loader_handle_t) { emf_cbase_library_predefined_handles_native }

#if defined(Win32) || defined(_WIN32)
#define EMF_CBASE_OS_PATH_CHAR wchar_t
#else
#define EMF_CBASE_OS_PATH_CHAR char
#endif

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

typedef struct emf_cbase_t emf_cbase_t;
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_fn_t, void, void)

typedef enum emf_cbase_library_predefined_handles_t : int32_t {
    emf_cbase_library_predefined_handles_native = 0,
} emf_cbase_library_predefined_handles_t;

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

typedef EMF_CBASE_OS_PATH_CHAR emf_cbase_os_path_char_t;

typedef struct emf_cbase_library_handle_t {
    int32_t id;
} emf_cbase_library_handle_t;

typedef struct emf_cbase_library_loader_handle_t {
    int32_t id;
} emf_cbase_library_loader_handle_t;

typedef struct emf_cbase_internal_library_handle_t {
    intptr_t id;
} emf_cbase_internal_library_handle_t;

typedef struct emf_cbase_data_symbol_t {
    void* EMF_CBASE_NOT_NULL symbol;
} emf_cbase_data_symbol_t;

typedef struct emf_cbase_fn_symbol_t {
    emf_cbase_fn_t EMF_CBASE_NOT_NULL symbol;
} emf_cbase_fn_symbol_t;

EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_library_type_t, char, EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH)
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_library_type_span_t, emf_cbase_library_type_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_result_t, int8_t, emf_cbase_library_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_size_result_t, size_t, emf_cbase_library_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_handle_result_t, emf_cbase_library_handle_t, emf_cbase_library_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_loader_handle_result_t, emf_cbase_library_loader_handle_t, emf_cbase_library_error_t)
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_internal_library_handle_result_t, emf_cbase_internal_library_handle_t, emf_cbase_library_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_data_symbol_result_t, emf_cbase_data_symbol_t, emf_cbase_library_error_t)
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_fn_symbol_result_t, emf_cbase_fn_symbol_t, emf_cbase_library_error_t)

// library loader interface
typedef struct emf_cbase_library_loader_t emf_cbase_library_loader_t;

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_loader_interface_load_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_internal_library_handle_result_t,
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_loader_interface_unload_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_result_t,
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader, emf_cbase_internal_library_handle_t library_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_loader_interface_get_data_symbol_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_library_data_symbol_result_t, emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    emf_cbase_internal_library_handle_t library_handle, const char* EMF_CBASE_NOT_NULL symbol_name)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_loader_interface_get_function_symbol_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_library_fn_symbol_result_t, emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    emf_cbase_internal_library_handle_t library_handle, const char* EMF_CBASE_NOT_NULL symbol_name)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_loader_interface_get_internal_interface_fn_t,
    EMF_CBASE_NODISCARD const void* EMF_CBASE_NOT_NULL, emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader)

typedef struct emf_cbase_library_loader_interface_t {
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader;
    emf_cbase_library_loader_interface_load_fn_t EMF_CBASE_NOT_NULL load_fn;
    emf_cbase_library_loader_interface_unload_fn_t EMF_CBASE_NOT_NULL unload_fn;
    emf_cbase_library_loader_interface_get_data_symbol_fn_t EMF_CBASE_NOT_NULL get_data_symbol_fn;
    emf_cbase_library_loader_interface_get_function_symbol_fn_t EMF_CBASE_NOT_NULL get_function_fn;
    emf_cbase_library_loader_interface_get_internal_interface_fn_t EMF_CBASE_NOT_NULL get_internal_interface_fn;
} emf_cbase_library_loader_interface_t;

EMF_CBASE_RESULT_TYPEDEF(emf_cbase_library_loader_interface_result_t,
    const emf_cbase_library_loader_interface_t* EMF_CBASE_NOT_NULL, emf_cbase_library_error_t)

// native library loader interface
#if defined(Win32) || defined(_WIN32)
typedef void* emf_cbase_native_library_handle_fn_t;

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_library_loader_interface_load_ext_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_internal_library_handle_result_t,
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path, void* EMF_CBASE_MAYBE_NULL h_file, uint32_t flags)
#else
typedef void* emf_cbase_native_library_handle_fn_t;

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_library_loader_interface_load_ext_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_internal_library_handle_result_t,
    emf_cbase_library_loader_t* EMF_CBASE_MAYBE_NULL library_loader,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path, int flags)
#endif // defined(Win32) || defined(_WIN32)

EMF_CBASE_RESULT_TYPEDEF(emf_cbase_native_library_handle_result_t, emf_cbase_native_library_handle_fn_t EMF_CBASE_MAYBE_NULL,
    emf_cbase_library_error_t)

EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_library_loader_get_native_handle_fn_t, emf_cbase_native_library_handle_result_t,
    emf_cbase_library_loader_t*, library_loader, emf_cbase_internal_library_handle_t internal_handle)

typedef struct emf_cbase_native_library_loader_interface_t {
    const emf_cbase_library_loader_interface_t* EMF_CBASE_NOT_NULL library_loader_interface;
    emf_cbase_native_library_loader_interface_load_ext_fn_t EMF_CBASE_NOT_NULL load_ext_fn;
    emf_cbase_native_library_loader_get_native_handle_fn_t EMF_CBASE_NOT_NULL get_native_handle_fn;
} emf_cbase_native_library_loader_interface_t;

// library api
// loader management
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_register_loader_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_library_loader_interface_t* EMF_CBASE_NOT_NULL loader_interface,
    const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unregister_loader_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_loader_handle_t loader_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_loader_interface_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_library_loader_interface_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_library_loader_handle_t loader_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_loader_handle_from_type_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_loader_handle_from_library_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_library_handle_t library_handle)

// queries
EMF_CBASE_FUNCTION_PTR_T(
    emf_cbase_library_get_num_loaders_fn_t, EMF_CBASE_NODISCARD size_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_library_exists_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_type_exists_fn_t, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_library_types_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_size_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_type_span_t* EMF_CBASE_NOT_NULL buffer)

// internal library management
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_create_library_handle_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_handle_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_remove_library_handle_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_link_library_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle,
    emf_cbase_library_loader_handle_t loader_handle, emf_cbase_internal_library_handle_t internal_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_internal_library_handle_fn_t,
    EMF_CBASE_NODISCARD emf_cbase_internal_library_handle_result_t, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_library_handle_t library_handle)

// library management
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_load_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_handle_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_loader_handle_t loader_handle,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_unload_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_data_symbol_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_data_symbol_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle,
    const char* EMF_CBASE_NOT_NULL symbol_name)
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_library_get_function_symbol_fn_t, EMF_CBASE_NODISCARD emf_cbase_library_fn_symbol_result_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_library_handle_t library_handle,
    const char* EMF_CBASE_NOT_NULL symbol_name)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CBASE_EMF_CBASE_LIBRARY_H
