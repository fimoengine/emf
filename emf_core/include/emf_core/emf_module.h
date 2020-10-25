#ifndef EMF_CORE_EMF_MODULE_H
#define EMF_CORE_EMF_MODULE_H

#ifdef __cplusplus
#include <cstddef>
#else
#include <stddef.h>
#endif // __cplusplus

#include <emf_core/emf_error_t.h>
#include <emf_core/emf_fn_ptr_id_t.h>
#include <emf_core/emf_fs.h>
#include <emf_core/emf_macros.h>
#include <emf_core/emf_version_t.h>

#define EMF_MODULE_INFO_NAME_MAX_LENGTH 32 /// Max module name length.
#define EMF_MODULE_INFO_VERSION_MAX_LENGTH 32 /// Max module version length.
#define EMF_INTERFACE_INFO_NAME_MAX_LENGTH 32 /// Max interface name length.
#define EMF_INTERFACE_EXTENSION_NAME_MAX_LENGTH 32 /// Max interface extension name length.
#define EMF_MODULE_LOADER_TYPE_MAX_LENGTH 64 /// Module type name max length.

#define EMF_NATIVE_MODULE_TYPE_NAME "emf::core::native" /// Name of the native module type.
#define EMF_NATIVE_MODULE_INTERFACE_SYMBOL_NAME emf_native_module_interface /// Name of the native interface symbol.

#ifdef __cplusplus
#define EMF_MODULE_LOADER_DEFAULT_HANDLE                                                                                         \
    emf_module_loader_handle_t { EMF::Core::C::emf_module_predefined_handles_native }
#else
#define EMF_MODULE_LOADER_DEFAULT_HANDLE                                                                                         \
    (emf_module_loader_handle_t) { emf_module_loader_default_handle_ }
#endif // __cplusplus

#ifdef __cplusplus
namespace EMF::Core::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

EMF_FUNCTION_PTR_T(emf, void, void)
EMF_FUNCTION_PTR_T(emf_has_function, EMF_NODISCARD emf_bool_t, emf_fn_ptr_id_t fn_id)
EMF_FUNCTION_PTR_T(emf_get_function, EMF_NODISCARD emf_fn_t EMF_NOT_NULL, emf_fn_ptr_id_t fn_id)

/**
 * Handle to a module.
 */
typedef struct emf_module_handle_t {
    /// Module id.
    int32_t id;
} emf_module_handle_t;

/**
 * The name of a module.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_module_name_t, char, EMF_MODULE_INFO_NAME_MAX_LENGTH)

/**
 * The version of a module.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_module_version_t, char, EMF_MODULE_INFO_VERSION_MAX_LENGTH)

/**
 * Module info.
 */
typedef struct emf_module_info_t {
    /// Module name.
    emf_module_name_t name;
    /// Module version string.
    emf_module_version_t version;
} emf_module_info_t;

/**
 * Interface extension.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_interface_extension_t, char, EMF_INTERFACE_EXTENSION_NAME_MAX_LENGTH)

/**
 * The name of a interface.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_interface_name_t, char, EMF_INTERFACE_INFO_NAME_MAX_LENGTH)

/**
 * Interface info.
 */
typedef struct emf_interface_info_t {
    /// Interface name.
    emf_interface_name_t name;
    /// Interface version.
    emf_version_t version;
} emf_interface_info_t;

/**
 * Interface of a module.
 */
typedef struct emf_interface_t {
    /// Interface pointer.
    void* EMF_MAYBE_NULL interface;
} emf_interface_t;

/**
 * Handle to a module loader.
 */
typedef struct emf_module_loader_handle_t {
    /// Loader id.
    int32_t id;
} emf_module_loader_handle_t;

/**
 * Internal handle to a module.
 */
typedef struct emf_module_loader_module_handle_t {
    /// Internal id.
    intptr_t id;
} emf_module_loader_module_handle_t;

/**
 * Type of a module.
 */
EMF_FIXED_BUFFER_TYPEDEF(emf_module_type_t, char, EMF_MODULE_LOADER_TYPE_MAX_LENGTH)

