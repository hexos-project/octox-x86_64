#pragma once

#include <types.h>

extern "C" {
    #include <idt.h>
}

namespace IDT {
    void load();
}
