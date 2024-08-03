#include <math.h>

int ceil(int orig, int base) {
    return orig + (base - (orig % base)) % base;
}
