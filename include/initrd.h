#pragma once

#include "types.h"
#include "tar.h"
#include "bootboot.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef tarball_t initrd_t;

void initrd_init(BOOTBOOT bootboot);
void *initrd_get(initrd_t initrd, char *fp);

#ifdef __cplusplus
}

namespace initrd {
    void virt init(BOOTBOOT bootboot) WRAP(initrd_init(bootboot));
    virt void *get(initrd_t initrd, char *fp) RWRAP(initrd_get(initrd, fp));
}

#endif
