#pragma once

#include "types.hh"
#include "tar.hh"
#include "boot.hh"

using initrd_t = tarball_t;

namespace initrd {
    void init(BOOT::BOOTBOOT bootboot);
    void *get(initrd_t initrd, char *fp);
}
