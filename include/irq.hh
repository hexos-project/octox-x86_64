#pragma once

#include <types.h>

extern "C" {
    #include <irq.h>
}

class IRQ {
public:
    static inline void on(u8 irq) {
        irq_on(irq);
    }
    static inline void off(u8 irq) {
        irq_off(irq);
    }

    static inline void all_on() {
        irq_all_on();
    }
    static inline void all_off() {
        irq_all_off();
    }
};
