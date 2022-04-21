<!--
SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>

SPDX-License-Identifier: AGPL-3.0-only
-->

<h1 align="center">🐉 NixEL</h2>

<p align="center">Lexer, Parser, Abstract Syntax Tree and Concrete Syntax Tree for the Nix Expressions Language.</p>

<p align="center">
  <a href="https://buildkite.com/kamadorueda/nixel">
    <img
      alt="CI/CD"
      src="https://badge.buildkite.com/e6a10842c4ea84190bee67360062b18a7e0c548f66ed0886a6.svg?branch=main"
    >
    </img>
  </a>
  <a href="https://docs.rs/nixel">
    <img
      alt="Documentation"
      src="https://img.shields.io/docsrs/nixel?color=brightgreen"
    >
    </img>
  </a>
  <a href="https://coveralls.io/github/kamadorueda/nixel?branch=main">
    <img
      alt="Coverage"
      src="https://coveralls.io/repos/github/kamadorueda/nixel/badge.svg?branch=main"
    >
    </img>
  </a>
  <a href="https://crates.io/crates/nixel">
    <img
      alt="Version"
      src="https://img.shields.io/crates/v/nixel?color=brightgreen"
    >
    </img>
  </a>
  <a href="https://spdx.org/licenses/AGPL-3.0-only.html">
    <img
      alt="License"
      src="https://img.shields.io/crates/l/nixel?color=brightgreen"
    >
    </img>
  </a>
  <!-- <a href="https://crates.io/crates/santiago">
    <img
      alt="Downloads"
      src="https://img.shields.io/crates/d/santiago"
    >
    </img>
  </a> -->

</p>

NixEl is a Rust library that turns
[Nix](https://nixos.org) code
into a variety of correct, typed, memory-safe data-structures.

It's based on the original
[lexer](https://github.com/NixOS/nix/blob/a4a1de69dcc3c6e0c40a093d67b5f20568a5f31e/src/libexpr/lexer.l)
and [parser](https://github.com/NixOS/nix/blob/a4a1de69dcc3c6e0c40a093d67b5f20568a5f31e/src/libexpr/parser.y)
of Nix,
using the same algorithms and methods,
which means guaranteed correctness.
Additionally,
it's been tested against every file
in [Nixpkgs](https://github.com/nixos/nixpkgs),
and also continuously on our infrastructure.

It also provides a command line application
called `$ nixel` which calls the library
and pretty-prints the results.

For example, given some code:

```nix
let
  greeting = "Hello World!";
in
  greeting
```

NixEL can generate an Abstract Syntax Tree for you:

```rust
LetIn {
    bindings: [
        KeyValue(
            AttributePath {
                attributes: [
                    Raw {
                        content: "greeting",
                        position: (2, 3),
                    },
                ],
            },
            String {
                parts: [
                    Raw {
                        content: "Hello World!",
                    },
                ],
                position: (2, 14),
            },
        ),
    ],
    target: Variable {
        identifier: "greeting",
        position: (4, 3),
    },
    position: (1, 1),
}
```

Or perform Lexical Analysis:

```rust
LET "let" (1, 1)
ID "greeting" (2, 3)
= "=" (2, 12)
" "\"" (2, 14)
STR "Hello World!" (2, 15)
" "\"" (2, 27)
; ";" (2, 28)
IN "in" (3, 1)
ID "greeting" (4, 3)
```

And produce a Parse Tree:

```rust
Γ := rules "expr"
  expr := rules "expr_function"
    expr_function := rules "LET" "binds" "IN" "expr_function"
      LET := lexemes "LET"
        LET "let" (1, 1)
      binds := rules "binds" "attrpath" "=" "expr" ";"
        binds := rules
        attrpath := rules "attr"
          attr := rules "ID"
            ID := lexemes "ID"
              ID "greeting" (2, 3)
        = := lexemes "="
          = "=" (2, 12)
        expr := rules "expr_function"
          expr_function := rules "expr_if"
            expr_if := rules "expr_op"
              expr_op := rules "expr_app"
                expr_app := rules "expr_select"
                  expr_select := rules "expr_simple"
                    expr_simple := rules "\"" "string_parts" "\""
                      " := lexemes "\""
                        " "\"" (2, 14)
                      string_parts := rules "STR"
                        STR := lexemes "STR"
                          STR "Hello World!" (2, 15)
                      " := lexemes "\""
                        " "\"" (2, 27)
        ; := lexemes ";"
          ; ";" (2, 28)
      IN := lexemes "IN"
        IN "in" (3, 1)
      expr_function := rules "expr_if"
        expr_if := rules "expr_op"
          expr_op := rules "expr_app"
            expr_app := rules "expr_select"
              expr_select := rules "expr_simple"
                expr_simple := rules "ID"
                  ID := lexemes "ID"
                    ID "greeting" (4, 3)
```

This library is based on [Santiago](https://github.com/kamadorueda/santiago)
and can be used to implement tools like
[Code Formatters](https://github.com/kamadorueda/alejandra),
documentation generators,
and even alternative evaluators of the Nix expression language.

You can checkout more examples
in the [tests](https://github.com/kamadorueda/nixel/tree/main/tests/cases) folder.

We hope you find NixEL useful!

And don’t forget to give us a star ⭐
