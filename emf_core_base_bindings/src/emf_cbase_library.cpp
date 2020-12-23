#include <emf_core_base/emf_cbase_library.h>
#include <emf_core_base_bindings/emf_cbase_bindings.h>

using namespace EMF::CoreBase::C;

namespace EMF::CoreBase::Bindings::C {

extern "C" {

EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_library_register_loader(
    const emf_cbase_library_loader_interface_t* EMF_CBASE_NOT_NULL loader_interface,
    const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(loader_interface != nullptr, "emf_cbase_library_register_loader()")
    EMF_CBASE_ASSERT_ERROR(library_type != nullptr, "emf_cbase_library_register_loader()")
    return emf_cbase_binding_interface->library_register_loader_fn(
        emf_cbase_binding_interface->cbase, loader_interface, library_type);
}

EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t EMF_CBASE_CALL_C emf_cbase_library_unregister_loader(
    emf_cbase_library_loader_handle_t loader_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_unregister_loader_fn(emf_cbase_binding_interface->cbase, loader_handle);
}

EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_library_get_num_loaders() EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_get_num_loaders_fn(emf_cbase_binding_interface->cbase);
}

EMF_CBASE_NODISCARD emf_cbase_library_size_result_t EMF_CBASE_CALL_C emf_cbase_library_get_library_types(
    emf_cbase_library_type_span_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(buffer != nullptr, "emf_cbase_library_get_library_types()")
    EMF_CBASE_ASSERT_ERROR(buffer->data != nullptr, "emf_cbase_library_get_library_types()")
    return emf_cbase_binding_interface->library_get_library_types_fn(emf_cbase_binding_interface->cbase, buffer);
}

EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_library_get_loader_handle(
    const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(library_type != nullptr, "emf_cbase_library_get_loader_handle()")
    return emf_cbase_binding_interface->library_get_loader_handle_fn(emf_cbase_binding_interface->cbase, library_type);
}

EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_library_type_exists(
    const emf_cbase_library_type_t* EMF_CBASE_NOT_NULL library_type) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(library_type != nullptr, "emf_cbase_library_type_exists()")
    return emf_cbase_binding_interface->library_type_exists_fn(emf_cbase_binding_interface->cbase, library_type);
}

EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_library_library_exists(
    emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_library_exists_fn(emf_cbase_binding_interface->cbase, library_handle);
}

EMF_CBASE_NODISCARD emf_cbase_library_handle_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_create_library_handle()
    EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_unsafe_create_library_handle_fn(emf_cbase_binding_interface->cbase);
}

EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_remove_library_handle(
    emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_unsafe_remove_library_handle_fn(
        emf_cbase_binding_interface->cbase, library_handle);
}

EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_link_library(
    emf_cbase_library_handle_t library_handle, emf_cbase_library_loader_handle_t loader_handle,
    emf_cbase_library_loader_library_handle_t loader_library_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_unsafe_link_library_fn(
        emf_cbase_binding_interface->cbase, library_handle, loader_handle, loader_library_handle);
}

EMF_CBASE_NODISCARD emf_cbase_library_loader_library_handle_result_t EMF_CBASE_CALL_C
emf_cbase_library_unsafe_get_loader_library_handle(emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_unsafe_get_loader_library_handle_fn(
        emf_cbase_binding_interface->cbase, library_handle);
}

EMF_CBASE_NODISCARD emf_cbase_library_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_get_loader_handle(
    emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_unsafe_get_loader_handle_fn(emf_cbase_binding_interface->cbase, library_handle);
}

EMF_CBASE_NODISCARD emf_cbase_library_loader_interface_result_t EMF_CBASE_CALL_C emf_cbase_library_unsafe_get_loader_interface(
    emf_cbase_library_loader_handle_t loader_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_unsafe_get_loader_interface_fn(emf_cbase_binding_interface->cbase, loader_handle);
}

EMF_CBASE_NODISCARD emf_cbase_library_handle_result_t EMF_CBASE_CALL_C emf_cbase_library_load(
    emf_cbase_library_loader_handle_t loader_handle,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL library_path) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(library_path != nullptr, "emf_cbase_library_load()")
    return emf_cbase_binding_interface->library_load_fn(emf_cbase_binding_interface->cbase, loader_handle, library_path);
}

EMF_CBASE_NODISCARD emf_cbase_library_error_optional_t EMF_CBASE_CALL_C emf_cbase_library_unload(
    emf_cbase_library_handle_t library_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->library_unload_fn(emf_cbase_binding_interface->cbase, library_handle);
}

EMF_CBASE_NODISCARD emf_cbase_library_data_symbol_result_t EMF_CBASE_CALL_C emf_cbase_library_get_data_symbol(
    emf_cbase_library_handle_t library_handle, const char* EMF_CBASE_NOT_NULL symbol_name) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(symbol_name != nullptr, "emf_cbase_library_get_data_symbol()")
    return emf_cbase_binding_interface->library_get_data_symbol_fn(
        emf_cbase_binding_interface->cbase, library_handle, symbol_name);
}

EMF_CBASE_NODISCARD emf_cbase_library_fn_symbol_result_t EMF_CBASE_CALL_C emf_cbase_library_get_function_symbol(
    emf_cbase_library_handle_t library_handle, const char* EMF_CBASE_NOT_NULL symbol_name) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(symbol_name != nullptr, "emf_cbase_library_get_function_symbol()")
    return emf_cbase_binding_interface->library_get_function_symbol_fn(
        emf_cbase_binding_interface->cbase, library_handle, symbol_name);
}
}

}