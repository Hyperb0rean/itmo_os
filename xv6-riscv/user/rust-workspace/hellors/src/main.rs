#![no_main]
#![no_std]

extern crate alloc;

use alloc::format;
use alloc::string::String;
use lib_xv6_rs::*;
use std_fd::STDOUT;

#[no_mangle]
pub extern "C" fn main() {
    let str = "Hello World! It's Rust and Cargo!\n";

    write(STDOUT, str.as_bytes());

    exit(0);
}