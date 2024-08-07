#pragma once

#include "types.h"

namespace uart {
    void putc(char c);
    void puts(char *s);
    void puts(const char *s);
    void puthex(u64 n);
}