#include <acpi.h>

/* ABSOLUTELY WORKS */
u16 ACPI_CoreID() {
    u16 apic_id;
    asm volatile("cpuid" : "=b"(apic_id) : "a"(1));
    return apic_id >> 24;
}
