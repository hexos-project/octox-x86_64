#include <uart.h>
#include <ports.h>


void uart::putc(char c)
{
    u8 status;
    do {
        status = inb(0x3f8);
    } while ((status & 0x20) == 0);
    outb(0x3f8, c);
}

void uart::puts(char *s)
{
    while (*s) {
        putc(*s++);
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

uart::ostream uart::cout;

uart::ostream::ostream()
{
}

uart::ostream& uart::ostream::operator<<(char c)
{
    uart::putc(c);
    return *this;
}

uart::ostream& uart::ostream::operator<<(char *s)
{
    uart::puts(s);
    return *this;
}

uart::ostream& uart::ostream::operator<<(const char *s)
{
    uart::puts(s);
    return *this;
}

uart::ostream& uart::ostream::operator<<(u64 n)
{
    uart::puts("0x");
    uart::puthex(n);
    return *this;
}
