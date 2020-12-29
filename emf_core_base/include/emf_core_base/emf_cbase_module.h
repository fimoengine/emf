//! # Introduction
//!
//! The `module` api is built on top of the `library` api and specifies the loading and unloading of `modules`.
//! A `module` is a collection libraries and resources, that together form an independent unit.
//! Similarly to the `library` api, the loading and unloading of modules is implemented by `module loaders`,
//! which are associated to one `module type`.
//!
//! ## Loaders
//!
//! `Module loaders` implement the actual loading and unloading of modules. Custom `module loaders` can be added by
//! constructing a [`emf_cbase_module_loader_interface_t`](./struct.emf_cbase_module_loader_interface_t.md)
//! and calling the [`emf_cbase_module_register_loader()`](./fn.emf_cbase_module_register_loader.md) function.
//!
//! ## Module types
//!
//! The type of a module identifies a `module loader` capable of loading a specific module.
//! A `module type` is represented by a [`emf_cbase_module_type_t`](./struct.emf_cbase_module_type_t.md).
//!
//! # Module structure
//!
//! > module/module.json\
//! > module/...\
//! > ...\
//!
//! A `module` is a simple directory containing all the required resources.
//! The internal structure of the `module` is defined by the respective `module loader`.
//! The only requirement is the existence of the `module.json` file at the root of the module.
//! This file is the `module manifest` and specifies that the directory is indeed a module.
//!
//! # Module manifest
//!
//! The `module manifest` identifies a module and specifies how a module can be loaded.
//! To allow for backwards (and forwards) compatibility, the version of the `manifest schema`
//! is saved in the manifest with the key `schema`.
//!
//! ## Version 0
//!
//! The version `0` introduces several required and optional fields:
//!
//! - `name`: A `string` describing the name of the module. Has a maximum length of 32 ASCII characters. Is required.
//! - `type`: A `string` describing the `module type` of the module. Has a maximum length of 64 ASCII characters. Is required.
//! - `version`: A `string` describing the version of the module. Has a maximum length of 32 ASCII characters. Is required.
//! - `load_dependencies`: An `array` of `<interface_descriptors>` describing the load dependencies.
//! - `runtime_dependencies`: An `array` of `<interface_descriptors>` describing the runtime dependencies.
//! - `exports`: An `array` of `<interface_descriptors>` describing the exportable interfaces.
//!
//! The definition of the custom types can be found below:
//!
//! - `<interface_descriptor>`: The descriptor of an interface.
//!   - `name`: A `string` describing the name of the interface. Has a maximum length of 32 ASCII characters. Is required.
//!   - `version`: A `<version>` describing the version of the interface. Is required.
//!   - `extensions`: An `array` of strings describing the extensions of the interface. Each extension has a maximum length of 32
//!   ASCII characters.
//!
//! - `<version>`: The `string` representation of a version. See [`Versions`](../../conventions.md#versions).
//!
//! Example:
//!
//! ```json
//! {
//!     "schema": 0,
//!     "name": "jobs",
//!     "type": "emf::core_base::native",
//!     "version": "0.1.5-rc.7-a",
//!     "load_dependencies": [{
//!         "name": "memory",
//!         "version": "0.1.0"
//!     }],
//!     "runtime_dependencies": [{
//!         "name": "logging",
//!         "version": "1.0.0"
//!     }],
//!     "exports": [{
//!         "name": "jobs_interface",
//!         "version": "1.0.0",
//!         "extensions": [
//!             "schedulers",
//!             "fibers"
//!         ]
//!     }]
//! }
//! ```
//!
//! # Predefined Loaders
//!
//! Some `module loaders` are always present and can not be removed at runtime.
//!
//! ## Native
//!
//! The native `module loader` is built on top of the native `library loader` and is able to load modules consisting of native
//! libraries. It is reachable with the
//! [`EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE`](./constant.EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE.md) handle. The same restrictions
//! of the native `library loader` apply to the native `module loader`. The native `module loader` requires the presence of a
//! `native module manifest` file named `native_module.json` at the root of the module.
//!
//! ### Native module manifest
//!
//! The `native module manifest` specifies which library implements the module.
//! To allow for backwards (and forwards) compatibility, the version of the `manifest schema`
//! is saved in the manifest with the key `schema`.
//!
//! #### Native module manifest version 0
//!
//! The version `0` requires one field:
//!
//! - `library_path`: A `string` describing the relative path to the library. Is required.
//!
//! Example:
//!
//! ```json
//! {
//!     "schema": 0,
//!     "library_path": "./lib/jobs.so"
//! }
//! ```
//!
//! ### Native module interface
//!
//! Once the module library has been loaded by the native `library loader`, the native `module loader` searches for a symbol with
//! the name `emf_cbase_native_module_interface` (see
//! [`EMF_CBASE_NATIVE_MODULE_INTERFACE_SYMBOL_NAME`](./constant.EMF_CBASE_NATIVE_MODULE_INTERFACE_SYMBOL_NAME.md)) and the type
//! [`emf_cbase_native_module_interface_t`](./struct.emf_cbase_native_module_interface_t.md).
//!
//! # Example
//!
//! ```c
//! emf_cbase_sys_lock();
//!
//! const emf_cbase_os_path_char_t* module_path = "./jobs_module";
//! emf_cbase_module_handle_result_t module_handle_res =
//!     emf_cbase_module_add_module(EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE, module_path);
//! if (module_handle_res.has_error) {
//!     emf_cbase_sys_panic("Unable to load the `./jobs_module` module.");
//! }
//! emf_cbase_module_handle_t module_handle = module_handle_res.result;
//!
//! emf_cbase_module_error_optional_t error_opt;
//! error_opt = emf_cbase_module_load(module_handle);
//! if (error_opt.has_value) {
//!     emf_cbase_sys_panic("Unable to load the `./jobs_module` module.");
//! }
//!
//! error_opt = emf_cbase_module_initialize(module_handle);
//! if (error_opt.has_value) {
//!     emf_cbase_sys_panic("Unable to initialize the `./jobs_module` module.");
//! }
//!
//! emf_cbase_interface_descriptor_t interface_descriptor = {
//!     .name = { .data = "jobs_interface", .length = 14 },
//!     .version = emf_cbase_version_construct_short(1, 0, 0),
//!     .extensions = { .data = NULL, length = 0 }
//! }
//! error_opt = emf_cbase_module_export_interface(module_handle, &interface_descriptor);
//! if (error_opt.has_value) {
//!     emf_cbase_sys_panic("Unable to export `jobs_interface` "
//!         "from the `./jobs_module` module.");
//! }
//!
//! emf_cbase_sys_unlock();
//! ```
#ifndef EMF_CORE_BASE_EMF_CBASE_MODULE_H
#define EMF_CORE_BASE_EMF_CBASE_MODULE_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif // __cplusplus

