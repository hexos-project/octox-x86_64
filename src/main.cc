#include <types.h>
#include <uart.h>
#include <acpi.h>
#include <idt.h>
#include <irq.h>
#include <bootboot.h>
#include <config.h>
#include <initrd.h>
#include <ihc.h>
#include <pit.h>
#include <clock.h>

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

    uart::cout << " * PIT Initialization, 1 MHz... ";
    PIT::init(1000000);
    uart::cout << "Done\n";

    uart::cout << " * Disabling IRQs... ";
    IRQ::all_off();
    uart::cout << "Done\n";

    uart::cout << " * Enabling interrupts:\n";

    uart::cout << "   * INT 0x23 IRQ clock\n";
    IHC::set_handler(0x23, clock_ihc_handler);
    IRQ::on(0x20);
    IRQ::on(0x21);
    IRQ::on(0x22);
    IRQ::on(0x24);
    IRQ::on(0x25);
    IRQ::on(0x26);
    IRQ::on(0x27);
    IRQ::on(0x28);
    IRQ::on(0x29);
    IRQ::on(0x2A);
    IRQ::on(0x2B);
    IRQ::on(0x2C);
    IRQ::on(0x2D);
    IRQ::on(0x2E);
    IRQ::on(0x2F);

    uart::cout << " * Loading IDT... ";
    IDT::load();
    uart::cout << "Done\n";
}
