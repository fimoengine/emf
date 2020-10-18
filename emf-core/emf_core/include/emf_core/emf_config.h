#ifndef EMF_INTERFACE_C_EMF_CONFIG_H
#define EMF_INTERFACE_C_EMF_CONFIG_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core/emf_bool_t.h>
#include <emf_core/emf_error_t.h>
#include <emf_core/emf_macros.h>

#define EMF_CONFIG_NAMESPACE_MAX_LENGTH 128
#define EMF_CONFIG_PROPERTY_MAX_LENGTH 32

#ifdef __cplusplus
namespace EMF::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

/**
 * The name of a namespace.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_config_namespace_t, char, EMF_CONFIG_NAMESPACE_MAX_LENGTH)

/**
 * The name of a property.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_config_property_t, char, EMF_CONFIG_PROPERTY_MAX_LENGTH)

/**
 * The type of a property.
 */
typedef enum emf_config_property_type_t : int32_t {
    /// Boolean property.
    emf_config_prop_type_bool = 0,
    /// Integer property.
    emf_config_prop_type_integer = 1,
    /// Real property.
    emf_config_prop_type_real = 2,
    /// String property
    emf_config_prop_type_string = 3,
} emf_config_property_type_t;

/**
 * Information of a property.
 */
typedef struct emf_config_property_info_t {
    /// Namespace of the property.
    emf_config_namespace_t group;
    /// Name of the property.
    emf_config_property_t property;
    /// Type of the property.
    emf_config_property_type_t property_type;
    /// Property array size.
    size_t size;
} emf_config_property_info_t;

/**
 * A span of namespaces.
 */
EMF_SPAN_TYPEDEF(emf_config_namespace_span_t, emf_config_namespace_t)

/**
 * A span of property infos.
 */
EMF_SPAN_TYPEDEF(emf_config_property_info_span_t, emf_config_property_info_t)

/**
 * A string.
 */
EMF_SPAN_TYPEDEF(emf_config_string_t, const char)

/*
 * A buffer for containing strings.
 */
EMF_SPAN_TYPEDEF(emf_config_string_buffer_t, char)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/**
 * @brief Creates a new namespace
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_namespace_exists(group) == emf_bool_false</code>.
 *
 * @post A new namespace is added.
 *
 * @param group Namespace.
 */
void EMF_CALL_C emf_config_add_namespace(const emf_config_namespace_t* EMF_NOT_NULL group) EMF_NOEXCEPT;

/**
 * @brief Removes an existing namespace
 *
 * Removes an existing namespace, its properties and sub-namespaces.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 *
 * @post The namespace is removed.
 *
 * @param group Namespace.
 */
void EMF_CALL_C emf_config_remove_namespace(const emf_config_namespace_t* EMF_NOT_NULL group) EMF_NOEXCEPT;

/**
 * @brief Adds a new property to a namespace
 *
 * @note Requires synchronisation.
 * @note If no namespace is passed, the property will be added to the global scope.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_false</code>.
 * @pre <code>array_size >= 1</code>.
 *
 * @post A new property is added.
 * @post The property is initialized with default_value.
 *
 * @param group Namespace.
 * @param property Property.
 * @param array_size Size.
 * @param default_value Value.
 */
void EMF_CALL_C emf_config_add_property_boolean(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, emf_bool_t default_value) EMF_NOEXCEPT;

/**
 * @brief Adds a new property to a namespace
 *
 * @note Requires synchronisation.
 * @note If no namespace is passed, the property will be added to the global scope.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_false</code>.
 * @pre <code>array_size >= 1</code>.
 *
 * @post A new property is added.
 * @post The property is initialized with default_value.
 *
 * @param group Namespace.
 * @param property Property.
 * @param array_size Size.
 * @param default_value Value.
 */
void EMF_CALL_C emf_config_add_property_integer(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, int64_t default_value) EMF_NOEXCEPT;

