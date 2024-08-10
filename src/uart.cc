#include <uart.h>
#include <ports.h>


void uart::puthex(u64 n)
{
    const char *hex = "0123456789abcdef";
    char buf[17];
    int i = 0;
    for (i = 0; i < 16; i++) {
        buf[i] = hex[(n >> (60 - 4 * i)) & 0xF];
    }
    buf[16] = 0;
    uart::puts(buf);
}

void uart::puthex(u8 n)
{
    uart::putc((n >> 4) & 0xF > 9 ? 'A' - 10 + n : '0' + (n >> 4) & 0xF);
    uart::putc(n & 0xF > 9 ? 'A' - 10 + n : '0' + n & 0xF);
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

uart::ostream& uart::ostream::operator<<(u8 n)
{
    uart::puts("0x");
    uart::puthex(n);
    return *this;
}
