#include <emf_core/emf_version_t.h>
#include <emf_core_bindings/emf_core_bindings.h>

using namespace EMF::Core::C;

namespace EMF::Core::Bindings::C {

extern "C" {

EMF_NODISCARD emf_version_t EMF_CALL_C emf_version_construct_short(int32_t major, int32_t minor, int32_t patch) EMF_NOEXCEPT
{
    return emf_binding_interface->version_construct_short_fn(major, minor, patch);
}

EMF_NODISCARD emf_version_t EMF_CALL_C emf_version_construct_long(
    int32_t major, int32_t minor, int32_t patch, emf_version_release_t release_type, int8_t release_number) EMF_NOEXCEPT
{
    return emf_binding_interface->version_construct_long_fn(major, minor, patch, release_type, release_number);
}

EMF_NODISCARD emf_version_t EMF_CALL_C emf_version_construct_full(int32_t major, int32_t minor, int32_t patch,
    emf_version_release_t release_type, int8_t release_number, int64_t build) EMF_NOEXCEPT
{
    return emf_binding_interface->version_construct_full_fn(major, minor, patch, release_type, release_number, build);
}

EMF_NODISCARD emf_version_t EMF_CALL_C emf_version_construct_from_string(const char* EMF_NOT_NULL version_string) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(version_string != nullptr, "emf_version_construct_from_string()")
    EMF_ASSERT_ERROR(emf_version_representation_is_valid(version_string) == emf_bool_true, "emf_version_construct_from_string()")
    return emf_binding_interface->version_construct_from_string_fn(version_string);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_version_representation_is_valid(const char* EMF_NOT_NULL version_string) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(version_string != nullptr, "emf_version_representation_is_valid()")
    return emf_binding_interface->version_representation_is_valid_fn(version_string);
}

size_t EMF_CALL_C emf_version_get_short_representation(
    const emf_version_t* EMF_NOT_NULL version, emf_version_representation_buffer_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(version != nullptr, "emf_version_get_short_representation()")
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_version_get_short_representation()")
    EMF_ASSERT_ERROR(
        buffer->length >= emf_version_get_short_representation_size(version) + 1, "emf_version_get_short_representation()")
    return emf_binding_interface->version_get_short_representation_fn(version, buffer);
}

EMF_NODISCARD size_t EMF_CALL_C emf_version_get_short_representation_size(const emf_version_t* EMF_NOT_NULL version) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(version != nullptr, "emf_version_get_short_representation_size()")
    return emf_binding_interface->version_get_short_representation_size_fn(version);
}

size_t EMF_CALL_C emf_version_get_long_representation(
    const emf_version_t* EMF_NOT_NULL version, emf_version_representation_buffer_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(version != nullptr, "emf_version_get_long_representation()")
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_version_get_long_representation()")
    EMF_ASSERT_ERROR(
        buffer->length >= emf_version_get_long_representation_size(version) + 1, "emf_version_get_long_representation()")
    return emf_binding_interface->version_get_long_representation_fn(version, buffer);
}

EMF_NODISCARD size_t EMF_CALL_C emf_version_get_long_representation_size(const emf_version_t* EMF_NOT_NULL version) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(version != nullptr, "emf_version_get_long_representation_size()")
    return emf_binding_interface->version_get_long_representation_size_fn(version);
}

size_t EMF_CALL_C emf_version_get_full_representation(
    const emf_version_t* EMF_NOT_NULL version, emf_version_representation_buffer_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(version != nullptr, "emf_version_get_full_representation()")
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_version_get_full_representation()")
    EMF_ASSERT_ERROR(
        buffer->length >= emf_version_get_full_representation_size(version) + 1, "emf_version_get_full_representation()")
    return emf_binding_interface->version_get_full_representation_fn(version, buffer);
}

EMF_NODISCARD size_t EMF_CALL_C emf_version_get_full_representation_size(const emf_version_t* EMF_NOT_NULL version) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(version != nullptr, "emf_version_get_full_representation_size()")
    return emf_binding_interface->version_get_full_representation_size_fn(version);
}

EMF_NODISCARD int32_t EMF_CALL_C emf_version_compare(
    const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(lhs != nullptr, "emf_version_compare()")
    EMF_ASSERT_ERROR(rhs != nullptr, "emf_version_compare()")
    return emf_binding_interface->version_compare_fn(lhs, rhs);
}

EMF_NODISCARD int32_t EMF_CALL_C emf_version_compare_weak(
    const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(lhs != nullptr, "emf_version_compare_weak()")
    EMF_ASSERT_ERROR(rhs != nullptr, "emf_version_compare_weak()")
    return emf_binding_interface->version_compare_weak_fn(lhs, rhs);
}

EMF_NODISCARD int32_t EMF_CALL_C emf_version_compare_strong(
    const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(lhs != nullptr, "emf_version_compare_strong()")
    EMF_ASSERT_ERROR(rhs != nullptr, "emf_version_compare_strong()")
    return emf_binding_interface->version_compare_strong_fn(lhs, rhs);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_version_is_compatible(
    const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(lhs != nullptr, "emf_version_is_compatible()")
    EMF_ASSERT_ERROR(rhs != nullptr, "emf_version_is_compatible()")
    return emf_binding_interface->version_is_compatible_fn(lhs, rhs);
}
}

}