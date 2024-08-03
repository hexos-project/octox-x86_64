#include <gfx.h>
void puts(char *s);

#include <types.h>
#include <acpi.h>
#include <bootboot.h>
#include <uart.h>
#include <config.h>
#include <logo_hires.h>
#include <tar.h>

extern BOOTBOOT bootboot;
extern unsigned char environment[4096];
extern u32 fb;
u64 apicID;


void gfx_test() {
    for (int x = 0; x < bootboot.fb_width; x++)
        for (int y = 0; y < bootboot.fb_height; y++)
            gfx_putpixel(x, y, 0x1C1C1C);

    for (int x = 0; x < bootboot.fb_width; x++) {
        gfx_putpixel(x, 0, 0x00ffffff);
        gfx_putpixel(x, bootboot.fb_height - 1, 0x00ffffff);
        gfx_putpixel(x, bootboot.fb_height / 2, 0x00ffffff);
    }

    for (int y = 0; y < bootboot.fb_height; y++) {
        gfx_putpixel(0, y, 0x00ffffff);
        gfx_putpixel(bootboot.fb_width - 1, y, 0x00ffffff);
        gfx_putpixel(bootboot.fb_width / 2, y, 0x00ffffff);
    }
}

void _start()
{
    if ((apicID = ACPI_CoreID()) != 0) { while (1); }

    gfx_init(bootboot, &fb);

    for (int i = 0; i < bootboot.fb_width * bootboot.fb_height; i++)
        (&fb)[i] = 0x1c1c1c;

    if (GFX_TEST)
        gfx_test();
    
    gfx_blit_chroma(logo_hires_width, logo_hires_height, logo_hires_contents,
        bootboot.fb_width / 2 - logo_hires_width / 2,
        bootboot.fb_height / 2 - logo_hires_height / 2,
        0);

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
