#include <pit.h>

#define PIT_COMMAND 0x43
#define PIT_CHANNEL0 0x40
#define PIT_FREQUENCY 1193182

void pit_init(u32 frequency) {
    u32 divisor = PIT_FREQUENCY / frequency;

    outb(PIT_COMMAND, 0x36);
    
    outb(PIT_CHANNEL0, (u8)(divisor & 0xFF));
    outb(PIT_CHANNEL0, (u8)((divisor >> 8) & 0xFF));
}