/**
 * Predefined handles.
 *
 * @note The handles 0-99 are reserved for the specification.
 * @note The handles 100-199 are reserved for the implementation.
 */
typedef enum emf_module_predefined_handles_t : int32_t {
    /// Handle to the native module loader.
    emf_module_predefined_handles_native = 0,
} emf_module_predefined_handles_t;

/**
 * Span of module infos.
 */
EMF_SPAN_TYPEDEF(emf_module_info_span_t, const emf_module_info_t)

/**
 * Span of interface infos.
 */
EMF_SPAN_TYPEDEF(emf_interface_info_span_t, const emf_interface_info_t)

/**
 * Span of interface extensions.
 */
EMF_SPAN_TYPEDEF(emf_interface_extension_span_t, const emf_interface_extension_t)

/**
 * Span of module types.
 */
EMF_SPAN_TYPEDEF(emf_module_type_span_t, emf_module_type_t)

/**
 * A descriptor of an interface.
 */
typedef struct emf_interface_descriptor_t {
    /// Interface info.
    emf_interface_info_t info;
    /// Interface extensions.
    emf_interface_extension_span_t extensions;
} emf_interface_descriptor_t;

/**
 * Span of interface descriptors.
 */
EMF_SPAN_TYPEDEF(emf_interface_descriptor_span_t, const emf_interface_descriptor_t)

/******************************************************************************************************
*********************************************  Interface  *********************************************
******************************************************************************************************/

/******************************************  Module Loader  ******************************************/

EMF_FUNCTION_PTR_T(
    emf_module_loader_interface_load, EMF_NODISCARD emf_module_loader_module_handle_t, const emf_path_t* EMF_NOT_NULL module_path)
EMF_FUNCTION_PTR_T(emf_module_loader_interface_unload, void, emf_module_loader_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_loader_interface_initialize, void, emf_module_loader_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_loader_interface_terminate, void, emf_module_loader_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_loader_interface_get_module_info, EMF_NODISCARD const emf_module_info_t* EMF_NOT_NULL,
    emf_module_loader_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_loader_interface_get_exported_interfaces,
    EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL, emf_module_loader_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_loader_interface_get_imported_interfaces,
    EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL, emf_module_loader_module_handle_t module_handle)
EMF_FUNCTION_PTR_T(emf_module_loader_interface_get_interface, EMF_NODISCARD emf_error_t,
    emf_module_loader_module_handle_t module_handle, const emf_interface_info_t* EMF_NOT_NULL required_interface,
    emf_interface_t* EMF_NOT_NULL interface)

/**
 * Interface of a module loader.
 */
typedef struct emf_module_loader_interface_t {
    /// Load function.
    emf_module_loader_interface_load_fn_t EMF_NOT_NULL load_fn;
    /// Unload function.
    emf_module_loader_interface_unload_fn_t EMF_NOT_NULL unload_fn;
    /// Initialize function.
    emf_module_loader_interface_initialize_fn_t EMF_NOT_NULL initialize_fn;
    /// Terminate function.
    emf_module_loader_interface_terminate_fn_t EMF_NOT_NULL terminate_fn;
    ///  Get module info function.
    emf_module_loader_interface_get_module_info_fn_t EMF_NOT_NULL get_module_info_fn;
    /// Get exported interfaces function.
    emf_module_loader_interface_get_exported_interfaces_fn_t EMF_NOT_NULL get_exported_interfaces_fn;
    /// Get imported interfaces function.
    emf_module_loader_interface_get_imported_interfaces_fn_t EMF_NOT_NULL get_imported_interfaces_fn;
    /// Get interface function.
    emf_module_loader_interface_get_interface_fn_t EMF_NOT_NULL get_interface_fn;
} emf_module_loader_interface_t;

/******************************************  Native Module  ******************************************/

EMF_FUNCTION_PTR_T(emf_native_module_interface_load, void, emf_module_handle_t module_handle,
    const emf_path_t* EMF_NOT_NULL module_path, emf_has_function_fn_t EMF_NOT_NULL has_function_fn,
    emf_get_function_fn_t EMF_NOT_NULL get_function_fn)
