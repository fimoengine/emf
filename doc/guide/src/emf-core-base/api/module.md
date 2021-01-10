# Module API

## Introduction

The `module` api is built on top of the `library` api and specifies the loading and unloading of `modules`.
A `module` is a collection libraries and resources, that together form an independent unit.
Similarly to the `library` api, the loading and unloading of modules is implemented by `module loaders`,
which are associated to one `module type`.

### Loaders

`Module loaders` implement the actual loading and unloading of modules. Custom `module loaders` can be added by
constructing a [`emf_cbase_module_loader_interface_t`](../reference/struct.emf_cbase_module_loader_interface_t.md)
and calling the [`emf_cbase_module_register_loader()`](../reference/fn.emf_cbase_module_register_loader.md) function.

### Module types

The type of a module identifies a `module loader` capable of loading a specific module.
A `module type` is represented by a [`emf_cbase_module_type_t`](../reference/struct.emf_cbase_module_type_t.md).

## Module structure

> module/module.json\
> module/...\
> ...\

A `module` is a simple directory containing all the required resources.
The internal structure of the `module` is defined by the respective `module loader`.
The only requirement is the existance of the `module.json` file at the root of the module.
This file is the `module manifest` and specifies that the directory is indeed a module.

## Module manifest

The `module manifest` identifies a module and specifies how a module can be loaded.
To allow for backwards (and forwards) compatibility, the version of the `manifest schema`
is saved in the manifest with the key `schema`.

### Version 0

The version `0` introduces several required and optional fields:

- `name`: A `string` describing the name of the module. Has a maximum length of 32 ASCII characters. Is required.
- `type`: A `string` describing the `module type` of the module. Has a maximum length of 64 ASCII characters. Is required.
- `version`: A `string` describing the version of the module. Has a maximum length of 32 ASCII characters. Is required.
- `load_dependencies`: An `array` of `<interface_descriptors>` describing the load dependencies.
- `runtime_dependencies`: An `array` of `<interface_descriptors>` describing the runtime dependencies.
- `exports`: An `array` of `<interface_descriptors>` describing the exportable interfaces.

The definition of the custom types can be found below:

- `<interface_descriptor>`: The descriptor of an interface.
  - `name`: A `string` describing the name of the interface. Has a maximum length of 32 ASCII characters. Is required.
  - `version`: A `<version>` describing the version of the interface. Is required.
  - `extensions`: An `array` of strings describing the extensions of the interface. Each extension has a maximum length of 32 ASCII characters.

