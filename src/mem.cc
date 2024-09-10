#include <mem.hh>
#include <types.hh>

void *mem::set(void *s, uintn c, size_t n) {
    for (size_t i = 0; i < n; i++)
        ((char *)s)[i] = c;
    return s;
}

void *mem::copy(void *dest, const void *src, size_t n) {
    for (size_t i = 0; i < n; i++)
        ((char *)dest)[i] = ((char *)src)[i];
    return dest;
}

void *mem::move(void *dest, const void *src, size_t n) {
    if (dest < src) {
        for (size_t i = 0; i < n; i++)
            ((char *)dest)[i] = ((char *)src)[i];
    } else {
        for (size_t i = n; i > 0; i--)
            ((char *)dest)[i - 1] = ((char *)src)[i - 1];
    }
    return dest;
}

int mem::cmp(const void *s1, const void *s2, size_t n) {
    for (size_t i = 0; i < n; i++)
        if (((char *)s1)[i] != ((char *)s2)[i])
            return ((char *)s1)[i] - ((char *)s2)[i];
    return 0;
}

int mem::bcmp(const void *s1, const void *s2, size_t n) {
    const u8 *p1 = (const u8 *)s1;
    const u8 *p2 = (const u8 *)s2;

    for (size_t i = 0; i < n; i++)
        if (p1[i] != p2[i])
            return 1;
    return 0;
}

int str::len(char *str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void str::rev(char *str) {
    int i = 0;
    int j = str::len(str) - 1;
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++; j--;
    }
}

void itoh(u64 value, char* str) {
    int index = 0;
    char hexses[17] = "0123456789abcdef";
    while (value > 0)
    {
        str[index] = hexses[value % 16];
        index++;
        value /= 16;
    }

    str[index] = '\0';

    str::rev(str);
}


void itoa(int value, char *str, int base) {
    int i = 0;
    int sign = 0;
    if (value < 0) {
        sign = 1;
        value = -value;
    }
    while (value > 0) {
        int num = (value % base);
        str[i++] = (num < 10) ? num + '0' : num + 'A' - 10;
        value /= base;
    }
    if (sign)
        str[i++] = '-';
    str[i] = '\0';
    str::rev(str);
}

u64 otoi(char *str) {
    u64 value = 0;
    int base = 1;
    int i = str::len(str) - 1;
    while (i >= 0) {
        value += (str[i] - '0') * base;
        base *= 8;
        i--;
    }
    return value;
}

int str::cmp(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
