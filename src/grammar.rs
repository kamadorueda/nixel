// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

//! Grammar of the Nix expressions language.

use std::collections::LinkedList;

use santiago::grammar::Associativity;
use santiago::grammar::Grammar;
use santiago::lexer::Position;

use crate::ast::AttributePath;
use crate::ast::BinaryOperator;
use crate::ast::Binding;
use crate::ast::DestructuredArgument;
use crate::ast::DestructuredArguments;
use crate::ast::DestructuredIdentifier;
use crate::ast::FunctionArgument;
use crate::ast::Part;
use crate::ast::UnaryOperator;
use crate::ast::AST;

pub fn grammar() -> Grammar<AST> {
    santiago::grammar!(
        "expr" => rules "expr_function";

        "expr_function" => rules "ID" ":" "expr_function"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::Function {
                    argument: FunctionArgument::Simple {
                        identifier: lexeme.raw.clone(),
                    },
                    definition: Box::new(asts.swap_remove(0)),
                    position: lexeme.position.clone(),
                },
                _ => unreachable!(),
            };
        "expr_function" => rules "{" "formals" "}" ":" "expr_function"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::Function {
                    argument: {
                        let formals = match asts.swap_remove(1) {
                            AST::__DestructuredArguments(formals) => formals,
                            _ => unreachable!(),
                        };

                        FunctionArgument::Destructured {
                            identifier: DestructuredIdentifier::None,
                            arguments: formals.arguments,
                            ellipsis: formals.ellipsis,
                        }
                    },
                    definition: Box::new(asts.swap_remove(0)),
                    position: lexeme.position.clone(),
                },
                _ => unreachable!(),
            };
        "expr_function" => rules "{" "formals" "}" "@" "ID" ":" "expr_function"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::Function {
                    argument: {
                        let formals = match asts.swap_remove(1) {
                            AST::__DestructuredArguments(formals) => formals,
                            _ => unreachable!(),
                        };
                        let identifier = match asts.swap_remove(4) {
                            AST::__Lexeme(lexeme) => DestructuredIdentifier::RightAt(
                                lexeme.raw.clone()
                            ),
                            _ => unreachable!(),
                        };

                        FunctionArgument::Destructured {
                            identifier,
                            arguments: formals.arguments,
                            ellipsis: formals.ellipsis,
                        }
                    },
                    definition: Box::new(asts.swap_remove(0)),
                    position: lexeme.position.clone(),
                },
                _ => unreachable!(),
            };
        "expr_function" => rules "ID" "@" "{" "formals" "}" ":" "expr_function"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::Function {
                    argument: {
                        let formals = match asts.swap_remove(3) {
                            AST::__DestructuredArguments(formals) => formals,
                            _ => unreachable!(),
                        };
                        let identifier = DestructuredIdentifier::LeftAt(
                            lexeme.raw.clone()
                        );

                        FunctionArgument::Destructured {
                            identifier,
                            arguments: formals.arguments,
                            ellipsis: formals.ellipsis,
                        }
                    },
                    definition: Box::new(asts.swap_remove(0)),
                    position: lexeme.position.clone(),
                },
                _ => unreachable!(),
            };
        "expr_function" => rules "ASSERT" "expr" ";" "expr_function"
            => |mut asts| AST::Assert {
                expression: Box::new(asts.swap_remove(1)),
                target: Box::new(asts.swap_remove(1)),
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_function" => rules "WITH" "expr" ";" "expr_function"
            => |mut asts| AST::With {
                expression: Box::new(asts.swap_remove(1)),
                target: Box::new(asts.swap_remove(1)),
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_function" => rules "LET" "binds" "IN" "expr_function"
            => |mut asts| {
                let binds = asts.swap_remove(1);

                AST::LetIn {
                    bindings: match binds {
                        AST::__Bindings(bindings) => bindings,
                        _ => unreachable!(),
                    },
                    target: Box::new(asts.swap_remove(1)),
                    position: match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => lexeme.position.clone(),
                        _ => unreachable!(),
                    },
                }
            };
        "expr_function" => rules "expr_if";

        "expr_if" => rules "IF" "expr" "THEN" "expr" "ELSE" "expr"
            => |mut asts| AST::IfThenElse {
                predicate: Box::new(asts.swap_remove(1)),
                then: Box::new(asts.swap_remove(3)),
                else_: Box::new(asts.swap_remove(1)),
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_if" => rules "expr_op";

        "expr_op" => rules "NOT" "expr_op"
            => |mut asts| AST::UnaryOperation {
                operator: UnaryOperator::Not,
                operand: Box::new(asts.swap_remove(1)),
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "NEGATE" "expr_op"
            => |mut asts| AST::UnaryOperation {
                operator: UnaryOperator::Negate,
                operand: Box::new(asts.swap_remove(1)),
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "EQ" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::EqualTo,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "NEQ" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::NotEqualTo,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "<" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::LessThan,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "LEQ" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::LessThanOrEqualTo,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" ">" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::GreaterThan,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "GEQ" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::GreaterThanOrEqualTo,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "AND" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::LogicalAnd,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "OR" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::LogicalOr,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "IMPL" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Implication,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "UPDATE" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Update,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "?" "attrpath"
            => |mut asts| AST::HasProperty {
                expression: Box::new(asts.swap_remove(0)),
                attribute_path: match asts.swap_remove(0) {
                    AST::__AttributePath(attribute_path) => attribute_path,
                    _ => unreachable!(),
                },
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "+" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Addition,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "-" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Subtraction,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "*" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Multiplication,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "/" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Division,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_op" "CONCAT" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Concatenation,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        "expr_op" => rules "expr_app";

        "expr_app" => rules "expr_app" "expr_select"
            => |mut asts| {
                let mut expr_app = asts.swap_remove(0);

                if let AST::FunctionApplication { arguments, .. } = &mut expr_app {
                    arguments.push_back(asts.swap_remove(0));
                    expr_app
                } else {
                    AST::FunctionApplication {
                        function: Box::new(expr_app),
                        arguments: LinkedList::from([asts.swap_remove(0)]),
                    }
                }
            };
        "expr_app" => rules "expr_select";

        "expr_select" => rules "expr_simple" "." "attrpath"
            => |mut asts| AST::PropertyAccess {
                expression: Box::new(asts.swap_remove(0)),
                attribute_path: match asts.swap_remove(0) {
                    AST::__AttributePath(attribute_path) => attribute_path,
                    _ => unreachable!(),
                },
                default: None,
            };
        "expr_select" => rules "expr_simple" "." "attrpath" "OR_KW" "expr_select"
            => |mut asts| AST::PropertyAccess {
                expression: Box::new(asts.swap_remove(0)),
                attribute_path: match asts.swap_remove(2) {
                    AST::__AttributePath(attribute_path) => attribute_path,
                    _ => unreachable!(),
                },
                default: Some(Box::new(asts.swap_remove(0))),
            };
        "expr_select" => rules "expr_simple" "OR_KW"
            => |mut asts| AST::FunctionApplication {
                function: Box::new(asts.swap_remove(0)),
                arguments: LinkedList::from([
                    match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => AST::Variable {
                            identifier: lexeme.raw.clone(),
                            position: lexeme.position.clone(),
                        },
                        _ => unreachable!(),
                    }
                ]),
            };
        "expr_select" => rules "expr_simple";

        "expr_simple" => rules "ID"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => {
                    AST::Variable {
                        identifier: lexeme.raw.clone(),
                        position: lexeme.position.clone(),
                    }
                },
                _ => unreachable!(),
            };
        "expr_simple" => rules "INT"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => {
                    AST::Int {
                        value: match str::parse::<i64>(&lexeme.raw) {
                            Ok(value) => value,
                            Err(_) => {
                                panic!("\n\n\
                                    The maximum supported integer is: 9223372036854775807\n\
                                    But yours is: {}\n\n", &lexeme.raw);
                            },
                        },
                        position: lexeme.position.clone(),
                    }
                },
                _ => unreachable!(),
            };
        "expr_simple" => rules "FLOAT"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => {
                    AST::Float {
                        value: str::parse::<f64>(&lexeme.raw).unwrap(),
                        position: lexeme.position.clone(),
                    }
                },
                _ => unreachable!(),
            };
        "expr_simple" => rules "\"" "string_parts" "\""
            => |mut asts| match asts.swap_remove(1) {
                AST::__Parts(parts) => AST::String {
                    parts,
                    position: match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => lexeme.position.clone(),
                        _ => unreachable!(),
                    },
                },
                _ => unreachable!(),
            };
        "expr_simple" => rules "IND_STRING_OPEN" "ind_string_parts" "IND_STRING_CLOSE"
            => |mut asts| match asts.swap_remove(1) {
                AST::__Parts(parts) => AST::String {
                    parts: strip_indentation(parts),
                    position: match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => lexeme.position.clone(),
                        _ => unreachable!(),
                    },
                },
                _ => unreachable!(),
            };
        "expr_simple" => rules "path_start" "PATH_END"
            =>  |mut asts| asts.swap_remove(0);
        "expr_simple" => rules "path_start" "string_parts_interpolated" "PATH_END"
            => |mut asts| {
                let (
                    mut path_start_parts,
                    path_start_position,
                ) = match asts.swap_remove(0) {
                    AST::Path { parts, position } => (parts, position),
                    _ => unreachable!(),
                };
                let mut string_parts_interpolated = match asts.swap_remove(1) {
                    AST::__Parts(parts) => parts,
                    _ => unreachable!(),
                };

                let mut parts = LinkedList::new();
                parts.append(&mut path_start_parts);
                parts.append(&mut string_parts_interpolated);

                AST::Path { parts, position: path_start_position }
            };
        "expr_simple" => rules "SPATH"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::SearchNixPath {
                    path: lexeme.raw.clone(),
                    position: lexeme.position.clone(),
                },
                _ => unreachable!(),
            };
        "expr_simple" => rules "(" "expr" ")"
            => |mut asts| AST::Parentheses {
                expression: Box::new(asts.swap_remove(1)),
                position: match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.position.clone(),
                    _ => unreachable!(),
                },
            };
        // "expr_simple" => rules "LET" "{" "binds" "}"
        "expr_simple" => rules "REC" "{" "binds" "}"
            => |mut asts| {
                let binds = asts.swap_remove(2);

                AST::Map {
                    bindings: match binds {
                        AST::__Bindings(bindings) => bindings,
                        _ => unreachable!(),
                    },
                    position: match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => lexeme.position.clone(),
                        _ => unreachable!(),
                    },
                    recursive: true,
                }
            };
        "expr_simple" => rules "{" "binds" "}"
            => |mut asts| {
                let binds = asts.swap_remove(1);

                AST::Map {
                    bindings: match binds {
                        AST::__Bindings(bindings) => bindings,
                        _ => unreachable!(),
                    },
                    position: match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => lexeme.position.clone(),
                        _ => unreachable!(),
                    },
                    recursive: false,
                }
            };
        "expr_simple" => rules "[" "expr_list" "]"
            => |mut asts| {
                let mut expr_list = asts.swap_remove(1);

                match &mut expr_list {
                    AST::List { position, .. } => {
                        *position = match asts.swap_remove(0) {
                            AST::__Lexeme(lexeme) => lexeme.position.clone(),
                            _ => unreachable!(),
                        };
                    },
                    _ => unreachable!(),
                }

                expr_list
            };

        "string_parts" => rules "STR"
            => |mut asts| AST::__Parts(
                LinkedList::from([
                    match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => Part::Raw {
                            content: lexeme.raw.clone(),
                            position: lexeme.position.clone(),
                        },
                        _ => unreachable!(),
                    },
                ]),
            );
        "string_parts" => rules "string_parts_interpolated"
            => |mut asts| asts.swap_remove(0);
        "string_parts" => empty
            => |_| AST::__Parts(LinkedList::new());

        "string_parts_interpolated" => rules "string_parts_interpolated" "STR"
            => |mut asts| {
                let mut string_parts_interpolated = asts.swap_remove(0);

                match &mut string_parts_interpolated {
                    AST::__Parts(parts) => {
                        parts.push_back(match asts.swap_remove(0) {
                            AST::__Lexeme(lexeme) => Part::Raw {
                                content: lexeme.raw.clone(),
                                position: lexeme.position.clone(),
                            },
                            _ => unreachable!(),
                        });
                    }
                    _ => unreachable!(),
                }

                string_parts_interpolated
            };
        "string_parts_interpolated" => rules "string_parts_interpolated" "DOLLAR_CURLY" "expr" "}"
            => |mut asts| {
                let mut string_parts_interpolated = asts.swap_remove(0);

                match &mut string_parts_interpolated {
                    AST::__Parts(parts) => {
                        parts.push_back(Part::Interpolation {
                            expression: Box::new(asts.swap_remove(2)),
                        });
                    }
                    _ => unreachable!(),
                }

                string_parts_interpolated
            };
        "string_parts_interpolated" => rules "DOLLAR_CURLY" "expr" "}"
            => |mut asts| AST::__Parts(LinkedList::from([
                Part::Interpolation {
                    expression: Box::new(asts.swap_remove(1)),
                }
            ]));
        "string_parts_interpolated" => rules "STR" "DOLLAR_CURLY" "expr" "}"
            => |mut asts| AST::__Parts(LinkedList::from([
                match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => Part::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone(),
                    },
                    _ => unreachable!(),
                },
                Part::Interpolation {
                    expression: Box::new(asts.swap_remove(2)),
                },
            ]));

        "path_start" => rules "PATH"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::Path {
                    parts: LinkedList::from([
                        Part::Raw {
                            content: lexeme.raw.clone(),
                            position: lexeme.position.clone(),
                        },
                    ]),
                    position: lexeme.position.clone(),
                },
                _ => unreachable!(),
            };
        "path_start" => rules "HPATH"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::Path {
                    parts: LinkedList::from([
                        Part::Raw {
                            content: lexeme.raw.clone(),
                            position: lexeme.position.clone(),
                        },
                    ]),
                    position: lexeme.position.clone(),
                },
                _ => unreachable!(),
            };

        "ind_string_parts" => rules "ind_string_parts" "IND_STR"
            => |mut asts| {
                let mut ind_string_parts = asts.swap_remove(0);

                match &mut ind_string_parts {
                    AST::__Parts(parts) => match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => {
                            parts.push_back(Part::Raw {
                                content: lexeme.raw.clone(),
                                position: lexeme.position.clone(),
                            });
                        },
                        _ => unreachable!(),
                    }
                    _ => unreachable!(),
                }
                ind_string_parts
            };
        "ind_string_parts" => rules "ind_string_parts" "DOLLAR_CURLY" "expr" "}"
            => |mut asts| {
                let mut ind_string_parts = asts.swap_remove(0);

                match &mut ind_string_parts {
                    AST::__Parts(parts) => {
                        parts.push_back(Part::Interpolation {
                            expression: Box::new(asts.swap_remove(2)),
                        });
                    }
                    _ => unreachable!(),
                }
                ind_string_parts
            };
        "ind_string_parts" => empty
            => |_| AST::__Parts(LinkedList::new());

        "binds" => rules "binds" "attrpath" "=" "expr" ";"
            => |mut asts| {
                let mut binds = asts.swap_remove(0);

                match &mut binds {
                    AST::__Bindings(bindings) => {
                        bindings.push_back(Binding::Binding {
                            from: match asts.swap_remove(1) {
                                AST::__AttributePath(attribute_path) => attribute_path,
                                _ => unreachable!(),
                            },
                            to: Box::new(asts.swap_remove(1)),
                        });
                    },
                    _ => unreachable!(),
                }

                binds
            };
        "binds" => rules "binds" "INHERIT" "attrs" ";"
            => |mut asts| {
                let mut binds = asts.swap_remove(0);

                match &mut binds {
                    AST::__Bindings(bindings) => {
                        match asts.swap_remove(2) {
                            AST::__Attributes(attributes) => {
                                bindings.push_back(Binding::Inherit {
                                    from: None,
                                    attributes,
                                });
                            },
                            _ => unreachable!(),
                        }
                    },
                    _ => unreachable!(),
                };

                binds
            };
        "binds" => rules "binds" "INHERIT" "(" "expr" ")" "attrs" ";"
            => |mut asts| {
                let mut binds = asts.swap_remove(0);

                match &mut binds {
                    AST::__Bindings(bindings) => {
                        match asts.swap_remove(5) {
                            AST::__Attributes(attributes) => {
                                bindings.push_back(Binding::Inherit {
                                    from: Some(Box::new(asts.swap_remove(3))),
                                    attributes,
                                });
                            },
                            _ => unreachable!(),
                        }
                    },
                    _ => unreachable!(),
                };

                binds
            };
        "binds" => empty
            => |_| AST::__Bindings(LinkedList::new());

        "attrs" => rules "attrs" "attr"
            => |mut asts| {
                let mut attrs = asts.swap_remove(0);

                match &mut attrs {
                    AST::__Attributes(attributes) => {
                        attributes.push_back(match asts.swap_remove(0) {
                            AST::__Part(attribute) => attribute,
                            _ => unreachable!(),
                        });
                    },
                    _ => unreachable!(),
                }

                attrs
            };
        "attrs" => rules "attrs" "string_attr"
            => |mut asts| {
                let mut attrs = asts.swap_remove(0);

                match &mut attrs {
                    AST::__Attributes(attributes) => {
                        attributes.push_back(match asts.swap_remove(0) {
                            AST::__Part(attribute) => attribute,
                            _ => unreachable!(),
                        });
                    },
                    _ => unreachable!(),
                }

                attrs
            };
        "attrs" => empty
            => |_| AST::__Attributes(LinkedList::new());

        "attrpath" => rules "attrpath" "." "attr"
            => |mut asts| {
                let mut attrpath = asts.swap_remove(0);

                match &mut attrpath {
                    AST::__AttributePath(attribute_path) => {
                        attribute_path.parts.push_back(
                            match asts.swap_remove(0) {
                                AST::__Part(attribute) => attribute,
                                _ => unreachable!(),
                            },
                        );
                    },
                    _ => unreachable!(),
                }

                attrpath
            };
        "attrpath" => rules "attrpath" "." "string_attr"
            => |mut asts| {
                let mut attrpath = asts.swap_remove(0);

                match &mut attrpath {
                    AST::__AttributePath(attribute_path) => {
                        attribute_path.parts.push_back(
                            match asts.swap_remove(0) {
                                AST::__Part(attribute) => attribute,
                                _ => unreachable!(),
                            },
                        );
                    },
                    _ => unreachable!(),
                }

                attrpath
            };
        "attrpath" => rules "attr"
            => |mut asts| AST::__AttributePath(AttributePath {
                parts: LinkedList::from([
                    (match asts.swap_remove(0) {
                        AST::__Part(attribute) => attribute,
                        _ => unreachable!(),
                    })
                ]),
            });
        "attrpath" => rules "string_attr"
            => |mut asts| AST::__AttributePath(AttributePath {
                parts: LinkedList::from([
                    (match asts.swap_remove(0) {
                        AST::__Part(attribute) => attribute,
                        _ => unreachable!(),
                    })
                ]),
            });
        "attr" => rules "ID"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => {
                    AST::__Part(Part::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone(),
                    })
                },
                _ => unreachable!(),
            };
        "attr" => rules "OR_KW"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => {
                    AST::__Part(Part::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone(),
                    })
                },
                _ => unreachable!(),
            };

        "string_attr" => rules "\"" "string_parts" "\""
            => |mut asts| match asts.swap_remove(1) {
                AST::__Parts(parts) => AST::__Part(Part::Expression {
                    ast: Box::new(AST::String {
                        parts,
                        position: match asts.swap_remove(0) {
                            AST::__Lexeme(lexeme) => lexeme.position.clone(),
                            _ => unreachable!(),
                        },
                    }),
                }),
                _ => unreachable!(),
            };
        "string_attr" => rules "DOLLAR_CURLY" "expr" "}"
            => |mut asts| AST::__Part(Part::Interpolation {
                expression: Box::new(asts.swap_remove(1)),
            });

        "expr_list" => rules "expr_list" "expr_select"
            => |mut asts| {
                let mut expr_list = asts.swap_remove(0);

                match &mut expr_list {
                    AST::List { elements, .. } => {
                        elements.push_back(asts.swap_remove(0));
                    }
                    _ => unreachable!(),
                }

                expr_list
            };
        "expr_list" => empty
            => |_| AST::List {
                elements: LinkedList::new(),
                position: Position {
                    line: usize::MAX,
                    column: usize::MAX,
                },
            };

        "formals" => rules "formal" "," "formals"
            => |mut asts| {
                let mut formals = asts.swap_remove(2);
                let formal = match asts.swap_remove(0) {
                    AST::__DestructuredArgument(formal) => formal,
                    _ => unreachable!(),
                };

                match &mut formals {
                    AST::__DestructuredArguments(formals) => {
                        formals.arguments.push_front(formal);
                    },
                    _ => unreachable!(),
                }

                formals
            };
        "formals" => rules "formal"
            => |mut asts| {
                let formal = match asts.swap_remove(0) {
                    AST::__DestructuredArgument(formal) => formal,
                    _ => unreachable!(),
                };

                AST::__DestructuredArguments(
                    DestructuredArguments {
                        arguments: LinkedList::from([formal]),
                        ellipsis: false,
                    },
                )
            };
        "formals" => rules "ELLIPSIS"
            => |_| AST::__DestructuredArguments(
                DestructuredArguments {
                    arguments: LinkedList::new(),
                    ellipsis: true,
                },
            );
        "formals" => empty
            => |_| AST::__DestructuredArguments(
                DestructuredArguments {
                    arguments: LinkedList::new(),
                    ellipsis: false,
                },
            );

        "formal" => rules "ID"
            => |mut asts| {
                let id = match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme,
                    _ => unreachable!(),
                };

                AST::__DestructuredArgument(DestructuredArgument {
                    identifier: id.raw.clone(),
                    default: None,
                })
            };
        "formal" => rules "ID" "?" "expr"
            => |mut asts| {
                let id = match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme,
                    _ => unreachable!(),
                };

                AST::__DestructuredArgument(DestructuredArgument {
                    identifier: id.raw.clone(),
                    default: Some(Box::new(asts.swap_remove(0))),
                })
            };

        // All lexemes
        "\"" => lexemes "\""
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "(" => lexemes "("
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        ")" => lexemes ")"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "*" => lexemes "*"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "+" => lexemes "+"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "," => lexemes ","
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "." => lexemes "."
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "/" => lexemes "/"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        ":" => lexemes ":"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        ";" => lexemes ";"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "<" => lexemes "<"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "=" => lexemes "="
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        ">" => lexemes ">"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "?" => lexemes "?"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "@" => lexemes "@"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "[" => lexemes "["
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "]" => lexemes "]"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "{" => lexemes "{"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "}" => lexemes "}"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "AND" => lexemes "AND"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "ASSERT" => lexemes "ASSERT"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "CONCAT" => lexemes "CONCAT"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "DOLLAR_CURLY" => lexemes "DOLLAR_CURLY"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "ELLIPSIS" => lexemes "ELLIPSIS"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "ELSE" => lexemes "ELSE"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "EQ" => lexemes "EQ"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "FLOAT" => lexemes "FLOAT"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "GEQ" => lexemes "GEQ"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "HPATH" => lexemes "HPATH"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "ID" => lexemes "ID"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "IF" => lexemes "IF"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "IMPL" => lexemes "IMPL"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "IN" => lexemes "IN"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "IND_STR" => lexemes "IND_STR"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "IND_STRING_CLOSE" => lexemes "IND_STRING_CLOSE"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "IND_STRING_OPEN" => lexemes "IND_STRING_OPEN"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "INHERIT" => lexemes "INHERIT"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "INT" => lexemes "INT"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "LEQ" => lexemes "LEQ"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "LET" => lexemes "LET"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "NEQ" => lexemes "NEQ"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "OR" => lexemes "OR"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "OR_KW" => lexemes "OR_KW"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "PATH" => lexemes "PATH"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "PATH_END" => lexemes "PATH_END"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "REC" => lexemes "REC"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "SPATH" => lexemes "SPATH"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "STR" => lexemes "STR"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "THEN" => lexemes "THEN"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "UPDATE" => lexemes "UPDATE"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "WITH" => lexemes "WITH"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "NOT" => lexemes "!"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "NEGATE" => lexemes "-"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());
        "-" => lexemes "-"
            => |lexemes| AST::__Lexeme(lexemes[0].clone());

        Associativity::Right => rules "IMPL";
        Associativity::Left => rules "OR";
        Associativity::Left => rules "AND";
        Associativity::None => rules "EQ" "NEQ";
        Associativity::None => rules "<" ">" "LEQ" "GEQ";
        Associativity::Right => rules "UPDATE";
        Associativity::Left => rules "NOT";
        Associativity::Left => rules "+" "-";
        Associativity::Left => rules "*" "/";
        Associativity::Right => rules "CONCAT";
        Associativity::None => rules "?";
        Associativity::None => rules "NEGATE";
    )
}

