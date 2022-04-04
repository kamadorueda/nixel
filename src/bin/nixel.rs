// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use std::io::Read;

fn main() -> Result<(), ()> {
    // Get CLI arguments
    let args = cli();

    // Read stdin or the file we want to use
    let input = match get_input(&args) {
        Ok(input) => input,
        Err(error) => return error,
    };

    // HashSet with the names of the outputs we want to print
    let outputs: std::collections::HashSet<&str> =
        args.values_of("outputs").unwrap().collect();

    // Perform lexical analysis
    let lexing_rules = nixel::lexer::lexer_rules();

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

    // Perform parsing of the input
    let grammar = nixel::grammar::grammar();
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

    // Generate the Abstract Syntax Tree
    let ast = parse_tree.as_abstract_syntax_tree();

    if outputs.contains("ast") {
        println!("Abstract Syntax Tree:");
        println!("{ast:#?}");
    }

    Ok(())
}

fn get_input(args: &clap::ArgMatches) -> Result<String, Result<(), ()>> {
    Ok(match args.value_of("path") {
        Some(path) => match std::fs::read_to_string(&path) {
            Ok(data) => data,
            Err(error) => {
                eprintln!("{error:#?}");
                return Err(Err(()));
            }
        },
        None => {
            let mut stdin = std::io::stdin();
            let mut data = String::new();
            if let Err(error) = stdin.read_to_string(&mut data) {
                eprintln!("{error:#?}");
                return Err(Err(()));
            };
            data
        }
    })
}

fn cli() -> clap::ArgMatches {
    clap::Command::new("NixEL")
        .about(
            "Lexer, Parser, Abstract Syntax Tree and Concrete Syntax Tree for \
             the Nix Expressions Language.",
        )
        .version("1.0.1")
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
        .get_matches()
}
