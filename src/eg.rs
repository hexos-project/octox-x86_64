#![no_std]
#[panic_handler]fn panic(_:&::core::panic::PanicInfo)->!{loop{}}

extern {
    fn uart_puts(s: *const u8);
}

#[no_mangle]
pub extern "C"
fn rs_main() -> () {
    unsafe {
        uart_puts(b"\n * Hello from Rust!\n\0" as *const u8);
    }
    return ();
}