#include <emf_core_base/emf_cbase_fn_ptr_id_t.h>
#include <emf_core_base/emf_cbase_library.h>
#include <emf_core_base/emf_cbase_macros.h>
#include <emf_core_base/emf_cbase_version_t.h>

/// Max length of a module name.
#define EMF_CBASE_MODULE_INFO_NAME_MAX_LENGTH 32

/// Max length of a module version string.
#define EMF_CBASE_MODULE_INFO_VERSION_MAX_LENGTH 32

/// Max length of an interface name string.
#define EMF_CBASE_INTERFACE_INFO_NAME_MAX_LENGTH 32

/// Max length of an interface extension name.
#define EMF_CBASE_INTERFACE_EXTENSION_NAME_MAX_LENGTH 32

/// Max length of a module type name.
#define EMF_CBASE_MODULE_LOADER_TYPE_MAX_LENGTH 64

/// Name of the native module type.
#define EMF_CBASE_NATIVE_MODULE_TYPE_NAME "emf::core_base::native"

/// Name of the native interface symbol.
#define EMF_CBASE_NATIVE_MODULE_INTERFACE_SYMBOL_NAME emf_cbase_native_module_interface

#ifdef __cplusplus
/// Handle to the default module loader.
#define EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE                                                                                   \
    emf_cbase_module_loader_handle_t { EMF::CoreBase::C::emf_cbase_module_predefined_handles_native }
#else
/// Handle to the default module loader.
#define EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE                                                                                   \
    (emf_cbase_module_loader_handle_t) { emf_cbase_module_predefined_handles_native }
#endif // __cplusplus

#ifdef __cplusplus
namespace EMF::CoreBase::C {
#endif // __cplusplus

/******************************************************************************************************
***********************************************  Types  ***********************************************
******************************************************************************************************/

/// An opaque structure representing the emf-core-base interface.
typedef struct emf_cbase_t emf_cbase_t;

#ifndef EMF_CBASE_SYS_FN_OPTIONAL_T_DEF
#define EMF_CBASE_SYS_FN_OPTIONAL_T_DEF
/// An optional `emf_cbase_fn_t` value
///
/// # Fields
///
/// - **value**: [`emf_cbase_fn_t`](./type.emf_cbase_fn_t.md)
///
///     A pointer to a function.
///
/// - **has_value**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the optional contains a value.
EMF_CBASE_OPTIONAL_TYPEDEF(emf_cbase_sys_fn_optional_t, emf_cbase_fn_t EMF_CBASE_NOT_NULL)
#endif // !EMF_CBASE_SYS_FN_OPTIONAL_T_DEF

/// Function pointer to the `emf_cbase_sys_has_function` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_has_function, EMF_CBASE_NODISCARD emf_cbase_bool_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_fn_ptr_id_t fn_id)

/// Function pointer to the `emf_cbase_sys_get_function` function.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_sys_get_function, EMF_CBASE_NODISCARD emf_cbase_sys_fn_optional_t,
    emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module, emf_cbase_fn_ptr_id_t fn_id)

/// An enum describing all possible module states.
///
/// # Variants
///
/// | Name                                   | Value | Description                      |
/// | -------------------------------------- | ----- | -------------------------------- |
/// | **emf_cbase_module_status_unloaded**   | `0`   | The module has not been loaded.  |
/// | **emf_cbase_module_status_terminated** | `1`   | The module has been loaded.      |
/// | **emf_cbase_module_status_ready**      | `2`   | The module has been initialized. |
typedef enum emf_cbase_module_status_t : int32_t {
    emf_cbase_module_status_unloaded = 0,
    emf_cbase_module_status_terminated = 1,
    emf_cbase_module_status_ready = 2,
} emf_cbase_module_status_t;

/// A handle to a module
///
/// # Fields
///
/// - **id**: `int32_t`
///
///     The id of the module.
typedef struct emf_cbase_module_handle_t {
    /// Module id.
    int32_t id;
} emf_cbase_module_handle_t;

/// The name of a module.
///
/// A module name is modelled as an `UTF-8` encoded string, without a `\0` terminator.
///
/// # Fields
///
/// - **data**: [`char[EMF_CBASE_MODULE_INFO_NAME_MAX_LENGTH]`](./constant.EMF_CBASE_MODULE_INFO_NAME_MAX_LENGTH.md)
///
///     The name string.
///
/// - **length**: `size_t`
///
///     Length of the string.
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_module_name_t, char, EMF_CBASE_MODULE_INFO_NAME_MAX_LENGTH)

/// The version string of a module.
///
/// A version string is modelled as an `UTF-8` encoded string, without a `\0` terminator.
///
/// # Fields
///
/// - **data**: [`char[EMF_CBASE_MODULE_INFO_VERSION_MAX_LENGTH]`](./constant.EMF_CBASE_MODULE_INFO_VERSION_MAX_LENGTH.md)
///
///     The version string.
///
/// - **length**: `size_t`
///
///     Length of the string.
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_module_version_t, char, EMF_CBASE_MODULE_INFO_VERSION_MAX_LENGTH)

