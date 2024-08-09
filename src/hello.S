.text

.extern uart_puts
.global gas_hello
gas_hello:
    leaq message(%rip), %rdi
    call uart_puts
    ret

.data
message:
    .ascii "Hello from gas!\n"
