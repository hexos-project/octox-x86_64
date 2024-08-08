#pragma once

#include "types.h"
#include "acpi.h"

namespace acpi {
    static inline u16 id() {
        u16 apic_id;
        asm volatile("cpuid" : "=b"(apic_id) : "a"(1));
        return apic_id >> 24;
    }
}
