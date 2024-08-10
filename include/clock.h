#pragma once

#include <types.h>
#include <ihc.h>

#ifdef __cplusplus
extern "C" {
#endif

extern u128 uptime;

void clock_ihc_handler(u8 n);

#ifdef __cplusplus
}
#endif
