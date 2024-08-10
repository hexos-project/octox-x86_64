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
    void virt on(u8 irq) WRAP(irq_on(irq));
    void virt off(u8 irq) WRAP(irq_off(irq));
    void virt all_on() WRAP(irq_all_on());
    void virt all_off() WRAP(irq_all_off());
};
#endif
