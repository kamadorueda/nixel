// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use std::io::Read;
use std::process::exit;

fn main() {
    let args = clap::Command::new("NixEL")
        .about("The Nix Expressions Language Parser")
        .version("5.0.1")
        .arg(
            clap::Arg::new("path")
                .help("File to parse, or leave empty to parse stdin")
                .required(false),
        )
        .arg(
            clap::Arg::new("format")
                .help("What format to print the AST in")
                .long("format")
                .value_parser(["json", "debug", "none"])
                .default_value("json")
                .required(false),
        )
        .term_width(80)
        .get_matches();

    let source = match args.get_one::<String>("path") {
        Some(path) => path,
        None => "<stdin>",
    };
    let input = match args.get_one::<String>("path") {
        Some(path) => {
            match std::fs::read_to_string(path) {
                Ok(input) => input,
                Err(error) => {
                    eprintln!("In {source:?}: {error:#?}");
                    exit(1);
                },
            }
        },
        None => {
            let mut input = String::new();
            match std::io::stdin().read_to_string(&mut input) {
                Ok(_) => input,
                Err(error) => {
                    eprintln!("In {source:?}: {error:#?}");
                    exit(1);
                },
            }
        },
    };

    let parsed = nixel::parse(input);

    match args.get_one::<String>("format").unwrap().as_str() {
        "debug" => {
            println!("{parsed:#?}");
        },
        "json" => {
            match serde_json::to_string_pretty(&parsed) {
                Ok(json) => {
                    println!("{json}");
                },
                Err(error) => {
                    eprintln!("In {source:?}: {error:#?}");
                    exit(1);
                },
            }
        },
        _ => {},
    }
}
