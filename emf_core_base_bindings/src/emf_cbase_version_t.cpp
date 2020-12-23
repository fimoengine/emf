#include <emf_core_base/emf_cbase_version_t.h>
#include <emf_core_base_bindings/emf_cbase_bindings.h>

using namespace EMF::CoreBase::C;

namespace EMF::CoreBase::Bindings::C {

extern "C" {

EMF_CBASE_NODISCARD emf_cbase_version_t EMF_CBASE_CALL_C emf_cbase_version_construct_short(
    int32_t major, int32_t minor, int32_t patch) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->version_construct_short_fn(emf_cbase_binding_interface->cbase, major, minor, patch);
}

EMF_CBASE_NODISCARD emf_cbase_version_t EMF_CBASE_CALL_C emf_cbase_version_construct_long(int32_t major, int32_t minor,
    int32_t patch, emf_cbase_version_release_t release_type, int8_t release_number) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->version_construct_long_fn(
        emf_cbase_binding_interface->cbase, major, minor, patch, release_type, release_number);
}

EMF_CBASE_NODISCARD emf_cbase_version_t EMF_CBASE_CALL_C emf_cbase_version_construct_full(int32_t major, int32_t minor,
    int32_t patch, emf_cbase_version_release_t release_type, int8_t release_number, int64_t build) EMF_CBASE_NOEXCEPT
{
    return emf_cbase_binding_interface->version_construct_full_fn(
        emf_cbase_binding_interface->cbase, major, minor, patch, release_type, release_number, build);
}

EMF_CBASE_NODISCARD emf_cbase_version_result_t EMF_CBASE_CALL_C emf_cbase_version_construct_from_string(
    const emf_cbase_version_const_string_buffer_t* EMF_CBASE_NOT_NULL version_string) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(version_string != nullptr, "emf_cbase_version_construct_from_string()")
    EMF_CBASE_ASSERT_ERROR(version_string->data != nullptr, "emf_cbase_version_construct_from_string()")
    return emf_cbase_binding_interface->version_construct_from_string_fn(emf_cbase_binding_interface->cbase, version_string);
}

EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_version_representation_is_valid(
    const emf_cbase_version_const_string_buffer_t* EMF_CBASE_NOT_NULL version_string) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(version_string != nullptr, "emf_cbase_version_representation_is_valid()")
    EMF_CBASE_ASSERT_ERROR(version_string->data != nullptr, "emf_cbase_version_representation_is_valid()")
    return emf_cbase_binding_interface->version_representation_is_valid_fn(emf_cbase_binding_interface->cbase, version_string);
}

EMF_CBASE_NODISCARD emf_cbase_version_size_result_t EMF_CBASE_CALL_C emf_cbase_version_get_short_representation(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(version != nullptr, "emf_cbase_version_get_short_representation()")
    EMF_CBASE_ASSERT_ERROR(buffer != nullptr, "emf_cbase_version_get_short_representation()")
    EMF_CBASE_ASSERT_ERROR(buffer->data != nullptr, "emf_cbase_version_get_short_representation()")
    return emf_cbase_binding_interface->version_get_short_representation_fn(emf_cbase_binding_interface->cbase, version, buffer);
}

EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_version_get_short_representation_length(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(version != nullptr, "emf_cbase_version_get_short_representation_length()")
    return emf_cbase_binding_interface->version_get_short_representation_length_fn(emf_cbase_binding_interface->cbase, version);
}

EMF_CBASE_NODISCARD emf_cbase_version_size_result_t EMF_CBASE_CALL_C emf_cbase_version_get_long_representation(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(version != nullptr, "emf_cbase_version_get_long_representation()")
    EMF_CBASE_ASSERT_ERROR(buffer != nullptr, "emf_cbase_version_get_long_representation()")
    EMF_CBASE_ASSERT_ERROR(buffer->data != nullptr, "emf_cbase_version_get_long_representation()")
    return emf_cbase_binding_interface->version_get_long_representation_fn(emf_cbase_binding_interface->cbase, version, buffer);
}

EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_version_get_long_representation_length(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(version != nullptr, "emf_cbase_version_get_long_representation_length()")
    return emf_cbase_binding_interface->version_get_long_representation_length_fn(emf_cbase_binding_interface->cbase, version);
}

EMF_CBASE_NODISCARD emf_cbase_version_size_result_t EMF_CBASE_CALL_C emf_cbase_version_get_full_representation(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(version != nullptr, "emf_cbase_version_get_full_representation()")
    EMF_CBASE_ASSERT_ERROR(buffer != nullptr, "emf_cbase_version_get_full_representation()")
    EMF_CBASE_ASSERT_ERROR(buffer->data != nullptr, "emf_cbase_version_get_full_representation()")
    return emf_cbase_binding_interface->version_get_full_representation_fn(emf_cbase_binding_interface->cbase, version, buffer);
}

EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_version_get_full_representation_length(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(version != nullptr, "emf_cbase_version_get_full_representation_length()")
    return emf_cbase_binding_interface->version_get_full_representation_length_fn(emf_cbase_binding_interface->cbase, version);
}

EMF_CBASE_NODISCARD int32_t EMF_CBASE_CALL_C emf_cbase_version_compare(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs, const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(lhs != nullptr, "emf_cbase_version_compare()")
    EMF_CBASE_ASSERT_ERROR(rhs != nullptr, "emf_cbase_version_compare()")
    return emf_cbase_binding_interface->version_compare_fn(emf_cbase_binding_interface->cbase, lhs, rhs);
}

EMF_CBASE_NODISCARD int32_t EMF_CBASE_CALL_C emf_cbase_version_compare_weak(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs, const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(lhs != nullptr, "emf_cbase_version_compare_weak()")
    EMF_CBASE_ASSERT_ERROR(rhs != nullptr, "emf_cbase_version_compare_weak()")
    return emf_cbase_binding_interface->version_compare_weak_fn(emf_cbase_binding_interface->cbase, lhs, rhs);
}

EMF_CBASE_NODISCARD int32_t EMF_CBASE_CALL_C emf_cbase_version_compare_strong(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs, const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(lhs != nullptr, "emf_cbase_version_compare_strong()")
    EMF_CBASE_ASSERT_ERROR(rhs != nullptr, "emf_cbase_version_compare_strong()")
    return emf_cbase_binding_interface->version_compare_strong_fn(emf_cbase_binding_interface->cbase, lhs, rhs);
}

EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_version_is_compatible(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs, const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs) EMF_CBASE_NOEXCEPT
{
    EMF_CBASE_ASSERT_ERROR(lhs != nullptr, "emf_cbase_version_is_compatible()")
    EMF_CBASE_ASSERT_ERROR(rhs != nullptr, "emf_cbase_version_is_compatible()")
    return emf_cbase_binding_interface->version_is_compatible_fn(emf_cbase_binding_interface->cbase, lhs, rhs);
}
}

}