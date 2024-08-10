#pragma once

#include <types.h>

#ifdef __cplusplus
extern "C" {
#endif

void irq_all_on();
void irq_all_off();
void irq_on(u8 irq);
void irq_off(u8 irq);

#ifdef __cplusplus
}

namespace IRQ {
    void stub on(u8 irq) WRAP(irq_on(irq));
    void stub off(u8 irq) WRAP(irq_off(irq));
    void stub all_on() WRAP(irq_all_on());
    void stub all_off() WRAP(irq_all_off());
};
#endif