/// Module info.
///
/// # Fields
///
/// - **name**: [`emf_cbase_module_name_t`](./struct.emf_cbase_module_name_t.md)
///
///     The name of the module.
///
/// - **version**: [`emf_cbase_module_version_t`](./struct.emf_cbase_module_version_t.md)
///
///     The version of the module.
typedef struct emf_cbase_module_info_t {
    /// Module name.
    emf_cbase_module_name_t name;
    /// Module version string.
    emf_cbase_module_version_t version;
} emf_cbase_module_info_t;

/// An extension of an interface.
///
/// An interface extension is modelled as an `UTF-8` encoded string, without a `\0` terminator.
///
/// # Fields
///
/// - **data**:
/// [`char[EMF_CBASE_INTERFACE_EXTENSION_NAME_MAX_LENGTH]`](./constant.EMF_CBASE_INTERFACE_EXTENSION_NAME_MAX_LENGTH.md)
///
///     The extension string.
///
/// - **length**: `size_t`
///
///     Length of the string.
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_interface_extension_t, char, EMF_CBASE_INTERFACE_EXTENSION_NAME_MAX_LENGTH)

/// The name of an interface.
///
/// An interface extension is modelled as an `UTF-8` encoded string, without a `\0` terminator.
///
/// # Fields
///
/// - **data**:
/// [`char[EMF_CBASE_INTERFACE_INFO_NAME_MAX_LENGTH]`](./constant.EMF_CBASE_INTERFACE_INFO_NAME_MAX_LENGTH.md)
///
///     The name string.
///
/// - **length**: `size_t`
///
///     Length of the string.
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_interface_name_t, char, EMF_CBASE_INTERFACE_INFO_NAME_MAX_LENGTH)

/// An interface.
///
/// # Fields
///
/// - **interface**: `void*`
///
///     A pointer to the interface.
///     Is never `NULL`.
typedef struct emf_cbase_module_interface_t {
    /// Interface pointer.
    void* EMF_CBASE_NOT_NULL interface;
} emf_cbase_module_interface_t;

/// A handle to a module loader.
///
/// # Fields
///
/// - **id**: `int32_t`
///
///     The id of the loader.
typedef struct emf_cbase_module_loader_handle_t {
    /// Loader id.
    int32_t id;
} emf_cbase_module_loader_handle_t;

/// An internal module handle used by module loaders.
///
/// # Fields
///
/// - **id**: `intptr_t`
///
///     Internal id of the module.
typedef struct emf_cbase_module_loader_module_handle_t {
    /// Internal id.
    intptr_t id;
} emf_cbase_module_loader_module_handle_t;

/// The type of a module
///
/// A module type is modelled as an `UTF-8` encoded string, without a `\0` terminator.
///
/// # Fields
///
/// - **data**: [`char[EMF_CBASE_MODULE_LOADER_TYPE_MAX_LENGTH]`](./constant.EMF_CBASE_MODULE_LOADER_TYPE_MAX_LENGTH.md)
///
///     The type string.
///
/// - **length**: `size_t`
///
///     Length of the string.
EMF_CBASE_FIXED_BUFFER_TYPEDEF(emf_cbase_module_type_t, char, EMF_CBASE_MODULE_LOADER_TYPE_MAX_LENGTH)

/// An enum describing all predefined module loader handles.
///
/// The values `0-99` are reserved for future use.
///
/// # Variants
///
/// | Name                                           | Value | Description            |
/// | ---------------------------------------------- | ----- | ---------------------- |
/// | **emf_cbase_module_predefined_handles_native** | `0`   | The default handle.    |
typedef enum emf_cbase_module_predefined_handles_t : int32_t {
    /// Handle to the native module loader.
    emf_cbase_module_predefined_handles_native = 0,
} emf_cbase_module_predefined_handles_t;

/// A span of module infos.
///
/// # Fields
///
/// - **data**: [`emf_cbase_module_info_t*`](./struct.emf_cbase_module_info_t.md)
///
///     The start of the span.
///
/// - **length**: `size_t`
///
///     The length of the span.
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_module_info_span_t, emf_cbase_module_info_t)

/// A span of interface extensions.
///
/// # Fields
///
/// - **data**: [`const emf_cbase_interface_extension_t*`](./struct.emf_cbase_interface_extension_t.md)
///
///     The start of the span.
///
/// - **length**: `size_t`
///
///     The length of the span.
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_interface_extension_span_t, const emf_cbase_interface_extension_t)

/// A span of module types.
///
/// # Fields
///
/// - **data**: [`emf_cbase_module_type_t*`](./struct.emf_cbase_module_type_t.md)
///
///     The start of the span.
///
/// - **length**: `size_t`
///
///     The length of the span.
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_module_type_span_t, emf_cbase_module_type_t)

/// A descriptor of an interface.
///
/// # Fields
///
/// - **name**: [`emf_cbase_interface_name_t`](./struct.emf_cbase_interface_name_t.md)
///
///     The name of the interface.
///
/// - **version**: [`emf_cbase_version_t`](./struct.emf_cbase_version_t.md)
///
///     The version of the interface.
///
/// - **extensions**: [`emf_cbase_interface_extension_span_t`](./struct.emf_cbase_interface_extension_span_t.md)
///
///     The extensions of the interface.
typedef struct emf_cbase_interface_descriptor_t {
    /// Interface name.
    emf_cbase_interface_name_t name;
    /// Interface version.
    emf_cbase_version_t version;
    /// Interface extensions.
    emf_cbase_interface_extension_span_t extensions;
} emf_cbase_interface_descriptor_t;

