#include <acpi.h>

int ACPI_CoreID() {
    // use CPUID to get the APIC ID
    // APIC ID is in ebx[31:24]
    int apic_id;
    asm volatile("cpuid" : "=b"(apic_id) : "a"(1));
    return apic_id >> 24;
}
