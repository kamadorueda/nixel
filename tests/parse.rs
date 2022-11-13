// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#[test]
fn trivia() {
    let parsed = nixel::parse(String::from(
        r#"
            # a
            [
                # b
                c
                # d
            ]
            # e
        "#,
    ));

    match &*parsed.expression {
        nixel::Expression::List(list) => {
            assert_eq!(parsed.trivia_before(&list.span.start), &[
                nixel::Trivia::Whitespace(nixel::TriviaWhitespace {
                    content: "\n            ".into(),
                    span: Box::new(nixel::Span {
                        start: Box::new(nixel::Position { line: 1, column: 1 }),
                        end: Box::new(nixel::Position { line: 2, column: 13 })
                    })
                }),
                nixel::Trivia::Comment(nixel::TriviaComment {
                    content: "# a".into(),
                    span: Box::new(nixel::Span {
                        start: Box::new(nixel::Position {
                            line: 2,
                            column: 13
                        }),
                        end: Box::new(nixel::Position { line: 2, column: 16 })
                    })
                }),
                nixel::Trivia::Whitespace(nixel::TriviaWhitespace {
                    content: "\n            ".into(),
                    span: Box::new(nixel::Span {
                        start: Box::new(nixel::Position {
                            line: 2,
                            column: 16
                        }),
                        end: Box::new(nixel::Position { line: 3, column: 13 })
                    })
                })
            ]);
            assert_eq!(parsed.trivia_after(&list.span.end), &[
                nixel::Trivia::Whitespace(nixel::TriviaWhitespace {
                    content: "\n            ".into(),
                    span: Box::new(nixel::Span {
                        start: Box::new(nixel::Position {
                            line: 7,
                            column: 14
                        }),
                        end: Box::new(nixel::Position { line: 8, column: 13 })
                    })
                }),
                nixel::Trivia::Comment(nixel::TriviaComment {
                    content: "# e".into(),
                    span: Box::new(nixel::Span {
                        start: Box::new(nixel::Position {
                            line: 8,
                            column: 13
                        }),
                        end: Box::new(nixel::Position { line: 8, column: 16 })
                    })
                }),
                nixel::Trivia::Whitespace(nixel::TriviaWhitespace {
                    content: "\n        ".into(),
                    span: Box::new(nixel::Span {
                        start: Box::new(nixel::Position {
                            line: 8,
                            column: 16
                        }),
                        end: Box::new(nixel::Position { line: 9, column: 9 })
                    })
                }),
            ]);
        },
        _ => unreachable!(),
    }
}
