<!--
SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>

SPDX-License-Identifier: GPL-3.0-only
-->

<h1 align="center">🐉 NixEL</h2>

<p align="center">Parser for the Nix Expressions Language.</p>

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
  <a href="https://spdx.org/licenses/GPL-3.0-only.html">
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

## Features

- ✔️ **Fast**

  It parses all the files in [Nixpkgs](https://github.com/NixOS/nixpkgs)
  in under 25 seconds, single-threaded.
  [^benchmark-specs]

  It's written in [Rust](https://www.rust-lang.org/)
  and a little bit of [C++](https://isocpp.org/),
  [Flex](https://github.com/westes/flex)
  and [GNU Bison](https://www.gnu.org/software/bison/).

- ✔️ **Correct**

  This library is a copy-paste of the original
  [lexer](https://github.com/NixOS/nix/blob/dd1970c233a82328445b69e903574e14115ee933/src/libexpr/lexer.l)
  and [parser](https://github.com/NixOS/nix/blob/dd1970c233a82328445b69e903574e14115ee933/src/libexpr/parser.y)
  of Nix,
  with some types adapted for better ergonomy.

  No parser can get closer to the original implementation than this.

- ✔️ **Reliable**

  High coverage, battle-tested, and memory-safe[^memory-safe].

- ✔️ **Useful**

  It gives you comments, whitespace, starting and end positions,
  automatic string un-escaping, multiline string indentation handling,
  a typed API,
  and everything you need to parse the Nix language!

## Usage

You can check out the documentation at [docs.rs/nixel](https://docs.rs/nixel).

This is a full usage example:

```rust
let input: String = String::from(
    r#"
        # Greet the user
        "Hello, World!"
        # Bye!
    "#,
);

let parsed: nixel::Parsed = nixel::parse(input);

match &*parsed.expression {
    nixel::Expression::String(string) => {
        assert_eq!(
            &string.span,
            &nixel::Span {
                start: nixel::Position { line: 3, column: 9 }.into(),
                end: nixel::Position { line: 3, column: 24 }.into(),
            }
            .into()
        );
        assert_eq!(
            &parsed.trivia_before(&string.span.start)[1],
            &nixel::Trivia::Comment(nixel::TriviaComment {
                content: "# Greet the user".into(),
                span: nixel::Span {
                    start: nixel::Position { line: 2, column: 9 }.into(),
                    end: nixel::Position { line: 2, column: 25 }.into(),
                }
                .into()
            })
        );
        assert_eq!(
            &string.parts[0],
            &nixel::Part::Raw(nixel::PartRaw {
                content: "Hello, World!".into(),
                span: nixel::Span {
                    start: nixel::Position { line: 3, column: 10 }.into(),
                    end: nixel::Position { line: 3, column: 23 }.into(),
                }
                .into()
            })
        );
        assert_eq!(
            &parsed.trivia_after(&string.span.end)[1],
            &nixel::Trivia::Comment(nixel::TriviaComment {
                content: "# Bye!".into(),
                span: nixel::Span {
                    start: nixel::Position { line: 4, column: 9 }.into(),
                    end: nixel::Position { line: 4, column: 15 }.into(),
                }
                .into()
            })
        );
    },
    expression => unreachable!("Expected a String, got: {expression:#?}"),
}
```

Or from the CLI using Rust's Debug trait:

```sh
$ echo '1 + 2' | nix run github:kamadorueda/nixel -- --format=debug

BinaryOperation(
    BinaryOperation {
        left: Integer(
            Integer {
                value: "1",
                span: Span {
                    start: Position {
                        line: 1,
                        column: 1,
                    },
                    end: Position {
                        line: 1,
                        column: 2,
                    },
                },
            },
        ),
        operator: Addition,
        right: Integer(
            Integer {
                value: "2",
                span: Span {
                    start: Position {
                        line: 1,
                        column: 5,
                    },
                    end: Position {
                        line: 1,
                        column: 6,
                    },
                },
            },
        ),
    },
)
```

Or from the CLI using JSON format:

```sh
$ echo '1 + 2' | nix run github:kamadorueda/nixel -- --format=json

{
  "BinaryOperation": {
    "left": {
      "Integer": {
        "value": "1",
        "span": {
          "start": {
            "line": 1,
            "column": 1
          },
          "end": {
            "line": 1,
            "column": 2
          }
        }
      }
    },
    "operator": "Addition",
    "right": {
      "Integer": {
        "value": "2",
        "span": {
          "start": {
            "line": 1,
            "column": 5
          },
          "end": {
            "line": 1,
            "column": 6
          }
        }
      }
    }
  }
}
```

You can check out more examples
in the [tests](https://github.com/kamadorueda/nixel/tree/main/tests/cases) folder.

## Alternatives

- [rnix-parser](https://github.com/nix-community/rnix-parser).

## License

Please read [LICENSE.md](./LICENSE.md).

## Footnotes

[^benchmark-specs]:
    Running on a [machine](https://github.com/kamadorueda/machine) with:

    - CPU: 4 physical, 4 logical, 11th Gen Intel(R) Core(TM) i7-1165G7 @ 2.80GHz
    - MHz: from 400 to 4700 MHz
    - BogoMips: 5606.40
    - Cache L3: 12 MiB

    The following command takes around 1 minute:

    ```bash
    $ nix build --system x86_64-linux
    $ time find /data/nixpkgs -type f -name '*.nix' \
      -exec ./result/bin/nixel --format=none {} \;

    real  0m24.293s
    user  0m15.066s
    sys   0m8.955s
    ```

[^memory-safe]:
    Tested under real-life workloads using [Valgrind](https://valgrind.org/),
    and by running an infinite loop of parsing cycles over Nixpkgs :).

    ```bash
    $ nix build --system x86_64-linux
    $ valgrind ./result/bin/nixel $file

      LEAK SUMMARY:
        definitely lost: 0 bytes in 0 blocks
        indirectly lost: 0 bytes in 0 blocks
          possibly lost: 0 bytes in 0 blocks
             suppressed: 0 bytes in 0 blocks
    ```
