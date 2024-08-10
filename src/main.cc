#include <types.h>
#include <uart.h>
#include <acpi.h>
#include <idt.h>
#include <irq.h>
#include <bootboot.h>
#include <config.h>
#include <initrd.h>
#include <ihc.h>

extern BOOTBOOT bootboot;

nomangle
void cxx_main() {
    uart::cout << "\n * Octox v" MMP "+rev" MLS " (build " __DATE__ " " __TIME__ ")\n";
    uart::cout << '\n';
    uart::cout << " * INITRD located at " << bootboot.initrd_ptr << '\n';
    uart::cout << " * memory map located at " << (u64)&bootboot.mmap.ptr << '\n';
    uart::cout << " * ACPI ID (must be zero): " << (u8)acpi::id() << '\n';
    uart::cout << " * ACPI CPU count: " << (u8)ACPI_CpuCount << '\n';

    uart::cout << " * INITRD Initialization... ";
    initrd::init(bootboot);
    uart::cout << "Done\n";
    uart::cout << " * IHC Initialization... ";
    IHC::init();
    uart::cout << "Done\n";
    uart::cout << " * IDT Initialization... ";
    IDT::init();
    uart::cout << "Done\n";
    uart::cout << " * Disabling IRQs... ";
    IRQ::all_off();
    uart::cout << "Done\n";
    uart::cout << " * Setting up IDTR... ";
    IDT::load();
    uart::cout << "Done\n";
}
