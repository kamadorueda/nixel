// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

fn main() -> Result<(), Box<dyn std::error::Error>> {
    for path in [
        "src/lexer",
        "src/parser",
        "src/types.hh",
        "src/utils.cc",
        "src/utils.hh",
        "src/vendored",
    ] {
        println!("cargo:rerun-if-changed={path}");
    }

    let out = std::path::PathBuf::from(std::env::var("OUT_DIR")?);

    bindgen::Builder::default()
        .derive_copy(false)
        .derive_debug(false)
        .derive_default(false)
        .derive_eq(false)
        .derive_hash(false)
        .derive_ord(false)
        .derive_partialeq(false)
        .derive_partialord(false)
        .header("src/types.hh")
        .generate()
        .expect("Unable to generate bindings")
        .write_to_file(out.join("ffi.rs"))?;

    cc::Build::new()
        .include("src")
        .file("src/vendored/lexer.cc")
        .file("src/vendored/parser.cc")
        .file("src/utils.cc")
        .warnings(false)
        .compile("something");

    println!("cargo:rustc-link-lib=static=something");
    println!("cargo:rustc-link-lib=stdc++");
    println!("cargo:rustc-link-arg=-lc");
    println!("cargo:rustc-link-arg=-lstdc++");

    Ok(())
}
