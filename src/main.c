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
#include <rs.h>
#include <fasm_eg.h>
#include <gas_hello.h>

extern BOOTBOOT bootboot;
extern unsigned char environment[4096];
extern u32 fb;

void test_acpi() {
    uart_puts("\n * ACPI test\n");
}

void _start() {
    ACPI_Register();

    if (ACPI_CpuID()) while (1); // i will work on this later

    gas_hello();

    uart_puts("\n * Hello from C!\n");

    cxx_hello();

    fasm_main();

    rs_main();

    cxx_main();

    while(1);
}
