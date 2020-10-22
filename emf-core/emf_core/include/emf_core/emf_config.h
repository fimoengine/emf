//! # Introduction
//! 
//! The `config` system consists of namespaces and properties. Namespaces can contain properties and other namespaces. Properties are homogenous arrays of values. A namespace- or property-name must be a `UTF-8` string. All Namespaces are implicitly nested inside the global namespace.
//! 
//! ## Properties
//! 
//! Properties can have the following types:
//! 
//! - Bool ([`emf_bool_t`](../reference/type.emf_bool_t.md))
//! - Integer (`int64_t`)
//! - Reals (`double`)
//! - String (`char*`)
//! 
//! Strings are treated as a sized blob of data, and as such can contain values other than strings. Unless stated otherwise, a string property represents a `UTF-8` string without a terminating `\0` character.
//! 
//! The array length of a property can not be changed after it's construction. Additionally, String properties are assigned a maximum length at construction.
//! 
//! # Example
//! 
//! ## JSON
//! 
//! ```json
//! {
//!     "str": "test",
//!     "test_namespace": {
//!         "double": 0.57,
//!         "arr": [5, 5],
//!         "nested_namespace": {
//!             "bool": true
//!         }
//!     }
//! }
//! ```
//! 
//! ## Equivalent
//! 
//! ```c
//! emf_config_namespace_t ns1 = { "test_namespace" };
//! emf_config_namespace_t ns2 = { "test_namespace::nested_namespace" };
//! 
//! emf_config_property_t g_str = { "str" };
//! emf_config_property_t ns1_double = { "double" };
//! emf_config_property_t ns1_arr = { "arr" };
//! emf_config_property_t ns2_bool = { "bool" };
//! 
//! emf_config_string_t g_str_val = { "test", strlen("test") + 1 };
//! 
//! emf_lock();
//! 
//! emf_config_add_namespace(&ns1);
//! emf_config_add_namespace(&ns2);
//! 
//! emf_config_add_property_string(NULL, &g_str, 1, 256, &g_str_val);
//! emf_config_add_property_real(&ns1, &ns1_double, 1, 0.57);
//! emf_config_add_property_integer(&ns1, &ns1_arr, 2, 5);
//! emf_config_add_property_boolean(&ns2, &ns2_bool, 1, true);
//! 
//! emf_unlock();
//! ```

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

/// The maximum length of a namespace identifier.
#define EMF_CONFIG_NAMESPACE_MAX_LENGTH 128

/// The maximum length of a property identifier.
#define EMF_CONFIG_PROPERTY_MAX_LENGTH 32

#ifdef __cplusplus
namespace EMF::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

/// The name of a namespace.
///
/// # Fields
/// 
/// - **data**: [`char[EMF_CONFIG_NAMESPACE_MAX_LENGTH]`](./constant.EMF_CONFIG_NAMESPACE_MAX_LENGTH.md)
/// 
///     The identifier of the namespace.
/// 
/// - **length**: `size_t`
/// 
///     Length of the identifier.
EMF_FIXED_BUFFER_TYPEDEF(emf_config_namespace_t, char, EMF_CONFIG_NAMESPACE_MAX_LENGTH)

/// The name of a property.
/// 
/// # Fields
/// 
/// - **data**: [`char[EMF_CONFIG_PROPERTY_MAX_LENGTH]`](./constant.EMF_CONFIG_PROPERTY_MAX_LENGTH.md)
/// 
///     The identifier of the property.
/// 
/// - **length**: `size_t`
/// 
///     Length of the identifier.
EMF_FIXED_BUFFER_TYPEDEF(emf_config_property_t, char, EMF_CONFIG_PROPERTY_MAX_LENGTH)

/// An enum describing all possible property types.
/// 
/// # Variants
/// 
/// | Name                             | Value | Description          |
/// | -------------------------------- | ----- | -------------------- |
/// | **emf_config_prop_type_bool**    | `0`   | A boolean property.  |
/// | **emf_config_prop_type_integer** | `1`   | An integer property. |
/// | **emf_config_prop_type_real**    | `2`   | A real property.     |
/// | **emf_config_prop_type_string**  | `3`   | A string property.   |
typedef enum emf_config_property_type_t : int32_t {
    /// A boolean property.
    emf_config_prop_type_bool = 0,
    /// An integer property.
    emf_config_prop_type_integer = 1,
    /// A real property.
    emf_config_prop_type_real = 2,
    /// A string property.
    emf_config_prop_type_string = 3,
} emf_config_property_type_t;

/// Information of a property.
/// 
/// # Fields
/// 
/// - **group**: [`emf_config_namespace_t`](./struct.emf_config_namespace_t.md)
/// 
///     The identifier of the namespace.
/// 
/// - **property**: [`emf_config_property_t`](./struct.emf_config_property_t.md)
/// 
///     The identifier of the property.
/// 
/// - **property_type**: [`emf_config_property_type_t`](./enum.emf_config_property_type_t.md)
/// 
///     The type of the property.
/// 
/// - **size**: `size_t`
/// 
///     Array size of the property.
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

