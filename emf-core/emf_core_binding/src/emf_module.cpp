#ifdef EMF_C_BINDINGS

#include "../../emf_core/include/emf_core/emf_module.h"
#include <emf_core/emf_binding.h>

namespace EMF::C {

extern "C" {

emf_module_loader_handle_t EMF_CALL_C emf_module_register_loader(
    const emf_module_loader_interface_t* EMF_NOT_NULL loader_interface,
    const emf_module_type_t* EMF_NOT_NULL module_type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(loader_interface != nullptr, "emf_module_register_loader()")
    EMF_ASSERT_ERROR(module_type != nullptr, "emf_module_register_loader()")
    EMF_ASSERT_ERROR(emf_module_type_exists(module_type) == emf_bool_false, "emf_module_register_loader()")
    return emf_binding_interface->module_register_loader_fn(loader_interface, module_type);
}

void EMF_CALL_C emf_module_unregister_loader(emf_module_loader_handle_t loader_handle) EMF_NOEXCEPT
{
    emf_binding_interface->module_unregister_loader_fn(loader_handle);
}

EMF_NODISCARD size_t EMF_CALL_C emf_module_get_num_loaders() EMF_NOEXCEPT
{
    return emf_binding_interface->module_get_num_loaders_fn();
}

size_t EMF_CALL_C emf_module_get_module_types(emf_module_type_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_module_get_module_types()")
    EMF_ASSERT_ERROR(buffer->length >= emf_module_get_num_loaders(), "emf_module_get_module_types()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_module_get_module_types()")
    return emf_binding_interface->module_get_module_types_fn(buffer);
}

EMF_NODISCARD size_t EMF_CALL_C emf_module_get_num_modules() EMF_NOEXCEPT
{
    return emf_binding_interface->module_get_num_modules_fn();
}

size_t EMF_CALL_C emf_module_get_modules(emf_module_info_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_module_get_modules()")
    EMF_ASSERT_ERROR(buffer->length >= emf_module_get_num_modules(), "emf_module_get_modules()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_module_get_modules()")
    return emf_binding_interface->module_get_modules_fn(buffer);
}

EMF_NODISCARD size_t EMF_CALL_C emf_module_get_num_public_interfaces() EMF_NOEXCEPT
{
    return emf_binding_interface->module_get_num_public_interfaces_fn();
}

size_t EMF_CALL_C emf_module_get_public_interfaces(emf_interface_descriptor_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_module_get_public_interfaces()")
    EMF_ASSERT_ERROR(buffer->length >= emf_module_get_num_public_interfaces(), "emf_module_get_public_interfaces()")
    EMF_ASSERT_ERROR(buffer->data != nullptr, "emf_module_get_public_interfaces()")
    return emf_binding_interface->module_get_public_interfaces_fn(buffer);
}

EMF_NODISCARD emf_module_loader_handle_t EMF_CALL_C emf_module_get_loader_handle(
    const emf_module_type_t* EMF_NOT_NULL module_type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(module_type != nullptr, "emf_module_get_loader_handle()")
    EMF_ASSERT_ERROR(emf_module_type_exists(module_type) == emf_bool_true, "emf_module_get_loader_handle()")
    return emf_binding_interface->module_get_loader_handle_fn(module_type);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_module_type_exists(const emf_module_type_t* EMF_NOT_NULL module_type) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(module_type != nullptr, "emf_module_type_exists()")
    return emf_binding_interface->module_type_exists_fn(module_type);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_module_module_exists(emf_module_handle_t module_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->module_module_exists_fn(module_handle);
}

EMF_NODISCARD emf_module_handle_t EMF_CALL_C emf_module_get_interface_handle(
    const emf_interface_info_t* EMF_NOT_NULL interface) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(interface != nullptr, "emf_module_get_interface_handle()")
    EMF_ASSERT_ERROR(emf_module_interface_exists(interface) == emf_bool_true, "emf_module_get_interface_handle()")
    return emf_binding_interface->module_get_interface_handle_fn(interface);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_module_interface_exists(const emf_interface_info_t* EMF_NOT_NULL interface) EMF_NOEXCEPT
{
    return emf_binding_interface->module_interface_exists_fn(interface);
}

EMF_NODISCARD emf_module_handle_t EMF_CALL_C emf_module_unsafe_create_module_handle() EMF_NOEXCEPT
{
    return emf_binding_interface->module_unsafe_create_module_handle_fn();
}

void EMF_CALL_C emf_module_unsafe_remove_module_handle(emf_module_handle_t module_handle) EMF_NOEXCEPT
{
    emf_binding_interface->module_unsafe_remove_module_handle_fn(module_handle);
}

void EMF_CALL_C emf_module_unsafe_link_module(emf_module_handle_t module_handle, emf_module_loader_handle_t loader_handle,
    emf_module_loader_module_handle_t loader_module_handle,
    const emf_interface_info_span_t* EMF_MAYBE_NULL public_interfaces) EMF_NOEXCEPT
{
#ifdef EMF_ENABLE_ERROR_CHECKING
    if (public_interfaces->data != nullptr && public_interfaces->length > 0) {
        for (std::size_t i { 0 }; i < public_interfaces->length; i++) {
            EMF_ASSERT_ERROR(
                emf_module_interface_exists(&public_interfaces->data[i]) == emf_bool_false, "emf_module_unsafe_link_module()")
        }
    }
#endif // EMF_ENABLE_ERROR_CHECKING

    emf_binding_interface->module_unsafe_link_module_fn(module_handle, loader_handle, loader_module_handle, public_interfaces);
}

EMF_NODISCARD emf_module_loader_module_handle_t EMF_CALL_C emf_module_unsafe_get_loader_module_handle(
    emf_module_handle_t module_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->module_unsafe_get_loader_module_handle_fn(module_handle);
}

EMF_NODISCARD emf_module_loader_interface_t EMF_CALL_C emf_module_unsafe_get_loader(
    emf_module_loader_handle_t loader_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->module_unsafe_get_loader_fn(loader_handle);
}

EMF_NODISCARD emf_module_handle_t EMF_CALL_C emf_module_load(emf_module_loader_handle_t loader_handle,
    const emf_interface_info_span_t* EMF_MAYBE_NULL public_interfaces, const emf_path_t* EMF_NOT_NULL module_path) EMF_NOEXCEPT
{
#ifdef EMF_ENABLE_ERROR_CHECKING
    if (public_interfaces->data != nullptr && public_interfaces->length > 0) {
        for (std::size_t i { 0 }; i < public_interfaces->length; i++) {
            EMF_ASSERT_ERROR(emf_module_interface_exists(&public_interfaces->data[i]) == emf_bool_false, "emf_module_load()")
        }
    }
#endif // EMF_ENABLE_ERROR_CHECKING

    EMF_ASSERT_ERROR(module_path != nullptr, "emf_module_load()")
    return emf_binding_interface->module_load_fn(loader_handle, public_interfaces, module_path);
}

void EMF_CALL_C emf_module_unload(emf_module_handle_t module_handle) EMF_NOEXCEPT
{
    emf_binding_interface->module_unload_fn(module_handle);
}

void EMF_CALL_C emf_module_initialize(emf_module_handle_t module_handle) EMF_NOEXCEPT
{
    emf_binding_interface->module_initialize_fn(module_handle);
}

void EMF_CALL_C emf_module_terminate(emf_module_handle_t module_handle) EMF_NOEXCEPT
{
    emf_binding_interface->module_terminate_fn(module_handle);
}

EMF_NODISCARD const emf_module_info_t* EMF_NOT_NULL EMF_CALL_C emf_module_get_module_info(
    emf_module_handle_t module_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->module_get_module_info_fn(module_handle);
}

EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL EMF_CALL_C emf_module_get_exported_interfaces(
    emf_module_handle_t module_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->module_get_exported_interfaces_fn(module_handle);
}

EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL EMF_CALL_C emf_module_get_imported_interfaces(
    emf_module_handle_t module_handle) EMF_NOEXCEPT
{
    return emf_binding_interface->module_get_imported_interfaces_fn(module_handle);
}

EMF_NODISCARD emf_error_t EMF_CALL_C emf_module_get_interface(emf_module_handle_t module_handle,
    const emf_interface_info_t* EMF_NOT_NULL interface_info, emf_interface_t* EMF_NOT_NULL interface) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(interface_info != nullptr, "emf_module_get_interface()")
    EMF_ASSERT_ERROR(interface != nullptr, "emf_module_get_interface()")
    return emf_binding_interface->module_get_interface_fn(module_handle, interface_info, interface);
}
}

}

#endif // EMF_C_BINDINGS