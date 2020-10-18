#ifdef EMF_C_BINDINGS

#include "../../emf_core/include/emf_core/emf_library.h"
#include <emf_core/emf_binding.h>

namespace EMF::C {

extern "C" {

emf_library_loader_handle_t EMF_CALL_C emf_library_register_loader(
    const emf_library_loader_interface_t* EMF_NOT_NULL loader_interface,
    const emf_library_type_t* EMF_NOT_NULL library_type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(loader_interface != nullptr, "emf_library_register_loader()")
    EMF_ASSERT_ERROR(library_type != nullptr, "emf_library_register_loader()")
    EMF_ASSERT_ERROR(emf_library_type_exists(library_type) == emf_bool_false, "emf_library_register_loader()")
    return emf_binding_interface->library_register_loader_fn(loader_interface, library_type);
}

void EMF_CALL_C emf_library_unregister_loader(emf_library_loader_handle_t loader_handle) EMF_NOEXCEPT
{
    emf_binding_interface->library_unregister_loader_fn(loader_handle);
}

EMF_NODISCARD size_t EMF_CALL_C emf_library_get_num_loaders() EMF_NOEXCEPT
{
    return emf_binding_interface->library_get_num_loaders_fn();
}

size_t EMF_CALL_C emf_library_get_library_types(emf_library_type_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_library_get_library_types()")
    EMF_ASSERT_ERROR(buffer->length >= emf_library_get_num_loaders(), "emf_library_get_library_types()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_library_get_library_types()")
    return emf_binding_interface->library_get_library_types_fn(buffer);
}

EMF_NODISCARD emf_library_loader_handle_t EMF_CALL_C emf_library_get_loader_handle(
    const emf_library_type_t* EMF_NOT_NULL library_type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(library_type != nullptr, "emf_library_get_loader_handle()")
    EMF_ASSERT_ERROR(emf_library_type_exists(library_type) == emf_bool_true, "emf_library_get_loader_handle()")
    return emf_binding_interface->library_get_loader_handle_fn(library_type);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_library_type_exists(const emf_library_type_t* EMF_NOT_NULL library_type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(library_type != nullptr, "emf_library_type_exists()")
    return emf_binding_interface->library_type_exists_fn(library_type);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_library_library_exists(emf_library_handle_t library_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->library_library_exists_fn(library_handle);
}

EMF_NODISCARD emf_library_handle_t EMF_CALL_C emf_library_unsafe_create_library_handle() EMF_NOEXCEPT
{
    return emf_binding_interface->library_unsafe_create_library_handle_fn();
}

void EMF_CALL_C emf_library_unsafe_remove_library_handle(emf_library_handle_t library_handle) EMF_NOEXCEPT
{
    emf_binding_interface->library_unsafe_remove_library_handle_fn(library_handle);
}

void EMF_CALL_C emf_library_unsafe_link_library(emf_library_handle_t library_handle, emf_library_loader_handle_t loader_handle,
    emf_library_loader_library_handle_t loader_library_handle) EMF_NOEXCEPT
{
    emf_binding_interface->library_unsafe_link_library_fn(library_handle, loader_handle, loader_library_handle);
}

EMF_NODISCARD emf_library_loader_library_handle_t EMF_CALL_C emf_library_unsafe_get_loader_library_handle(
    emf_library_handle_t library_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->library_unsafe_get_loader_library_handle_fn(library_handle);
}

EMF_NODISCARD emf_library_loader_interface_t EMF_CALL_C emf_library_unsafe_get_loader(
    emf_library_loader_handle_t loader_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->library_unsafe_get_loader_fn(loader_handle);
}

EMF_NODISCARD emf_library_handle_t EMF_CALL_C emf_library_load(
    emf_library_loader_handle_t loader_handle, const emf_path_t* EMF_NOT_NULL library_path) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(library_path != nullptr, "emf_library_load()")
    return emf_binding_interface->library_load_fn(loader_handle, library_path);
}

void EMF_CALL_C emf_library_unload(emf_library_handle_t library_handle) EMF_NOEXCEPT
{
    emf_binding_interface->library_unload_fn(library_handle);
}

EMF_NODISCARD emf_error_t EMF_CALL_C emf_library_get_symbol(
    emf_library_handle_t library_handle, const char* EMF_NOT_NULL symbol_name, emf_symbol_t* EMF_NOT_NULL symbol) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(symbol_name != nullptr, "emf_library_get_symbol()")
    EMF_ASSERT_ERROR(symbol != nullptr, "emf_library_get_symbol()")
    return emf_binding_interface->library_get_symbol_fn(library_handle, symbol_name, symbol);
}

EMF_NODISCARD emf_error_t EMF_CALL_C emf_library_get_function_symbol(
    emf_library_handle_t library_handle, const char* EMF_NOT_NULL symbol_name, emf_fn_symbol_t* EMF_NOT_NULL symbol) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(symbol_name != nullptr, "emf_library_get_function_symbol()")
    EMF_ASSERT_ERROR(symbol != nullptr, "emf_library_get_function_symbol()")
    return emf_binding_interface->library_get_function_symbol_fn(library_handle, symbol_name, symbol);
}
}

}

#endif // EEMF_C_BINDINGS