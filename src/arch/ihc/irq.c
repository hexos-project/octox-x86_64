#include <types.h>
#include <irq.h>
#include <ports.h>

#define PIC_MASTER_CMD  0x20
#define PIC_MASTER_DATA 0x21
#define PIC_SLAVE_CMD   0xA0
#define PIC_SLAVE_DATA  0xA1

void irq_all_on() {
    outb(PIC_MASTER_DATA, 0x00);
    outb(PIC_SLAVE_DATA, 0x00);
}

void irq_all_off() {
    outb(PIC_MASTER_DATA, 0xFF);
    outb(PIC_SLAVE_DATA, 0xFF);
}

void irq_on(u8 irq) {
    u8 mask;

    // get current mask
    mask = inb(PIC_MASTER_DATA);

    if (irq < 8) { // PIC_MASTER
        mask &= ~(1 << irq); // Reset bit for IRQ
        outb(PIC_MASTER_DATA, mask);
    } else { // PIC_SLAVE
        mask = inb(PIC_SLAVE_DATA);
        mask &= ~(1 << (irq - 8)); // Reset bit for IRQ
        outb(PIC_SLAVE_DATA, mask);
    }
}

void irq_off(u8 irq) {
    u8 mask;

    // Get current mask
    mask = inb(PIC_MASTER_DATA);

    if (irq < 8) { // PIC_MASTER
        mask |= (1 << irq); // Set bit for IRQ
        outb(PIC_MASTER_DATA, mask);
    } else { // PIC_SLAVE
        mask = inb(PIC_SLAVE_DATA);
        mask |= (1 << (irq - 8)); // Set bit for IRQ
        outb(PIC_SLAVE_DATA, mask);
    }
}
