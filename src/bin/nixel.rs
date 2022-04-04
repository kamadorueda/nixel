// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use std::collections::HashSet;
use std::io::Read;

fn main() -> Result<(), ()> {
    let matches = clap::Command::new("NixEL")
        .about(
            "Lexer, Parser, Abstract Syntax Tree and Concrete Syntax Tree for \
             the Nix Expressions Language.",
        )
        .arg(
            clap::Arg::new("path")
                .help("File to process, or leave empty to process stdin."),
        )
        .arg(
            clap::Arg::new("outputs")
                .default_value("ast")
                .help("What to print to stdout.")
                .multiple_values(false)
                .multiple_occurrences(true)
                .possible_values(&["lexemes", "parse-tree", "ast"])
                .short('o')
                .takes_value(true),
        )
        .term_width(80)
        .get_matches();

    let outputs: HashSet<&str> =
        matches.values_of("outputs").unwrap().collect();

    let input = match matches.value_of("path") {
        Some(path) => match std::fs::read_to_string(&path) {
            Ok(data) => data,
            Err(error) => {
                eprintln!("{error:#?}");
                return Err(());
            }
        },
        None => {
            let mut stdin = std::io::stdin();
            let mut data = String::new();
            if let Err(error) = stdin.read_to_string(&mut data) {
                eprintln!("{error:#?}");
                return Err(());
            };
            data
        }
    };

    let lexing_rules = nixel::lexer::lexer_rules();
    let grammar = nixel::grammar::grammar();

    let lexemes = match santiago::lexer::lex(&lexing_rules, &input) {
        Ok(lexemes) => lexemes,
        Err(error) => {
            eprintln!("Lexing Error:");
            eprintln!("{error}");
            return Err(());
        }
    };

    if outputs.contains("lexemes") {
        println!("Lexemes:");
        for lexeme in &lexemes {
            println!("  {lexeme}");
        }
    }

    let parse_tree = match santiago::parser::parse(&grammar, &lexemes) {
        Ok(mut parse_trees) => {
            if parse_trees.len() == 1 {
                parse_trees.swap_remove(0)
            } else {
                eprintln!("Parsing Error:");
                eprintln!("Found more than 1 possible parse tree.");
                return Err(());
            }
        }
        Err(error) => {
            eprintln!("Parsing Error:");
            eprintln!("{error}");
            return Err(());
        }
    };

    if outputs.contains("parse-tree") {
        println!("Parse Tree:");
        println!("{parse_tree}");
    }

    let ast = parse_tree.as_abstract_syntax_tree();

    if outputs.contains("ast") {
        println!("Abstract Syntax Tree:");
        println!("{ast:#?}");
    }

    Ok(())
}
