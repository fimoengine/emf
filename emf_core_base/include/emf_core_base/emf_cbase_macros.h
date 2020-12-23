#ifndef EMF_CORE_BASE_EMF_CBASE_MACROS_H
#define EMF_CORE_BASE_EMF_CBASE_MACROS_H

/******************************************************************************************************
*****************************************  EMF_CBASE_CALL_C  *****************************************
******************************************************************************************************/

#ifndef EMF_CBASE_CALL_C
#ifdef __GNUC__
#define EMF_CBASE_CALL_C __attribute__((__cdecl__))
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
***********************************************  Misc  ***********************************************
******************************************************************************************************/

#ifdef __cplusplus
#define EMF_CBASE_NOEXCEPT noexcept
#define EMF_CBASE_NORETURN [[noreturn]]
#define EMF_CBASE_FUNCTION_PTR_T(Name, Ret_T, ...)                                                                               \
    namespace CBASE_FUNCTION_PTR_DUMMYS {                                                                                        \
    Ret_T EMF_CBASE_CALL_C Name##_fn_dummy(__VA_ARGS__) EMF_CBASE_NOEXCEPT;                                                      \
    }                                                                                                                            \
    using Name##_fn_t = decltype(&CBASE_FUNCTION_PTR_DUMMYS::Name##_fn_dummy);
#define EMF_CBASE_EXTERN_C extern "C"
#else
#define EMF_CBASE_NOEXCEPT
#define EMF_CBASE_NORETURN _Noreturn
#define EMF_CBASE_FUNCTION_PTR_T(Name, Ret_T, ...) typedef Ret_T(EMF_CBASE_CALL_C* Name##_fn_t)(__VA_ARGS__);
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
        union {                                                                                                                  \
            ResT result;                                                                                                         \
            ErrT error;                                                                                                          \
        };                                                                                                                       \
        emf_cbase_bool_t has_error;                                                                                              \
    }

#define EMF_CBASE_OPTIONAL(Name, T)                                                                                              \
    struct Name {                                                                                                                \
        union {                                                                                                                  \
            T value;                                                                                                             \
            emf_cbase_bool_t _dummy;                                                                                             \
        };                                                                                                                       \
        emf_cbase_bool_t has_value;                                                                                              \
    }

#define EMF_CBASE_SPAN_TYPEDEF(Name, T) typedef EMF_CBASE_SPAN(Name, T) Name;
#define EMF_CBASE_FIXED_BUFFER_TYPEDEF(Name, T, Length) typedef EMF_CBASE_FIXED_BUFFER(Name, T, Length) Name;
#define EMF_CBASE_RESULT_TYPEDEF(Name, ResT, ErrT) typedef EMF_CBASE_RESULT(Name, ResT, ErrT) Name;
#define EMF_CBASE_OPTIONAL_TYPEDEF(Name, T) typedef EMF_CBASE_OPTIONAL(Name, T) Name;

#endif // !EMF_CORE_BASE_EMF_CBASE_MACROS_H