#include <types.hh>
#include <irq.hh>
#include <ports.hh>

namespace PIC {
    namespace master {
        constexpr u16 cmd  = 0x20;
        constexpr u16 data = 0x21;
    };
    namespace slave {
        constexpr u16 cmd  = 0xA0;
        constexpr u16 data = 0xA1;
    };
}

void IRQ::all_on() {
    outb(PIC::master::data, 0x00);
    outb(PIC::slave::data, 0x00);
}

void IRQ::all_off() {
    outb(PIC::master::data, 0xFF);
    outb(PIC::slave::data, 0xFF);
}

void IRQ::on(u8 irq) {
    u8 mask;

    // get current mask
    mask = inb(PIC::master::data);

    if (irq < 8) { // PIC_MASTER
        mask &= ~(1 << irq); // Reset bit for IRQ
        outb(PIC::master::data, mask);
    } else { // PIC_SLAVE
        mask = inb(PIC::slave::data);
        mask &= ~(1 << (irq - 8)); // Reset bit for IRQ
        outb(PIC::slave::data, mask);
    }
}

void IRQ::off(u8 irq) {
    u8 mask;

    // Get current mask
    mask = inb(PIC::master::data);

    if (irq < 8) { // PIC_MASTER
        mask |= (1 << irq); // Set bit for IRQ
        outb(PIC::master::data, mask);
    } else { // PIC_SLAVE
        mask = inb(PIC::slave::data);
        mask |= (1 << (irq - 8)); // Set bit for IRQ
        outb(PIC::slave::data, mask);
    }
}
