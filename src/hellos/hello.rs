#![no_std]

#[panic_handler]
fn panic(_:&::core::panic::PanicInfo) -> ! {
    unsafe {
        uart_puts(b"\n * Panic!\n\0" as *const u8);
    }
    loop {}
}

extern {
    fn uart_puts(s: *const u8);
}

#[no_mangle]
pub extern "C"
fn rs_hello() -> () {
    unsafe {
        uart_puts(b" * Hello from Rust!\n\0" as *const u8);
    }
    return ();
}
