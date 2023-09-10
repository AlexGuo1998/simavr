#pragma once

#include <malloc.h>
#define alloca _alloca

extern int strcasecmp(const char *a, const char *b);
extern void usleep(__int64 usec);
extern char* strsep(char** stringp, const char* delim);
extern char* basename(const char* filename);
