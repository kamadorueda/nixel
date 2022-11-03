// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#[test]
fn run() {
    use std::io::Write;

    let should_update = std::env::var("UPDATE").is_ok();

    let test_inputs = "tests/inputs";
    let cases_dir = "tests/cases";

    for path_input in &nix_files(test_inputs) {
        dbg!(&path_input);

        let case = path_input.strip_prefix(test_inputs).unwrap()[1..]
            .replace('/', "-");

        let path_expression = format!("{cases_dir}/{case}.txt");

        let input = std::fs::read_to_string(path_input)
            .unwrap()
            .trim_end_matches('\n')
            .to_string();

        let expression = nixel::parse(input.clone()).expression;
        let expression_str = format!("{expression:#?}")
            .lines()
            .map(re_indent)
            .collect::<Vec<String>>()
            .join("\n");

        #[cfg(not(tarpaulin))]
        if should_update {
            std::fs::File::create(&path_expression)
                .unwrap()
                .write_all(expression_str.as_bytes())
                .unwrap();
        }

        assert_eq!(
            expression_str,
            std::fs::read_to_string(&path_expression).unwrap()
        );
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
        .filter_map(|entry| {
            match entry {
                Ok(entry) => Some(entry),
                Err(_) => None,
            }
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
