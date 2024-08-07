#include <uart.hh>
#include <ports.h>


void uart::putc(char c)
{
    while ((inb(0x3f8+5) & 0x20) == 0);
    outb(0x3f8, c);
}

void uart::puts(char *s)
{
    while (*s) {
        putc(*s);
        s++;
    }
}


void uart::puts(const char *s)
{
    uart::puts((char*)s);
}


void uart::puthex(u64 n)
{
    const char *hex = "0123456789abcdef";
    char buf[17];
    int i = 0;
    for (i = 0; i < 16; i++) {
        buf[i] = hex[(n >> (60 - 4 * i)) & 0xF];
    }
    buf[16] = 0;
    puts(buf);
}
