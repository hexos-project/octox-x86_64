#include <ihc.hh>
#include <uart.hh>

ihc_handler_t ihc_handlers[256];

void IHC::init(void) {
    for (int i = 0; i < 256; i++) ihc_handlers[i] = (ihc_handler_t)ihc_default_handler;
}

void IHC::set_handler(u8 n, ihc_handler_t handler) {
    ihc_handlers[n] = handler;
}

void ihc_default_handler(u8 n) {
    uart::cout << " ! Unhandled interrupt: " << n << '\n';
}
