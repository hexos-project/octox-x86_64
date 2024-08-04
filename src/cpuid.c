#include <cpuid.h>
#include <types.h>
#include <string.h>
#include <memory.h>

char cpuidBrandString[25];

char *cpuid_getCpuidBrandString() {
    u32 eax, ebx, ecx;
    
    // Вычисляем префикс процессора
    _cpuid(0x80000000, 0, &eax, &ebx, &ecx);
    if (eax < 0x80000000)
        return NULL;
    
    // Вычисляем идентификатор процессора
    _cpuid(0x80000002, 0, &eax, &ebx, &ecx);
    
    // Вычисляем подсистему и версию процессора
    _cpuid(0x80000003, 0, &eax, &ebx, &ecx);
    
    // Вычисляем префикс процессора
    memcpy(cpuidBrandString, "GenuineIntel", 12);
    memcpy(cpuidBrandString + 12, &eax, 4);
    memcpy(cpuidBrandString + 16, &ebx, 4);
    memcpy(cpuidBrandString + 20, &ecx, 4);
    cpuidBrandString[24] = '\0';
    return cpuidBrandString;
}
