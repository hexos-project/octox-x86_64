#pragma once

#include "types.h"
#include "uart.h"

extern error_t __errno;

#define throw(x) { __errno = x; return; }
#define on
#define error(x) if (__errno == x)
#define err if (__errno)
#define calm __errno = null
#define panic(x) { uart_puts("panic: "); uart_puts(x); uart_puts("\n"); while(1); }
#define oops(x) { uart_puts("oops: "); uart_puts(x); uart_puts("\n") }