- `<version>`: The `string` representation of a version. See [`Versions`](../../conventions.md#versions).

Example:

```json
{
    "schema": 0,
    "name": "jobs",
    "type": "emf::core_base::native",
    "version": "0.1.5-rc.7-a",
    "load_dependencies": [{
        "name": "memory",
        "version": "0.1.0"
    }],
    "runtime_dependencies": [{
        "name": "logging",
        "version": "1.0.0"
    }],
    "exports": [{
        "name": "jobs_interface",
        "version": "1.0.0",
        "extensions": [
            "schedulers",
            "fibers"
        ]
    }]
}
```

## Predefined Loaders

Some `module loaders` are always present and can not be removed at runtime.

### Native

The native `module loader` is built on top of the native `library loader` and is able to load modules consisting of native libraries.
It is reachable with the [`EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE`](../reference/constant.EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE.md) handle.
The same restrictions of the native `library loader` apply to the native `module loader`.
The native `module loader` requires the presence of a `native module manifest` file named `native_module.json` at the root of the module.

#### Native module manifest

The `native module manifest` specifies which library implements the module.
To allow for backwards (and forwards) compatibility, the version of the `manifest schema`
is saved in the manifest with the key `schema`.

##### Native module manifest version 0

The version `0` requires one field:

- `library_path`: A `string` describing the relative path to the library. Is required.

Example:

```json
{
    "schema": 0,
    "library_path": "./lib/jobs.so"
}
```

#### Native module interface

Once the module library has been loaded by the native `library loader`, the native `module loader` searches for a symbol with the name
`emf_cbase_native_module_interface` (see [`EMF_CBASE_NATIVE_MODULE_INTERFACE_SYMBOL_NAME`](../reference/constant.EMF_CBASE_NATIVE_MODULE_INTERFACE_SYMBOL_NAME.md))
and the type [`emf_cbase_native_module_interface_t`](../reference/struct.emf_cbase_native_module_interface_t.md).

## Example

```c
emf_cbase_sys_lock();

const emf_cbase_os_path_char_t* module_path = "./jobs_module";
emf_cbase_module_handle_result_t module_handle_res = 
    emf_cbase_module_add_module(EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE, module_path);
if (module_handle_res.has_error) {
    emf_cbase_sys_panic("Unable to load the `./jobs_module` module.");
}
emf_cbase_module_handle_t module_handle = module_handle_res.result;

emf_cbase_module_error_optional_t error_opt;
error_opt = emf_cbase_module_load(module_handle);
if (error_opt.has_value) {
    emf_cbase_sys_panic("Unable to load the `./jobs_module` module.");
}

error_opt = emf_cbase_module_initialize(module_handle);
if (error_opt.has_value) {
    emf_cbase_sys_panic("Unable to initialize the `./jobs_module` module.");
}

emf_cbase_interface_descriptor_t interface_descriptor = {
    .name = { .data = "jobs_interface", .length = 14 },
    .version = emf_cbase_version_construct_short(1, 0, 0),
    .extensions = { .data = NULL, length = 0 }
}
error_opt = emf_cbase_module_export_interface(module_handle, &interface_descriptor);
if (error_opt.has_value) {
    emf_cbase_sys_panic("Unable to export `jobs_interface` "
        "from the `./jobs_module` module.");
}

emf_cbase_sys_unlock();
```

## Constants

- [`EMF_CBASE_INTERFACE_EXTENSION_NAME_MAX_LENGTH`](../reference/constant.EMF_CBASE_INTERFACE_EXTENSION_NAME_MAX_LENGTH.md)
- [`EMF_CBASE_INTERFACE_INFO_NAME_MAX_LENGTH`](../reference/constant.EMF_CBASE_INTERFACE_INFO_NAME_MAX_LENGTH.md)
- [`EMF_CBASE_MODULE_INFO_NAME_MAX_LENGTH`](../reference/constant.EMF_CBASE_MODULE_INFO_NAME_MAX_LENGTH.md)
- [`EMF_CBASE_MODULE_INFO_VERSION_MAX_LENGTH`](../reference/constant.EMF_CBASE_MODULE_INFO_VERSION_MAX_LENGTH.md)
- [`EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE`](../reference/constant.EMF_CBASE_MODULE_LOADER_DEFAULT_HANDLE.md)
- [`EMF_CBASE_MODULE_LOADER_TYPE_MAX_LENGTH`](../reference/constant.EMF_CBASE_MODULE_LOADER_TYPE_MAX_LENGTH.md)
- [`EMF_CBASE_NATIVE_MODULE_INTERFACE_SYMBOL_NAME`](../reference/constant.EMF_CBASE_NATIVE_MODULE_INTERFACE_SYMBOL_NAME.md)
- [`EMF_CBASE_NATIVE_MODULE_TYPE_NAME`](../reference/constant.EMF_CBASE_NATIVE_MODULE_TYPE_NAME.md)

## Enums

- [`emf_cbase_module_error_t`](../reference/enum.emf_cbase_module_error_t.md)
- [`emf_cbase_module_predefined_handles_t`](../reference/enum.emf_cbase_module_predefined_handles_t.md)
- [`emf_cbase_module_status_t`](../reference/enum.emf_cbase_module_status_t.md)

## Structs

- [`emf_cbase_interface_descriptor_span_result_t`](../reference/struct.emf_cbase_interface_descriptor_span_result_t.md)
- [`emf_cbase_interface_descriptor_span_t`](../reference/struct.emf_cbase_interface_descriptor_span_t.md)
- [`emf_cbase_interface_descriptor_t`](../reference/struct.emf_cbase_interface_descriptor_t.md)
- [`emf_cbase_interface_extension_span_t`](../reference/struct.emf_cbase_interface_extension_span_t.md)
- [`emf_cbase_interface_extension_t`](../reference/struct.emf_cbase_interface_extension_t.md)
- [`emf_cbase_interface_name_t`](../reference/struct.emf_cbase_interface_name_t.md)
- [`emf_cbase_module_error_optional_t`](../reference/struct.emf_cbase_module_error_optional_t.md)
- [`emf_cbase_module_handle_result_t`](../reference/struct.emf_cbase_module_handle_result_t.md)
- [`emf_cbase_module_handle_t`](../reference/struct.emf_cbase_module_handle_t.md)
- [`emf_cbase_module_info_ptr_result_t`](../reference/struct.emf_cbase_module_info_ptr_result_t.md)
- [`emf_cbase_module_info_span_t`](../reference/struct.emf_cbase_module_info_span_t.md)
- [`emf_cbase_module_info_t`](../reference/struct.emf_cbase_module_info_t.md)
- [`emf_cbase_module_interface_result_t`](../reference/struct.emf_cbase_module_interface_result_t.md)
- [`emf_cbase_module_interface_t`](../reference/struct.emf_cbase_module_interface_t.md)
- [`emf_cbase_module_loader_handle_result_t`](../reference/struct.emf_cbase_module_loader_handle_result_t.md)
- [`emf_cbase_module_loader_handle_t`](../reference/struct.emf_cbase_module_loader_handle_t.md)
- [`emf_cbase_module_loader_interface_result_t`](../reference/struct.emf_cbase_module_loader_interface_result_t.md)
- [`emf_cbase_module_loader_interface_t`](../reference/struct.emf_cbase_module_loader_interface_t.md)
- [`emf_cbase_module_loader_module_handle_result_t`](../reference/struct.emf_cbase_module_loader_module_handle_result_t.md)
- [`emf_cbase_module_loader_module_handle_t`](../reference/struct.emf_cbase_module_loader_module_handle_t.md)
- [`emf_cbase_module_loader_t`](../reference/struct.emf_cbase_module_loader_t.md)
- [`emf_cbase_module_name_t`](../reference/struct.emf_cbase_module_name_t.md)
- [`emf_cbase_module_size_result_t`](../reference/struct.emf_cbase_module_size_result_t.md)
- [`emf_cbase_module_status_result_t`](../reference/struct.emf_cbase_module_status_result_t.md)
- [`emf_cbase_module_type_span_t`](../reference/struct.emf_cbase_module_type_span_t.md)
- [`emf_cbase_module_type_t`](../reference/struct.emf_cbase_module_type_t.md)
- [`emf_cbase_module_version_t`](../reference/struct.emf_cbase_module_version_t.md)
- [`emf_cbase_native_module_interface_t`](../reference/struct.emf_cbase_native_module_interface_t.md)
- [`emf_cbase_native_module_loader_interface_t`](../reference/struct.emf_cbase_native_module_loader_interface_t.md)
- [`emf_cbase_native_module_ptr_result_t`](../reference/struct.emf_cbase_native_module_ptr_result_t.md)
- [`emf_cbase_native_module_t`](../reference/struct.emf_cbase_native_module_t.md)
- [`emf_cbase_sys_fn_optional_t`](../reference/struct.emf_cbase_sys_fn_optional_t.md)
- [`emf_cbase_t`](../reference/struct.emf_cbase_t.md)

## Type definitions

- [`emf_cbase_module_loader_interface_add_module_fn_t`](../reference/type.emf_cbase_module_loader_interface_add_module_fn_t.md)
- [`emf_cbase_module_loader_interface_fetch_status_fn_t`](../reference/type.emf_cbase_module_loader_interface_fetch_status_fn_t.md)
- [`emf_cbase_module_loader_interface_get_exportable_interfaces_fn_t`](../reference/type.emf_cbase_module_loader_interface_get_exportable_interfaces_fn_t.md)
- [`emf_cbase_module_loader_interface_get_interface_fn_t`](../reference/type.emf_cbase_module_loader_interface_get_interface_fn_t.md)
- [`emf_cbase_module_loader_interface_get_internal_interface_fn_t`](../reference/type.emf_cbase_module_loader_interface_get_internal_interface_fn_t.md)
- [`emf_cbase_module_loader_interface_get_load_dependencies_fn_t`](../reference/type.emf_cbase_module_loader_interface_get_load_dependencies_fn_t.md)
- [`emf_cbase_module_loader_interface_get_module_info_fn_t`](../reference/type.emf_cbase_module_loader_interface_get_module_info_fn_t.md)
- [`emf_cbase_module_loader_interface_get_module_path_fn_t`](../reference/type.emf_cbase_module_loader_interface_get_module_path_fn_t.md)
- [`emf_cbase_module_loader_interface_get_runtime_dependencies_fn_t`](../reference/type.emf_cbase_module_loader_interface_get_runtime_dependencies_fn_t.md)
- [`emf_cbase_module_loader_interface_initialize_fn_t`](../reference/type.emf_cbase_module_loader_interface_initialize_fn_t.md)
- [`emf_cbase_module_loader_interface_load_fn_t`](../reference/type.emf_cbase_module_loader_interface_load_fn_t.md)
- [`emf_cbase_module_loader_interface_remove_module_fn_t`](../reference/type.emf_cbase_module_loader_interface_remove_module_fn_t.md)
- [`emf_cbase_module_loader_interface_terminate_fn_t`](../reference/type.emf_cbase_module_loader_interface_terminate_fn_t.md)
- [`emf_cbase_module_loader_interface_unload_fn_t`](../reference/type.emf_cbase_module_loader_interface_unload_fn_t.md)
- [`emf_cbase_native_module_interface_get_exportable_interfaces_fn_t`](../reference/type.emf_cbase_native_module_interface_get_exportable_interfaces_fn_t.md)
- [`emf_cbase_native_module_interface_get_interface_fn_t`](../reference/type.emf_cbase_native_module_interface_get_interface_fn_t.md)
- [`emf_cbase_native_module_interface_get_load_dependencies_fn_t`](../reference/type.emf_cbase_native_module_interface_get_load_dependencies_fn_t.md)
- [`emf_cbase_native_module_interface_get_module_info_fn_t`](../reference/type.emf_cbase_native_module_interface_get_module_info_fn_t.md)
- [`emf_cbase_native_module_interface_get_runtime_dependencies_fn_t`](../reference/type.emf_cbase_native_module_interface_get_runtime_dependencies_fn_t.md)
- [`emf_cbase_native_module_interface_initialize_fn_t`](../reference/type.emf_cbase_native_module_interface_initialize_fn_t.md)
- [`emf_cbase_native_module_interface_load_fn_t`](../reference/type.emf_cbase_native_module_interface_load_fn_t.md)
- [`emf_cbase_native_module_interface_terminate_fn_t`](../reference/type.emf_cbase_native_module_interface_terminate_fn_t.md)
- [`emf_cbase_native_module_interface_unload_fn_t`](../reference/type.emf_cbase_native_module_interface_unload_fn_t.md)
- [`emf_cbase_native_module_loader_interface_get_native_module_fn_t`](../reference/type.emf_cbase_native_module_loader_interface_get_native_module_fn_t.md)
- [`emf_cbase_sys_get_function_fn_t`](../reference/type.emf_cbase_sys_get_function_fn_t.md)
- [`emf_cbase_sys_has_function_fn_t`](../reference/type.emf_cbase_sys_has_function_fn_t.md)

## Functions

- [`emf_cbase_module_add_dependency`](../reference/fn.emf_cbase_module_add_dependency.md)
- [`emf_cbase_module_add_module`](../reference/fn.emf_cbase_module_add_module.md)
- [`emf_cbase_module_export_interface`](../reference/fn.emf_cbase_module_export_interface.md)
- [`emf_cbase_module_exported_interface_exists`](../reference/fn.emf_cbase_module_exported_interface_exists.md)
- [`emf_cbase_module_fetch_status`](../reference/fn.emf_cbase_module_fetch_status.md)
- [`emf_cbase_module_get_exportable_interfaces`](../reference/fn.emf_cbase_module_get_exportable_interfaces.md)
- [`emf_cbase_module_get_exported_interface_handle`](../reference/fn.emf_cbase_module_get_exported_interface_handle.md)
- [`emf_cbase_module_get_exported_interfaces`](../reference/fn.emf_cbase_module_get_exported_interfaces.md)
- [`emf_cbase_module_get_interface`](../reference/fn.emf_cbase_module_get_interface.md)
- [`emf_cbase_module_get_load_dependencies`](../reference/fn.emf_cbase_module_get_load_dependencies.md)
- [`emf_cbase_module_get_loader_handle`](../reference/fn.emf_cbase_module_get_loader_handle.md)
- [`emf_cbase_module_get_module_info`](../reference/fn.emf_cbase_module_get_module_info.md)
- [`emf_cbase_module_get_module_path`](../reference/fn.emf_cbase_module_get_module_path.md)
- [`emf_cbase_module_get_module_types`](../reference/fn.emf_cbase_module_get_module_types.md)
- [`emf_cbase_module_get_modules`](../reference/fn.emf_cbase_module_get_modules.md)
- [`emf_cbase_module_get_num_exported_interfaces`](../reference/fn.emf_cbase_module_get_num_exported_interfaces.md)
- [`emf_cbase_module_get_num_loaders`](../reference/fn.emf_cbase_module_get_num_loaders.md)
- [`emf_cbase_module_get_num_modules`](../reference/fn.emf_cbase_module_get_num_modules.md)
- [`emf_cbase_module_get_runtime_dependencies`](../reference/fn.emf_cbase_module_get_runtime_dependencies.md)
- [`emf_cbase_module_initialize`](../reference/fn.emf_cbase_module_initialize.md)
- [`emf_cbase_module_load`](../reference/fn.emf_cbase_module_load.md)
- [`emf_cbase_module_module_exists`](../reference/fn.emf_cbase_module_module_exists.md)
- [`emf_cbase_module_register_loader`](../reference/fn.emf_cbase_module_register_loader.md)
- [`emf_cbase_module_remove_dependency`](../reference/fn.emf_cbase_module_remove_dependency.md)
- [`emf_cbase_module_remove_module`](../reference/fn.emf_cbase_module_remove_module.md)
- [`emf_cbase_module_terminate`](../reference/fn.emf_cbase_module_terminate.md)
- [`emf_cbase_module_type_exists`](../reference/fn.emf_cbase_module_type_exists.md)
- [`emf_cbase_module_unload`](../reference/fn.emf_cbase_module_unload.md)
- [`emf_cbase_module_unregister_loader`](../reference/fn.emf_cbase_module_unregister_loader.md)
- [`emf_cbase_module_unsafe_create_module_handle`](../reference/fn.emf_cbase_module_unsafe_create_module_handle.md)
- [`emf_cbase_module_unsafe_get_loader_handle`](../reference/fn.emf_cbase_module_unsafe_get_loader_handle.md)
- [`emf_cbase_module_unsafe_get_loader_module_handle`](../reference/fn.emf_cbase_module_unsafe_get_loader_module_handle.md)
- [`emf_cbase_module_unsafe_get_loader`](../reference/fn.emf_cbase_module_unsafe_get_loader.md)
- [`emf_cbase_module_unsafe_link_module`](../reference/fn.emf_cbase_module_unsafe_link_module.md)
- [`emf_cbase_module_unsafe_remove_module_handle`](../reference/fn.emf_cbase_module_unsafe_remove_module_handle.md)
