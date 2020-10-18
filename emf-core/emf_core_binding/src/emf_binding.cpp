#ifdef EMF_C_BINDINGS

#include <string>

#include <emf_core/emf_binding.h>
#include <emf_core/version.h>

namespace EMF::C {

constexpr emf_version_t s_emf_core_version { EMF_CORE_VERSION_MAJOR, EMF_CORE_VERSION_MINOR, EMF_CORE_VERSION_PATCH,
    EMF_CORE_BUILD, EMF_CORE_PRE_RELEASE_NUMBER, static_cast<emf_version_release_t>(EMF_CORE_PRE_RELEASE_TYPE) };
constexpr emf_interface_info_t s_emf_core_interface_info {
    { EMF_CORE_INTERFACE_NAME, std::char_traits<char>::length(EMF_CORE_INTERFACE_NAME) }, s_emf_core_version
};

extern "C" {

emf_core_interface_t emf_binding_interface_internal {};
const emf_core_interface_t* const EMF_NOT_NULL emf_binding_interface { &emf_binding_interface_internal };

void EMF_CALL_C emf_binding_initialize(emf_get_function_fn_t EMF_NOT_NULL get_function_fn) EMF_NOEXCEPT
{
    auto panic_fn { reinterpret_cast<emf_panic_fn_t>(get_function_fn(emf_fn_ptr_id_panic)) };

    auto module_get_interface_handle_fn { reinterpret_cast<emf_module_get_interface_handle_fn_t>(
        get_function_fn(emf_fn_ptr_id_module_get_interface_handle)) };
    auto module_get_interface_fn { reinterpret_cast<emf_module_get_interface_fn_t>(
        get_function_fn(emf_fn_ptr_id_module_get_interface)) };

    emf_interface_t interface_buffer {};
    auto interface_handle { module_get_interface_handle_fn(&s_emf_core_interface_info) };

    if (module_get_interface_fn(interface_handle, &s_emf_core_interface_info, &interface_buffer) != emf_error_none) {
        panic_fn("Could not initialize the bindings to the '" EMF_CORE_INTERFACE_NAME "' interface");
    } else {
        emf_binding_interface_internal = *static_cast<emf_core_interface_t*>(interface_buffer.interface);
    }
}
}

}

#endif // EMF_C_BINDINGS