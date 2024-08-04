#include <gfx.h>
void puts(char *s);

#include <types.h>
#include <acpi.h>
#include <bootboot.h>
#include <uart.h>
#include <config.h>
#include <tar.h>

extern BOOTBOOT bootboot;
extern unsigned char environment[4096];
extern u32 fb;
u64 apicID;

void _start()
{
    if ((apicID = ACPI_CoreID()) != 0) { while (1); }

    gfx_init(bootboot, &fb);

    // for (int i = 0; i < bootboot.fb_width * bootboot.fb_height; i++) (&fb)[i] = 0x1c1c1c;

    uart_puts("\n * HexOS kernel v0.7.1-rev79 (build " __DATE__ " " __TIME__ ")\n");
    uart_puts(" * ACPI Core ID: 0x");
    uart_puthex(apicID);
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

    tarball_t initrd = (tarball_t)bootboot.initrd_ptr;

    while(1);
}