/// A span of namespaces.
/// 
/// # Fields
/// 
/// - **data**: [`emf_config_namespace_t`](./struct.emf_config_namespace_t.md)
/// 
///     The start of the span.
/// 
/// - **length**: `size_t`
/// 
///     The length of the span.
EMF_SPAN_TYPEDEF(emf_config_namespace_span_t, emf_config_namespace_t)

/// A span of property infos.
/// 
/// # Fields
/// 
/// - **data**: [`emf_config_property_info_t`](./struct.emf_config_property_info_t.md)
/// 
///     The start of the span.
/// 
/// - **length**: `size_t`
/// 
///     The length of the span.
EMF_SPAN_TYPEDEF(emf_config_property_info_span_t, emf_config_property_info_t)

/// A `UTF-8` string used by the `config` system.
/// 
/// The string is not teminated with the `\0` character.
/// 
/// # Fields
/// 
/// - **data**: `const char*`
/// 
///     Start of the string.
/// 
/// - **length**: `size_t`
/// 
///     Length of the string.
EMF_SPAN_TYPEDEF(emf_config_string_t, const char)

/// A writable `UTF-8` string used by the `config` system.
/// 
/// The string is not teminated with the `\0` character.
/// 
/// # Fields
/// 
/// - **data**: `char*`
/// 
///     Start of the string.
/// 
/// - **length**: `size_t`
/// 
///     Length of the string.
EMF_SPAN_TYPEDEF(emf_config_string_buffer_t, char)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/// Creates a new namespace.
/// 
/// Creates a new namespace, which can hold properties. 
/// Multiple namespaces can be nested inside each other.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_NE(
///     group,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_namespace_exists(group),
///     emf_bool_false
/// );
/// ```
void EMF_CALL_C emf_config_add_namespace(const emf_config_namespace_t* EMF_NOT_NULL group) EMF_NOEXCEPT;

/// Removes an existing namespace.
/// 
/// Removes a namespace, its properties and its child-namespaces.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_NE(
///     group,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_namespace_exists(group),
///     emf_bool_true
/// );
/// ```
void EMF_CALL_C emf_config_remove_namespace(const emf_config_namespace_t* EMF_NOT_NULL group) EMF_NOEXCEPT;

/// Adds a boolean property to a namespace.
/// 
/// Adds a boolean property to the supplied namespace. 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group),
///     emf_bool_false
/// );
/// ASSERT(
///     array_size >= 1
/// );
/// ```
void EMF_CALL_C emf_config_add_property_boolean(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, emf_bool_t default_value) EMF_NOEXCEPT;

/// Adds an integer property to a namespace.
/// 
/// Adds an integer property to the supplied namespace. 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group),
///     emf_bool_false
/// );
/// ASSERT(
///     array_size >= 1
/// );
/// ```
void EMF_CALL_C emf_config_add_property_integer(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, int64_t default_value) EMF_NOEXCEPT;

/// Adds a real property to a namespace.
/// 
/// Adds a real property to the supplied namespace. 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group),
///     emf_bool_false
/// );
/// ASSERT(
///     array_size >= 1
/// );
/// ```
void EMF_CALL_C emf_config_add_property_real(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, double default_value) EMF_NOEXCEPT;

/// Adds a string property to a namespace.
/// 
/// Adds a string property to the supplied namespace. 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group),
///     emf_bool_false
/// );
/// ASSERT(
///     array_size >= 1
/// );
/// ASSERT(
///     string_length >= 1
/// );
/// ASSERT_NE(
///     default_value,
///     NULL
/// );
/// ```
void EMF_CALL_C emf_config_add_property_string(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t array_size, size_t string_length,
    const emf_config_string_t* EMF_NOT_NULL default_value) EMF_NOEXCEPT;

