#ifdef GE_API
#define API _declspec(dllexport)
#else
#define API _declspec(dllimport)
#endif