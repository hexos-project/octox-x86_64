#include <types.h>
#include <acpi.h>
#include <bootboot.h>
#include <uart.h>
#include <config.h>
#include <initrd.h>
#include <ihc.h>
#include <sysfn.h>
#include <idt.h>
#include <cxx_main.h>
#include <hellos.h>

extern BOOTBOOT bootboot;
extern unsigned char environment[4096];
extern u32 fb;

void _start() {
    if (ACPI_CpuID()) while (1); // i will work on this later

    ACPI_Init();

    gas_hello();
    c_hello();
    cxx_hello();
    fasm_hello();
    rs_hello();

    cxx_main();
    while(1);
}
