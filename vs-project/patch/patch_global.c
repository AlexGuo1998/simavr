#include "patch_global.h"

#include <ctype.h>
#include <windows.h>

// credit:
// https://stackoverflow.com/a/31128931
int strcasecmp(const char* a, const char* b) {
    int ca, cb;
    do {
        ca = *(unsigned char*)a;
        cb = *(unsigned char*)b;
        ca = tolower(ca);
        cb = tolower(cb);
        a++;
        b++;
    } while (ca == cb && ca != '\0');
    return ca - cb;
}

// credit:
// https://stackoverflow.com/a/17283549/16177472
// http://www.c-plusplus.de/forum/109539-full
void usleep(__int64 usec) {
    HANDLE timer;
    LARGE_INTEGER ft;

    ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimerW(NULL, TRUE, NULL);
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
    WaitForSingleObject(timer, INFINITE);
    CloseHandle(timer);
}

// credit:
// glibc/string/strsep.c
char* strsep(char** stringp, const char* delim)
{
    char* begin, * end;
    begin = *stringp;
    if (begin == NULL)
        return NULL;
    /* Find the end of the token.  */
    end = begin + strcspn(begin, delim);
    if (*end)
    {
        /* Terminate the token and set *STRINGP past NUL character.  */
        *end++ = '\0';
        *stringp = end;
    }
    else
        /* No more delimiters; this is the last token.  */
        *stringp = NULL;
    return begin;
}

static inline void* max_ptr(void* a, void* b) {
    if (a >= b) return a;
    return b;
}

// credit:
// glibc/string/basename.c (modified)
char* basename(const char* filename)
{
    char* p = strrchr(filename, '/');
    p = max_ptr(p, strrchr(filename, '\\'));
    return p ? p + 1 : (char*)filename;
}

#ifdef _MSC_VER
#include <intrin.h>
void __sync_synchronize() {
    MemoryBarrier();
}

unsigned int __builtin_popcount(unsigned int n) {
    return __popcnt(n);
}
#endif
