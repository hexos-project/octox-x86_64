#pragma once

#include "types.hh"

namespace cpu {
    __noreturn __naked
    inline void halt() {
        __asm__ volatile ("cli\nhlt\njmp .-2\n");
    }
}
