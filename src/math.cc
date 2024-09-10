#include <math.hh>

int math::ceil(int orig, int base) {
    return orig + (base - (orig % base)) % base;
}
