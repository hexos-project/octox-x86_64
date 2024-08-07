#include <cxx_main.h>

#include <types.h>
#include <uart.h>
#include <ihc.h>
#include <idt.h>
#include <sysfn.h>
#include <cpu.hh>
#include <uart.hh>

nomangle
void cxx_main() {
    uart::puts(" * Hello from C++ part!\n");
    uart::puts(" * IHC Initialization... ");
    // ihc_init();
    uart::puts("Done\n");

}
