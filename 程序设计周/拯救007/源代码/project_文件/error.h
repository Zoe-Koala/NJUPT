#ifndef ___DS_PROJ_2_ERROR_H___
#define ___DS_PROJ_2_ERROR_H___
#define CHECK(X) if(NULL==(X)) Error("Out of space!!!")
void Error(const char *msg);
void Warning(const char *msg);
#endif // !___DS_PROJ_2_ERROR_H___
