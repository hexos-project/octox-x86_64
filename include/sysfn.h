#pragma once

#include <types.h>
#include <ihc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define COMP_NOP                  0b0000000000000000ULL
#define COMP_COM_SERIAL_UART_PUTS 0b0001000000000000ULL
#define COMP_ARCH_IRQ_ON          0b0010000000000000ULL
#define COMP_ARCH_IRQ_OFF         0b0010000000010000ULL
#define COMP_ARCH_IHC_SET         0b0010000000010000ULL
#define COMP_SYSFN_BLOCK          0b0011000000000000ULL

extern void _syscall(u64 component, u64 arg1, u64 arg2, u64 arg3, u64 arg4);

void sysfn_ihc_handler(u8 n);

#ifdef __cplusplus
}
#endif
