#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include "ports.h"
#include "string.h"

void uart_putc(char c);
void uart_puts(char *s);
void uart_puthex(u64 val);
void uart_puthexb(u8 val);
void uart_putdec(u32 val);

#ifdef __cplusplus
}

namespace uart {
    struct ostream {
        ostream();
        ostream& operator<<(char c);
        ostream& operator<<(char *s);
        ostream& operator<<(const char *s);
        ostream& operator<<(u64 n);
        ostream& operator<<(u8 n);
    };
    void virt putc(char c) WRAP(uart_putc(c));
    void virt puts(const char *s) WRAP(uart_puts((char*)s));
    void virt puts(char *s) WRAP(uart_puts(s));
    void puthex(u64 n);
    void puthex(u8 n);

    extern uart::ostream cout;
}

#endif
