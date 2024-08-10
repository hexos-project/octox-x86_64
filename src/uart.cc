#include <uart.h>
#include <ports.h>


void uart::puthex(u64 n)
{
    const char *hex = "0123456789ABCDEF";
    char buf[17];
    int i = 0;
    for (i = 0; i < 16; i++) {
        buf[i] = hex[(n >> (60 - 4 * i)) & 0xF];
    }
    buf[16] = 0;
    char *p = buf;
    // while (*p++ == '0');
    uart::puts(p);
}

void uart::puthex(u8 n)
{
    const char *hex = "0123456789ABCDEF";
    char buf[3];
    int i = 0;
    for (i = 0; i < 2; i++) {
        buf[i] = hex[(n >> (4 - 4 * i)) & 0xF];
    }
    buf[2] = 0;
    uart::puts(buf);
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
    uart::puts("@");
    uart::puthex(n);
    return *this;
}

uart::ostream& uart::ostream::operator<<(u8 n)
{
    uart::puts("@");
    uart::puthex(n);
    return *this;
}
