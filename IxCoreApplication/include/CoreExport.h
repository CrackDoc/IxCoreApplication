

#if defined(WIN32)

#ifdef IxCoreApplication_EXPORTS
#define CORE_EXPORT __declspec(dllexport)
#else
#define CORE_EXPORT __declspec(dllimport)
#endif

#elif __linux__
#define CORE_EXPORT

#else
#define CORE_EXPORT
#endif