/// An enum describing all defined error values.
///
/// The values `0-99` are reserved for future use.
///
/// # Variants
///
/// | Name                                                    | Value | Description                                            |
/// | ------------------------------------------------------- | ----- | ------------------------------------------------------ |
/// | **emf_cbase_module_error_path_invalid**                 | `0`   | The path is invalid.                                   |
/// | **emf_cbase_module_error_module_state_invalid**         | `1`   | The state of the module is invalid.                    |
/// | **emf_cbase_module_error_module_handle_invalid**        | `2`   | The module handle is invalid.                          |
/// | **emf_cbase_module_error_loader_handle_invalid**        | `3`   | The loader is invalid.                                 |
/// | **emf_cbase_module_error_loader_module_handle_invalid** | `4`   | The internal module handle is invalid.                 |
/// | **emf_cbase_module_error_module_type_invalid**          | `5`   | The module type is invalid.                            |
/// | **emf_cbase_module_error_module_type_not_found**        | `6`   | The module type does not exist.                        |
/// | **emf_cbase_module_error_duplicate_module_type**        | `7`   | The operation would result in a duplicate module type. |
/// | **emf_cbase_module_error_interface_not_found**          | `8`   | The interface could not be found.                      |
/// | **emf_cbase_module_error_duplicate_interface**          | `9`   | The operation would result in a duplicate interface.   |
/// | **emf_cbase_module_error_module_dependency_not_found**  | `10`  | A dependency could not be found.                       |
/// | **emf_cbase_module_error_buffer_overflow**              | `11`  | The operation would result in a buffer overflow.       |
typedef enum emf_cbase_module_error_t : int32_t {
    emf_cbase_module_error_path_invalid = 0,
    emf_cbase_module_error_module_state_invalid = 1,
    emf_cbase_module_error_module_handle_invalid = 2,
    emf_cbase_module_error_loader_handle_invalid = 3,
    emf_cbase_module_error_loader_module_handle_invalid = 4,
    emf_cbase_module_error_module_type_invalid = 5,
    emf_cbase_module_error_module_type_not_found = 6,
    emf_cbase_module_error_duplicate_module_type = 7,
    emf_cbase_module_error_interface_not_found = 8,
    emf_cbase_module_error_duplicate_interface = 9,
    emf_cbase_module_error_module_dependency_not_found = 10,
    emf_cbase_module_error_buffer_overflow = 11,
} emf_cbase_module_error_t;

/// A span of interface descriptors.
///
/// # Fields
///
/// - **data**: [`const emf_cbase_interface_descriptor_t*`](./struct.emf_cbase_interface_descriptor_t.md)
///
///     The start of the span.
///
/// - **length**: `size_t`
///
///     The length of the span.
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_interface_descriptor_span_t, emf_cbase_interface_descriptor_t)

/// A span of constant interface descriptors.
///
/// # Fields
///
/// - **data**: [`const emf_cbase_interface_descriptor_t*`](./struct.emf_cbase_interface_descriptor_t.md)
///
///     The start of the span.
///
/// - **length**: `size_t`
///
///     The length of the span.
EMF_CBASE_SPAN_TYPEDEF(emf_cbase_interface_descriptor_const_span_t, const emf_cbase_interface_descriptor_t)

/// An optional `emf_cbase_module_error_t` value
///
/// # Fields
///
/// - **value**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error value.
///
/// - **has_value**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the optional contains a value.
EMF_CBASE_OPTIONAL_TYPEDEF(emf_cbase_module_error_optional_t, emf_cbase_module_error_t)

/// A struct containing either an `emf_cbase_module_interface_t` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_module_interface_t`](./struct.emf_cbase_module_interface_t.md)
///
///     The interface.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_interface_result_t, emf_cbase_module_interface_t, emf_cbase_module_error_t)

/// A struct containing either an `emf_cbase_module_handle_t` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_module_handle_t`](./struct.emf_cbase_module_handle_t.md)
///
///     The module handle.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_handle_result_t, emf_cbase_module_handle_t, emf_cbase_module_error_t)

/// A struct containing either an `emf_cbase_module_status_t` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_module_status_t`](./enum.emf_cbase_module_status_t.md)
///
///     The status of the module.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_status_result_t, emf_cbase_module_status_t, emf_cbase_module_error_t)

/// A struct containing either an `emf_cbase_module_loader_module_handle_t` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_module_loader_module_handle_t`](./struct.emf_cbase_module_loader_module_handle_t.md)
///
///     The internal handle of the module.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_module_loader_module_handle_result_t, emf_cbase_module_loader_module_handle_t, emf_cbase_module_error_t)

/// A struct containing either an `emf_cbase_interface_descriptor_const_span_t` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_interface_descriptor_const_span_t`](./struct.emf_cbase_interface_descriptor_const_span_t.md)
///
///     The span of interface descriptors.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_interface_descriptor_const_span_result_t, emf_cbase_interface_descriptor_const_span_t, emf_cbase_module_error_t)

/// A struct containing either an `const emf_cbase_module_info_t*` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`const emf_cbase_module_info_t*`](./struct.emf_cbase_module_info_t.md)
///
///     The pointer to a module info.
///     Is never `NULL`.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_module_info_ptr_result_t, const emf_cbase_module_info_t* EMF_CBASE_NOT_NULL, emf_cbase_module_error_t)

/// A struct containing either an `emf_cbase_module_loader_handle_t` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_module_loader_handle_t`](./struct.emf_cbase_module_loader_handle_t.md)
///
///     The handle of the loader.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_loader_handle_result_t, emf_cbase_module_loader_handle_t, emf_cbase_module_error_t)

/// A struct containing either a `size_t` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: `size_t`
///
///     The size value.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_size_result_t, size_t, emf_cbase_module_error_t)

/// A struct containing either a `const emf_cbase_os_path_char_t*` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`const emf_cbase_os_path_char_t*`](./type.emf_cbase_os_path_char_t.md)
///
///     The handle of the loader.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_os_path_char_result_t, const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL, emf_cbase_module_error_t)

/******************************************************************************************************
*********************************************  Interface  *********************************************
******************************************************************************************************/

/******************************************  Module Loader  ******************************************/

/// An opaque structure representing a module loader.
typedef struct emf_cbase_module_loader_t emf_cbase_module_loader_t;

/// A function pointer to a `add_module` function.
///
/// This function loads the module, which is located at `module_path`, and returns its handle.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_add_module,
    EMF_CBASE_NODISCARD emf_cbase_module_loader_module_handle_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL module_path)

