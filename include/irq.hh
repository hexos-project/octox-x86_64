#pragma once

#include <types.h>
#include <cc.hh>

extern "C" {
    #include <irq.h>
}

class IRQ {
public:
    void stub on(u8 irq) WRAP(irq_on(irq));
    void stub off(u8 irq) WRAP(irq_off(irq));
    void stub all_on() WRAP(irq_all_on());
    void stub all_off() WRAP(irq_all_off());
};
