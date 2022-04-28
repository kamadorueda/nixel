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

<!-- clip tests/inputs/manual/readme.nix -->

```nix
let
  # https://en.wikipedia.org/wiki/John_Doe
  name = "John Doe";
in "Hello, ${name}!"
```

NixEL can generate an Abstract Syntax Tree for you:

<!-- clip tests/cases/manual-readme.nix/asts -->

```rust
---
LetIn {
 bindings: [
  Binding {
   from: AttributePath {
    parts: [
     Raw {
      content: "name",
      position: (3, 3),
     },
    ],
   },
   to: String {
    parts: [
     Raw {
      content: "John Doe",
      position: (3, 11),
     },
    ],
    position: (3, 10),
   },
  },
 ],
 target: String {
  parts: [
   Raw {
    content: "Hello, ",
    position: (4, 5),
   },
   Expression {
    expression: Variable {
     identifier: "name",
     position: (4, 14),
    },
   },
   Raw {
    content: "!",
    position: (4, 19),
   },
  ],
  position: (4, 4),
 },
 position: (1, 1),
}
```

Or generate a Concrete Syntax Tree
preserving comments and metadata:

<!-- clip tests/cases/manual-readme.nix/csts -->

```rust
---
Root {
 trivia_before: [],
 expression: LetIn {
  let_: Lexeme {
   kind: "LET",
   raw: "let",
   position: (1, 1),
  },
  let_trivia: [
   Lexeme {
    kind: "WS",
    raw: "\n  ",
    position: (1, 4),
   },
   Lexeme {
    kind: "COMMENT",
    raw: "# https://en.wikipedia.org/wiki/John_Doe",
    position: (2, 3),
   },
   Lexeme {
    kind: "WS",
    raw: "\n  ",
    position: (2, 43),
   },
  ],
  bindings: [
   Binding {
    binding: Binding {
     from: AttributePath {
      parts: [
       AttributePathPart {
        part: PartRaw {
         lexeme: Lexeme {
          kind: "ID",
          raw: "name",
          position: (3, 3),
         },
        },
        part_trivia: [],
        dot: None,
       },
      ],
     },
     from_trivia: [
      Lexeme {
       kind: "WS",
       raw: " ",
       position: (3, 7),
      },
     ],
     equal: Lexeme {
      kind: "=",
      raw: "=",
      position: (3, 8),
     },
     equal_trivia: [
      Lexeme {
       kind: "WS",
       raw: " ",
       position: (3, 9),
      },
     ],
     to: String {
      open: Lexeme {
       kind: "\"",
       raw: "\"",
       position: (3, 10),
      },
      parts: [
       PartRaw {
        lexeme: Lexeme {
         kind: "STR",
         raw: "John Doe",
         position: (3, 11),
        },
       },
      ],
      close: Lexeme {
       kind: "\"",
       raw: "\"",
       position: (3, 19),
      },
     },
     to_trivia: [],
     semicolon: Lexeme {
      kind: ";",
      raw: ";",
      position: (3, 20),
     },
    },
    binding_trivia: [
     Lexeme {
      kind: "WS",
      raw: "\n",
      position: (3, 21),
     },
    ],
   },
  ],
  in_: Lexeme {
   kind: "IN",
   raw: "in",
   position: (4, 1),
  },
  in_trivia: [
   Lexeme {
    kind: "WS",
    raw: " ",
    position: (4, 3),
   },
  ],
  target: String {
   open: Lexeme {
    kind: "\"",
    raw: "\"",
    position: (4, 4),
   },
   parts: [
    PartRaw {
     lexeme: Lexeme {
      kind: "STR",
      raw: "Hello, ",
      position: (4, 5),
     },
    },
    PartExpressionInterpolation {
     open: Lexeme {
      kind: "DOLLAR_CURLY",
      raw: "${",
      position: (4, 12),
     },
     open_trivia: [],
     expression: Variable {
      lexeme: Lexeme {
       kind: "ID",
       raw: "name",
       position: (4, 14),
      },
     },
     expression_trivia: [],
     close: Lexeme {
      kind: "}",
      raw: "}",
      position: (4, 18),
     },
    },
    PartRaw {
     lexeme: Lexeme {
      kind: "STR",
      raw: "!",
      position: (4, 19),
     },
    },
   ],
   close: Lexeme {
    kind: "\"",
    raw: "\"",
    position: (4, 20),
   },
  },
 },
 trivia_after: [],
}
```

<!-- clip tests/cases/manual-readme.nix/lexemes -->

Or perform Lexical Analysis:

```rust
LET "let" (1, 1)
WS "\n  " (1, 4)
COMMENT "# https://en.wikipedia.org/wiki/John_Doe" (2, 3)
WS "\n  " (2, 43)
ID "name" (3, 3)
WS " " (3, 7)
= "=" (3, 8)
WS " " (3, 9)
" "\"" (3, 10)
STR "John Doe" (3, 11)
" "\"" (3, 19)
; ";" (3, 20)
WS "\n" (3, 21)
IN "in" (4, 1)
WS " " (4, 3)
" "\"" (4, 4)
STR "Hello, " (4, 5)
DOLLAR_CURLY "${" (4, 12)
ID "name" (4, 14)
} "}" (4, 18)
STR "!" (4, 19)
" "\"" (4, 20)
```

<!-- clip tests/cases/manual-readme.nix/parse-tree -->

And produce a Parse Tree:

```rust
---
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
              ID "name" (3, 3)
        = := lexemes "="
          = "=" (3, 8)
        expr := rules "expr_function"
          expr_function := rules "expr_if"
            expr_if := rules "expr_op"
              expr_op := rules "expr_app"
                expr_app := rules "expr_select"
                  expr_select := rules "expr_simple"
                    expr_simple := rules "\"" "string_parts" "\""
                      " := lexemes "\""
                        " "\"" (3, 10)
                      string_parts := rules "STR"
                        STR := lexemes "STR"
                          STR "John Doe" (3, 11)
                      " := lexemes "\""
                        " "\"" (3, 19)
        ; := lexemes ";"
          ; ";" (3, 20)
      IN := lexemes "IN"
        IN "in" (4, 1)
      expr_function := rules "expr_if"
        expr_if := rules "expr_op"
          expr_op := rules "expr_app"
            expr_app := rules "expr_select"
              expr_select := rules "expr_simple"
                expr_simple := rules "\"" "string_parts" "\""
                  " := lexemes "\""
                    " "\"" (4, 4)
                  string_parts := rules "string_parts_interpolated"
                    string_parts_interpolated := rules "string_parts_interpolated" "STR"
                      string_parts_interpolated := rules "STR" "DOLLAR_CURLY" "expr" "}"
                        STR := lexemes "STR"
                          STR "Hello, " (4, 5)
                        DOLLAR_CURLY := lexemes "DOLLAR_CURLY"
                          DOLLAR_CURLY "${" (4, 12)
                        expr := rules "expr_function"
                          expr_function := rules "expr_if"
                            expr_if := rules "expr_op"
                              expr_op := rules "expr_app"
                                expr_app := rules "expr_select"
                                  expr_select := rules "expr_simple"
                                    expr_simple := rules "ID"
                                      ID := lexemes "ID"
                                        ID "name" (4, 14)
                        } := lexemes "}"
                          } "}" (4, 18)
                      STR := lexemes "STR"
                        STR "!" (4, 19)
                  " := lexemes "\""
                    " "\"" (4, 20)
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
