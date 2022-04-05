// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use nixel::ast::AST;

#[test]
fn run() {
    use std::io::Write;

    let should_update = std::env::var("UPDATE").is_ok();
    let lexer_rules = nixel::lexer::lexer_rules();
    let grammar = nixel::grammar::grammar();

    let nixpkgs_dir = "/data/nixpkgs";
    let cases_dir = "tests/cases";

    for path_input in &nix_files(nixpkgs_dir)[0..1000] {
        let case = path_input.strip_prefix(nixpkgs_dir).unwrap()[1..]
            .replace('/', "-");

        std::fs::create_dir_all(format!("{cases_dir}/{case}")).unwrap();

        // let path_lexemes = format!("{cases_dir}/{case}/lexemes");
        // let path_parse_trees = format!("{cases_dir}/{case}/parse_trees");
        let path_asts = format!("{cases_dir}/{case}/asts");

        let input = std::fs::read_to_string(&path_input)
            .unwrap()
            .trim_end_matches('\n')
            .to_string();

        let lexemes = santiago::lexer::lex(&lexer_rules, &input).unwrap();
        // let lexemes_str: String = lexemes
        //     .iter()
        //     .map(|lexeme| lexeme.to_string())
        //     .collect::<Vec<String>>()
        //     .join("\n");

        // #[cfg(not(tarpaulin))]
        // if should_update {
        //     std::fs::File::create(&path_lexemes)
        //         .unwrap()
        //         .write_all(lexemes_str.as_bytes())
        //         .unwrap();
        // }

        let parse_trees = santiago::parser::parse(&grammar, &lexemes).unwrap();
        // let parse_trees_str: String = parse_trees
        //     .iter()
        //     .map(|parse_tree| format!("---\n{parse_tree}"))
        //     .collect::<String>()
        //     .lines()
        //     .collect::<Vec<&str>>()
        //     .join("\n");

        // #[cfg(not(tarpaulin))]
        // if should_update {
        //     std::fs::File::create(&path_parse_trees)
        //         .unwrap()
        //         .write_all(parse_trees_str.as_bytes())
        //         .unwrap();
        // }

        let ast: Vec<AST> = parse_trees
            .iter()
            .map(|parse_tree| parse_tree.as_abstract_syntax_tree())
            .collect();
        let ast_str: String = ast
            .iter()
            .map(|ast| {
                format!("---\n{ast:#?}")
                    .lines()
                    .map(|line| {
                        let indentation =
                            line.find(|char| char != ' ').unwrap_or(0);

                        format!(
                            "{}{}",
                            &line[0..indentation].replace("    ", " "),
                            &line[indentation..]
                        )
                    })
                    .collect::<Vec<String>>()
                    .join("\n")
            })
            .collect::<String>()
            .lines()
            .collect::<Vec<&str>>()
            .join("\n");

        #[cfg(not(tarpaulin))]
        if should_update {
            std::fs::File::create(&path_asts)
                .unwrap()
                .write_all(ast_str.as_bytes())
                .unwrap();
        }

        // assert_eq!(
        //     lexemes_str,
        //     std::fs::read_to_string(&path_lexemes).unwrap()
        // );
        // assert_eq!(
        //     parse_trees_str,
        //     std::fs::read_to_string(&path_parse_trees).unwrap()
        // );
        assert_eq!(ast_str, std::fs::read_to_string(&path_asts).unwrap());
    }
}

fn nix_files(path: &str) -> Vec<String> {
    let mut paths = nix_files_in_path(path);
    paths.sort();
    paths
}

fn nix_files_in_path(path: &str) -> Vec<String> {
    walkdir::WalkDir::new(path)
        .into_iter()
        .filter_entry(is_nix_file_or_dir)
        .filter_map(|entry| match entry {
            Ok(entry) => Some(entry),
            Err(_) => None,
        })
        .filter(is_nix_file)
        .map(to_full_path)
        .collect()
}

fn is_nix_file(entry: &walkdir::DirEntry) -> bool {
    entry.file_type().is_file()
        && entry.file_name().to_str().unwrap().ends_with(".nix")
}

fn is_nix_file_or_dir(entry: &walkdir::DirEntry) -> bool {
    entry.file_type().is_dir() || is_nix_file(entry)
}

fn to_full_path(entry: walkdir::DirEntry) -> String {
    entry.path().to_str().unwrap().to_string()
}
