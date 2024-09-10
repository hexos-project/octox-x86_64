#include <clock.hh>


u64 uptime = 0;

void clock_ihc_handler(u8 n) {
    uptime++;
}
