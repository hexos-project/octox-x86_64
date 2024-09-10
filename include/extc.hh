#pragma once

#include "uart.hh"

extern error_t __errno;

#define throw(x) { __errno = x; return; }
#define error(x) if (__errno == x)
#define err if (__errno)
#define calm __errno = null
#define panic(x) { uart::cout << "panic: " << x << "\n"; while(1); }
#define oops(x) { uart::cout << "oops: " << x << "\n" }
