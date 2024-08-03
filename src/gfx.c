#include <gfx.h>
#include <bootboot.h>
#include <uart.h>
#include <config.h>

u8 *gfx_fb;
u64 gfx_fb_scanline;
u64 gfx_fb_width;
u64 gfx_fb_height;

void gfx_putpixel(int x, int y, u32 color) {
    *((u32*)(&*gfx_fb + gfx_fb_scanline*y + x*4)) = color & 0x00FFFFFF;
}

void gfx_init(BOOTBOOT bootboot, u8 *fb) {
    gfx_fb = fb;
    gfx_fb_scanline = bootboot.fb_scanline;
    gfx_fb_width = bootboot.fb_width;
    gfx_fb_height = bootboot.fb_height;
}

void gfx_blit(int width, int height, u32 *data, int x, int y) {
    if (UART_TRACE_GFX) {
        uart_puts("Image size: ");
        uart_putdec(width);
        uart_puts("x");
        uart_putdec(height);
        uart_puts("\n");
    }
    for (int _y = 0; _y < height; _y++)
        for (int _x = 0; _x < width; _x++) {
            if (UART_TRACE_GFX) {
                uart_puts("Putting pixel");
                uart_puthex(data[_y * width + _x] & 0x00FFFFFF);
                uart_puts(" at ");
                uart_putdec(x + _x);
                uart_puts(", ");
                uart_putdec(y + _y);
                uart_puts("\n");
            }
                gfx_putpixel(x + _x, y + _y, data[_y * width + _x]);
                // gfx_putpixel(x + _x, y + _y, 0xFF0000);
        }
}

void gfx_blit_chroma(int width, int height, u32 *data, int x, int y, u32 chroma) {
    if (UART_TRACE_GFX) {
        uart_puts("Image size: ");
        uart_putdec(width);
        uart_puts("x");
        uart_putdec(height);
        uart_puts("\n");
    }
    for (int _y = 0; _y < height; _y++)
        for (int _x = 0; _x < width; _x++) {
            if (UART_TRACE_GFX) {
                uart_puts("Putting pixel");
                uart_puthex(data[_y * width + _x] & 0x00FFFFFF);
                uart_puts(" at ");
                uart_putdec(x + _x);
                uart_puts(", ");
                uart_putdec(y + _y);
                uart_puts("\n");
            }
                if ((data[_y * width + _x] & 0x00FFFFFF) == chroma)
                    continue;
                gfx_putpixel(x + _x, y + _y, data[_y * width + _x]);
                // gfx_putpixel(x + _x, y + _y, 0xFF0000);
        }
}
