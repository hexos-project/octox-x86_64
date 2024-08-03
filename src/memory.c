#include <memory.h>

void *memset(void *s, int c, size_t n) {
    for (size_t i = 0; i < n; i++)
        ((char *)s)[i] = c;
    return s;
}

void *memcpy(void *dest, const void *src, size_t n) {
    for (size_t i = 0; i < n; i++)
        ((char *)dest)[i] = ((char *)src)[i];
    return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
    if (dest < src) {
        for (size_t i = 0; i < n; i++)
            ((char *)dest)[i] = ((char *)src)[i];
    } else {
        for (size_t i = n; i > 0; i--)
            ((char *)dest)[i - 1] = ((char *)src)[i - 1];
    }
    return dest;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    for (size_t i = 0; i < n; i++)
        if (((char *)s1)[i] != ((char *)s2)[i])
            return ((char *)s1)[i] - ((char *)s2)[i];
    return 0;
}
