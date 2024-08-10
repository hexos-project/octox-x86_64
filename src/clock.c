#include <clock.h>


u128 uptime = 0;

void clock_ihc_handler(u8 n) {
    uptime++;
}
