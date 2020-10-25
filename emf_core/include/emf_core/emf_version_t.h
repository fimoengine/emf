#ifndef EMF_CORE_VERSION_T_H
#define EMF_CORE_VERSION_T_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core/emf_bool_t.h>
#include <emf_core/emf_macros.h>

#ifdef __cplusplus
namespace EMF::Core::C {
#endif // __cplusplus

/**
 * Version release type.
 */
typedef enum emf_version_release_t : int8_t {
    /// A gold release.
    emf_version_release_gold = 0,
    /// A pre-alpha release.
    emf_version_release_pre_alpha = 1,
    /// An alpha release.
    emf_version_release_alpha = 2,
    /// A beta release.
    emf_version_release_beta = 3,
    /// A release candidate.
    emf_version_release_rc = 4,
} emf_version_release_t;

/**
 * Version struct.
 */
typedef struct emf_version_t {
    /// Major number.
    int32_t major; /// Minor number.
    int32_t minor; /// Patch number.
    int32_t patch; /// Build number.
    int64_t build_number; /// Release number.
    int8_t release_number; /// Release type.
    emf_version_release_t release_type;
} emf_version_t;

/**
 * A buffer to store the representation of a version instance.
 */
EMF_SPAN_TYPEDEF(emf_version_representation_buffer_t, char)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Construct a new version object.
 *
 * Construct a new version using the major-,minor- and patch version.
 *
 * @param major Major version.
 * @param minor Minor version.
 * @param patch Patch version.
 *
 * @return The constructed version.
 */
EMF_NODISCARD emf_version_t EMF_CALL_C emf_version_construct_short(int32_t major, int32_t minor, int32_t patch) EMF_NOEXCEPT;

/**
 * @brief Construct a new version object.
 *
 * Construct a new version using the major-,minor- and patch version, release type and release number.
 *
 * @note If <code>release_type == emf_version_release_gold</code>, then <code>release_number</code> is set to 0.
 *
 * @param major Major version.
 * @param minor Minor version.
 * @param patch Patch version.
 * @param release_type Type of release.
 * @param release_number Number of release.
 *
 * @return The constructed version.
 */
EMF_NODISCARD emf_version_t EMF_CALL_C emf_version_construct_long(
    int32_t major, int32_t minor, int32_t patch, emf_version_release_t release_type, int8_t release_number) EMF_NOEXCEPT;

/**
 *
 * @brief Construct a new version object.
 *
 * Construct a new version using the major-,minor- and patch version, release type, release number and a build number.
 *
 * @note If <code>release_type == emf_version_release_gold</code>, then <code>release_number</code> is set to 0.
 *
 * @param major Major version.
 * @param minor Minor version.
 * @param patch Patch version.
 * @param release_type Type of release.
 * @param release_number Number of release.
 * @param build Build number.
 *
 * @return The constructed version.
 */
EMF_NODISCARD emf_version_t EMF_CALL_C emf_version_construct_full(int32_t major, int32_t minor, int32_t patch,
    emf_version_release_t release_type, int8_t release_number, int64_t build) EMF_NOEXCEPT;

/**
 * @brief Construct a new version object from a null terminated string.
 *
 * Represents a version object as a string of the form: Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?\+Build.
 * E.g <code>"1.2.3-rc.156+5789454618"</code>.
 *
 * @pre <code>version_string</code> may not be <code>NULL</code>.
 * @pre <code>emf_version_representation_is_valid(version_string) == emf_bool_true</code>
 *
 * @param version_string String representation of the version.
 *
 * @return The constructed version.
 */
EMF_NODISCARD emf_version_t EMF_CALL_C emf_version_construct_from_string(const char* EMF_NOT_NULL version_string) EMF_NOEXCEPT;

/**
 * @brief Checks if the representation is valid.
 *
 * Checks if the string is of the form: Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?\+Build.
 *
 * @pre <code>version_string</code> may not be <code>NULL</code>.
 *
 * @param version_string Representation
 *
 * @return <code>emf_bool_true</code> if the representation is valid.
 * @return <code>emf_bool_false</code> otherwise.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_version_representation_is_valid(const char* EMF_NOT_NULL version_string) EMF_NOEXCEPT;

/**
 * @brief Represents a version object as a string.
 *
 * Represents a version object as a string of the form: Major.Minor.Patch.
 * E.g <code>"1.2.3"</code>.
 *
 * @pre <code>version</code> may not be <code>NULL</code>.
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.length >= emf_version_get_short_representation_size(version) + 1</code>.
 *
 * @post The representation is written in the buffer.
 *
 * @param version A version object.
 * @param buffer Destination buffer.
 *
 * @return Number of written characters.
 */
size_t EMF_CALL_C emf_version_get_short_representation(
    const emf_version_t* EMF_NOT_NULL version, emf_version_representation_buffer_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Returns the size of the short version representation.
 *
 * Returns the size of the short version representation, disregarding the null terminator.
 *
 * @pre <code>version</code> may not be <code>NULL</code>.
 *
 * @param version Version object.
 *
 * @return Size of the representation.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_version_get_short_representation_size(const emf_version_t* EMF_NOT_NULL version) EMF_NOEXCEPT;

/**
 * @brief Represents a version object as a string.
 *
 * Represents a version object as a string of the form: Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?.
 * E.g <code>"1.2.3-pre-alpha.3"</code>.
 *
 * @pre <code>version</code> may not be <code>NULL</code>.
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.length >= emf_version_get_long_representation_size(version) + 1</code>.
 *
 * @post The representation is written in the buffer.
 *
 * @param version A version object.
 * @param buffer Destination buffer.
 *
 * @return Number of written characters.
 */
size_t EMF_CALL_C emf_version_get_long_representation(
    const emf_version_t* EMF_NOT_NULL version, emf_version_representation_buffer_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Returns the size of the long version representation.
 *
 * Returns the size of the long version representation, disregarding the null terminator.
 *
 * @pre <code>version</code> may not be <code>NULL</code>.
 *
 * @param version Version object.
 *
 * @return Size of the representation.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_version_get_long_representation_size(const emf_version_t* EMF_NOT_NULL version) EMF_NOEXCEPT;

/**
 * @brief Represents a version object as a string.
 *
 * Represents a version object as a string of the form: Major.Minor.Patch(-((pre-)?alpha|beta|rc).Release)?\+Build.
 * E.g <code>"1.2.3-alpha.8+45648"</code>.
 *
 * @pre <code>version</code> may not be <code>NULL</code>.
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.length >= emf_version_get_full_representation_size(version) + 1</code>.
 *
 * @post The representation is written in the buffer.
 *
 * @param version A version object.
 * @param buffer Destination buffer.
 *
 * @return Number of written characters.
 */
size_t EMF_CALL_C emf_version_get_full_representation(
    const emf_version_t* EMF_NOT_NULL version, emf_version_representation_buffer_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Returns the size of the full version representation.
 *
 * Returns the size of the full version representation, disregarding the null terminator.
 *
 * @pre <code>version</code> may not be <code>NULL</code>.
 *
 * @param version Version object.
 *
 * @return Size of the representation.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_version_get_full_representation_size(const emf_version_t* EMF_NOT_NULL version) EMF_NOEXCEPT;

/**
 * @brief Compares two versions.
 *
 * Compares two versions using their major-,minor- and patch version, release type and release number.
 * Returns <code>-1</code> if <code>lhs > rhs</code>, <code>0</code> if <code>lhs == rhs</code> or <code>1</code> if <code>lhs \<
 * rhs</code>.
 *
 * @pre <code>lhs</code> may not be <code>NULL</code>.
 * @pre <code>rhs</code> may not be <code>NULL</code>.
 *
 * @param lhs First version.
 * @param rhs Second version.
 *
 * @return <code>-1</code> if <code>lhs > rhs</code>.
 * @return <code>0</code> if <code>lhs == rhs</code>.
 * @return <code>1</code> if <code>lhs < rhs</code>.
 */
EMF_NODISCARD int32_t EMF_CALL_C emf_version_compare(
    const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT;

/**
 * @brief Compares two versions.
 *
 * Compares two versions using their major-,minor- and patch version.
 * Returns <code>-1</code> if <code>lhs > rhs</code>, <code>0</code> if <code>lhs == rhs</code> or <code>1</code> if <code>lhs \<
 * rhs</code>.
 *
 * @pre <code>lhs</code> may not be <code>NULL</code>.
 * @pre <code>rhs</code> may not be <code>NULL</code>.
 *
 * @param lhs First version.
 * @param rhs Second version.
 *
 * @return <code>-1</code> if <code>lhs > rhs</code>.
 * @return <code>0</code> if <code>lhs == rhs</code>.
 * @return <code>1</code> if <code>lhs < rhs</code>.
 */
EMF_NODISCARD int32_t EMF_CALL_C emf_version_compare_weak(
    const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT;

/**
 * @brief Compares two versions.
 *
 * Compares two versions using their major-,minor- and patch version, release type, release number and build number.
 * Returns <code>-1</code> if <code>lhs > rhs</code>, <code>0</code> if <code>lhs == rhs</code> or <code>1</code> if <code>lhs \<
 * rhs</code>.
 *
 * @pre <code>lhs</code> may not be <code>NULL</code>.
 * @pre <code>rhs</code> may not be <code>NULL</code>.
 *
 * @param lhs First version.
 * @param rhs Second version.
 *
 * @return <code>-1</code> if <code>lhs > rhs</code>.
 * @return <code>0</code> if <code>lhs == rhs</code>.
 * @return <code>1</code> if <code>lhs < rhs</code>.
 */
EMF_NODISCARD int32_t EMF_CALL_C emf_version_compare_strong(
    const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT;

/**
 * @brief Indicates if the first version is compatible to the second version.
 *
 * Indicates if the first version is compatible to the second version, i.e <code>lhs</code> can be replaced with <code>rhs</code>
 * without breaking functionality.
 *
 * @note Pre-alpha- and alpha- versions are considered to have an unstable api.
 * @note Unstable versions are incompatible with any version other than theirs.
 * @note Stable versions are compatible with any version, that has the same major version and is higher or equal.
 *
 * @pre <code>lhs</code> may not be <code>NULL</code>.
 * @pre <code>rhs</code> may not be <code>NULL</code>.
 *
 * @param lhs First version.
 * @param rhs Second version.
 *
 * @return <code>emf_bool_true</code> if <code>lhs</code> and <code>rhs</code> are compatible.
 * @return <code>emf_bool_false</code> otherwise.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_version_is_compatible(
    const emf_version_t* EMF_NOT_NULL lhs, const emf_version_t* EMF_NOT_NULL rhs) EMF_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_VERSION_T_H
