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
#include <sysfn.h>

extern BOOTBOOT bootboot;

nomangle
void cxx_main() {
    uart::cout << "\n * Octox v" MMP "+rev" MLS " (build " __DATE__ " " __TIME__ ")\n";
    uart::cout << '\n';
    uart::cout << " * INITRD located at " << bootboot.initrd_ptr << '\n';
    uart::cout << " * memory map located at " << (u64)&bootboot.mmap.ptr << '\n';
    uart::cout << " * ACPI ID (must be zero): " << (u8)acpi::id() << '\n';
    uart::cout << " * ACPI CPU count: " << (u8)ACPI_CpuCount << '\n';
    uart::cout << " * CS Value: " << (u64)get_cs() << '\n';

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
    PIT::init(100);
    uart::cout << "Done\n";

    uart::cout << " * Disabling IRQs... ";
    IRQ::all_off();
    uart::cout << "Done\n";

    uart::cout << " * Enabling interrupts:\n";

    uart::cout << "   * INT 0x23 IRQ clock\n";
    IHC::set_handler(0x23, clock_ihc_handler);
    uart::cout << "   * INT 0x80 Syscall\n";
    IHC::set_handler(0x80, sysfn_ihc_handler);

    uart::cout << " * Loading IDT... ";
    IDT::load();
    uart::cout << "Done\n";

    uart::cout << " * Testing syscall OS::COM::SERIAL::PUTS... ";
    _syscall(COMP_COM_SERIAL_UART_PUTS, (u64)"Hello, world!\n", 0, 0, 0);
    uart::cout << "Done\n";

    uart::cout << " * Testing syscall OS::SYSFN::BLOCK... ";
    _syscall(COMP_SYSFN_BLOCK, 0, 0, 0, 0);
    uart::cout << "Done\n";

    uart::cout << " * Testing syscall block... ";
    _syscall(COMP_COM_SERIAL_UART_PUTS, (u64)"Hello, world!\n", 0, 0, 0);
    uart::cout << "Done\n";
}
