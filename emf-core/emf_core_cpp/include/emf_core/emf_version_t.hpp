#ifndef EMF_C_EMF_VERSION_T_HPP
#define EMF_C_EMF_VERSION_T_HPP

#ifdef __cplusplus

#include <emf_core/emf_version_t.h>

#include <span>
#include <string_view>

namespace EMF::Version {

/**
 * See emf_version_construct_short()
 */
EMF_NODISCARD inline C::emf_version_t construct(std::int32_t major, std::int32_t minor, std::int32_t patch) noexcept
{
    return C::emf_version_construct_short(major, minor, patch);
}

/**
 * See emf_version_construct_long()
 */
EMF_NODISCARD inline C::emf_version_t construct(std::int32_t major, std::int32_t minor, std::int32_t patch,
    C::emf_version_release_t release_type, std::int8_t release_number) noexcept
{
    return C::emf_version_construct_long(major, minor, patch, release_type, release_number);
}

/**
 * See emf_version_construct_full()
 */
EMF_NODISCARD inline C::emf_version_t construct(std::int32_t major, std::int32_t minor, std::int32_t patch,
    C::emf_version_release_t release_type, std::int8_t release_number, std::int64_t build) noexcept
{
    return C::emf_version_construct_full(major, minor, patch, release_type, release_number, build);
}

/**
 * See emf_version_construct_from_string()
 */
EMF_NODISCARD inline C::emf_version_t construct(std::string_view version_string) noexcept
{
    return C::emf_version_construct_from_string(version_string.data());
}

/**
 * See emf_version_representation_is_valid()
 */
EMF_NODISCARD inline bool is_valid(std::string_view version_string) noexcept
{
    return static_cast<bool>(C::emf_version_representation_is_valid(version_string.data()));
}

/**
 * See emf_version_get_short_representation()
 */
inline std::size_t to_string_short(const C::emf_version_t& version, std::span<char> buffer) noexcept
{
    C::emf_version_representation_buffer_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_version_get_short_representation(&version, &c_buffer);
}

/**
 * See emf_version_get_short_representation_size()
 */
EMF_NODISCARD std::size_t short_string_size(const C::emf_version_t& version) noexcept
{
    return C::emf_version_get_short_representation_size(&version);
}

/**
 * See emf_version_get_long_representation()
 */
inline std::size_t to_string_long(const C::emf_version_t& version, std::span<char> buffer) noexcept
{
    C::emf_version_representation_buffer_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_version_get_long_representation(&version, &c_buffer);
}

/**
 * See emf_version_get_long_representation_size()
 */
EMF_NODISCARD std::size_t long_string_size(const C::emf_version_t& version) noexcept
{
    return C::emf_version_get_long_representation_size(&version);
}

/**
 * See emf_version_get_full_representation()
 */
inline std::size_t to_string_full(const C::emf_version_t& version, std::span<char> buffer) noexcept
{
    C::emf_version_representation_buffer_t c_buffer { buffer.data(), buffer.size() };
    return C::emf_version_get_full_representation(&version, &c_buffer);
}

/**
 * See emf_version_get_full_representation_size()
 */
EMF_NODISCARD std::size_t full_string_size(const C::emf_version_t& version) noexcept
{
    return C::emf_version_get_full_representation_size(&version);
}

/**
 * See emf_version_compare()
 */
EMF_NODISCARD std::int32_t compare(const C::emf_version_t& lhs, const C::emf_version_t& rhs) noexcept
{
    return C::emf_version_compare(&lhs, &rhs);
}

/**
 * See emf_version_compare_weak()
 */
EMF_NODISCARD std::int32_t compare_weak(const C::emf_version_t& lhs, const C::emf_version_t& rhs) noexcept
{
    return C::emf_version_compare_weak(&lhs, &rhs);
}

/**
 * See emf_version_compare_strong()
 */
EMF_NODISCARD std::int32_t compare_strong(const C::emf_version_t& lhs, const C::emf_version_t& rhs) noexcept
{
    return C::emf_version_compare_strong(&lhs, &rhs);
}

/**
 * See emf_version_is_compatible()
 */
EMF_NODISCARD bool is_compatible(const C::emf_version_t& lhs, const C::emf_version_t& rhs) noexcept
{
    return static_cast<bool>(C::emf_version_is_compatible(&lhs, &rhs));
}

}

#endif // __cplusplus

#endif // !EMF_C_EMF_VERSION_T_HPP
