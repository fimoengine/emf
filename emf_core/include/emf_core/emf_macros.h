#ifndef EMF_CORE_EMF_MACROS_H
#define EMF_CORE_EMF_MACROS_H

/******************************************************************************************************
********************************************  EMF_CALL_C  ********************************************
******************************************************************************************************/

#ifndef EMF_CALL_C
#ifdef __GNUC__
#define EMF_CALL_C __attribute__((__cdecl__))
#else
#define EMF_CALL_C __cdecl
#endif // __GNUC__
#endif // !EMF_CALL_C

/******************************************************************************************************
************************************  EMF_NOT_NULL/EMF_MAYBE_NULL  ************************************
******************************************************************************************************/

#ifdef __clang__
#define EMF_NOT_NULL _Nonnull
#define EMF_MAYBE_NULL _Nullable
#else
#define EMF_NOT_NULL
#define EMF_MAYBE_NULL
#endif // __clang__

/******************************************************************************************************
*******************************************  EMF_NODISCARD  *******************************************
******************************************************************************************************/

#ifdef __cplusplus
#define EMF_NODISCARD [[nodiscard]]
#else
#if defined(__clang__) || defined(__GNUC__)
#define EMF_NODISCARD __attribute__((warn_unused_result))
#else
#define EMF_NODISCARD
#endif // defined(__clang__) || defined(__GNUC__)
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Misc  ***********************************************
******************************************************************************************************/

#ifdef __cplusplus
#define EMF_NOEXCEPT noexcept
#define EMF_NORETURN [[noreturn]]
#define EMF_FUNCTION_PTR_T(Name, Ret_T, ...)                                                                                     \
    namespace FUNCTION_PTR_DUMMYS {                                                                                              \
    Ret_T EMF_CALL_C Name##_fn_dummy(__VA_ARGS__) EMF_NOEXCEPT;                                                                  \
    }                                                                                                                            \
    using Name##_fn_t = decltype(&FUNCTION_PTR_DUMMYS::Name##_fn_dummy);
#define EMF_EXTERN_C extern "C"
#else
#define EMF_NOEXCEPT
#define EMF_NORETURN _Noreturn
#define EMF_FUNCTION_PTR_T(Name, Ret_T, ...) typedef Ret_T(EMF_CALL_C* Name##_fn_t)(__VA_ARGS__);
#define EMF_EXTERN_C
#endif // __cplusplus

#define EMF_SPAN(Name, T)                                                                                                        \
    struct Name {                                                                                                                \
        /* Start of the span. */                                                                                                 \
        T* EMF_MAYBE_NULL data;                                                                                                  \
        /* Length of the data. */                                                                                                \
        size_t length;                                                                                                           \
    }

#define EMF_FIXED_BUFFER(Name, T, Length)                                                                                        \
    struct Name {                                                                                                                \
        /* Data of the buffer. */                                                                                                \
        T data[Length];                                                                                                          \
        /* Length of the data. */                                                                                                \
        size_t length;                                                                                                           \
    }

#define EMF_SPAN_TYPEDEF(Name, T) typedef EMF_SPAN(Name, T) Name;
#define EMF_FIXED_BUFFER_TYPEDEF(Name, T, Length) typedef EMF_FIXED_BUFFER(Name, T, Length) Name;

#endif // !EMF_CORE_EMF_MACROS_H
