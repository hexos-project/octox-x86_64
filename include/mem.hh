#pragma once

#include "types.hh"

namespace mem {
    void *set(void *s, uintn c, size_t n);
    void *copy(void *dest, const void *src, size_t n);
    void *move(void *dest, const void *src, size_t n);
    int cmp(const void *s1, const void *s2, size_t n);
    int bcmp(const void *s1, const void *s2, size_t n);
}

void itoa(int value, char *str, int base);
u64 otoi(char *str);
void itoh(u64 value, char *str);

namespace str {
    void rev(char *str);
    int len(char *str);
    int cmp(char *s1, char *s2);
}
