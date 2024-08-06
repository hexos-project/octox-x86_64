#include <cxx_main.h>

#include <types.h>
#include <uart.h>

nomangle
void cxx_main() {
    uart_puts("Hello from C++!\n");
}