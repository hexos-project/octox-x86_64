#include <idt.hh>

void IDT::load() {
    struct {
        uint16_t limit;
        uint64_t base;
    } __packed idtr;
    idtr.limit = sizeof(idt) - 1;
    idtr.base = (uint64_t)&idt;
    asm volatile("lidt %0" : : "m"(idtr));
    asm volatile("sti\n");
}

void IDT::init() {
    idt_init();
}
