// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

//! NixEl is a Rust library that turns
//! [Nix](https://nixos.org) code
//! into a correct, typed data-structured.
//!
//! It's based on the original
//! [lexer](https://github.com/NixOS/nix/blob/a4a1de69dcc3c6e0c40a093d67b5f20568a5f31e/src/libexpr/lexer.l)
//! and [parser](https://github.com/NixOS/nix/blob/a4a1de69dcc3c6e0c40a093d67b5f20568a5f31e/src/libexpr/parser.y)
//! of Nix,
//! using the same algorithms and methods,
//! which means guaranteed correctness.
//! Additionally,
//! it's been tested against every file
//! in [Nixpkgs](https://github.com/nixos/nixpkgs),
//! and also continuously on our infrastructure.
//!
//! It also provides a command line application
//! called `$ nixel` which calls the library
//! and pretty-prints the results.
//!
//! Below you'll find a full usage example:
//! ```no_run
#![doc = include_str!("./bin/nixel.rs")]
//! ```
pub mod ast;
pub mod grammar;
pub mod lexer;
