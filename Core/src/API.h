#ifdef CORE_EXPORTS
#define GE_API _declspec(dllexport)
#else
#define GE_API _declspec(dllimport)
#endif