#include <types.hh>

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