/// A function pointer to a `remove_module` function.
///
/// This function unloads a module, that was loaded previously.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_remove_module, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `fetch_status` function.
///
/// This function returns the status of an already loaded module.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_fetch_status, EMF_CBASE_NODISCARD emf_cbase_module_status_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `load` function.
///
/// This function executes the loading procedure of the module.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_load, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `unload` function.
///
/// This function executes the unloading procedure of the module.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_unload, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `initialize` function.
///
/// This function executes the initialization procedure of the module.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_initialize, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `terminate` function.
///
/// This function executes the termination procedure of the module.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_terminate, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `get_module_info` function.
///
/// This function fetches the module info from a module.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_module_info,
    EMF_CBASE_NODISCARD emf_cbase_module_info_ptr_result_t, emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader,
    emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `get_exportable_interfaces_fn` function.
///
/// This function fetches the exportable interfaces from a module.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_exportable_interfaces,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `get_runtime_dependencies` function.
///
/// This function fetches the runtime dependencies from a module.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_runtime_dependencies,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `get_interface` function.
///
/// This function fetches an interface from a module.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_interface, EMF_CBASE_NODISCARD emf_cbase_module_interface_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)

/// A function pointer to a `get_load_dependencies` function.
///
/// This function fetches a list of dependencies the module needs to allow its loading.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_load_dependencies,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// A function pointer to a `get_module_path` function.
///
/// This function fetches the path a module was loaded from.
/// The function must be thread-safe.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_module_loader_interface_get_module_path, EMF_CBASE_NODISCARD emf_cbase_os_path_char_result_t,
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader, emf_cbase_module_loader_module_handle_t module_handle)

/// Interface of a module loader.
///
/// # Fields
///
/// - **module_loader**: [`emf_cbase_module_loader_t`](./struct.emf_cbase_module_loader_t.md)
///
///     A pointer to the module loader.
///
/// - **add_module_fn**:
/// [`emf_cbase_module_loader_interface_add_module_fn_t`](./type.emf_cbase_module_loader_interface_add_module_fn_t.md)
///
///     The add_module function of the module loader.
///     May not be `NULL`.
///
/// - **remove_module_fn**:
/// [`emf_cbase_module_loader_interface_remove_module_fn_t`](./type.emf_cbase_module_loader_interface_remove_module_fn_t.md)
///
///     The remove_module function of the module loader.
///     May not be `NULL`.
///
/// - **fetch_status_fn**:
/// [`emf_cbase_module_loader_interface_fetch_status_fn_t`](./type.emf_cbase_module_loader_interface_fetch_status_fn_t.md)
///
///     The fetch_status function of the module loader.
///     May not be `NULL`.
///
/// - **load_fn**: [`emf_cbase_module_loader_interface_load_fn_t`](./type.emf_cbase_module_loader_interface_load_fn_t.md)
///
///     The load function of the module loader.
///     May not be `NULL`.
///
/// - **unload_fn**: [`emf_cbase_module_loader_interface_unload_fn_t`](./type.emf_cbase_module_loader_interface_unload_fn_t.md)
///
///     The unload function of the module loader.
///     May not be `NULL`.
///
/// - **initialize**:
/// [`emf_cbase_module_loader_interface_initialize_fn_t`](./type.emf_cbase_module_loader_interface_initialize_fn_t.md)
///
///     The initialize function of the module loader.
///     May not be `NULL`.
///
/// - **terminate_fn**:
/// [`emf_cbase_module_loader_interface_terminate_fn_t`](./type.emf_cbase_module_loader_interface_terminate_fn_t.md)
///
///     The terminate function of the module loader.
///     May not be `NULL`.
///
/// - **get_module_info_fn**:
/// [`emf_cbase_module_loader_interface_get_module_info_fn_t`](./type.emf_cbase_module_loader_interface_get_module_info_fn_t.md)
///
///     The get_module_info function of the module loader.
///     May not be `NULL`.
///
/// - **get_exportable_interfaces_fn**:
/// [`emf_cbase_module_loader_interface_get_exportable_interfaces_fn_t`](./type.emf_cbase_module_loader_interface_get_exportable_interfaces_fn_t.md)
///
///     The get_exportable_interfaces function of the module loader.
///     May not be `NULL`.
///
/// - **get_runtime_dependencies_fn**:
/// [`emf_cbase_module_loader_interface_get_runtime_dependencies_fn_t`](./type.emf_cbase_module_loader_interface_get_runtime_dependencies_fn_t.md)
///
///     The get_runtime_dependencies function of the module loader.
///     May not be `NULL`.
///
/// - **get_interface_fn**:
/// [`emf_cbase_module_loader_interface_get_interface_fn_t`](./type.emf_cbase_module_loader_interface_get_interface_fn_t.md)
///
///     The get_interface function of the module loader.
///     May not be `NULL`.
///
/// - **get_load_dependencies_fn**:
/// [`emf_cbase_module_loader_interface_get_load_dependencies_fn_t`](./type.emf_cbase_module_loader_interface_get_load_dependencies_fn_t.md)
///
///     The get_load_dependencies function of the module loader.
///     May not be `NULL`.
///
/// - **get_module_path_fn**:
/// [`emf_cbase_module_loader_interface_get_module_path_fn_t`](./type.emf_cbase_module_loader_interface_get_module_path_fn_t.md)
///
///     The get_module_path function of the module loader.
///     May not be `NULL`.
typedef struct emf_cbase_module_loader_interface_t {
    /// Module loader.
    emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader;
    /// Add module function.
    emf_cbase_module_loader_interface_add_module_fn_t EMF_CBASE_NOT_NULL add_module_fn;
    /// Remove module function.
    emf_cbase_module_loader_interface_remove_module_fn_t EMF_CBASE_NOT_NULL remove_module_fn;
    /// Fetch status function.
    emf_cbase_module_loader_interface_fetch_status_fn_t EMF_CBASE_NOT_NULL fetch_status_fn;
    /// Load function.
    emf_cbase_module_loader_interface_load_fn_t EMF_CBASE_NOT_NULL load_fn;
    /// Unload function.
    emf_cbase_module_loader_interface_unload_fn_t EMF_CBASE_NOT_NULL unload_fn;
    /// Initialize function.
    emf_cbase_module_loader_interface_initialize_fn_t EMF_CBASE_NOT_NULL initialize_fn;
    /// Terminate function.
    emf_cbase_module_loader_interface_terminate_fn_t EMF_CBASE_NOT_NULL terminate_fn;
    ///  Get module info function.
    emf_cbase_module_loader_interface_get_module_info_fn_t EMF_CBASE_NOT_NULL get_module_info_fn;
    /// Get exported interfaces function.
    emf_cbase_module_loader_interface_get_exportable_interfaces_fn_t EMF_CBASE_NOT_NULL get_exportable_interfaces_fn;
    /// Get imported interfaces function.
    emf_cbase_module_loader_interface_get_runtime_dependencies_fn_t EMF_CBASE_NOT_NULL get_runtime_dependencies_fn;
    /// Get interface function.
    emf_cbase_module_loader_interface_get_interface_fn_t EMF_CBASE_NOT_NULL get_interface_fn;
    /// Get load dependencies function.
    emf_cbase_module_loader_interface_get_load_dependencies_fn_t EMF_CBASE_NOT_NULL get_load_dependencies_fn;
    /// Get module path function.
    emf_cbase_module_loader_interface_get_module_path_fn_t EMF_CBASE_NOT_NULL get_module_path_fn;
} emf_cbase_module_loader_interface_t;

