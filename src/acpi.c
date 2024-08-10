#include <acpi.h>

u64 ACPI_CmdBuffer[ACPI_CMD_BUFFER_SIZE];
u16 ACPI_CpuCount;

/* ABSOLUTELY WORKS, DUNT EDIT */
u16 ACPI_CpuID() {
    u32 apic_id;
    asm volatile("cpuid" : "=b"(apic_id) : "a"(1));
    return apic_id >> 24;
}

void ACPI_CmdCenter() {
ACPI_CmdCenter_loop:
    while (ACPI_CmdBuffer[1] == ACPI_NOP || ACPI_CmdBuffer[0] != ACPI_CpuID());
    if (ACPI_CmdBuffer[0] == ACPI_JUMP) {
        ACPI_CmdBuffer[1] = ACPI_NOP;
        asm volatile("jmp *%0" :: "r"(ACPI_CmdBuffer[2]));
    } else if (ACPI_CmdBuffer[0] == ACPI_STOP) {
        ACPI_CmdCenter_stopLoop:
        asm volatile("hlt");
        goto ACPI_CmdCenter_stopLoop;
    }
    else if (ACPI_CmdBuffer[0] == ACPI_CALL) {
        ACPI_CmdBuffer[1] = ACPI_NOP;
        ((void (*)())ACPI_CmdBuffer[2])();
    } else {
        ACPI_CmdBuffer[1] = ACPI_NOP;
        goto ACPI_CmdCenter_loop;
    }
}

void ACPI_SendCommand(u8 cpuid, u8 cmd, u64 a, u64 b, u64 c, u64 d) {
    ACPI_CmdBuffer[0] = cpuid;
    ACPI_CmdBuffer[1] = cmd;
    ACPI_CmdBuffer[2] = a;
    ACPI_CmdBuffer[3] = b;
    ACPI_CmdBuffer[4] = c;
    ACPI_CmdBuffer[5] = d;
}

void ACPI_Register() {
    ACPI_CmdBuffer[0] = -1;
    ACPI_CmdBuffer[1] = ACPI_NOP;
    ACPI_CpuCount = ACPI_CpuCount < ACPI_CpuID() ? ACPI_CpuID() : ACPI_CpuCount;
    if (ACPI_CpuID()) ACPI_CmdCenter();
}
