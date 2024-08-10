#pragma once

#include "types.h"

extern char cpuidBrandString[25];

static inline void _cpuid(uint32_t eax, uint32_t ecx, uint32_t *ebx, uint32_t *edx, uint32_t *esi) {
    asm volatile (
        "cpuid"
        : "=b" (*ebx), "=c" (ecx), "=d" (*edx), "=a" (eax) // выходные значения
        : "0" (eax), "2" (ecx) // входные значения
    );
}

char *cpuid_getCpuidBrandString();