/// A struct containing either an `const emf_cbase_module_loader_interface_t*` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_module_loader_handle_t`](./struct.emf_cbase_module_loader_handle_t.md)
///
///     The pointer to the interface.
///     Is never `NULL`.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(emf_cbase_module_loader_interface_result_t,
    const emf_cbase_module_loader_interface_t* EMF_CBASE_NOT_NULL, emf_cbase_module_error_t)

/******************************************  Native Module  ******************************************/

/// An opaque structure representing a native module.
typedef struct emf_cbase_native_module_t emf_cbase_native_module_t;

/// A struct containing either an `emf_cbase_native_module_t*` or an `emf_cbase_module_error_t`
///
/// # Fields
///
/// - **result**: [`emf_cbase_native_module_t`](./struct.emf_cbase_native_module_t.md)
///
///     The pointer to the native module.
///
/// - **error**: [`emf_cbase_module_error_t`](./enum.emf_cbase_module_error_t.md)
///
///     The error.
///
/// - **has_error**: [`emf_cbase_bool_t`](./enum.emf_cbase_bool_t.md)
///
///     A boolean indicating if the result contains an error.
EMF_CBASE_RESULT_TYPEDEF(
    emf_cbase_native_module_ptr_result_t, emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL, emf_cbase_module_error_t)

/// A function pointer to a `load` function.
///
/// The function loads a module and returns a pointer which represents the newly loaded module.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_load, EMF_CBASE_NODISCARD emf_cbase_native_module_ptr_result_t,
    emf_cbase_module_handle_t module_handle, emf_cbase_t* EMF_CBASE_MAYBE_NULL base_module,
    emf_cbase_sys_has_function_fn_t EMF_CBASE_NOT_NULL has_function_fn,
    emf_cbase_sys_get_function_fn_t EMF_CBASE_NOT_NULL get_function_fn)

/// A function pointer to a `unload` function.
///
/// The function unloads the module and disposes of the pointer.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_unload, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)

/// A function pointer to a `initialize` function.
///
/// The function initializes the module.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_initialize, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)

/// A function pointer to a `terminate` function.
///
/// The function terminates the module.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_terminate, EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)

/// A function pointer to a `get_module_info` function.
///
/// The function fetches the module info from the module.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_module_info,
    EMF_CBASE_NODISCARD emf_cbase_module_info_ptr_result_t, emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)

/// A function pointer to a `get_exportable_interfaces` function.
///
/// The function fetches the exportable interfaces from the module.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_exportable_interfaces,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)

/// A function pointer to a `get_runtime_dependencies` function.
///
/// The function fetches the runtime dependencies from the module.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_runtime_dependencies,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module)

/// A function pointer to a `get_interface` function.
///
/// The function fetches an interface from the module.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_interface, EMF_CBASE_NODISCARD emf_cbase_module_interface_result_t,
    emf_cbase_native_module_t* EMF_CBASE_MAYBE_NULL module,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor)

/// A function pointer to a `get_load_dependencies` function.
///
/// The function fetches a list of dependencies the module needs, in order for it to be loaded.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_interface_get_load_dependencies,
    EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_t, void)