EMF_FUNCTION_PTR_T(emf_native_module_interface_unload, void, void)
EMF_FUNCTION_PTR_T(emf_native_module_interface_initialize, void, void)
EMF_FUNCTION_PTR_T(emf_native_module_interface_terminate, void, void)
EMF_FUNCTION_PTR_T(emf_native_module_interface_get_module_info, EMF_NODISCARD const emf_module_info_t* EMF_NOT_NULL, void)
EMF_FUNCTION_PTR_T(
    emf_native_module_interface_get_exported_interfaces, EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL, void)
EMF_FUNCTION_PTR_T(
    emf_native_module_interface_get_imported_interfaces, EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL, void)
EMF_FUNCTION_PTR_T(emf_native_module_interface_get_interface, EMF_NODISCARD emf_error_t,
    const emf_interface_info_t* EMF_NOT_NULL required_interface, emf_interface_t* EMF_NOT_NULL interface)

/**
 * Interface of a native module.
 */
typedef struct emf_native_module_interface_t {
    /// Load function.
    emf_native_module_interface_load_fn_t EMF_NOT_NULL load_fn;
    /// Unload function.
    emf_native_module_interface_unload_fn_t EMF_NOT_NULL unload_fn;
    /// Initialize function.
    emf_native_module_interface_initialize_fn_t EMF_NOT_NULL initialize_fn;
    /// Terminate function.
    emf_native_module_interface_terminate_fn_t EMF_NOT_NULL terminate_fn;
    /// Get module info function.
    emf_native_module_interface_get_module_info_fn_t EMF_NOT_NULL get_module_info_fn;
    /// Get exported interfaces function.
    emf_native_module_interface_get_exported_interfaces_fn_t EMF_NOT_NULL get_exported_interfaces_fn;
    /// Get imported interfaces function.
    emf_native_module_interface_get_imported_interfaces_fn_t EMF_NOT_NULL get_imported_interfaces_fn;
    /// Get interface function.
    emf_native_module_interface_get_interface_fn_t EMF_NOT_NULL get_interface_fn;
} emf_native_module_interface_t;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/**
 * @brief Registers a new loader.
 *
 * Registers a new loader, that can load modules of the type <code>module_type</code>.
 *
 * @note Requires synchronisation.
 * @note All names starting with "__" are reserved for the implementors of the "emf::core" module.
 * @note All names starting with "_Interface" are reserved for the implementors of the respective interface.
 *
 * @pre <code>loader_interface</code> may not be <code>NULL</code>.
 * @pre <code>module_type</code> may not be <code>NULL</code>.
 * @pre <code>emf_module_type_exists(module_type) == emf_bool_false</code>.
 *
 * @post The loader is registered.
 *
 * @param loader_interface Interface to the loader.
 * @param module_type Type of modules it can load.
 *
 * @return Loader handle.
 */
emf_module_loader_handle_t EMF_CALL_C emf_module_register_loader(
    const emf_module_loader_interface_t* EMF_NOT_NULL loader_interface,
    const emf_module_type_t* EMF_NOT_NULL module_type) EMF_NOEXCEPT;

/**
 * @brief Unregisters a loader.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>loader_handle</code> must be acquired by a call to emf_module_register_loader() or emf_module_get_loader_handle().
 *
 * @post All modules associated with the loader, and their dependencies, are unloaded.
 * @post The loader is unregistered.
 *
 * @param loader_handle Loader handle.
 */
void EMF_CALL_C emf_module_unregister_loader(emf_module_loader_handle_t loader_handle) EMF_NOEXCEPT;

/**
 * @brief Get the number of loaders.
 *
 * @note Requires synchronisation.
 *
 * @return Number of loaders.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_module_get_num_loaders() EMF_NOEXCEPT;

/**
 * @brief Copy the module types able to be loaded.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.length >= emf_module_get_num_loaders()</code>.
 * @pre <code>buffer.data != NULL</code>.
 *
 * @post <code>buffer</code> contains all library types.
 *
 * @param buffer Destination
 *
 * @return Number of module types.
 */
