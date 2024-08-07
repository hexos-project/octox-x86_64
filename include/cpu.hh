#pragma once

#include "types.h"

nomangle
struct gdtd_t {
    u16 limit0;
    u16 base0;
    u8 base1;
    u8 access;
    u8 lim1_n_flags;
    u8 base2;
    u32 base3;
    u32 zero;
};

nomangle
struct idtd_t {
   u16 offset0;
   u16 selector;
   u8 ist;
   u8 type_attributes;
   u16 offset1;
   u32 offset2;
   u32 zero;
};

namespace cpu {
    void set_idt(idtd_t *idt);
    void set_gdt(gdtd_t *gdt);
    void sti();
    void cli();
    void hlt();
}