/// Interface of a native module.
///
/// # Fields
///
/// - **load_fn**: [`emf_cbase_native_module_interface_load_fn_t`](./type.emf_cbase_native_module_interface_load_fn_t.md)
///
///     The load function of the module.
///     May not be `NULL`.
///
/// - **unload_fn**: [`emf_cbase_native_module_interface_unload_fn_t`](./type.emf_cbase_native_module_interface_unload_fn_t.md)
///
///     The unload function of the module.
///     May not be `NULL`.
///
/// - **initialize_fn**:
/// [`emf_cbase_native_module_interface_initialize_fn_t`](./type.emf_cbase_native_module_interface_initialize_fn_t.md)
///
///     The initialize function of the module.
///     May not be `NULL`.
///
/// - **terminate_fn**:
/// [`emf_cbase_native_module_interface_terminate_fn_t`](./type.emf_cbase_native_module_interface_terminate_fn_t.md)
///
///     The terminate function of the module.
///     May not be `NULL`.
///
/// - **get_module_info_fn**:
/// [`emf_cbase_native_module_interface_get_module_info_fn_t`](./type.emf_cbase_native_module_interface_get_module_info_fn_t.md)
///
///     The get_module_info function of the module.
///     May not be `NULL`.
///
/// - **get_exportable_interfaces_fn**:
/// [`emf_cbase_native_module_interface_get_exportable_interfaces_fn_t`](./type.emf_cbase_native_module_interface_get_exportable_interfaces_fn_t.md)
///
///     The get_exportable_interfaces function of the module.
///     May not be `NULL`.
///
/// - **get_runtime_dependencies_fn**:
/// [`emf_cbase_native_module_interface_get_runtime_dependencies_fn_t`](./type.emf_cbase_native_module_interface_get_runtime_dependencies_fn_t.md)
///
///     The get_runtime_dependencies function of the module.
///     May not be `NULL`.
///
/// - **get_interface_fn**:
/// [`emf_cbase_native_module_interface_get_interface_fn_t`](./type.emf_cbase_native_module_interface_get_interface_fn_t.md)
///
///     The get_interface function of the module.
///     May not be `NULL`.
///
/// - **get_load_dependencies_fn**:
/// [`emf_cbase_native_module_interface_get_load_dependencies_fn_t`](./type.emf_cbase_native_module_interface_get_load_dependencies_fn_t.md)
///
///     The get_load_dependencies function of the module.
///     May not be `NULL`.
typedef struct emf_cbase_native_module_interface_t {
    /// Load function.
    emf_cbase_native_module_interface_load_fn_t EMF_CBASE_NOT_NULL load_fn;
    /// Unload function.
    emf_cbase_native_module_interface_unload_fn_t EMF_CBASE_NOT_NULL unload_fn;
    /// Initialize function.
    emf_cbase_native_module_interface_initialize_fn_t EMF_CBASE_NOT_NULL initialize_fn;
    /// Terminate function.
    emf_cbase_native_module_interface_terminate_fn_t EMF_CBASE_NOT_NULL terminate_fn;
    /// Get module info function.
    emf_cbase_native_module_interface_get_module_info_fn_t EMF_CBASE_NOT_NULL get_module_info_fn;
    /// Get exportable interfaces function.
    emf_cbase_native_module_interface_get_exportable_interfaces_fn_t EMF_CBASE_NOT_NULL get_exportable_interfaces_fn;
    /// Get runtime dependencies function.
    emf_cbase_native_module_interface_get_runtime_dependencies_fn_t EMF_CBASE_NOT_NULL get_runtime_dependencies_fn;
    /// Get interface function.
    emf_cbase_native_module_interface_get_interface_fn_t EMF_CBASE_NOT_NULL get_interface_fn;
    /// Get load dependencies function.
    emf_cbase_native_module_interface_get_load_dependencies_fn_t EMF_CBASE_NOT_NULL get_load_dependencies_fn;
} emf_cbase_native_module_interface_t;

/***************************************  Native Module Loader ***************************************/

/// A function pointer to a `get_native_module` function.
///
/// The function returns a pointer to the native module.
EMF_CBASE_FUNCTION_PTR_T(emf_cbase_native_module_loader_interface_get_native_module,
    EMF_CBASE_NODISCARD emf_cbase_native_module_ptr_result_t, emf_cbase_module_loader_t* EMF_CBASE_MAYBE_NULL module_loader,
    emf_cbase_module_loader_module_handle_t module_handle)

/// Interface of the native module loader.
///
/// # Fields
///
/// - **module_loader_interface**: [`emf_cbase_module_loader_interface_t`](./struct.emf_cbase_module_loader_interface_t.md)
///
///     The base module loader interface.
///
/// - **get_native_module_fn**:
/// [`emf_cbase_native_module_loader_interface_get_native_module_fn_t`](./type.emf_cbase_native_module_loader_interface_get_native_module_fn_t.md)
///
///     The get_native_module function of the module loader.
///     May not be `NULL`.
typedef struct emf_cbase_native_module_loader_interface_t {
    /// Module loader interface.
    emf_cbase_module_loader_interface_t module_loader_interface;
    emf_cbase_native_module_loader_interface_get_native_module_fn_t EMF_CBASE_NOT_NULL get_native_module_fn;
} emf_cbase_native_module_loader_interface_t;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************************************
*****************************************  System operations  *****************************************
******************************************************************************************************/

/// Registers a new module loader.
///
/// Module names starting with `__` are reserved for future use.
///
/// # Failure
///
/// The function fails if `module_type` already exists.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    loader_interface,
///    NULL
/// );
/// ASSERT_NE(
///    module_type,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_module_register_loader(
    const emf_cbase_module_loader_interface_t* EMF_CBASE_NOT_NULL loader_interface,
    const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type) EMF_CBASE_NOEXCEPT;

/// Unregisters an existing module loader.
///
/// Unregistering a module loader also unregisters the modules it loaded.
///
/// # Failure
///
/// The function fails if `loader_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_unregister_loader(
    emf_cbase_module_loader_handle_t loader_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the number of loaders.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_module_get_num_loaders() EMF_CBASE_NOEXCEPT;

/// Copies the available module types.
///
/// # Failure
///
/// The function fails if `buffer` too small.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    buffer,
///    NULL
/// );
/// ASSERT_NE(
///    buffer->data,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_size_result_t EMF_CBASE_CALL_C emf_cbase_module_get_module_types(
    emf_cbase_module_type_span_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT;

/// Fetches the number of loaded modules.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_module_get_num_modules() EMF_CBASE_NOEXCEPT;

/// Copies the available module infos.
///
/// # Failure
///
/// The function fails if `buffer` too small.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    buffer,
///    NULL
/// );
/// ASSERT_NE(
///    buffer->data,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_size_result_t EMF_CBASE_CALL_C emf_cbase_module_get_modules(
    emf_cbase_module_info_span_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT;

/// Fetches the number of exported interfaces.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD size_t EMF_CBASE_CALL_C emf_cbase_module_get_num_exported_interfaces() EMF_CBASE_NOEXCEPT;

/// Copies the descriptors of the exported interfaces.
///
/// # Failure
///
/// The function fails if `buffer` too small.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    buffer,
///    NULL
/// );
/// ASSERT_NE(
///    buffer->data,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_size_result_t EMF_CBASE_CALL_C emf_cbase_module_get_exported_interfaces(
    emf_cbase_interface_descriptor_span_t* EMF_CBASE_NOT_NULL buffer) EMF_CBASE_NOEXCEPT;

/// Fetches the handle of the loader associated with a module type.
///
/// # Failure
///
/// The function fails if `module_type` does not exist.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    module_type,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_module_get_loader_handle(
    const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type) EMF_CBASE_NOEXCEPT;

