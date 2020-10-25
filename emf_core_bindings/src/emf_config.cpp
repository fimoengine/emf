#include <emf_core/emf_config.h>
#include <emf_core_bindings/emf_core_bindings.h>

using namespace EMF::Core::C;

namespace EMF::Core::Bindings::C {

extern "C" {

void EMF_CALL_C emf_config_add_namespace(const emf_config_namespace_t* EMF_NOT_NULL group) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group != nullptr, "emf_config_add_namespace()")
    EMF_ASSERT_ERROR(emf_config_namespace_exists(group) == emf_bool_false, "emf_config_add_namespace()")
    emf_binding_interface->config_add_namespace_fn(group);
}

void EMF_CALL_C emf_config_remove_namespace(const emf_config_namespace_t* EMF_NOT_NULL group) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group != nullptr, "emf_config_remove_namespace()")
    EMF_ASSERT_ERROR(emf_config_namespace_exists(group) == emf_bool_true, "emf_config_remove_namespace()")
    emf_binding_interface->config_remove_namespace_fn(group);
}

void EMF_CALL_C emf_config_add_property_boolean(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, emf_bool_t default_value) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_add_property_boolean()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_add_property_boolean()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_false, "emf_config_add_property_boolean()")
    EMF_ASSERT_ERROR(array_size >= 1, "emf_config_add_property_boolean()")
    emf_binding_interface->config_add_property_boolean_fn(group, property, array_size, default_value);
}

void EMF_CALL_C emf_config_add_property_integer(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, int64_t default_value) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_add_property_integer()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_add_property_integer()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_false, "emf_config_add_property_integer()")
    EMF_ASSERT_ERROR(array_size >= 1, "emf_config_add_property_integer()")
    emf_binding_interface->config_add_property_integer_fn(group, property, array_size, default_value);
}

void EMF_CALL_C emf_config_add_property_real(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, double default_value) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_add_property_real()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_add_property_real()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_false, "emf_config_add_property_real()")
    EMF_ASSERT_ERROR(array_size >= 1, "emf_config_add_property_real()")
    emf_binding_interface->config_add_property_real_fn(group, property, array_size, default_value);
}

void EMF_CALL_C emf_config_add_property_string(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, size_t string_length,
    const emf_config_string_t* EMF_NOT_NULL default_value) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_add_property_string()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_add_property_string()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_false, "emf_config_add_property_string()")
    EMF_ASSERT_ERROR(array_size >= 1, "emf_config_add_property_string()")
    EMF_ASSERT_ERROR(string_length >= 1, "emf_config_add_property_string()")
    EMF_ASSERT_ERROR(default_value != nullptr, "emf_config_add_property_string()")
    emf_binding_interface->config_add_property_string_fn(group, property, array_size, string_length, default_value);
}

void EMF_CALL_C emf_config_remove_property(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_remove_property()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_remove_property()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_remove_property()")
    emf_binding_interface->config_remove_property_fn(group, property);
}

EMF_NODISCARD size_t EMF_CALL_C emf_config_get_num_namespaces(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_get_num_namespaces()")
    return emf_binding_interface->config_get_num_namespaces_fn(group, recursive);
}

size_t EMF_CALL_C emf_config_get_namespaces(const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive,
    emf_config_namespace_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_get_namespaces()")
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_config_get_namespaces()")
    EMF_ASSERT_ERROR(buffer->data != nullptr && buffer->length >= emf_config_get_num_namespaces(group, recursive),
        "emf_config_get_namespaces()")
    return emf_binding_interface->config_get_namespaces_fn(group, recursive, buffer);
}

EMF_NODISCARD size_t EMF_CALL_C emf_config_get_num_properties(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_get_num_properties()")
    return emf_binding_interface->config_get_num_properties_fn(group, recursive);
}

size_t EMF_CALL_C emf_config_get_properties(const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive,
    emf_config_property_info_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_get_properties()")
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_config_get_properties()")
    EMF_ASSERT_ERROR(buffer->data != nullptr && buffer->length >= emf_config_get_num_properties(group, recursive),
        "emf_config_get_properties()")
    return emf_binding_interface->config_get_properties_fn(group, recursive, buffer);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_config_namespace_exists(const emf_config_namespace_t* EMF_NOT_NULL group) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group != nullptr, "emf_config_namespace_exists()")
    return emf_binding_interface->config_namespace_exists_fn(group);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_config_property_exists(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group != nullptr, "emf_config_property_exists()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_property_exists()")
    return emf_binding_interface->config_property_exists_fn(group, property);
}

EMF_NODISCARD emf_config_property_type_t EMF_CALL_C emf_config_get_property_type(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_get_property_type()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_get_property_type()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_get_property_type()")
    return emf_binding_interface->config_get_property_type_fn(group, property);
}

