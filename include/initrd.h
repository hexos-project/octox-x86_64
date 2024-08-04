#pragma once

#include "types.h"
#include "tar.h"

typedef tarball_t initrd_t;

initrd_t initrd_init(tarball_t tarball);
void *initrd_get(initrd_t initrd, char *fp);
