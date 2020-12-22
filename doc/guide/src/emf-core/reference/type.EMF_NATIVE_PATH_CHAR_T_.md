# Type definition `EMF_NATIVE_PATH_CHAR_T`

```c
#ifdef _WIN32
#define EMF_NATIVE_PATH_CHAR_T wchar_t
#else
#define EMF_NATIVE_PATH_CHAR_T char
#endif
```

The character type used by the system to represent paths.
