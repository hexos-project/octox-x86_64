#pragma once

#include "types.h"
#include "ports.h"
#include "string.h"

void uart_putc(char c);
void uart_puts(char *s);
void uart_puthex(u64 val);
void uart_puthexb(u8 val);
void uart_putdec(u32 val);
