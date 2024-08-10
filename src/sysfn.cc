#include <types.h>
#include <ihc.h>
#include <uart.h>
#include <ihc.h>
#include <irq.h>

#define COMP_NOP                  0b0000000000000000ULL
#define COMP_COM_SERIAL_UART_PUTS 0b0001000000000000ULL
#define COMP_ARCH_IRQ_ON          0b0010000000000000ULL
#define COMP_ARCH_IRQ_OFF         0b0010000000010000ULL
#define COMP_ARCH_IHC_SET         0b0010000000010000ULL
#define COMP_SYSFN_BLOCK          0b0011000000000000ULL

static bool __justexit = false;

nomangle
void sysfn_ihc_handler(u64 component, u64 arg1, u64 arg2, u64 arg3, u64 arg4) {
    uart::cout << " * syscall invoked\n";
    if (__justexit) {
        uart::cout << " * syscall: blocked\n";
        return;
    }
    if (component == COMP_NOP) {
        return;
    } else if (component == COMP_COM_SERIAL_UART_PUTS) {
        uart::cout << (char *)arg1 << '\n';
        return;
    } else if (component == COMP_ARCH_IRQ_ON) {
        IRQ::on(arg1);
        return;
    } else if (component == COMP_ARCH_IRQ_OFF) {
        IRQ::off(arg1);
        return;
    } else if (component == COMP_ARCH_IHC_SET) {
        IHC::set_handler(arg1, (void (*)(u8))arg2);
        return;
    } else if (component == COMP_SYSFN_BLOCK) {
        __justexit = true;
        return;
    }
            
}
