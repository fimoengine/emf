#ifndef EMF_CORE_VERSION_T_H
#define EMF_CORE_VERSION_T_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_bool_t.h>
#include <emf_core_base/emf_cbase_macros.h>

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

/// An enum describing the release type of a version.
///
/// # Variants
///
/// | Name                                    | Value | Description          |
/// | --------------------------------------- | ----- | -------------------- |
/// | **emf_cbase_version_release_gold**      | `0`   | A gold release.      |
/// | **emf_cbase_version_release_pre_alpha** | `1`   | A pre-alpha release. |
/// | **emf_cbase_version_release_alpha**     | `2`   | An alpha release.    |
/// | **emf_cbase_version_release_beta**      | `3`   | A beta release.      |
/// | **emf_cbase_version_release_rc**        | `4`   | A release candidate. |
typedef enum emf_cbase_version_release_t : int8_t {
    /// A gold release.
    emf_cbase_version_release_gold = 0,
    /// A pre-alpha release.
    emf_cbase_version_release_pre_alpha = 1,
    /// An alpha release.
    emf_cbase_version_release_alpha = 2,
    /// A beta release.
    emf_cbase_version_release_beta = 3,
    /// A release candidate.
    emf_cbase_version_release_rc = 4,
} emf_cbase_version_release_t;

/// A version.
///
/// # Invariants
///
/// If `release_type == emf_cbase_version_release_gold` then `release_number == 0`.
///
/// # Fields
///
/// - **major**: `int32_t`
///
///     The major version number.
///
/// - **minor**: `int32_t`
///
///     The minor version number.
///
/// - **patch**: `int32_t`
///
///     The patch version number.
///
/// - **build_number**: `int64_t`
///
///     The build number.
///
/// - **release_number**: `int8_t`
///
///     The version release number.
///
/// - **release_type**: [`emf_cbase_version_release_t`](enum.emf_cbase_version_release_t.md)
///
///     The version release type.
typedef struct emf_cbase_version_t {
    /// Major number.
    int32_t major;
    /// Minor number.
    int32_t minor;
    /// Patch number.
    int32_t patch;
    /// Build number.
    int64_t build_number;
    /// Release number.
    int8_t release_number;
    /// Release type.
    emf_cbase_version_release_t release_type;
} emf_cbase_version_t;

/// An enum describing the possible error values of the `version` api.
///
/// The values `0-99` are reserved for future use.
///
/// # Variants
///
/// | Name                                        | Value | Description              |
/// | ------------------------------------------- | ----- | ------------------------ |
/// | **emf_cbase_version_error_invalid_string**  | `0`   | The string is invalid.   |
/// | **emf_cbase_version_error_buffer_overflow** | `1`   | The buffer is too small. |
typedef enum emf_cbase_version_error_t : int32_t {
    emf_cbase_version_error_invalid_string = 0,
    emf_cbase_version_error_buffer_overflow = 1,
} emf_cbase_version_error_t;

/// A buffer to store the string representation of a version.
///
/// The string contains only `ASCII` characters and is not terminated with a `\0`.
///
/// # Fields
///
/// - **data**: `char*`
///
///     The start of the string.
///
/// - **length**: `size_t`
///
///     The length of the string.
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_version_string_buffer_t, char)

/// A buffer containing a constant string representation of a version.
///
/// The string contains only `ASCII` characters and is not terminated with a `\0`.
///
/// # Fields
///
/// - **data**: `const char*`
///
///     The start of the string.
///
/// - **length**: `size_t`
///
///     The length of the string.
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_version_const_string_buffer_t, const char)

/// A struct containing either an `emf_cbase_version_t` or an `emf_cbase_version_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_version_t`](./struct.emf_cbase_version_t.md)
///
///     The version.
///
/// - **error**: [`emf_cbase_version_error_t`](./enum.emf_cbase_version_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./type.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_version_result_t, emf_cbase_version_t, emf_cbase_version_error_t)

/// A struct containing either a `size_t` or an `emf_cbase_version_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_version_t`](./struct.emf_cbase_version_t.md)
///
///     The size.
///
/// - **error**: [`emf_cbase_version_error_t`](./enum.emf_cbase_version_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./type.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_version_size_result_t, size_t, emf_cbase_version_error_t)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/// Constructs a new version.
///
/// Constructs a new version with `major`, `minor` and `patch` and sets the rest to `0`.
EMF_CBASE_NODISCARD emf_cbase_version_t EMF_CBASE_CALL_C emf_cbase_version_construct_short(
    int32_t major, int32_t minor, int32_t patch) EMF_CBASE_NOEXCEPT;

/// Constructs a new version.
///
/// Constructs a new version with `major`, `minor`, `patch`, `release_type` and `release_number` and sets the rest to `0`.
EMF_CBASE_NODISCARD emf_cbase_version_t EMF_CBASE_CALL_C emf_cbase_version_construct_long(int32_t major, int32_t minor,
    int32_t patch, emf_cbase_version_release_t release_type, int8_t release_number) EMF_CBASE_NOEXCEPT;

