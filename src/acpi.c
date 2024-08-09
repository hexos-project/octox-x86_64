#include <acpi.h>

/* ABSOLUTELY WORKS, DUNT EDIT */
u16 ACPI_CoreID() {
    u32 apic_id;
    asm volatile("cpuid" : "=b"(apic_id) : "a"(1));
    return (u16)(apic_id >> 24); // pls use explicit casting everywhere where u can
}
