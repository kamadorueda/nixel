// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use std::rc::Rc;

use nixel::ast::AST;
use nixel::cst::build_concrete_syntax_tree;
use nixel::cst::CST;
use santiago::lexer::Lexeme;

#[test]
fn run() {
    use std::io::Write;

    let should_update = std::env::var("UPDATE").is_ok();
    let lexer_rules = nixel::lexer::lexer_rules();
    let grammar = nixel::grammar::grammar();

    let test_inputs = "tests/inputs";
    let cases_dir = "tests/cases";

    for path_input in &nix_files(test_inputs)[0..1000] {
        dbg!(&path_input);

        let case = path_input.strip_prefix(test_inputs).unwrap()[1..]
            .replace('/', "-");

        std::fs::create_dir_all(format!("{cases_dir}/{case}")).unwrap();

        let path_lexemes = format!("{cases_dir}/{case}/lexemes");
        let path_parse_tree = format!("{cases_dir}/{case}/parse-tree");
        let path_asts = format!("{cases_dir}/{case}/asts");
        let path_csts = format!("{cases_dir}/{case}/csts");

        let input = std::fs::read_to_string(&path_input)
            .unwrap()
            .trim_end_matches('\n')
            .to_string();

        let lexemes = santiago::lexer::lex(&lexer_rules, &input).unwrap();
        let lexeme_no_trivia: Vec<Rc<Lexeme>> = lexemes
            .iter()
            .filter(|lexeme| &lexeme.kind != "COMMENT")
            .filter(|lexeme| &lexeme.kind != "WS")
            .cloned()
            .collect();
        let lexemes_str: String =
            lexemes.iter().map(|lexeme| format!("{lexeme}\n")).collect();

        if case.starts_with("manual-") {
            std::fs::File::create(&path_lexemes)
                .unwrap()
                .write_all(lexemes_str.as_bytes())
                .unwrap();
        }

        let parse_trees =
            santiago::parser::parse(&grammar, &lexeme_no_trivia).unwrap();
        let parse_trees_str: String = parse_trees
            .iter()
            .map(|parse_trees| format!("---\n{parse_trees}"))
            .collect();

        if case.starts_with("manual-") {
            std::fs::File::create(&path_parse_tree)
                .unwrap()
                .write_all(parse_trees_str.as_bytes())
                .unwrap();
        }

        let asts: Vec<AST> = parse_trees
            .iter()
            .map(|parse_tree| parse_tree.as_abstract_syntax_tree())
            .collect();
        let asts_str: String = asts
            .iter()
            .map(|ast| {
                format!("---\n{ast:#?}")
                    .lines()
                    .map(re_indent)
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
                .write_all(asts_str.as_bytes())
                .unwrap();
        }

        let csts: Vec<CST> = asts
            .iter()
            .map(|ast| build_concrete_syntax_tree(ast, &lexemes))
            .collect();
        let csts_str: String = csts
            .iter()
            .map(|cst| {
                format!("---\n{cst:#?}")
                    .lines()
                    .map(re_indent)
                    .collect::<Vec<String>>()
                    .join("\n")
            })
            .collect::<String>()
            .lines()
            .collect::<Vec<&str>>()
            .join("\n");

        if case.starts_with("manual-") {
            std::fs::File::create(&path_csts)
                .unwrap()
                .write_all(csts_str.as_bytes())
                .unwrap();
        }

        if case.starts_with("manual-") {
            assert_eq!(
                lexemes_str,
                std::fs::read_to_string(&path_lexemes).unwrap()
            );
            assert_eq!(
                parse_trees_str,
                std::fs::read_to_string(&path_parse_tree).unwrap()
            );
        }
        assert_eq!(asts_str, std::fs::read_to_string(&path_asts).unwrap());
        if case.starts_with("manual-") {
            assert_eq!(csts_str, std::fs::read_to_string(&path_csts).unwrap());
        }
    }
}

fn re_indent(line: &str) -> String {
    let indentation = line.find(|char| char != ' ').unwrap_or(0);

    format!(
        "{}{}",
        &line[0..indentation].replace("    ", " "),
        &line[indentation..]
    )
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
