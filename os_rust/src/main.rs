#![no_std]
#![no_main]

fn main() {
    cc::Build::new()
        .file("src/foo.c")
        .compile("foo");
}

#[panic_handler]
fn my_panic(_info: &core::panic::PanicInfo) -> ! {
    loop {}
}