/**
 * @brief Adds a new property to a namespace
 *
 * @note Requires synchronisation.
 * @note If no namespace is passed, the property will be added to the global scope.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_false</code>.
 * @pre <code>array_size >= 1</code>.
 *
 * @post A new property is added.
 * @post The property is initialized with default_value.
 *
 * @param group Namespace.
 * @param property Property.
 * @param array_size Size.
 * @param default_value Value.
 */
void EMF_CALL_C emf_config_add_property_real(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, double default_value) EMF_NOEXCEPT;

/**
 * @brief Adds a new property to a namespace.
 *
 * @note Requires synchronisation.
 * @note If no namespace is passed, the property will be added to the global scope.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_false</code>.
 * @pre <code>array_size >= 1</code>.
 * @pre <code>string_length >= 1</code>.
 * @pre <code>default_value</code> may not be <code>NULL</code>.
 *
 * @post A new property is added.
 * @post The property is initialized with up to <code>string_length</code> characters of default_value.
 *
 * @param group Namespace.
 * @param property Property.
 * @param array_size Size.
 * @param string_length Max length of the string.
 * @param default_value Value.
 */
void EMF_CALL_C emf_config_add_property_string(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, size_t string_length,
    const emf_config_string_t* EMF_NOT_NULL default_value) EMF_NOEXCEPT;

/**
 * @brief Removes a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 *
 * @post The property is removed.
 *
 * @param group Namespace.
 * @param property Property.
 */
