#pragma once

#include "types.h"
#include "cc.hh"

nomangle {
    #include "acpi.h"
}

namespace acpi {
    u16 stub id() RWRAP(ACPI_CpuID());
}
