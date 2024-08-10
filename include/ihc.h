#pragma once

#include "types.h"
#include "ihc/extrns.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ihc_handler_t)(u8);

extern ihc_handler_t ihc_handlers[256];

void ihc_init(void);

void ihc_default_handler(u8);

void ihc_set_handler(u8, ihc_handler_t);

#ifdef __cplusplus
}

namespace IHC {
    void stub init() WRAP(ihc_init());
    void stub set_handler(u8 n, ihc_handler_t handler) WRAP(ihc_set_handler(n, handler));
    ihc_handler_t default_handler = ihc_default_handler;
}

#endif
