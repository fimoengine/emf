#include <emf_core_base/emf_cbase_module.h>
#include <emf_core_base_bindings/emf_cbase_bindings.h>

using namespace EMF::CoreBase::C;

namespace EMF::CoreBase::Bindings::C {

extern "C" {

EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_module_register_loader(
    const emf_cbase_module_loader_interface_t* EMF_CBASE_NOT_NULL loader_interface,
    const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(loader_interface != nullptr, "emf_cbase_module_register_loader()")
    EMF_CBASE_ASSERT_ERROR(module_type != nullptr, "emf_cbase_module_register_loader()")
    return emf_cbase_binding_interface->module_register_loader_fn(
        emf_cbase_binding_interface->cbase, loader_interface, module_type);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_unregister_loader(
    emf_cbase_module_loader_handle_t loader_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_unregister_loader_fn(emf_cbase_binding_interface->cbase, loader_handle);
}

EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_module_get_num_loaders() EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_get_num_loaders_fn(emf_cbase_binding_interface->cbase);
}

EMF_CBASE_NODISCARD emf_cbase_module_size_result_t EMF_CBASE_CALL_C emf_cbase_module_get_module_types(
    emf_cbase_module_type_span_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(buffer != nullptr, "emf_cbase_module_get_module_types()")
    EMF_CBASE_ASSERT_ERROR(buffer->data != nullptr, "emf_cbase_module_get_module_types()")
    return emf_cbase_binding_interface->module_get_module_types_fn(emf_cbase_binding_interface->cbase, buffer);
}

EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_module_get_num_modules() EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_get_num_modules_fn(emf_cbase_binding_interface->cbase);
}

EMF_CBASE_NODISCARD emf_cbase_module_size_result_t EMF_CBASE_CALL_C emf_cbase_module_get_modules(
    emf_cbase_module_info_span_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(buffer != nullptr, "emf_cbase_module_get_modules()")
    EMF_CBASE_ASSERT_ERROR(buffer->data != nullptr, "emf_cbase_module_get_modules()")
    return emf_cbase_binding_interface->module_get_modules_fn(emf_cbase_binding_interface->cbase, buffer);
}

EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_module_get_num_exported_interfaces() EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_get_num_exported_interfaces_fn(emf_cbase_binding_interface->cbase);
}

EMF_CBASE_NODISCARD emf_cbase_module_size_result_t EMF_CBASE_CALL_C emf_cbase_module_get_exported_interfaces(
    emf_cbase_interface_descriptor_span_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(buffer != nullptr, "emf_cbase_module_get_exported_interfaces()")
    EMF_CBASE_ASSERT_ERROR(buffer->data != nullptr, "emf_cbase_module_get_exported_interfaces()")
    return emf_cbase_binding_interface->module_get_exported_interfaces_fn(emf_cbase_binding_interface->cbase, buffer);
}

EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_module_get_loader_handle(
    const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(module_type != nullptr, "emf_cbase_module_get_loader_handle()")
    return emf_cbase_binding_interface->module_get_loader_handle_fn(emf_cbase_binding_interface->cbase, module_type);
}

EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_module_type_exists(
    const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(module_type != nullptr, "emf_cbase_module_type_exists()")
    return emf_cbase_binding_interface->module_type_exists_fn(emf_cbase_binding_interface->cbase, module_type);
}

EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_module_module_exists(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_module_exists_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_handle_result_t EMF_CBASE_CALL_C emf_cbase_module_get_exported_interface_handle(
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(interface != nullptr, "emf_cbase_module_get_exported_interface_handle()")
    return emf_cbase_binding_interface->module_get_exported_interface_handle_fn(emf_cbase_binding_interface->cbase, interface);
}

EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_module_exported_interface_exists(
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(interface != nullptr, "emf_cbase_module_exported_interface_exists()")
    return emf_cbase_binding_interface->module_exported_interface_exists_fn(emf_cbase_binding_interface->cbase, interface);
}

EMF_CBASE_NODISCARD emf_cbase_module_handle_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_create_module_handle() EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_unsafe_create_module_handle_fn(emf_cbase_binding_interface->cbase);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_remove_module_handle(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_unsafe_remove_module_handle_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_link_module(
    emf_cbase_module_handle_t module_handle, emf_cbase_module_loader_handle_t loader_handle,
    emf_cbase_module_loader_module_handle_t loader_module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_unsafe_link_module_fn(
        emf_cbase_binding_interface->cbase, module_handle, loader_handle, loader_module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_loader_module_handle_result_t EMF_CBASE_CALL_C
emf_cbase_module_unsafe_get_loader_module_handle(emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_unsafe_get_loader_module_handle_fn(
        emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_get_loader_handle(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_unsafe_get_loader_handle_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_loader_interface_result_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_get_loader(
    emf_cbase_module_loader_handle_t loader_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_unsafe_get_loader_fn(emf_cbase_binding_interface->cbase, loader_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_handle_result_t emf_cbase_module_add_module(emf_cbase_module_loader_handle_t loader_handle,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL module_path) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(module_path != nullptr, "emf_cbase_module_add_module()")
    return emf_cbase_binding_interface->module_add_module_fn(emf_cbase_binding_interface->cbase, loader_handle, module_path);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t emf_cbase_module_remove_module(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_remove_module_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t emf_cbase_module_get_load_dependencies(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_get_load_dependencies_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_status_result_t emf_cbase_module_fetch_status(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_fetch_status_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t emf_cbase_module_add_dependency(emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(interface_descriptor != nullptr, "emf_cbase_module_add_dependency()")
    return emf_cbase_binding_interface->module_add_dependency_fn(
        emf_cbase_binding_interface->cbase, module_handle, interface_descriptor);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t emf_cbase_module_remove_dependency(emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(interface_descriptor != nullptr, "emf_cbase_module_remove_dependency()")
    return emf_cbase_binding_interface->module_remove_dependency_fn(
        emf_cbase_binding_interface->cbase, module_handle, interface_descriptor);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t emf_cbase_module_export_interface(
    emf_cbase_module_handle_t module_handle, const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)
{
    EMF_CBASE_ASSERT_ERROR(interface_descriptor != nullptr, "emf_cbase_module_export_interface()")
    return emf_cbase_binding_interface->module_export_interface_fn(
        emf_cbase_binding_interface->cbase, module_handle, interface_descriptor);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_load(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_load_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_unload(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_unload_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_initialize(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_initialize_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_terminate(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_terminate_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_info_ptr_result_t EMF_CBASE_CALL_C emf_cbase_module_get_module_info(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_get_module_info_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t EMF_CBASE_CALL_C
emf_cbase_module_get_exportable_interfaces(emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_get_exportable_interfaces_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t EMF_CBASE_CALL_C emf_cbase_module_get_runtime_dependencies(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_get_runtime_dependencies_fn(emf_cbase_binding_interface->cbase, module_handle);
}

EMF_CBASE_NODISCARD emf_cbase_module_interface_result_t EMF_CBASE_CALL_C emf_cbase_module_get_interface(
    emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(interface_descriptor != nullptr, "emf_cbase_module_get_interface()")
    return emf_cbase_binding_interface->module_get_interface_fn(
        emf_cbase_binding_interface->cbase, module_handle, interface_descriptor);
}
}

EMF_CBASE_NODISCARD emf_cbase_os_path_char_result_t emf_cbase_module_get_module_path(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->module_get_module_path_fn(emf_cbase_binding_interface->cbase, module_handle);
}

}