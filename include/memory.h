#pragma once
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void *memset(void *s, uintn c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
int bcmp(const void *s1, const void *s2, size_t n);

#ifdef __cplusplus
}

namespace mem {
    void *virt set(void *s, uintn c, size_t n) WRAP(memset(s, c, n));
    void *virt copy(void *dest, const void *src, size_t n) WRAP(memcpy(dest, src, n));
    void *virt move(void *dest, const void *src, size_t n) WRAP(memmove(dest, src, n));
    int stub cmp(const void *s1, const void *s2, size_t n) WRAP(memcmp(s1, s2, n));
    int stub bcmp(const void *s1, const void *s2, size_t n) WRAP(bcmp(s1, s2, n));
}

#endif
