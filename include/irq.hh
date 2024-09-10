#pragma once

#include "types.hh"

namespace IRQ {
    void on(u8 irq);
    void off(u8 irq);
    void all_on();
    void all_off();
};