/// Checks if a module type exists.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    module_type,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_module_type_exists(
    const emf_cbase_module_type_t* EMF_CBASE_NOT_NULL module_type) EMF_CBASE_NOEXCEPT;

/// Checks if a module exists.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_module_module_exists(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the module handle of the exported interface.
///
/// # Failure
///
/// The function fails if `interface` does not exist.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    interface,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_handle_result_t EMF_CBASE_CALL_C emf_cbase_module_get_exported_interface_handle(
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface) EMF_CBASE_NOEXCEPT;

/// Checks whether an exported interface exists.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    interface,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_bool_t EMF_CBASE_CALL_C emf_cbase_module_exported_interface_exists(
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface) EMF_CBASE_NOEXCEPT;

/******************************************************************************************************
*************************************  Unsafe system operations  *************************************
******************************************************************************************************/

/// Creates a new unlinked module handle.
///
/// # Warning
///
/// The handle must be linked before use (See
/// [emf_cbase_module_unsafe_link_module()](./fn.emf_cbase_module_unsafe_link_module.md)).
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_handle_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_create_module_handle() EMF_CBASE_NOEXCEPT;

/// Removes an existing module handle.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid.
///
/// # Warning
///
/// Removing the handle does not unload the module.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_remove_module_handle(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Links a module handle to an internal module handle.
///
/// # Failure
///
/// The function fails if `module_handle` or`loader_handle` are invalid.
///
/// # Warning
///
/// Incorrect usage can lead to dangling handles or use-after-free errors.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_link_module(
    emf_cbase_module_handle_t module_handle, emf_cbase_module_loader_handle_t loader_handle,
    emf_cbase_module_loader_module_handle_t loader_module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the internal handle linked with the module handle.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_loader_module_handle_result_t EMF_CBASE_CALL_C
emf_cbase_module_unsafe_get_loader_module_handle(emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the loader handle linked with the module handle.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_loader_handle_result_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_get_loader_handle(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the interface of a module loader.
///
/// # Failure
///
/// The function fails if `loader_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_loader_interface_result_t EMF_CBASE_CALL_C emf_cbase_module_unsafe_get_loader(
    emf_cbase_module_loader_handle_t loader_handle) EMF_CBASE_NOEXCEPT;

/******************************************************************************************************
*****************************************  Loader operations  *****************************************
******************************************************************************************************/

/// Adds a new module.
///
/// # Failure
///
/// The function fails if `loader_handle` or `module_path` is invalid or the type of the module can not be loaded by the loader.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    module_path,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_handle_result_t emf_cbase_module_add_module(emf_cbase_module_loader_handle_t loader_handle,
    const emf_cbase_os_path_char_t* EMF_CBASE_NOT_NULL module_path) EMF_CBASE_NOEXCEPT;

/// Removes a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid or the module is not in an unloaded state.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t emf_cbase_module_remove_module(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the load dependencies of a module.
///
/// The load dependencies of a module must all be present at the time of loading.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t emf_cbase_module_get_load_dependencies(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the load status of a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_status_result_t emf_cbase_module_fetch_status(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Registers a new runtime dependency of the module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    interface_descriptor,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t emf_cbase_module_add_dependency(emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor) EMF_CBASE_NOEXCEPT;

/// Removes an existing runtime dependency from the module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    interface_descriptor,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t emf_cbase_module_remove_dependency(emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor) EMF_CBASE_NOEXCEPT;

/// Exports an interface of a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid, `interface_descriptor` is already exported, `interface_descriptor` is not
/// contained in the module or the module is not yet initialized.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    interface_descriptor,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t emf_cbase_module_export_interface(
    emf_cbase_module_handle_t module_handle, const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor);

/// Loads a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid, the load dependencies of the module are not exported or the module is not in
/// an unloaded state.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_load(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Unloads a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid or the module is in an unloaded or ready state.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_unload(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Initializes a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid, the runtime dependencies of the module are not exported or the module is not
/// in a loaded state.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_initialize(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Terminates a module.
///
/// Terminating a module also removes the interfaces it exported.
///
/// The modules that depend on the module are terminated.
/// If they list the module as a load dependency, they are also unloaded.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid or the module is not in a ready state.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_error_optional_t EMF_CBASE_CALL_C emf_cbase_module_terminate(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches the module info from a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid or the module is not yet loaded.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_module_info_ptr_result_t EMF_CBASE_CALL_C emf_cbase_module_get_module_info(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches a list of the exportable interfaces from a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid or the module is not yet loaded.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t EMF_CBASE_CALL_C
emf_cbase_module_get_exportable_interfaces(emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches a list of the runtime dependencies from a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid or the module is not yet loaded.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_interface_descriptor_const_span_result_t EMF_CBASE_CALL_C emf_cbase_module_get_runtime_dependencies(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

/// Fetches an interface from a module.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid, the module is not in a ready state or the interface is not contained in the
/// module.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
/// Furthermore, the caller must ensure that the following preconditions hold:
///
/// ```c
/// ASSERT_NE(
///    interface_descriptor,
///    NULL
/// );
/// ```
EMF_CBASE_NODISCARD emf_cbase_module_interface_result_t EMF_CBASE_CALL_C emf_cbase_module_get_interface(
    emf_cbase_module_handle_t module_handle,
    const emf_cbase_interface_descriptor_t* EMF_CBASE_NOT_NULL interface_descriptor) EMF_CBASE_NOEXCEPT;

/// Fetches the path a module was loaded from.
///
/// # Failure
///
/// The function fails if `module_handle` is invalid or the module is not yet loaded.
///
/// # Undefined Behaviour
///
/// The callee expects that the caller holds a lock (See [emf_cbase_sys_lock()](./fn.emf_cbase_sys_lock.md)).
EMF_CBASE_NODISCARD emf_cbase_os_path_char_result_t emf_cbase_module_get_module_path(
    emf_cbase_module_handle_t module_handle) EMF_CBASE_NOEXCEPT;

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EMF_CORE_BASE_EMF_CBASE_MODULE_H
