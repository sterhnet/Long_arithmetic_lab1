#ifdef BigInt_EXPORTS
#define BigInt_EXPORT __declspec(dllexport)
#else
#define BigInt_EXPORT __declspec(dllimport)
#endif