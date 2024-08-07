#pragma once

#include "types.h"
#include "tar.h"
#include "bootboot.h"

typedef tarball_t initrd_t;

extern initrd_t initrd;

initrd_t initrd_init(BOOTBOOT bootboot);
void *initrd_get(initrd_t initrd, char *fp);
