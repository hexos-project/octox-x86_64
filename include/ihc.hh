#pragma once

#include "types.hh"
#include "ihc/extrns.hh"

using ihc_handler_t = void (*)(u8);

extern ihc_handler_t ihc_handlers[256];

extern void ihc_default_handler(u8);

namespace IHC {
    void init();
    void set_handler(u8 n, ihc_handler_t handler);
    inline ihc_handler_t default_handler = ihc_default_handler;
}
