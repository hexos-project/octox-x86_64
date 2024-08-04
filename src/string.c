#include <string.h>
#include <types.h>

int strlen(char *str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void strrev(char *buffer) {
    char c;
    
    for (int i = 0, j = strlen(buffer) - 1; i < j; i++, j--) {
        c = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = c;
    }
}

void itoh(u64 value, char *str) {
    int i = 0;
    while (value) {
        str[i++] = (value % 16) + ((value % 16 < 10) ? '0' : 'A' - 10);
        value /= 16;
    }
    strrev(str);
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
    strrev(str);
}

u64 otoi(char *str) {
    u64 value = 0;
    int base = 1;
    int i = strlen(str) - 1;
    while (i >= 0) {
        value += (str[i] - '0') * base;
        base *= 8;
        i--;
    }
    return value;
}

int strcmp(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
