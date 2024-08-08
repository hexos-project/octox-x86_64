#include "acpi.hh"

u16 acpi::id() {
    u16 apic_id;
    asm volatile("cpuid" : "=b"(apic_id) : "a"(1));
    return apic_id >> 24;
}