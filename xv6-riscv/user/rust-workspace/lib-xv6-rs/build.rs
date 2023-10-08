fn main() {
    println!("cargo:rustc-link-search=native=/home/hyperb0rean/Documents/itmo_os/xv6-riscv/user");
    println!("cargo:warning=BUILD.rs");
    println!("cargo:rustc-link-arg=-z max-page-size=4096");
}