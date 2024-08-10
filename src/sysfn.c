#include <types.h>
#include <ihc.h>
#include <extc.h>
#include <uart.h>
#include <sysfn.h>

void sysfn_ihc_handler(u8 n) {
    uart_puts("sysfn_handler\n");
    uart_puts("n = ");
    uart_puthex(n);
    uart_putc('\n');
}