/// Constructs a new version.
///
/// Constructs a new version with `major`, `minor`, `patch`, `release_type`, `release_number` and `build`.
EMF_CBASE_NODISCARD emf_cbase_version_t EMF_CBASE_CALL_C emf_cbase_version_construct_full(int32_t major, int32_t minor,
    int32_t patch, emf_cbase_version_release_t release_type, int8_t release_number, int64_t build) EMF_CBASE_NOEXCEPT;

/// Constructs a version from a string.
///
/// # Failure
///
/// The function fails if `version_string` is not of the form "Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?\+Build".
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    version_string,
///    NULL
/// );
/// ASSERT_NE(
///    version_string->data,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_version_result_t EMF_CBASE_CALL_C emf_cbase_version_construct_from_string(
    const emf_cbase_version_const_string_buffer_t* EMF_CBASE_NOT_NULL version_string) EMF_CBASE_NOEXCEPT;

/// Checks weather the version string is valid.
///
/// The string is valid if it has the form "Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?\+Build".
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    version_string,
///    NULL
/// );
/// ASSERT_NE(
///    version_string->data,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_version_representation_is_valid(
    const emf_cbase_version_const_string_buffer_t* EMF_CBASE_NOT_NULL version_string) EMF_CBASE_NOEXCEPT;

/// Represents the version as a string.
///
/// The string has the form "Major.Minor.Patch".
///
/// # Failure
///
/// The function can fail if `buffer` is too small.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    version,
///    NULL
/// );
/// ASSERT_NE(
///    buffer,
///    NULL
/// );
/// ASSERT_NE(
///    buffer->data,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_version_size_result_t EMF_CBASE_CALL_C emf_cbase_version_get_short_representation(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT;

/// Computes the length of the version string.
///
/// Computes the minimum length a string of the form "Major.Minor.Patch" needs.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    version,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_version_get_short_representation_length(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version) EMF_CBASE_NOEXCEPT;

/// Represents the version as a string.
///
/// The string has the form "Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?".
///
/// # Failure
///
/// The function can fail if `buffer` is too small.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    version,
///    NULL
/// );
/// ASSERT_NE(
///    buffer,
///    NULL
/// );
/// ASSERT_NE(
///    buffer->data,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_version_size_result_t EMF_CBASE_CALL_C emf_cbase_version_get_long_representation(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT;

/// Computes the length of the version string.
///
/// Computes the minimum length a string of the form "Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?" needs.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    version,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_version_get_long_representation_length(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version) EMF_CBASE_NOEXCEPT;

/// Represents the version as a string.
///
/// The string has the form "Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?\+Build".
///
/// # Failure
///
/// The function can fail if `buffer` is too small.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    version,
///    NULL
/// );
/// ASSERT_NE(
///    buffer,
///    NULL
/// );
/// ASSERT_NE(
///    buffer->data,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_version_size_result_t EMF_CBASE_CALL_C emf_cbase_version_get_full_representation(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version,
    emf_cbase_version_string_buffer_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT;

/// Computes the length of the version string.
///
/// Computes the minimum length a string of the form "Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?\+Build" needs.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    version,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_version_get_full_representation_length(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL version) EMF_CBASE_NOEXCEPT;

/// Compares two versions.
///
/// Compares two versions using their major-,minor- and patch version, release type and release number.
///
/// # Return value
///
/// Returns `-1` if `lhs > rhs`.
/// Returns `0` if `lhs == rhs`.
/// Returns `1` if `lhs < rhs`.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    lhs,
///    NULL
/// );
/// ASSERT_NE(
///    rhs,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD int32_t EMF_CBASE_CALL_C emf_cbase_version_compare(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs, const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs) EMF_CBASE_NOEXCEPT;

/// Compares two versions.
///
/// Compares two versions using their major-,minor- and patch version.
///
/// # Return value
///
/// Returns `-1` if `lhs > rhs`.
/// Returns `0` if `lhs == rhs`.
/// Returns `1` if `lhs < rhs`.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    lhs,
///    NULL
/// );
/// ASSERT_NE(
///    rhs,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD int32_t EMF_CBASE_CALL_C emf_cbase_version_compare_weak(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs, const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs) EMF_CBASE_NOEXCEPT;

/// Compares two versions.
///
/// Compares two versions using their major-,minor- and patch version, release type, release number and build number.
///
/// # Return value
///
/// Returns `-1` if `lhs > rhs`.
/// Returns `0` if `lhs == rhs`.
/// Returns `1` if `lhs < rhs`.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    lhs,
///    NULL
/// );
/// ASSERT_NE(
///    rhs,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD int32_t EMF_CBASE_CALL_C emf_cbase_version_compare_strong(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs, const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs) EMF_CBASE_NOEXCEPT;

/// Compares weather two versions are compatible.
///
/// Compatibility of versions is not commutative.
///
/// # Return value
///
/// Returns `emf_cbase_bool_false` if `lhs` and `rhs` are incompatible.
/// Returns `emf_cbase_bool_true` if `lhs` is compatible with `rhs`.
///
/// # Undefined Behaviour
///
/// The caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    lhs,
///    NULL
/// );
/// ASSERT_NE(
///    rhs,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_version_is_compatible(
    const emf_cbase_version_t* EMF_CBASE_NOT_NULL lhs, const emf_cbase_version_t* EMF_CBASE_NOT_NULL rhs) EMF_CBASE_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_VERSION_T_H
