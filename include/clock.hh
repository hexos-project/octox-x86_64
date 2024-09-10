#pragma once

#include "types.hh"
#include "ihc.hh"

#ifdef __cplusplus
extern "C" {
#endif

extern u64 uptime;

void clock_ihc_handler(u8 n);

#ifdef __cplusplus
}
#endif
