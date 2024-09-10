#pragma once

#include "types.hh"

namespace IRQ {
    enum class irqs: u8 {
        ALL = 0xFF,
    };

    inline auto all = irqs::ALL;

    void on(u8 irq);
    void on(irqs irq);
    void off(u8 irq);
    void off(irqs irq);
    void all_on();
    void all_off();
};
