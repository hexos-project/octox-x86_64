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

extern BOOTBOOT bootboot;
extern unsigned char environment[4096];
extern u32 fb;

void _start() {
    if (ACPI_CoreID()) while (1);

    rs_main();

    cxx_main();

    while(1);
}
