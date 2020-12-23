#include <string>

#include <emf_core_base/emf_cbase_sys.h>
#include <emf_core_base/emf_cbase_version_t.h>
#include <emf_core_base_bindings/emf_cbase_bindings.h>
#include <emf_core_base_bindings/version.h>

using namespace EMF::CoreBase::C;

namespace EMF::CoreBase::Bindings::C {

constexpr emf_cbase_version_t s_emf_cbase_version { EMF_CORE_BASE_BINDINGS_VERSION_MAJOR, EMF_CORE_BASE_BINDINGS_VERSION_MINOR,
    EMF_CORE_BASE_BINDINGS_VERSION_PATCH, EMF_CORE_BASE_BINDINGS_BUILD, EMF_CORE_BASE_BINDINGS_PRE_RELEASE_NUMBER,
    static_cast<emf_cbase_version_release_t>(EMF_CORE_BASE_BINDINGS_PRE_RELEASE_TYPE) };
constexpr emf_cbase_interface_descriptor_t s_emf_core_interface_info {
    { EMF_CORE_BASE_INTERFACE_NAME, std::char_traits<char>::length(EMF_CORE_BASE_INTERFACE_NAME) }, s_emf_cbase_version,
    { nullptr, 0 }
};

extern "C" {

emf_cbase_interface_t emf_cbase_binding_interface_internal {};
const emf_cbase_interface_t* const EMF_CBASE_NOT_NULL emf_cbase_binding_interface { &emf_cbase_binding_interface_internal };

void EMF_CBASE_CALL_C emf_cbase_binding_initialize(emf_cbase_t* EMF_CBASE_MAYBE_NULL cbase,
    emf_cbase_sys_get_function_fn_t EMF_CBASE_NOT_NULL cbase_get_function_fn) EMF_CBASE_NOEXCEPT
{
    auto panic_opt { cbase_get_function_fn(cbase, emf_cbase_fn_ptr_id_sys_panic) };
    if (!panic_opt.has_value) {
        std::abort();
    }
    auto panic_fn { reinterpret_cast<emf_cbase_sys_panic_fn_t>(panic_opt.value) };

    auto module_get_exported_interface_handle_opt { cbase_get_function_fn(
        cbase, emf_cbase_fn_ptr_id_module_get_exported_interface_handle) };
    if (!module_get_exported_interface_handle_opt.has_value) {
        panic_fn(cbase, "Could not fetch the function pointer to `emf_cbase_module_get_exported_interface_handle`");
        std::abort();
    }
    auto module_get_exported_interface_handle_fn { reinterpret_cast<emf_cbase_module_get_exported_interface_handle_fn_t>(
        module_get_exported_interface_handle_opt.value) };

    auto module_get_interface_opt { cbase_get_function_fn(cbase, emf_cbase_fn_ptr_id_module_get_interface) };
    if (!module_get_interface_opt.has_value) {
        panic_fn(cbase, "Could not fetch the function pointer to `emf_cbase_module_get_interface`");
        std::abort();
    }
    auto module_get_interface_fn { reinterpret_cast<emf_cbase_module_get_interface_fn_t>(module_get_interface_opt.value) };

    emf_cbase_interface_t interface_buffer {};

    auto interface_handle_opt { module_get_exported_interface_handle_fn(cbase, &s_emf_core_interface_info) };
    if (interface_handle_opt.has_error) {
        panic_fn(cbase, "Could not fetch the handle to the '" EMF_CORE_BASE_INTERFACE_NAME "' interface module");
        std::abort();
    }
    auto interface_handle { interface_handle_opt.result };

    auto interface_opt { module_get_interface_fn(cbase, interface_handle, &s_emf_core_interface_info) };
    if (interface_opt.has_error) {
        panic_fn(cbase, "Could not initialize the bindings to the '" EMF_CORE_BASE_INTERFACE_NAME "' interface");
    }
    emf_cbase_binding_interface_internal = *static_cast<emf_cbase_interface_t*>(interface_opt.result.interface);
}
}

}