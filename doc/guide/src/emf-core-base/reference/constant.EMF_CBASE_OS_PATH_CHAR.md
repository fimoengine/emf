# Constant `EMF_CBASE_OS_PATH_CHAR`

```c
#if defined(Win32) || defined(_WIN32)
#define EMF_CBASE_OS_PATH_CHAR wchar_t
#else
#define EMF_CBASE_OS_PATH_CHAR char
#endif
```

Character used by the os to represent a path.
