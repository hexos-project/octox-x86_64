#pragma once
#include "types.hh"

struct intd_t {
    u16 offset_1;        // offset bits 0..15
    u16 selector;        // a code segment selector in GDT or LDT
    u8  ist;             // bits 0..2 holds Interrupt Stack Table offset, rest of bits zero.
    u8  type_attributes; // gate type, dpl, and p fields
    u16 offset_2;        // offset bits 16..31
    u32 offset_3;        // offset bits 32..63
    u32 zero;            // reserved
} __packed;

extern intd_t idt[256];

u16 get_cs(void);

namespace IDT {
    void init();
    void load();
}
