#ifndef EMF_C_EMF_LIBRARY_HPP
#define EMF_C_EMF_LIBRARY_HPP

#ifdef __cplusplus

#include <emf_core/emf_library.h>

#include <optional>
#include <span>
#include <string_view>

#include <emf_core/emf_fs.hpp>

namespace EMF::Library {

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/**
 * See emf_library_register_loader()
 */
inline C::emf_library_loader_handle_t register_loader(
    const C::emf_library_loader_interface_t& loader_interface, const C::emf_library_type_t& library_type) noexcept
{
    return C::emf_library_register_loader(&loader_interface, &library_type);
}

/**
 * See emf_library_unregister_loader()
 */
inline void unregister_loader(C::emf_library_loader_handle_t loader_handle) noexcept
{
    C::emf_library_unregister_loader(loader_handle);
}

/**
 * See emf_library_get_num_loaders()
 */
EMF_NODISCARD inline std::size_t get_num_loaders() noexcept { return C::emf_library_get_num_loaders(); }

/**
 * See emf_library_get_library_types()
 */
inline std::size_t get_library_types(std::span<C::emf_library_type_t> buffer) noexcept
{
    C::emf_library_type_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_library_get_library_types(&c_buffer);
}

/**
 * See emf_library_get_loader_handle()
 */
EMF_NODISCARD inline C::emf_library_loader_handle_t get_loader_handle(const C::emf_library_type_t& library_type) noexcept
{
    return C::emf_library_get_loader_handle(&library_type);
}

/**
 * See emf_library_type_exists()
 */
EMF_NODISCARD inline bool exists(const C::emf_library_type_t& library_type) noexcept
{
    return static_cast<bool>(C::emf_library_type_exists(&library_type));
}

/**
 * See emf_library_library_exists()
 */
EMF_NODISCARD inline bool exists(C::emf_library_handle_t library_handle) noexcept
{
    return static_cast<bool>(C::emf_library_library_exists(library_handle));
}

namespace Unsafe {

    /**
     * See emf_library_unsafe_create_library_handle()
     */
    EMF_NODISCARD inline C::emf_library_handle_t create_library_handle() noexcept
    {
        return C::emf_library_unsafe_create_library_handle();
    }

    /**
     * See emf_library_unsafe_remove_library_handle()
     */
    inline void remove_library_handle(C::emf_library_handle_t library_handle) noexcept
    {
        C::emf_library_unsafe_remove_library_handle(library_handle);
    }

    /**
     * See emf_library_unsafe_link_library()
     */
    inline void link_library(C::emf_library_handle_t library_handle, C::emf_library_loader_handle_t loader_handle,
        C::emf_library_loader_library_handle_t loader_library_handle) noexcept
    {
        C::emf_library_unsafe_link_library(library_handle, loader_handle, loader_library_handle);
    }

    /**
     * See emf_library_unsafe_get_loader_library_handle()
     */
    EMF_NODISCARD inline C::emf_library_loader_library_handle_t get_loader_library_handle(
        C::emf_library_handle_t library_handle) noexcept
    {
        return C::emf_library_unsafe_get_loader_library_handle(library_handle);
    }

    /**
     * See emf_library_unsafe_get_loader()
     */
    EMF_NODISCARD inline C::emf_library_loader_interface_t get_loader(C::emf_library_loader_handle_t loader_handle) noexcept
    {
        return C::emf_library_unsafe_get_loader(loader_handle);
    }

}

/**
 * See emf_library_load()
 */
EMF_NODISCARD inline C::emf_library_handle_t load(
    C::emf_library_loader_handle_t loader_handle, const C::emf_path_t& library_path) noexcept
{
    return C::emf_library_load(loader_handle, &library_path);
}

/**
 * See emf_library_unload()
 */
inline void unload(C::emf_library_handle_t library_handle) noexcept { C::emf_library_unload(library_handle); }

/**
 * See emf_library_get_symbol()
 */
EMF_NODISCARD inline std::optional<C::emf_symbol_t> get_symbol(
    C::emf_library_handle_t library_handle, std::string_view symbol_name) noexcept
{
    C::emf_symbol_t symbol { nullptr };
    if (C::emf_library_get_symbol(library_handle, symbol_name.data(), &symbol) == C::emf_error_none) {
        return symbol;
    } else {
        return std::nullopt;
    }
}

/**
 * See emf_library_get_function_symbol()
 */
EMF_NODISCARD inline std::optional<C::emf_fn_symbol_t> get_function_symbol(
    C::emf_library_handle_t library_handle, std::string_view symbol_name) noexcept
{
    C::emf_fn_symbol_t symbol { nullptr };
    if (C::emf_library_get_function_symbol(library_handle, symbol_name.data(), &symbol) == C::emf_error_none) {
        return symbol;
    } else {
        return std::nullopt;
    }
}

}

#endif // __cplusplus

#endif // !EMF_C_EMF_LIBRARY_HPP