fn strip_indentation(mut parts: LinkedList<Part>) -> LinkedList<Part> {
    let mut at_start_of_line = true;
    let mut min_indent: usize = usize::MAX;
    let mut cur_indent: usize = 0;

    // Compute the min indentation
    for part in &parts {
        if let Part::Raw { content, .. } = part {
            for char in content.chars() {
                if at_start_of_line {
                    match char {
                        ' ' => {
                            cur_indent += 1;
                        },
                        '\n' => {
                            cur_indent = 0;
                        },
                        _ => {
                            at_start_of_line = false;
                            if cur_indent < min_indent {
                                min_indent = cur_indent;
                            }
                        },
                    }
                } else if char == '\n' {
                    at_start_of_line = true;
                    cur_indent = 0;
                }
            }
        }
    }

    // Trim spaces from each line
    let mut cur_dropped: usize = 0;
    let parts_count = parts.len();
    for part in parts.iter_mut() {
        match part {
            Part::Raw { content, .. } => {
                *content = content
                    .chars()
                    .filter(|char| {
                        if at_start_of_line {
                            match char {
                                ' ' => {
                                    cur_dropped += 1;
                                    cur_dropped > min_indent
                                },
                                '\n' => {
                                    cur_dropped = 0;
                                    true
                                },
                                _ => {
                                    at_start_of_line = false;
                                    cur_dropped = 0;
                                    true
                                },
                            }
                        } else {
                            if *char == '\n' {
                                at_start_of_line = true;
                            }
                            true
                        }
                    })
                    .collect();

                if parts_count == 1 {
                    if let Some(last_new_line) = content.rfind('\n') {
                        if content[last_new_line + 1..]
                            .chars()
                            .all(|char| char == ' ')
                        {
                            content.truncate(last_new_line + 1);
                        }
                    }
                }
            },
            _ => {
                at_start_of_line = false;
                cur_dropped = 0;
            },
        }
    }

    parts
}