/// Removes a property.
/// 
/// Removes a property from the supplied namespace. 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ```
void EMF_CALL_C emf_config_remove_property(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/// Returns the number of namespaces.
/// 
/// Returns the number of namespaces inside (and including) the supplied namespace.
/// The namespaces can be counted recursively by setting `recursive` to `emf_bool_true`.
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ```
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_num_namespaces(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive) EMF_NOEXCEPT;

/// Copies all namespaces into a buffer.
/// 
/// Copies every namespace inside (and including) the supplied namespace into the supplied `buffer`. 
/// The namespaces can be copied recursively by setting `recursive` to `emf_bool_true`. 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     buffer,
///     NULL
/// );
/// ASSERT_NE(
///     buffer->data,
///     NULL
/// );
/// ASSERT(
///     buffer->length >= emf_config_get_num_namespaces(group, recursive)
/// );
/// ```
size_t EMF_CALL_C emf_config_get_namespaces(const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive,
    emf_config_namespace_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/// Retrieves the number of properties in a namespace.
/// 
/// Returns the number of properties inside the supplied namespace.
/// The properties can be counted recursively by setting `recursive` to `emf_bool_true`.
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ```
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_num_properties(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive) EMF_NOEXCEPT;

/// Copies all properties into a buffer.
/// 
/// Copies the properties inside the supplied namespace into `buffer`.
/// The properties can be copied recursively by setting `recursive` to `emf_bool_true`.
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     buffer->data,
///     NULL
/// );
/// ASSERT(
///     buffer->length >= emf_config_get_num_properties(group, recursive)
/// );
/// ```
size_t EMF_CALL_C emf_config_get_properties(const emf_config_namespace_t* EMF_MAYBE_NULL group, emf_bool_t recursive,
    emf_config_property_info_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/// Check if a namespace exists.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT_NE(
///     group,
///     NULL
/// );
/// ```
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_config_namespace_exists(const emf_config_namespace_t* EMF_NOT_NULL group) EMF_NOEXCEPT;

/// Checks if a property exists.
/// 
/// Checks if the property is present inside the supplied namespace. 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ```
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_config_property_exists(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/// Retrieves the type of a property.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ```
EMF_NODISCARD emf_config_property_type_t EMF_CALL_C emf_config_get_property_type(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/// Retrieves the array length of a property.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ```
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_property_array_size(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/// Retrieves the string length of a property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_string
/// );
/// ASSERT(
///     index < emf_config_get_property_array_size(group, property)
/// );
/// ```
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_property_string_size(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT;

/// Retrieves the maximum string length of a property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_string
/// );
/// ```
EMF_NODISCARD size_t EMF_CALL_C emf_config_get_property_string_max_size(
    const emf_config_namespace_t* EMF_MAYBE_NULL group, const emf_config_property_t* EMF_NOT_NULL property) EMF_NOEXCEPT;

/******************************************************************************************************
***********************************************  Read  ***********************************************
******************************************************************************************************/

/// Reads the value of a bool property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_bool
/// );
/// ASSERT(
///     index < emf_config_get_property_array_size(group, property)
/// );
/// ```
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_config_property_read_bool(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT;

/// Reads the value of an integer property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_integer
/// );
/// ASSERT(
///     index < emf_config_get_property_array_size(group, property)
/// );
/// ```
EMF_NODISCARD int64_t EMF_CALL_C emf_config_property_read_integer(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT;

/// Reads the value of a real property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_real
/// );
/// ASSERT(
///     index < emf_config_get_property_array_size(group, property)
/// );
/// ```
EMF_NODISCARD double EMF_CALL_C emf_config_property_read_real(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index) EMF_NOEXCEPT;

/// Reads the value of a string property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_NE(
///     buffer,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_string
/// );
/// ASSERT(
///     index < emf_config_get_property_array_size(group, property)
/// );
/// ASSERT_NE(
///     buffer->data,
///     NULL
/// );
/// ASSERT(
///     buffer->length >= emf_config_get_property_string_size(group, property, index)
/// );
/// ```
void EMF_CALL_C emf_config_property_read_string(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index,
    emf_config_string_buffer_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/******************************************************************************************************
***********************************************  Write  ***********************************************
******************************************************************************************************/

/// Writes a value into a bool property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_bool
/// );
/// ASSERT(
///     index < emf_config_get_property_array_size(group, property)
/// );
/// ```
void EMF_CALL_C emf_config_property_write_bool(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, emf_bool_t value) EMF_NOEXCEPT;

/// Writes a value into an integer property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_integer
/// );
/// ASSERT(
///     index < emf_config_get_property_array_size(group, property)
/// );
/// ```
void EMF_CALL_C emf_config_property_write_integer(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, int64_t value) EMF_NOEXCEPT;

/// Writes a value into a real property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_real
/// );
/// ASSERT(
///     index < emf_config_get_property_array_size(group, property)
/// );
/// ```
void EMF_CALL_C emf_config_property_write_real(const emf_config_namespace_t* EMF_MAYBE_NULL group,
    const emf_config_property_t* EMF_NOT_NULL property, size_t index, double value) EMF_NOEXCEPT;

/// Writes a value into a string property member.
/// 
/// The namespace `NULL` and the empty namespace refer to the global namespace.
/// 
/// # Undefined Behaviour
/// 
/// The callee expects that the caller holds a lock (See [emf_lock()](./fn.emf_lock.md)).  
/// Furthermore, the caller must ensure that the following preconditions hold:
/// 
/// ```c
/// ASSERT(
///     group == NULL ||
///     emf_config_namespace_exists(group) == emf_bool_true
/// );
/// ASSERT_NE(
///     property,
///     NULL
/// );
/// ASSERT_NE(
///     buffer,
///     NULL
/// );
/// ASSERT_EQ(
///     emf_config_property_exists(group, property),
///     emf_bool_true
/// );
/// ASSERT_EQ(
///     emf_config_get_property_type(group, property),
///     emf_config_prop_type_string
/// );
/// ASSERT(
///     index < emf_config_get_property_array_size(group, property)
/// );
/// ASSERT_NE(
///     buffer->data,
///     NULL
/// );
/// ```
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
