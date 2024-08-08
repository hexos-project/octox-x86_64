#include <cxx_main.h>

#include <types.h>
#include <uart.h>
#include <ihc.h>
#include <idt.h>
#include <sysfn.h>
#include <cpu.hh>
#include <uart.hh>
#include <acpi.hh>

nomangle
void cxx_main() {
    uart::cout << " * Hello from C++ part!\n";
    uart::cout << " * IHC Initialization... ";
    // ihc_init();
    uart::cout << "Done\n";
}
