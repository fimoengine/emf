# FileSystem system

## Introduction

The `FS` system specifies a customizable virtual file system, 
that is consistent across multiple platform.

The fs is realized in two parts, a `virtual` fs-graph 
which contains multiple `physical` fs-trees. 
Every node contains access permissions, is reference counted and 
is of the type `file`, `directory`, `link` or `mount point`.
The fs can be extended with `File handlers`.

### Entries

As mentioned above, the `entries` are modelled as `nodes` of the `graph` / `tree`.
They can have the following types:

- `file`: A file.
- `directory`: A directory.
- `link`: A link.
  - `soft link`: A symbolik link to a node. The link can be invalidated.
  - `hard link`: A strong link to a node. The creation of such a link increases the reference count of the node it points to. Linking to a `physical` node also increases the reference count of the corresponding `mount point`.
- `mount point`: A link between the `virtual` graph and a `physical` tree.

### The `virtual` graph

The first part of the fs is the `virtual` graph. This graph can contain cycles and is not tied to a real fs.
It consists of `directories`, `links` and `mount points`, and as such, does not contain any resource.

### The `physical` tree.

The rest of the fs is modelled as `trees`. They consist of `files` and `directories`.
Those `trees` are tied to a physical fs and are implemented with `File handlers`.

### `File handlers`

`File handlers` contain the actual logic of the fs. They implement common procedures, 
like creating files, mounting a fs or opening streams. Those procedures can be tuned to a specifiy fs by defining custom input structures, but sane defaults are specified. A `File handler` can assume that any modification of a mounted fs occurs through it self and that any resource is contained in only one `physical` fs. Mounting a path or sub-paths multiple times and any modification of the `physical` fs which does not occur by the `File handler` that mounted the path, may result in an erroneous state.

### `Streams`

A `stream` is a handle to an opened file. Their interface is similar to the `C File-API`.
Multiple `streams` to one file can exist. Concurrent read and write operations on one file are thread-safe, as long
as the `streams` are not shared, and they do not overlap.

## Example

```c
const char file_path_str = "/test";
emf_path_t file_path;
memset(&file_path, 0, sizeof(emf_path_t));

// Populate the event name.
// Bounds checking is omitted for brevity.
file_path.length = strlen(file_path_str);
memcpy(&file_path.data, file_path_str, file_path.length);

// Create a buffer.
char buffer[1024];
emf_fs_buffer_t fs_buffer = { buffer, 1024 };

emf_lock();

emf_file_stream_t stream = emf_fs_stream_open(&file_path,
    emf_file_open_mode_begin, emf_file_access_mode_read, NULL, 1024);

// Read up to 1024 bytes from the stream.
emf_error_t error = emf_fs_stream_read(stream, &fs_buffer, 1024);

emf_fs_stream_close(stream);

emf_unlock();
```
