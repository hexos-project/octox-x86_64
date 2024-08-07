#include <acpi.h>

/* ABSOLUTELY WORKS */
u32 ACPI_CoreID() {
    u32 apic_id;
    asm volatile("cpuid" : "=b"(apic_id) : "a"(1));
    return apic_id >> 24;
}