size_t EMF_CALL_C emf_module_get_module_types(emf_module_type_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Get the number of modules.
 *
 * @note Requires synchronisation.
 *
 * @return Number of modules.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_module_get_num_modules() EMF_NOEXCEPT;

/**
 * @brief Copy the loaded module infos.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.length >= emf_module_get_num_modules()</code>.
 * @pre <code>buffer.data != NULL</code>.
 *
 * @post <code>buffer</code> contains all loaded modules.
 *
 * @param buffer Destination
 *
 * @return Number of modules.
 */
size_t EMF_CALL_C emf_module_get_modules(emf_module_info_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Get the number of public interfaces.
 *
 * @note Requires synchronisation.
 *
 * @return Number of public interfaces.
 */
EMF_NODISCARD size_t EMF_CALL_C emf_module_get_num_public_interfaces() EMF_NOEXCEPT;

/**
 * @brief Copy the public interface infos.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>buffer</code> may not be <code>NULL</code>.
 * @pre <code>buffer.length >= emf_module_get_num_public_interfaces()</code>.
 * @pre <code>buffer.data != NULL</code>.
 *
 * @post <code>buffer</code> contains all loaded modules.
 *
 * @param buffer Destination
 *
 * @return Number of public interface infos.
 */
size_t EMF_CALL_C emf_module_get_public_interfaces(emf_interface_descriptor_span_t* EMF_NOT_NULL buffer) EMF_NOEXCEPT;

/**
 * @brief Get the handle of a loader by the module type it can load.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_type</code> may not be <code>NULL</code>.
 * @pre <code>emf_module_type_exists(module_type) == emf_bool_true</code>.
 *
 * @param module_type Module type.
 *
 * @return Handle to the loader.
 */
EMF_NODISCARD emf_module_loader_handle_t EMF_CALL_C emf_module_get_loader_handle(
    const emf_module_type_t* EMF_NOT_NULL module_type) EMF_NOEXCEPT;

/**
 * @brief Checks if a module type can be loaded.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_type</code> may not be <code>NULL</code>.
 *
 * @param module_type Module type.
 *
 * @return <code>emf_bool_true</code> if the module type can be loaded.
 * @return <code>emf_bool_false</code> if module type can not be loaded.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_module_type_exists(const emf_module_type_t* EMF_NOT_NULL module_type) EMF_NOEXCEPT;

/**
 * @brief Checks if a module is loaded.
 *
 * @note Requires synchronisation.
 *
 * @param module_handle Module handle.
 *
 * @return <code>emf_bool_true</code> if the module is loaded.
 * @return <code>emf_bool_false</code> if module is not loaded.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_module_module_exists(emf_module_handle_t module_handle) EMF_NOEXCEPT;

/**
 * @brief Get the handle of the module the interface belongs to.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>interface</code> may not be <code>NULL</code>.
 * @pre <code>emf_module_interface_exists(interface) == emf_bool_true</code>.
 *
 * @param interface Interface info.
 *
 * @return Handle to the module.
 */
EMF_NODISCARD emf_module_handle_t EMF_CALL_C emf_module_get_interface_handle(
    const emf_interface_info_t* EMF_NOT_NULL interface) EMF_NOEXCEPT;

/**
 * @brief Checks if an interface is public.
 *
 * @note Requires synchronisation.
 *
 * @param interface Interface.
 *
 * @return <code>emf_bool_true</code> if the interface is public.
 * @return <code>emf_bool_false</code> if module is not public.
 */
EMF_NODISCARD emf_bool_t EMF_CALL_C emf_module_interface_exists(const emf_interface_info_t* EMF_NOT_NULL interface) EMF_NOEXCEPT;

/******************************************************************************************************
*************************************  Unsafe system operations  *************************************
******************************************************************************************************/

/**
 * @brief Creates a new unlinked module handle.
 *
 * @note Requires synchronisation.
 *
 * @post A new unlinked module handle is created.
 *
 * @warning Using this handle without a call to emf_module_unsafe_link_module() will result in the termination of the program.
 *
 * @return Module handle.
 */
EMF_NODISCARD emf_module_handle_t EMF_CALL_C emf_module_unsafe_create_module_handle() EMF_NOEXCEPT;

/**
 * @brief Removes a module handle from the system.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> must be acquired by a call to emf_module_load() or emf_module_unsafe_create_module_handle().
 *
 * @post The handle is removed from the system.
 *
 * @warning Removing the handle does not unload the module.
 *
 * @param module_handle Module handle.
 */
void EMF_CALL_C emf_module_unsafe_remove_module_handle(emf_module_handle_t module_handle) EMF_NOEXCEPT;

/**
 * @brief Links the provided module handle to a loader and its handle.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> must be acquired by a call to emf_module_load() or emf_module_unsafe_create_module_handle().
 * @pre <code>loader_handle</code> must be acquired by a call to emf_module_register_loader() or emf_module_get_loader_handle().
 * @pre All interfaces in <code>public_interfaces</code> must be exposed by <code>loader_module_handle</code>.
 * @pre <code>for_each i in public_interfaces: emf_module_interface_exists(i) == emf_bool_false</code>.
 *
 * @post <code>module_handle</code> refers to the internal module <code>loader_module_handle</code> from the loader
 * <code>loader_handle</code>.
 * @post <code>for_each i in public_interfaces: emf_module_get_interface_handle(&i) == module_handle</code>.
 *
 * @warning Overwrites existing link, if it exists.
 * @warning Unsafe if <code>module_handle</code> was not acquired by a call to emf_module_unsafe_create_module_handle().
 * @warning Unsafe if <code>loader_library_handle</code> was acquired by a call to emf_module_unsafe_get_loader_module_handle().
 * @warning The uniqueness of the pair <code>loader_handle</code>, <code>loader_library_handle</code> must be ensured before a
 * call to emf_module_unload().
 *
 * @param module_handle Module handle.
 * @param loader_handle Loader handle.
 * @param loader_module_handle Internal module handle.
 * @param public_interfaces Interfaces to expose.
 */
void EMF_CALL_C emf_module_unsafe_link_module(emf_module_handle_t module_handle, emf_module_loader_handle_t loader_handle,
    emf_module_loader_module_handle_t loader_module_handle,
    const emf_interface_info_span_t* EMF_MAYBE_NULL public_interfaces) EMF_NOEXCEPT;

/**
 * @brief Get the internal handle of a module.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> has been obtained through a call to emf_module_load() or has been manually linked by calling
 * emf_module_unsafe_link_module().
 *
 * @param module_handle Module handle.
 *
 * @return Internal module handle.
 */
EMF_NODISCARD emf_module_loader_module_handle_t EMF_CALL_C emf_module_unsafe_get_loader_module_handle(
    emf_module_handle_t module_handle) EMF_NOEXCEPT;

/**
 * @brief Get the interface to a loader.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>loader_handle</code> must be acquired by a call to emf_module_register_loader() or emf_module_get_loader_handle().
 *
 * @warning The usage of the interface is safe as long as emf_unlock() has not been called. Otherwise the interface may have been
 * unregistered.
 *
 * @param loader_handle Loader handle.
 *
 * @return Interface of the loader.
 */
EMF_NODISCARD emf_module_loader_interface_t EMF_CALL_C emf_module_unsafe_get_loader(
    emf_module_loader_handle_t loader_handle) EMF_NOEXCEPT;

/******************************************************************************************************
*****************************************  Loader operations  *****************************************
******************************************************************************************************/

/**
 * @brief Loads a module.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>loader_handle</code> must be acquired by a call to emf_module_register_loader() or emf_module_get_loader_handle().
 * @pre All interfaces in <code>public_interfaces</code> must be exposed by <code>loader_module_handle</code>.
 * @pre <code>for_each i in public_interfaces: emf_module_interface_exists(i) == emf_bool_false</code>.
 * @pre <code>module_path</code> may not be <code>NULL</code>.
 * @pre <code>The</code> module pointed to by the path <code>module_path</code> must be of a type that is loadable by
 * <code>loader_handle</code>.
 *
 * @post A new module is loaded.
 * @post <code>for_each i in public_interfaces: emf_module_get_interface_handle(&i) == module_handle</code>.
 *
 * @param loader_handle Handle of the used loader.
 * @param public_interfaces Interfaces to expose.
 * @param module_path Path of the module.
 *
 * @return Module handle.
 */
EMF_NODISCARD emf_module_handle_t EMF_CALL_C emf_module_load(emf_module_loader_handle_t loader_handle,
    const emf_interface_info_span_t* EMF_MAYBE_NULL public_interfaces, const emf_path_t* EMF_NOT_NULL module_path) EMF_NOEXCEPT;

/**
 * @brief Unloads a module.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> must be acquired by a call to emf_module_load() or emf_module_unsafe_create_module_handle().
 *
 * @post The module is unloaded.
 * @post Every module that depends on <code>module_handle</code> are unloaded.
 * @post Every interface exposed by <code>module_handle</code> is removed.
 * @post <code>module_handle</code> is invalidated.
 *
 * @param module_handle Handle of the module.
 */
void EMF_CALL_C emf_module_unload(emf_module_handle_t module_handle) EMF_NOEXCEPT;

/**
 * @brief Initializes a module.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> must be acquired by a call to emf_module_load() or emf_module_unsafe_create_module_handle().
 *
 * @post The module is initialized and ready to be used.
 *
 * @param module_handle Handle of the module.
 */
void EMF_CALL_C emf_module_initialize(emf_module_handle_t module_handle) EMF_NOEXCEPT;

/**
 * @brief Terminates a module.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> must be acquired by a call to emf_module_load() or emf_module_unsafe_create_module_handle().
 *
 * @post The module, and all modules that depend on it, are terminated.
 *
 * @param module_handle Handle of the module.
 */
void EMF_CALL_C emf_module_terminate(emf_module_handle_t module_handle) EMF_NOEXCEPT;

/**
 * @brief Retrieves the information of a module.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> must be acquired by a call to emf_module_load() or emf_module_unsafe_create_module_handle().
 *
 * @param module_handle Handle of the module.
 *
 * @return Information of the module.
 */
EMF_NODISCARD const emf_module_info_t* EMF_NOT_NULL EMF_CALL_C emf_module_get_module_info(
    emf_module_handle_t module_handle) EMF_NOEXCEPT;

/**
 * @brief Retrieves the exposed interfaces of a module
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> must be acquired by a call to emf_module_load() or emf_module_unsafe_create_module_handle().
 *
 * @param module_handle Handle of the module.
 *
 * @return Span of exposed interfaces.
 */
EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL EMF_CALL_C emf_module_get_exported_interfaces(
    emf_module_handle_t module_handle) EMF_NOEXCEPT;

/**
 * @brief Retrieves the dependencies of a module
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> must be acquired by a call to emf_module_load() or emf_module_unsafe_create_module_handle().
 *
 * @param module_handle Handle of the module.
 *
 * @return Span of dependencies.
 */
EMF_NODISCARD const emf_interface_descriptor_span_t* EMF_NOT_NULL EMF_CALL_C emf_module_get_imported_interfaces(
    emf_module_handle_t module_handle) EMF_NOEXCEPT;

/**
 * @brief Retrieves an interface from a module.
 *
 * @note Requires synchronisation.
 *
 * @pre <code>module_handle</code> must be acquired by a call to emf_module_load() or emf_module_unsafe_create_module_handle().
 * @pre <code>interface_info</code> may not be <code>NULL</code>.
 * @pre <code>interface</code> may not be <code>NULL</code>.
 *
 * @post <code>interface.interface</code> points to the interface or is <code>NULL</code>.
 *
 * @param module_handle Handle of the module.
 * @param interface_info The interface to retrieve.
 * @param interface Interface.
 *
 * @return <code>emf_error_none</code> if the interface exists.
 * @return <code>emf_error_not_found</code> if the interface does not exist.
 */
EMF_NODISCARD emf_error_t EMF_CALL_C emf_module_get_interface(emf_module_handle_t module_handle,
    const emf_interface_info_t* EMF_NOT_NULL interface_info, emf_interface_t* EMF_NOT_NULL interface) EMF_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_EMF_MODULE_H
