#pragma once

extern int strcasecmp(const char *a, const char *b);
extern void usleep(__int64 usec);
extern char* strsep(char** stringp, const char* delim);
extern char* basename(const char* filename);
extern __int64 win32_gettimestampns();
