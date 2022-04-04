use nixel::expression::AST;

#[test]
fn run() {
    use std::io::Write;
    let should_update = std::env::var("UPDATE").is_ok();

    let cases_dir = format!("tests/cases");

    let cases: Vec<String> = std::fs::read_dir(&cases_dir)
        .unwrap()
        .map(|entry| entry.unwrap().file_name().into_string().unwrap())
        .collect();

    let lexer_rules = nixel::lexer::lexer_rules();
    let grammar = nixel::grammar::grammar();

    for case in cases {
        println!("{cases_dir}/{case}");
        let path_input = format!("{cases_dir}/{case}/input");
        let path_lexemes = format!("{cases_dir}/{case}/lexemes");
        let path_parse_trees = format!("{cases_dir}/{case}/parse_trees");
        let path_asts = format!("{cases_dir}/{case}/asts");

        let input = std::fs::read_to_string(&path_input)
            .unwrap()
            .trim_end_matches('\n')
            .to_string();

        let lexemes = santiago::lexer::lex(&lexer_rules, &input).unwrap();
        let lexemes_str: String = lexemes
            .iter()
            .map(|lexeme| lexeme.to_string())
            .collect::<Vec<String>>()
            .join("\n");

        #[cfg(not(tarpaulin))]
        if should_update {
            std::fs::File::create(&path_lexemes)
                .unwrap()
                .write_all(lexemes_str.as_bytes())
                .unwrap();
        }

        let parse_trees = santiago::parser::parse(&grammar, &lexemes).unwrap();
        let parse_trees_str: String = parse_trees
            .iter()
            .map(|parse_tree| format!("---\n{parse_tree}"))
            .collect::<String>()
            .lines()
            .collect::<Vec<&str>>()
            .join("\n");

        #[cfg(not(tarpaulin))]
        if should_update {
            std::fs::File::create(&path_parse_trees)
                .unwrap()
                .write_all(parse_trees_str.as_bytes())
                .unwrap();
        }

        let ast: Vec<AST> = parse_trees
            .iter()
            .map(|parse_tree| parse_tree.as_abstract_syntax_tree())
            .collect();
        let ast_str: String = ast
            .iter()
            .map(|ast| format!("---\n{ast:#?}"))
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

        assert_eq!(
            lexemes_str,
            std::fs::read_to_string(&path_lexemes).unwrap()
        );
        assert_eq!(
            parse_trees_str,
            std::fs::read_to_string(&path_parse_trees).unwrap()
        );
        assert_eq!(ast_str, std::fs::read_to_string(&path_asts).unwrap());
    }
}
