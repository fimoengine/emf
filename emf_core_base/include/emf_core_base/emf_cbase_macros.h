#ifndef EMF_CORE_BASE_EMF_CBASE_MACROS_H
#define EMF_CORE_BASE_EMF_CBASE_MACROS_H

/******************************************************************************************************
*****************************************  EMF_CBASE_CALL_C  *****************************************
******************************************************************************************************/

#ifndef EMF_CBASE_CALL_C
#ifdef __GNUC__
#if defined(__i386__)
#define EMF_CBASE_CALL_C __attribute__((cdecl))
#elif defined(__x86_64__) && (defined(_WIN32) || defined(_WIN64))
#define EMF_CBASE_CALL_C __attribute__((ms_abi))
#elif defined(__x86_64__)
#define EMF_CBASE_CALL_C __attribute__((sysv_abi))
#else
#define EMF_CBASE_CALL_C
#endif // __i386__
#else
#define EMF_CBASE_CALL_C __cdecl
#endif // __GNUC__
#endif // !EMF_CBASE_CALL_C

/******************************************************************************************************
******************************  EMF_CBASE_NOT_NULL/EMF_CBASE_MAYBE_NULL  ******************************
******************************************************************************************************/

#ifdef __clang__
#define EMF_CBASE_NOT_NULL _Nonnull
#define EMF_CBASE_MAYBE_NULL _Nullable
#else
#define EMF_CBASE_NOT_NULL
#define EMF_CBASE_MAYBE_NULL
#endif // __clang__

/******************************************************************************************************
****************************************  EMF_CBASE_NODISCARD  ****************************************
******************************************************************************************************/

#ifdef __cplusplus
#define EMF_CBASE_NODISCARD [[nodiscard]]
#else
#if defined(__clang__) || defined(__GNUC__)
#define EMF_CBASE_NODISCARD __attribute__((warn_unused_result))
#else
#define EMF_CBASE_NODISCARD
#endif // defined(__clang__) || defined(__GNUC__)
#endif // __cplusplus

/******************************************************************************************************
****************************************  EMF_CBASE_USE_ENUMS  ****************************************
******************************************************************************************************/

#if defined(__cplusplus) || defined(__clang__)
#define EMF_CBASE_USE_ENUMS
#endif // defined(__cplusplus) || defined(__clang__)

/******************************************************************************************************
***********************************************  Misc  ***********************************************
******************************************************************************************************/

#ifdef __cplusplus
#define EMF_CBASE_NOEXCEPT noexcept
#define EMF_CBASE_NORETURN [[noreturn]]
#define EMF_CBASE_FUNCTION_PTR_T(Name, Ret_T, ...)                                                                               \
    namespace CBASE_FUNCTION_PTR_DUMMYS {                                                                                        \
    Ret_T EMF_CBASE_CALL_C Name##_dummy(__VA_ARGS__) EMF_CBASE_NOEXCEPT;                                                         \
    }                                                                                                                            \
    using Name = decltype(&CBASE_FUNCTION_PTR_DUMMYS::Name##_dummy);
#define EMF_CBASE_EXTERN_C extern "C"
#else
#define EMF_CBASE_NOEXCEPT
#define EMF_CBASE_NORETURN _Noreturn
#define EMF_CBASE_FUNCTION_PTR_T(Name, Ret_T, ...) typedef Ret_T(EMF_CBASE_CALL_C* Name)(__VA_ARGS__);
#define EMF_CBASE_EXTERN_C
#endif // __cplusplus

#define EMF_CBASE_SPAN(Name, T)                                                                                                  \
    struct Name {                                                                                                                \
        /* Start of the span. */                                                                                                 \
        T* EMF_CBASE_MAYBE_NULL data;                                                                                            \
        /* Length of the data. */                                                                                                \
        size_t length;                                                                                                           \
    }

#define EMF_CBASE_FIXED_BUFFER(Name, T, Length)                                                                                  \
    struct Name {                                                                                                                \
        /* Data of the buffer. */                                                                                                \
        T data[Length];                                                                                                          \
        /* Length of the data. */                                                                                                \
        size_t length;                                                                                                           \
    }

#define EMF_CBASE_RESULT(Name, ResT, ErrT)                                                                                       \
    struct Name {                                                                                                                \
        int8_t tag;                                                                                                              \
        union {                                                                                                                  \
            ResT ok;                                                                                                             \
            ErrT err;                                                                                                            \
        };                                                                                                                       \
    }

#define EMF_CBASE_OPTIONAL(Name, T)                                                                                              \
    struct Name {                                                                                                                \
        int8_t tag;                                                                                                              \
        union {                                                                                                                  \
            int8_t _none;                                                                                                        \
            T some;                                                                                                              \
        };                                                                                                                       \
    }

#define EMF_CBASE_FAT_PTR(Name, Data, VTable)                                                                                    \
    struct Name {                                                                                                                \
        Data* EMF_CBASE_MAYBE_NULL data;                                                                                         \
        const VTable* EMF_CBASE_NOT_NULL vtable;                                                                                 \
    }

#define EMF_CBASE_SPAN_TYPEDEF(Name, T) typedef EMF_CBASE_SPAN(Name, T) Name;
#define EMF_CBASE_FIXED_BUFFER_TYPEDEF(Name, T, Length) typedef EMF_CBASE_FIXED_BUFFER(Name, T, Length) Name;
#define EMF_CBASE_RESULT_TYPEDEF(Name, ResT, ErrT) typedef EMF_CBASE_RESULT(Name, ResT, ErrT) Name;
#define EMF_CBASE_OPTIONAL_TYPEDEF(Name, T) typedef EMF_CBASE_OPTIONAL(Name, T) Name;
#define EMF_CBASE_FAT_PTR_TYPEDEF(Name, Data, VTable) typedef EMF_CBASE_FAT_PTR(Name, Data, VTable) Name;

#endif // !EMF_CORE_BASE_EMF_CBASE_MACROS_H
