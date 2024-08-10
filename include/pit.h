#pragma once

#include <ports.h>

#ifdef __cplusplus
extern "C" {
#endif

void pit_init(u32 frequency);

#ifdef __cplusplus
}

namespace PIT {
    void virt init(u32 frequency) WRAP(pit_init(frequency));
}

#endif

