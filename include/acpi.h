#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

#define ACPI_CMD_BUFFER_SIZE 8
#define ACPI_JUMP 0xEA // jump to specified address
#define ACPI_NOP 0x00 // no operation
#define ACPI_STOP 0xFF // entirely halts the CPU
#define ACPI_CALL 0x80 // call specified function

#define ACPI_MAX_CPUS 256

extern u64 ACPI_CmdBuffer[ACPI_CMD_BUFFER_SIZE];

extern u16 ACPI_CpuCount;

u16 ACPI_CpuID();
void ACPI_CmdCenter();
void ACPI_SendCommand(u8 cpuid, u8 cmd, u64 a, u64 b, u64 c, u64 d);
void ACPI_Register();

#ifdef __cplusplus
}

nomangle {
    #include "acpi.h"
}

namespace acpi {
    u16 virt id() RWRAP(ACPI_CpuID());
}

#endif
