#pragma once

#include <types.h>
#include <cc.hh>

extern "C" {
    #include <idt.h>
}

namespace IDT {
    void stub init() WRAP(idt_init());
    void stub load() WRAP(idt_load());
}
