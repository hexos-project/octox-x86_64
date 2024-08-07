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

extern BOOTBOOT bootboot;
extern unsigned char environment[4096];
extern u32 fb;

void _start()
{
    if (bootboot.bspid != 0) { while (1); }

    uart_puts("\n * Octox v" MMP "+rev" MLS " (build " __DATE__ " " __TIME__ ")\n");
    uart_puts(" * ACPI Core ID: 0x");
    uart_puthex(bootboot.bspid);
    uart_puts("\n");
    uart_puts(" * INITRD located at 0x");
    uart_puthex(bootboot.initrd_ptr);
    uart_puts("\n");
    uart_puts(" * INITRD size: 0x");
    uart_puthex(bootboot.initrd_size);
    uart_puts("\n");
    uart_puts(" * memory map located at 0x");
    uart_puthex(bootboot.mmap.ptr);
    uart_puts("\n");

    initrd = initrd_init(bootboot);

    cxx_main();

    while(1);
}
