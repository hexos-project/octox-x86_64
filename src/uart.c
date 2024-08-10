#include <uart.h>

#define UART_BASE 0x3F8

void uart_putc(char c)
{
    while ((inb(UART_BASE + 5) & 0x20) == 0);
    outb(UART_BASE, c);
}

void uart_puts(char *s)
{
    while (*s) {
        uart_putc(*s++);
    }
}

void uart_puthex(u64 val)
{
    char buf[17];
    itoh(val, buf);
    uart_puts(buf);
}

void uart_puthexb(u8 val)
{
    char buf[17];
    for (int i = 0; i < 3; i++) buf[i] = 0;
    itoh(val, buf);
    uart_puts(buf+14);
}

void uart_putdec(u32 val)
{
    char buf[64];
    itoa(val, buf, 10);
    uart_puts(buf);
}
