# Library API

## Introduction

The `library` api is a collection of procedures that provide a platform agnostic interface
to loading shared libraries. The actual loading of a library is handled by a `library loader`.
Each `library loader` is associated to a `library type`.

### Loaders

The job of a `library loader` is to manage the loading and unloading of libraries.
A `library loader` can be added by constructing a [`emf_cbase_library_loader_interface_t`](../reference/struct.emf_cbase_library_loader_interface_t.md) and then calling the [`emf_cbase_library_register_loader()`](../reference/fn.emf_cbase_library_register_loader.md) function.

### Library types

The `library` api allows the loading of custom library formats.
Each format is identified by a [`emf_cbase_library_type_t`](../reference/struct.emf_cbase_library_type_t.md) and is associated to exactly one `library loader`.

## Predefined Loaders

Some `library loaders` are always present and can not be removed at runtime.

### Native

The native `library loader` is able to load platform-specific libraries (e.g. dlopen()/LoadLibrary()).
It is associated to the [`EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME`](../reference/constant.EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME.md) `library type` and is reachable with the [`EMF_CBASE_LIBRARY_LOADER_DEFAULT_HANDLE`](../reference/constant.EMF_CBASE_LIBRARY_LOADER_DEFAULT_HANDLE.md) handle. Libraries with the same absolute path are loaded only once and subsequent load calls increase their reference count.

On posix the `library loader` defaults to the `RTLD_LAZY` and `RTLD_LOCAL` flags. More controll of how to load a library can be achieved by fetching a pointer to the interface with [`emf_cbase_library_unsafe_get_loader_interface`](../reference/fn.emf_cbase_library_unsafe_get_loader_interface.md), casting it to a [`emf_cbase_native_library_loader_interface_t`](../reference/struct.emf_cbase_native_library_loader_interface_t.md) and calling the [`load_ext_fn`](../reference/type.emf_cbase_native_library_loader_interface_load_ext_fn_t.md) function.

## Example

```c
const emf_cbase_os_path_char_t* library_path = "./example_lib.so";

emf_cbase_library_handle_result_t library_handle_res = 
    emf_cbase_library_load(EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME, library_path);
if (library_handle_res.has_error) {
    emf_cbase_sys_panic("Unable to load the `./example_lib.so` library.");
}

emf_cbase_library_handle_t library_handle = library_handle_res.result;

emf_cbase_library_fn_symbol_result_t fn_sym_res =
    emf_cbase_library_get_function_symbol(library_handle, "example_fn");
if (fn_sym_res.has_error) {
    emf_cbase_sys_panic("Unable to load the `example_fn` function from the library.");
}

emf_cbase_library_fn_symbol_t fn_sym = fn_sym_res.result;
void (*fn)(int, int) = (void(*)(int, int))fn_sym.symbol;
(*fn)(5, 7);

emf_cbase_library_error_optional_t error_opt =
    emf_cbase_library_unload(library_handle);
if (error_opt.has_value) {
    emf_cbase_sys_panic("Unable to unload the `./example_lib.so` library.");
}
```

## Constants

- [`EMF_CBASE_LIBRARY_LOADER_DEFAULT_HANDLE`](../reference/constant.EMF_CBASE_LIBRARY_LOADER_DEFAULT_HANDLE.md)
- [`EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH`](../reference/constant.EMF_CBASE_LIBRARY_LOADER_TYPE_MAX_LENGTH.md)
- [`EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME`](../reference/constant.EMF_CBASE_NATIVE_LIBRARY_TYPE_NAME.md)
- [`EMF_CBASE_OS_PATH_CHAR`](../reference/constant.EMF_CBASE_OS_PATH_CHAR.md)

## Enums

- [`emf_cbase_library_error_t`](../reference/enum.emf_cbase_library_error_t.md)
- [`emf_cbase_library_predefined_handles_t`](../reference/enum.emf_cbase_library_predefined_handles_t.md)

## Structs

