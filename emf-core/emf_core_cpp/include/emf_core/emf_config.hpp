#ifndef EMF_C_EMF_CONFIG_HPP
#define EMF_C_EMF_CONFIG_HPP

#ifdef __cplusplus

#include <emf_core/emf_config.h>

#include <optional>
#include <span>

namespace EMF::Config {

/**
 * See emf_config_add_namespace()
 */
inline void add_namespace(const C::emf_config_namespace_t& group) noexcept { C::emf_config_add_namespace(&group); }

/**
 * See emf_config_remove_namespace()
 */
inline void remove_namespace(const C::emf_config_namespace_t& group) noexcept { C::emf_config_remove_namespace(&group); }

/**
 * See emf_config_add_property_boolean()
 */
inline void add_property(const C::emf_config_namespace_t& group, const C::emf_config_property_t& property, std::size_t array_size,
    bool default_value) noexcept
{
    C::emf_config_add_property_boolean(&group, &property, array_size, static_cast<C::emf_bool_t>(default_value));
}

/**
 * See emf_config_add_property_integer()
 */
inline void add_property(const C::emf_config_namespace_t& group, const C::emf_config_property_t& property, std::size_t array_size,
    std::int64_t default_value) noexcept
{
    C::emf_config_add_property_integer(&group, &property, array_size, default_value);
}

/**
 * See emf_config_add_property_real()
 */
inline void add_property(const C::emf_config_namespace_t& group, const C::emf_config_property_t& property, std::size_t array_size,
    double default_value) noexcept
{
    C::emf_config_add_property_real(&group, &property, array_size, default_value);
}

/**
 * See emf_config_add_property_string()
 */
inline void add_property(const C::emf_config_namespace_t& group, const C::emf_config_property_t& property, std::size_t array_size,
    size_t string_length, std::span<const char> default_value) noexcept
{
    const C::emf_config_string_t c_value { default_value.data(), default_value.size() };
    C::emf_config_add_property_string(&group, &property, array_size, string_length, &c_value);
}

/**
 * See emf_config_remove_property()
 */
inline void remove_property(const C::emf_config_namespace_t& group, const C::emf_config_property_t& property) noexcept
{
    C::emf_config_remove_property(&group, &property);
}

/**
 * See emf_config_get_num_namespaces()
 */
EMF_NODISCARD inline std::size_t get_num_namespaces(
    std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group, bool recursive) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };

    return C::emf_config_get_num_namespaces(group_ptr, static_cast<C::emf_bool_t>(recursive));
}

/**
 * See emf_config_get_namespaces()
 */
inline std::size_t get_namespaces(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group, bool recursive,
    std::span<C::emf_config_namespace_t> buffer) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    C::emf_config_namespace_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_config_get_namespaces(group_ptr, static_cast<C::emf_bool_t>(recursive), &c_buffer);
}

/**
 * See emf_config_get_num_properties()
 */
EMF_NODISCARD inline std::size_t get_num_properties(
    std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group, bool recursive) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };

    return C::emf_config_get_num_properties(group_ptr, static_cast<C::emf_bool_t>(recursive));
}

/**
 * See emf_config_get_properties()
 */
inline std::size_t get_properties(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group, bool recursive,
    std::span<C::emf_config_property_info_t> buffer) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    C::emf_config_property_info_span_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_config_get_properties(group_ptr, static_cast<C::emf_bool_t>(recursive), &c_buffer);
}

/**
 * See emf_config_namespace_exists()
 */
EMF_NODISCARD inline bool namespace_exists(const C::emf_config_namespace_t& group) noexcept
{
    return static_cast<bool>(C::emf_config_namespace_exists(&group));
}

/**
 * See emf_config_property_exists()
 */
EMF_NODISCARD inline bool property_exists(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    return static_cast<bool>(C::emf_config_property_exists(group_ptr, &property));
}

/**
 * See emf_config_get_property_type()
 */
EMF_NODISCARD inline C::emf_config_property_type_t get_property_type(
    std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    return C::emf_config_get_property_type(group_ptr, &property);
}

/**
 * See emf_config_get_property_array_size()
 */
EMF_NODISCARD inline std::size_t get_property_array_size(
    std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    return C::emf_config_get_property_array_size(group_ptr, &property);
}

/**
 * See emf_config_get_property_string_size()
 */
EMF_NODISCARD inline std::size_t get_property_string_size(
    std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group, const C::emf_config_property_t& property,
    std::size_t idx) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    return C::emf_config_get_property_string_size(group_ptr, &property, idx);
}

/**
 * See emf_config_get_property_string_max_size()
 */
EMF_NODISCARD inline std::size_t get_property_string_max_size(
    std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    return C::emf_config_get_property_string_max_size(group_ptr, &property);
}

/**
 * See emf_config_property_read_bool()
 */
EMF_NODISCARD inline bool property_read_bool(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property, std::size_t idx) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    return static_cast<bool>(C::emf_config_property_read_bool(group_ptr, &property, idx));
}

/**
 * See emf_config_property_read_integer()
 */
EMF_NODISCARD inline std::int64_t property_read_integer(
    std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group, const C::emf_config_property_t& property,
    std::size_t idx) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    return C::emf_config_property_read_integer(group_ptr, &property, idx);
}

/**
 * See emf_config_property_read_real()
 */
EMF_NODISCARD inline double property_read_real(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property, std::size_t idx) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    return C::emf_config_property_read_real(group_ptr, &property, idx);
}

/**
 * See emf_config_property_read_string()
 */
inline void property_read_string(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property, std::size_t idx, std::span<char> buffer) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    C::emf_config_string_buffer_t c_buffer { buffer.data(), buffer.size() };
    C::emf_config_property_read_string(group_ptr, &property, idx, &c_buffer);
}

/**
 * See emf_config_property_write_bool()
 */
inline void property_write(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property, std::size_t idx, bool value) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    C::emf_config_property_write_bool(group_ptr, &property, idx, static_cast<C::emf_bool_t>(value));
}

/**
 * See emf_config_property_write_integer()
 */
inline void property_write(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property, std::size_t idx, std::int64_t value) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    C::emf_config_property_write_integer(group_ptr, &property, idx, value);
}

/**
 * See emf_config_property_write_real()
 */
inline void property_write(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property, std::size_t idx, double value) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    C::emf_config_property_write_real(group_ptr, &property, idx, value);
}

/**
 * See emf_config_property_write_string()
 */
inline void property_write(std::optional<std::reference_wrapper<const C::emf_config_namespace_t>> group,
    const C::emf_config_property_t& property, std::size_t idx, std::span<const char> buffer) noexcept
{
    auto group_ptr { group ? &group->get() : nullptr };
    const C::emf_config_string_t c_buffer { buffer.data(), buffer.size() };
    C::emf_config_property_write_string(group_ptr, &property, idx, &c_buffer);
}

}

#endif // __cplusplus

#endif // !EMF_C_EMF_CONFIG_HPP
