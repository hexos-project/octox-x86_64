#include <types.hh>
#include <acpi.hh>
#include <boot.hh>
#include <uart.hh>
#include <config.hh>
#include <initrd.hh>
#include <ihc.hh>
#include <sysfn.hh>
#include <idt.hh>

extern BOOT::BOOTBOOT bootboot;
extern unsigned char environment[4096];
extern u32 fb;

int main();

nomangle
void _start() {

    main();
    asm volatile (
        "cli\n"
        "hlt\n"
        "jmp .-2\n"
    );
}
