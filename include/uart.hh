#pragma once

#include "types.hh"
#include "ports.hh"


namespace uart {
    struct ostream {
        ostream();
        ostream& operator<<(char c);
        ostream& operator<<(char *s);
        ostream& operator<<(const char *s);
        ostream& operator<<(u64 n);
        ostream& operator<<(u8 n);
    };
    void putc(char c);
    void puts(const char *s);
    void puts(char *s);
    void puthex(u64 n);
    void puthex(u8 n);

    extern uart::ostream cout;
}
