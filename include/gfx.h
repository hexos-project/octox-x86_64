#pragma once

#include "bootboot.h"
#include "types.h"

extern u8 *gfx_fb;
extern u64 gfx_fb_scanline;
extern u64 gfx_fb_width;
extern u64 gfx_fb_height;

void gfx_init();

void gfx_putpixel(int x, int y, u32 color);

void gfx_blit(int width, int height, u32 *data, int x, int y);

void gfx_blit_chroma(int width, int height, u32 *data, int x, int y, u32 chroma);