EMF_NODISCARD size_t EMF_CALL_C emf_config_get_property_array_size(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(
        group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_get_property_array_size()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_get_property_array_size()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_get_property_array_size()")
    return emf_binding_interface->config_get_property_array_size_fn(group, property);
}

EMF_NODISCARD size_t EMF_CALL_C emf_config_get_property_string_size(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(
        group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_get_property_string_size()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_get_property_string_size()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_get_property_string_size()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_string, "emf_config_get_property_string_size()")
    EMF_ASSERT_ERROR(index < emf_config_get_property_array_size(group, property), "emf_config_get_property_string_size()")
    return emf_binding_interface->config_get_property_string_size_fn(group, property, index);
}

EMF_NODISCARD size_t EMF_CALL_C emf_config_get_property_string_max_size(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(
        group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_get_property_string_max_size()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_get_property_string_max_size()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_get_property_string_max_size()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_string, "emf_config_get_property_string_max_size()")
    return emf_binding_interface->config_get_property_string_max_size_fn(group, property);
}

EMF_NODISCARD emf_bool_t EMF_CALL_C emf_config_property_read_bool(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_property_read_bool()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_property_read_bool()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_property_read_bool()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_bool, "emf_config_property_read_bool()")
    EMF_ASSERT_ERROR(index < emf_config_get_property_array_size(group, property), "emf_config_property_read_bool()")
    return emf_binding_interface->config_property_read_bool_fn(group, property, index);
}

EMF_NODISCARD int64_t EMF_CALL_C emf_config_property_read_integer(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(
        group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_property_read_integer()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_property_read_integer()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_property_read_integer()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_integer, "emf_config_property_read_integer()")
    EMF_ASSERT_ERROR(index < emf_config_get_property_array_size(group, property), "emf_config_property_read_integer()")
    return emf_binding_interface->config_property_read_integer_fn(group, property, index);
}

EMF_NODISCARD double EMF_CALL_C emf_config_property_read_real(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_property_read_real()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_property_read_real()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_property_read_real()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_real, "emf_config_property_read_real()")
    EMF_ASSERT_ERROR(index < emf_config_get_property_array_size(group, property), "emf_config_property_read_real()")
    return emf_binding_interface->config_property_read_real_fn(group, property, index);
}

void EMF_CALL_C emf_config_property_read_string(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index,
    emf_config_string_buffer_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_property_read_string()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_property_read_string()")
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_config_property_read_string()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_property_read_string()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_string, "emf_config_property_read_string()")
    EMF_ASSERT_ERROR(index < emf_config_get_property_array_size(group, property), "emf_config_property_read_string()")
    EMF_ASSERT_ERROR(buffer->data != nullptr && buffer->length >= emf_config_get_property_string_size(group, property, index),
        "emf_config_property_read_string()")
    emf_binding_interface->config_property_read_string_fn(group, property, index, buffer);
}

void EMF_CALL_C emf_config_property_write_bool(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, emf_bool_t value) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_property_write_bool()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_property_write_bool()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_property_write_bool()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_bool, "emf_config_property_write_bool()")
    EMF_ASSERT_ERROR(index < emf_config_get_property_array_size(group, property), "emf_config_property_write_bool()")
    emf_binding_interface->config_property_write_bool_fn(group, property, index, value);
}

void EMF_CALL_C emf_config_property_write_integer(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, int64_t value) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(
        group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_property_write_integer()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_property_write_integer()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_property_write_integer()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_integer, "emf_config_property_write_integer()")
    EMF_ASSERT_ERROR(index < emf_config_get_property_array_size(group, property), "emf_config_property_write_integer()")
    emf_binding_interface->config_property_write_integer_fn(group, property, index, value);
}

void EMF_CALL_C emf_config_property_write_real(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, double value) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_property_write_real()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_property_write_real()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_property_write_real()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_real, "emf_config_property_write_real()")
    EMF_REQUIRE_ERROR(index < emf_config_get_property_array_size(group, property), "emf_config_property_write_real()")
    emf_binding_interface->config_property_write_real_fn(group, property, index, value);
}

void EMF_CALL_C emf_config_property_write_string(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, const emf_config_string_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT
{
    EMF_ASSERT_ERROR(
        group == nullptr || emf_config_namespace_exists(group) == emf_bool_true, "emf_config_property_write_string()")
    EMF_ASSERT_ERROR(property != nullptr, "emf_config_property_write_string()")
    EMF_ASSERT_ERROR(buffer != nullptr, "emf_config_property_write_string()")
    EMF_ASSERT_ERROR(emf_config_property_exists(group, property) == emf_bool_true, "emf_config_property_write_string()")
    EMF_ASSERT_ERROR(
        emf_config_get_property_type(group, property) == emf_config_prop_type_string, "emf_config_property_write_string()")
    EMF_REQUIRE_ERROR(index < emf_config_get_property_array_size(group, property), "emf_config_property_write_string()")
    EMF_REQUIRE_ERROR(buffer->data != nullptr, "emf_config_property_write_string()")
    emf_binding_interface->config_property_write_string_fn(group, property, index, buffer);
}
}

}