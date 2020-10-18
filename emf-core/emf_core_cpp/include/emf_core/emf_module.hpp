#ifndef EMF_C_EMF_MODULE_HPP
#define EMF_C_EMF_MODULE_HPP

#ifdef __cplusplus

#include <emf_core/emf_module.h>

#include <optional>
#include <span>

#include <emf_core/emf_library.hpp>

namespace EMF::Module {

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/**
 * See emf_module_register_loader()
 */
C::emf_module_loader_handle_t register_loader(
    const C::emf_module_loader_interface_t& loader_interface, const C::emf_module_type_t& module_type) noexcept
{
    return C::emf_module_register_loader(&loader_interface, &module_type);
}

/**
 * See emf_module_unregister_loader()
 */
void unregister_loader(C::emf_module_loader_handle_t loader_handle) noexcept { C::emf_module_unregister_loader(loader_handle); }

/**
 * See emf_module_get_num_loaders()
 */
EMF_NODISCARD std::size_t get_num_loaders() noexcept { return C::emf_module_get_num_loaders(); }

/**
 * See emf_module_get_module_types()
 */
std::size_t get_module_types(std::span<C::emf_module_type_t> buffer) noexcept
{
    C::emf_module_type_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_module_get_module_types(&c_buffer);
}

/**
 * See emf_module_get_num_modules()
 */
EMF_NODISCARD std::size_t get_num_modules() noexcept { return C::emf_module_get_num_modules(); }

/**
 * See emf_module_get_modules()
 */
std::size_t get_modules(std::span<C::emf_module_info_t> buffer) noexcept
{
    C::emf_module_info_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_module_get_modules(&c_buffer);
}

/**
 * See emf_module_get_num_public_interfaces()
 */
EMF_NODISCARD std::size_t get_num_public_interfaces() noexcept { return C::emf_module_get_num_public_interfaces(); }

/**
 * See emf_module_get_public_interfaces()
 */
std::size_t get_public_interfaces(std::span<C::emf_interface_descriptor_t> buffer) noexcept
{
    C::emf_interface_descriptor_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_module_get_public_interfaces(&c_buffer);
}

/**
 * See emf_module_get_loader_handle()
 */
EMF_NODISCARD C::emf_module_loader_handle_t get_loader_handle(const C::emf_module_type_t& module_type) noexcept
{
    return C::emf_module_get_loader_handle(&module_type);
}

/**
 * See emf_module_type_exists()
 */
EMF_NODISCARD bool type_exists(const C::emf_module_type_t& module_type) noexcept
{
    return static_cast<bool>(C::emf_module_type_exists(&module_type));
}

/**
 * See emf_module_module_exists()
 */
EMF_NODISCARD bool module_exists(C::emf_module_handle_t module_handle) noexcept
{
    return static_cast<bool>(C::emf_module_module_exists(module_handle));
}

/**
 * See emf_module_get_interface_handle()
 */
EMF_NODISCARD C::emf_module_handle_t get_interface_handle(const C::emf_interface_info_t& interface) noexcept
{
    return C::emf_module_get_interface_handle(&interface);
}

/**
 * See emf_module_interface_exists()
 */
EMF_NODISCARD bool interface_exists(const C::emf_interface_info_t& interface) noexcept
{
    return static_cast<bool>(C::emf_module_interface_exists(&interface));
}

namespace Unsafe {

    /**
     * See emf_module_unsafe_create_module_handle()
     */
    EMF_NODISCARD C::emf_module_handle_t create_module_handle() noexcept { return C::emf_module_unsafe_create_module_handle(); }

    /**
     * See emf_module_unsafe_remove_module_handle()
     */
    void remove_module_handle(C::emf_module_handle_t module_handle) noexcept
    {
        C::emf_module_unsafe_remove_module_handle(module_handle);
    }

    /**
     * See emf_module_unsafe_link_module()
     */
    void link_module(C::emf_module_handle_t module_handle, C::emf_module_loader_handle_t loader_handle,
        C::emf_module_loader_module_handle_t loader_module_handle,
        std::span<const C::emf_interface_info_t> public_interfaces) noexcept
    {
        const C::emf_interface_info_span_t c_public_interfaces { public_interfaces.data(), public_interfaces.size() };
        C::emf_module_unsafe_link_module(module_handle, loader_handle, loader_module_handle, &c_public_interfaces);
    }

    /**
     * See emf_module_unsafe_get_loader_module_handle()
     */
    EMF_NODISCARD C::emf_module_loader_module_handle_t get_loader_module_handle(C::emf_module_handle_t module_handle) noexcept
    {
        return C::emf_module_unsafe_get_loader_module_handle(module_handle);
    }

    /**
     * See emf_module_unsafe_get_loader()
     */
    EMF_NODISCARD C::emf_module_loader_interface_t get_loader(C::emf_module_loader_handle_t loader_handle) noexcept
    {
        return C::emf_module_unsafe_get_loader(loader_handle);
    }

}

/**
 * See emf_module_load()
 */
EMF_NODISCARD C::emf_module_handle_t load(C::emf_module_loader_handle_t loader_handle,
    std::span<const C::emf_interface_info_t> public_interfaces, const C::emf_path_t& module_path) noexcept
{
    const C::emf_interface_info_span_t c_public_interfaces { public_interfaces.data(), public_interfaces.size() };
    return C::emf_module_load(loader_handle, &c_public_interfaces, &module_path);
}

/**
 * See emf_module_unload()
 */
void unload(C::emf_module_handle_t module_handle) noexcept { C::emf_module_unload(module_handle); }

/**
 * See emf_module_initialize()
 */
void initialize(C::emf_module_handle_t module_handle) noexcept { C::emf_module_initialize(module_handle); }

/**
 * See emf_module_terminate()
 */
void terminate(C::emf_module_handle_t module_handle) noexcept { C::emf_module_terminate(module_handle); }

/**
 * See emf_module_get_module_info()
 */
EMF_NODISCARD const C::emf_module_info_t& get_module_info(C::emf_module_handle_t module_handle) noexcept
{
    return *C::emf_module_get_module_info(module_handle);
}

/**
 * See emf_module_get_exported_interfaces()
 */
EMF_NODISCARD std::span<const C::emf_interface_descriptor_t> get_exported_interfaces(
    C::emf_module_handle_t module_handle) noexcept
{
    auto c_span { C::emf_module_get_exported_interfaces(module_handle) };
    return std::span<const C::emf_interface_descriptor_t> { c_span->data, c_span->size };
}

/**
 * See emf_module_get_imported_interfaces()
 */
EMF_NODISCARD std::span<const C::emf_interface_descriptor_t> get_imported_interfaces(
    C::emf_module_handle_t module_handle) noexcept
{
    auto c_span { C::emf_module_get_imported_interfaces(module_handle) };
    return std::span<const C::emf_interface_descriptor_t> { c_span->data, c_span->size };
}

/**
 * See emf_module_get_interface()
 */
EMF_NODISCARD std::optional<C::emf_interface_t> get_interface(
    C::emf_module_handle_t module_handle, const C::emf_interface_info_t& interface_info) noexcept
{
    C::emf_interface_t interface {};
    if (C::emf_module_get_interface(module_handle, &interface_info, &interface) == C::emf_error_none) {
        return interface;
    } else {
        return std::nullopt;
    }
}

}

#endif // __cplusplus

#endif // !EMF_C_EMF_MODULE_HPP
