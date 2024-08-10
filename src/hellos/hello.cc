#include <uart.h>

nomangle void cxx_hello() {
    uart::cout << " * Hello from C++!\n";
}
