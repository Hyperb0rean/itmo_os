#![no_main]
#![no_std]

extern crate alloc;

use alloc::format;
use alloc::string::String;
use lib_xv6_rs::*;
use std_fd::STDOUT;

#[no_mangle]
pub extern "C" fn main() {
    let str = "Hello my Cargo friend\n";
    let str_owned = format!("This is owning string and format {}\n", 3);

    write(STDOUT, str.as_bytes());
    write(STDOUT, str_owned.as_bytes());

    exit(0);
}