#pragma once

#include "types.h"

namespace uart {
    struct ostream {
        ostream();
        ostream& operator<<(char c);
        ostream& operator<<(char *s);
        ostream& operator<<(const char *s);
        ostream& operator<<(u64 n);
    };
    void putc(char c);
    void puts(char *s);
    void puts(const char *s);
    void puthex(u64 n);

    extern uart::ostream cout;
}
