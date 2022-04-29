// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use std::io::Read;
use std::rc::Rc;

use clap::ArgGroup;
use nixel::cst::build_concrete_syntax_tree;
use nixel::deps::santiago::lexer::Lexeme;

fn main() -> Result<(), ()> {
    // Get CLI arguments
    let args = cli();

    // Read stdin or the file we want to use
    let input = match get_input(&args) {
        Ok(input) => input,
        Err(error) => return error,
    };

    // Perform lexical analysis
    let lexing_rules = nixel::lexer::lexer_rules();
    let lexemes = match santiago::lexer::lex(&lexing_rules, &input) {
        Ok(lexemes) => lexemes,
        Err(error) => {
            eprintln!("Lexing Error:");
            eprintln!("{error}");
            return Err(());
        },
    };
    let lexeme_no_trivia: Vec<Rc<Lexeme>> = lexemes
        .iter()
        .filter(|lexeme| &lexeme.kind != "COMMENT")
        .filter(|lexeme| &lexeme.kind != "WS")
        .cloned()
        .collect();

    // Print lexical analysis results
    if args.is_present("lex") {
        println!("Lexemes:");
        for lexeme in &lexemes {
            println!("  {lexeme}");
        }
    }

    // Perform parsing of the input
    let grammar = nixel::grammar::grammar();
    let parse_tree = match santiago::parser::parse(&grammar, &lexeme_no_trivia)
    {
        Ok(mut parse_trees) => {
            if parse_trees.len() == 1 {
                parse_trees.swap_remove(0)
            } else {
                eprintln!("Parsing Error:");
                eprintln!("Found more than 1 possible parse tree.");
                return Err(());
            }
        },
        Err(error) => {
            eprintln!("Parsing Error:");
            eprintln!("{error}");
            return Err(());
        },
    };

    // Print parsing results
    if args.is_present("parse") {
        println!("Parse Tree:");
        println!("{parse_tree}");
    }

    // Generate the Abstract Syntax Tree
    let ast = parse_tree.as_abstract_syntax_tree();

    // Print the Abstract Syntax Tree
    if args.is_present("ast") {
        println!("Abstract Syntax Tree:");
        println!("{ast:#?}");
    }

    // Generate the Concrete Syntax Tree
    let cst = build_concrete_syntax_tree(&ast, &lexemes);

    // Print the Concrete Syntax Tree
    if args.is_present("cst") {
        println!("Concrete Syntax Tree:");
        println!("{cst:#?}");
    }

    Ok(())
}

fn get_input(args: &clap::ArgMatches) -> Result<String, Result<(), ()>> {
    Ok(match args.value_of("path") {
        Some(path) => {
            match std::fs::read_to_string(&path) {
                Ok(data) => data,
                Err(error) => {
                    eprintln!("{error:#?}");
                    return Err(Err(()));
                },
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
        },
    })
}

fn cli() -> clap::ArgMatches {
    clap::Command::new("NixEL")
        .about(
            "Lexer, Parser, Abstract Syntax Tree and Concrete Syntax Tree for \
             the Nix Expressions Language",
        )
        .version("4.0.0")
        .arg(
            clap::Arg::new("path")
                .help("File to process, or leave empty to process stdin"),
        )
        .arg(
            clap::Arg::new("lex")
                .help("Print lexical analysis results to stdout")
                .long("lex")
                .required(false)
                .takes_value(false),
        )
        .arg(
            clap::Arg::new("parse")
                .help("Print parsing results to stdout")
                .long("parse")
                .required(false)
                .takes_value(false),
        )
        .arg(
            clap::Arg::new("ast")
                .help("Build and print the Abstract Syntax Tree to stdout")
                .long("ast")
                .required(false)
                .takes_value(false),
        )
        .arg(
            clap::Arg::new("cst")
                .help("Build and print the Concrete Syntax Tree to stdout")
                .long("cst")
                .required(false)
                .takes_value(false),
        )
        .group(
            ArgGroup::new("outputs")
                .args(&["lex", "parse", "ast", "cst"])
                .required(true)
                .multiple(true),
        )
        .term_width(80)
        .get_matches()
}
