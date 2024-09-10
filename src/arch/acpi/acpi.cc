#include <acpi.hh>
#include <boot.hh>

extern BOOT::BOOTBOOT bootboot;

u16 acpi::cpu_count;

/* ABSOLUTELY WORKS, DUNT EDIT */
u16 acpi::id() {
    u32 apic_id;
    asm volatile("cpuid" : "=b"(apic_id) : "a"(1));
    return apic_id >> 24;
}

void acpi::init() {
    acpi::cpu_count = bootboot.numcores;
}
