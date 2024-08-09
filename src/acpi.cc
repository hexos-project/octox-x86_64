#include "acpi.hh"

/* ABSOLUTELY WORKS, DUNT EDIT */
u16 acpi::id() {
    u32 apic_id;
    asm volatile("cpuid" : "=b"(apic_id) : "a"(1));
    return (u16)(apic_id >> 24);
}
