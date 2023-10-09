#![no_main]
#![no_std]

extern crate alloc;

use alloc::format;
use alloc::string::String;
use lib_xv6_rs::*;
use std_fd::STDOUT;
use std_fd::STDIN;
use crate::FileDescriptor;
use std_fd::STDERR;

#[no_mangle]
pub extern "C" fn main() {  
    let mut p: &mut [i32; 2] = &mut [-1; 2];
    pipe(p);

    let pid: i32 = fork();
    let mut buffer: &mut [u8; 5] = &mut [0 as u8; 5];
    if pid == 0 {
        read(FileDescriptor{fd: p[0]}, buffer, 5);
        write(STDOUT, b"parent: \n");
        write(FileDescriptor{fd: p[1]}, b"pong\0");
    } else if pid > 0 {
        write(FileDescriptor{fd :p[1]}, b"ping\0");
        read(FileDescriptor{fd: p[0]}, buffer, 5);
        write(STDOUT, b"child: \n");
    }

    exit(0);
}