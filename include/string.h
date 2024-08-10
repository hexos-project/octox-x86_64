#pragma once

#include <types.h>

#ifdef __cplusplus
extern "C" {
#endif

void itoa(int value, char *str, int base);
void strrev(char *str);
int strlen(char *str);
void itoh(u64 value, char *str);
int strcmp(char *s1, char *s2);
u64 otoi(char *str);

#ifdef __cplusplus
}
#endif
