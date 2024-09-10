#pragma once

#include "types.hh"

constexpr u16 ACPI_MAX_CPUS = 256;

namespace acpi {
    extern u16 cpu_count;

    u16 id();
    void init();
}
