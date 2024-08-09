#![no_std]
#[panic_handler]fn panic(_:&::core::panic::PanicInfo)->!{loop{}}
#[no_mangle] pub unsafe extern "C"
fn suma (a: i32, b: i32) -> i32
{
    a + b
}

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
