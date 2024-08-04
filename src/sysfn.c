#include <types.h>
#include <ihc.h>
#include <extc.h>
#include <uart.h>
#include <sysfn.h>

void sysfn_handler(u8 n, state_t state) {
    uart_puts("sysfn_handler\n");
    uart_puts("n = ");
    uart_puthex(n);
    uart_putc('\n');
}