- [`emf_cbase_data_symbol_t`](../reference/struct.emf_cbase_data_symbol_t.md)
- [`emf_cbase_fn_symbol_t`](../reference/struct.emf_cbase_fn_symbol_t.md)
- [`emf_cbase_library_data_symbol_result_t`](../reference/struct.emf_cbase_library_data_symbol_result_t.md)
- [`emf_cbase_library_error_optional_t`](../reference/struct.emf_cbase_library_error_optional_t.md)
- [`emf_cbase_library_fn_symbol_result_t`](../reference/struct.emf_cbase_library_fn_symbol_result_t.md)
- [`emf_cbase_library_handle_result_t`](../reference/struct.emf_cbase_library_handle_result_t.md)
- [`emf_cbase_library_handle_t`](../reference/struct.emf_cbase_library_handle_t.md)
- [`emf_cbase_library_loader_handle_result_t`](../reference/struct.emf_cbase_library_loader_handle_result_t.md)
- [`emf_cbase_library_loader_handle_t`](../reference/struct.emf_cbase_library_loader_handle_t.md)
- [`emf_cbase_library_loader_interface_result_t`](../reference/struct.emf_cbase_library_loader_interface_result_t.md)
- [`emf_cbase_library_loader_interface_t`](../reference/struct.emf_cbase_library_loader_interface_t.md)
- [`emf_cbase_library_loader_library_handle_result_t`](../reference/struct.emf_cbase_library_loader_library_handle_result_t.md)
- [`emf_cbase_library_loader_library_handle_t`](../reference/struct.emf_cbase_library_loader_library_handle_t.md)
- [`emf_cbase_library_loader_t`](../reference/struct.emf_cbase_library_loader_t.md)
- [`emf_cbase_library_size_result_t`](../reference/struct.emf_cbase_library_size_result_t.md)
- [`emf_cbase_library_type_span_t`](../reference/struct.emf_cbase_library_type_span_t.md)
- [`emf_cbase_library_type_t`](../reference/struct.emf_cbase_library_type_t.md)
- [`emf_cbase_native_library_loader_interface_t`](../reference/struct.emf_cbase_native_library_loader_interface_t.md)

## Type definitions

- [`emf_cbase_fn_t`](../reference/type.emf_cbase_fn_t.md)
- [`emf_cbase_library_loader_interface_get_data_symbol_fn_t`](../reference/type.emf_cbase_library_loader_interface_get_data_symbol_fn_t.md)
- [`emf_cbase_library_loader_interface_get_function_symbol_fn_t`](../reference/type.emf_cbase_library_loader_interface_get_function_symbol_fn_t.md)
- [`emf_cbase_library_loader_interface_load_fn_t`](../reference/type.emf_cbase_library_loader_interface_load_fn_t.md)
- [`emf_cbase_library_loader_interface_unload_fn_t`](../reference/type.emf_cbase_library_loader_interface_unload.md)
- [`emf_cbase_native_library_loader_interface_load_ext_fn_t`](../reference/type.emf_cbase_native_library_loader_interface_load_ext_fn_t.md)
- [`emf_cbase_os_path_char_t`](../reference/type.emf_cbase_os_path_char_t.md)

## Functions

- [`emf_cbase_library_get_data_symbol`](../reference/fn.emf_cbase_library_get_data_symbol.md)
- [`emf_cbase_library_get_function_symbol`](../reference/fn.emf_cbase_library_get_function_symbol.md)
- [`emf_cbase_library_get_library_types`](../reference/fn.emf_cbase_library_get_library_types.md)
- [`emf_cbase_library_get_loader_handle`](../reference/fn.emf_cbase_library_get_loader_handle.md)
- [`emf_cbase_library_get_num_loaders`](../reference/fn.emf_cbase_library_get_num_loaders.md)
- [`emf_cbase_library_library_exists`](../reference/fn.emf_cbase_library_library_exists.md)
- [`emf_cbase_library_load`](../reference/fn.emf_cbase_library_load.md)
- [`emf_cbase_library_register_loader`](../reference/fn.emf_cbase_library_register_loader.md)
- [`emf_cbase_library_type_exists`](../reference/fn.emf_cbase_library_type_exists.md)
- [`emf_cbase_library_unload`](../reference/fn.emf_cbase_library_unload.md)
- [`emf_cbase_library_unregister_loader`](../reference/fn.emf_cbase_library_unregister_loader.md)
- [`emf_cbase_library_unsafe_create_library_handle`](../reference/fn.emf_cbase_library_unsafe_create_library_handle.md)
- [`emf_cbase_library_unsafe_get_loader_handle`](../reference/fn.emf_cbase_library_unsafe_get_loader_handle.md)
- [`emf_cbase_library_unsafe_get_loader_interface`](../reference/fn.emf_cbase_library_unsafe_get_loader_interface.md)
- [`emf_cbase_library_unsafe_get_loader_library_handle`](../reference/fn.emf_cbase_library_unsafe_get_loader_library_handle.md)
- [`emf_cbase_library_unsafe_link_library`](../reference/fn.emf_cbase_library_unsafe_link_library.md)
- [`emf_cbase_library_unsafe_remove_library_handle`](../reference/fn.emf_cbase_library_unsafe_remove_library_handle.md)