void EMF_CALL_C emf_config_remove_property(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/**
 * @brief Retrieves the number of namespaces.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 *
 * @param group Namespace.
 * @param recursive Count recursively.
 *
 * @return Number of namespaces.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_num_namespaces(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive) EMF_NOEXCEPT;

/**
 * @brief Copies all namespaces into a buffer.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.data != NULL</code> and <code>buffer.length >= emf_config_get_num_namespaces(group, recursive)</code>.
 *
 * @post The namespaces are copied into <code>buffer</code>.
 *
 * @param group Namespace.
 * @param recursive Copy recursively.
 * @param buffer Buffer.
 *
 * @return Number of namespaces.
 */
size_t EMF_CALL_C emf_config_get_namespaces(const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive,
    emf_config_namespace_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Retrieves the number of properties in a namespace.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 *
 * @param group Namespace.
 * @param recursive Count recursively.
 *
 * @return Number of properties.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_num_properties(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive) EMF_NOEXCEPT;

/**
 * @brief Copies all properties into a buffer.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.data != NULL</code> and <code>buffer.length >= emf_config_get_num_properties(group, recursive)</code>.
 *
 * @post The properties are copied into <code>buffer</code>.
 *
 * @param group Namespace.
 * @param recursive Copy recursively.
 * @param buffer Buffer.
 *
 * @return Number of properties.
 */
size_t EMF_CALL_C emf_config_get_properties(const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive,
    emf_config_property_info_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Check if a namespace exists.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group</code> may not be <code>NULL</code>.
 *
 * @param group Namespace.
 *
 * @return <code>emf_bool_true</code> if the namespace exists.
 * @return <code>emf_bool_false</code> if the namespace does not exist.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_config_namespace_exists(const emf_config_namespace_t* EMF_NOT_NULL group) EMF_NOEXCEPT;

/**
 * @brief Check if a property exists.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 *
 * @param group Namespace.
 * @param property Property.
 *
 * @return <code>emf_bool_true</code> if the property exists.
 * @return <code>emf_bool_false</code> if the property does not exist.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_config_property_exists(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/**
 * @brief Retrieves the type of a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 *
 * @param group Namespace.
 * @param property Property.
 *
 * @return The type of the property.
 */
EMF_NODISCARD emf_config_property_type_t EMF_CALL_C emf_config_get_property_type(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/**
 * @brief Retrieves the array size of a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 *
 * @param group Namespace.
 * @param property Property.
 *
 * @return The array size of the property.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_property_array_size(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/**
 * @brief Retrieves the length of a string property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_string</code>.
 * @pre <code>index < emf_config_get_property_array_size(group, property)</code>.
 *
 * @param group Namespace.
 * @param property Property.
 * @param index Index.
 *
 * @return The length of the string property.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_property_string_size(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT;

/**
 * @brief Retrieves the max length of a string property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_string</code>.
 *
 * @param group Namespace.
 * @param property Property.
 *
 * @return The max length of the string property.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_property_string_max_size(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/******************************************************************************************************
***********************************************  Read  ***********************************************
******************************************************************************************************/

/**
 * @brief Reads the value from a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_bool</code>.
 * @pre <code>index < emf_config_get_property_array_size(group, property)</code>.
 *
 * @param group Namespace.
 * @param property Property.
 * @param index Index.
 *
 * @return The value of the property.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_config_property_read_bool(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT;

/**
 * @brief Reads the value from a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_integer</code>.
 * @pre <code>index < emf_config_get_property_array_size(group, property)</code>.
 *
 * @param group Namespace.
 * @param property Property.
 * @param index Index.
 *
 * @return The value of the property.
 */
EMF_NODISCARD int64_t EMF_CALL_C emf_config_property_read_integer(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT;

/**
 * @brief Reads the value from a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_real</code>.
 * @pre <code>index < emf_config_get_property_array_size(group, property)</code>.
 *
 * @param group Namespace.
 * @param property Property.
 * @param index Index.
 *
 * @return The value of the property.
 */
EMF_NODISCARD double EMF_CALL_C emf_config_property_read_real(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT;

/**
 * @brief Reads the value from a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_string</code>.
 * @pre <code>index < emf_config_get_property_array_size(group, property)</code>.
 * @pre <code>buffer.data != NULL</code> and <code>buffer.length >= emf_config_get_property_string_size(group, property,
 * index)</code>.
 *
 * @post The string is copied into <code>buffer</code>.
 *
 * @param group Namespace.
 * @param property Property.
 * @param index Index.
 * @param buffer Buffer.
 */
void EMF_CALL_C emf_config_property_read_string(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index,
    emf_config_string_buffer_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/******************************************************************************************************
***********************************************  Write  ***********************************************
******************************************************************************************************/

/**
 * @brief Reads a value into a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_bool</code>.
 * @pre <code>index < emf_config_get_property_array_size(group, property)</code>.
 *
 * @post <code>value</code> is written into the property.
 *
 * @param group Namespace.
 * @param property Property.
 * @param index Index.
 * @param value Value.
 */
void EMF_CALL_C emf_config_property_write_bool(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, emf_bool_t value) EMF_NOEXCEPT;

/**
 * @brief Reads a value into a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_integer</code>.
 * @pre <code>index < emf_config_get_property_array_size(group, property)</code>.
 *
 * @post <code>value</code> is written into the property.
 *
 * @param group Namespace.
 * @param property Property.
 * @param index Index.
 * @param value Value.
 */
void EMF_CALL_C emf_config_property_write_integer(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, int64_t value) EMF_NOEXCEPT;

/**
 * @brief Reads a value into a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_real</code>.
 * @pre <code>index < emf_config_get_property_array_size(group, property)</code>.
 *
 * @post <code>value</code> is written into the property.
 *
 * @param group Namespace.
 * @param property Property.
 * @param index Index.
 * @param value Value.
 */
void EMF_CALL_C emf_config_property_write_real(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, double value) EMF_NOEXCEPT;

/**
 * @brief Reads a value into a property.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>group == NULL</code> or <code>emf_config_namespace_exists(group) == emf_bool_true</code>.
 * @pre <code>property</code> may not be <code>NULL</code>.
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>emf_config_property_exists(group, property) == emf_bool_true</code>.
 * @pre <code>emf_config_get_property_type(group, property) == emf_config_prop_type_string</code>.
 * @pre <code>index < emf_config_get_property_array_size(group, property)</code>.
 * @pre <code>buffer.data != NULL</code>.
 *
 * @post Up to <code>emf_config_get_property_string_max_size(group, property)</code> characters are copied from
 * <code>buffer.data</code> into the property.
 *
 * @param group Namespace.
 * @param property Property.
 * @param index Index.
 * @param buffer String.
 */
void EMF_CALL_C emf_config_property_write_string(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index,
    const emf_config_string_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_INTERFACE_C_EMF_CONFIG_H
