#pragma once

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define M_PI 3.14159265358979323846

int ceil(int orig, int base);

#ifdef __cplusplus
}

namespace math {
    int ceil(int orig, int base) WRAP(ceil(orig, base));
}

#endif
