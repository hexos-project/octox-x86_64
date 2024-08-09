#include <types.h>
#include <cpu.hh>
#include <uart.hh>
#include <acpi.hh>

extern "C" {
    #include <ihc.h>
    #include <idt.h>
    #include <sysfn.h>
    #include <cxx_main.h>
    #include <initrd.h>
    #include <config.h>
    #include <bootboot.h>

    extern BOOTBOOT bootboot;
}

nomangle
void cxx_main() {
    uart::cout << "\n * Octox v" MMP "+rev" MLS " (build " __DATE__ " " __TIME__ ")\n";
    uart::cout << "\n";
    uart::cout << " * INITRD located at 0x";
    uart::cout << bootboot.initrd_ptr;
    uart::cout << "\n";
    uart::cout << " * INITRD size: 0x";
    uart::cout << bootboot.initrd_size;
    uart::cout << '\n';
    uart::cout << " * memory map located at 0x";
    uart::cout << bootboot.mmap.ptr;
    uart::cout << '\n';
    uart::cout << " * ACPI ID: " << (u64)acpi::id() << '\n';

    initrd = initrd_init(bootboot);
    uart::cout << " * IHC Initialization... ";
    // ihc_init();
    uart::cout << "Done\n";
}
