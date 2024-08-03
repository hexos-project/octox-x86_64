#pragma once

#include "types.h"
#include "ports.h"
#include "string.h"

#define UART_BASE 0x3F8

static inline void uart_putc(char c)
{
    while ((inb(UART_BASE + 5) & 0x20) == 0);
    outb(UART_BASE, c);
}

static inline void uart_puts(char *s)
{
    while (*s) {
        uart_putc(*s);
        s++;
    }
}

static inline void uart_puthex(u32 val)
{
    char buf[17];
    for (int i = 0; i < 17; i++)
        buf[i] = 0;
    itoh(val, buf);
    uart_puts(buf);
}

static inline void uart_puthexb(u8 val)
{
    char buf[17];
    for (int i = 0; i < 17; i++)
        buf[i] = 0;
    itoh(val, buf);
    uart_puts(buf+16);
}

static inline void uart_putdec(u32 val)
{
    char buf[64];
    itoa(val, buf, 10);
    uart_puts(buf);
}
