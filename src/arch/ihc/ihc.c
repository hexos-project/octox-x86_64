#include <ihc.h>
#include <extc.h>

ihc_handler_t ihc_handlers[256];

void ihc_init(void) {
    for (int i = 0; i < 256; i++) ihc_handlers[i] = (ihc_handler_t)ihc_default_handler;
}

void ihc_set_handler(u8 n, ihc_handler_t handler) {
    ihc_handlers[n] = handler;
}

void ihc_default_handler(u8 n) {
    uart_puts(" ! Unhandled interrupt: ");
    uart_puthex(n);
    uart_puts("\n");
}
