#ifndef EMF_C_VERSION_HPP
#define EMF_C_VERSION_HPP

#ifdef __cplusplus

#include <emf_core/emf_version_t.h>
#include <emf_core/version.h>

#include <cstdint>
#include <cstdlib>
#include <string_view>

namespace EMF {

inline constexpr std::string_view version_string_short { EMF_CORE_VERSION_SHORT };
inline constexpr std::string_view version_string_long { EMF_CORE_VERSION_LONG };
inline constexpr std::string_view version_string_full { EMF_CORE_VERSION_FULL };

inline constexpr std::int32_t version_major { EMF_CORE_VERSION_MAJOR };
inline constexpr std::int32_t version_minor { EMF_CORE_VERSION_MINOR };
inline constexpr std::int32_t version_patch { EMF_CORE_VERSION_PATCH };
inline constexpr std::int64_t version_build { EMF_CORE_BUILD };

inline constexpr C::emf_version_release_t version_release_type { static_cast<C::emf_version_release_t>(
    EMF_CORE_PRE_RELEASE_TYPE) };
inline constexpr std::int8_t version_release_number { EMF_CORE_PRE_RELEASE_NUMBER };

}

#endif // __cplusplus

#endif // !EMF_C_VERSION_HPP
