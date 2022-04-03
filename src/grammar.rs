// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use crate::expression::Attribute;
use crate::expression::AttributePath;
use crate::expression::BinaryOperator;
use crate::expression::Bind;
use crate::expression::FunctionArgument;
use crate::expression::FunctionArguments;
use crate::expression::StringPart;
use crate::expression::UnaryOperator;
use crate::expression::AST;
use santiago::grammar::Associativity;
use santiago::grammar::Grammar;
use std::collections::LinkedList;

pub fn grammar() -> Grammar<AST> {
    santiago::grammar!(
        "expr" => rules "expr_function";

        "expr_function" => rules "ID" ":" "expr_function"
            => |mut asts| AST::Function {
                argument: Some(match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.raw.clone(),
                    _ => unreachable!(),
                }),
                arguments: FunctionArguments {
                    arguments: LinkedList::new(),
                    ellipsis: false,
                },
                definition: Box::new(asts.swap_remove(0)),
            };
        "expr_function" => rules "{" "formals" "}" ":" "expr_function"
            => |mut asts| AST::Function {
                argument: None,
                arguments: match asts.swap_remove(1) {
                    AST::__FunctionArguments(function_arguments) => function_arguments,
                    _ => unreachable!(),
                },
                definition: Box::new(asts.swap_remove(1)),
            };
        "expr_function" => rules "{" "formals" "}" "@" "ID" ":" "expr_function"
            => |mut asts| AST::Function {
                argument: Some(match asts.swap_remove(4) {
                    AST::__Lexeme(lexeme) => lexeme.raw.clone(),
                    _ => unreachable!(),
                }),
                arguments: match asts.swap_remove(1) {
                    AST::__FunctionArguments(function_arguments) => function_arguments,
                    _ => unreachable!(),
                },
                definition: Box::new(asts.swap_remove(4)),
            };
        "expr_function" => rules "ID" "@" "{" "formals" "}" ":" "expr_function"
            => |mut asts| AST::Function {
                argument: Some(match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme.raw.clone(),
                    _ => unreachable!(),
                }),
                arguments: match asts.swap_remove(3) {
                    AST::__FunctionArguments(function_arguments) => function_arguments,
                    _ => unreachable!(),
                },
                definition: Box::new(asts.swap_remove(0)),
            };
        "expr_function" => rules "ASSERT" "expr" ";" "expr_function"
            => |mut asts| AST::Assert {
                expression: Box::new(asts.swap_remove(1)),
                target: Box::new(asts.swap_remove(1)),
            };
        "expr_function" => rules "WITH" "expr" ";" "expr_function"
            => |mut asts| AST::With {
                expression: Box::new(asts.swap_remove(1)),
                target: Box::new(asts.swap_remove(1)),
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
                }
            };
        "expr_function" => rules "expr_if";

        "expr_if" => rules "IF" "expr" "THEN" "expr" "ELSE" "expr"
            => |mut asts| AST::IfThenElse {
                predicate: Box::new(asts.swap_remove(1)),
                then: Box::new(asts.swap_remove(3)),
                else_: Box::new(asts.swap_remove(1)),
            };
        "expr_if" => rules "expr_op";

        "expr_op" => rules "NOT" "expr_op"
            => |mut asts| AST::UnaryOperation {
                operator: UnaryOperator::Not,
                operand: Box::new(asts.swap_remove(1)),
            };
        "expr_op" => rules "NEGATE" "expr_op"
            => |mut asts| AST::UnaryOperation {
                operator: UnaryOperator::Negate,
                operand: Box::new(asts.swap_remove(1)),
            };
        "expr_op" => rules "expr_op" "EQ" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::EqualTo,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "NEQ" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::NotEqualTo,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "<" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::LessThan,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "LEQ" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::LessThanOrEqualTo,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" ">" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::GreaterThan,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "GEQ" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::GreaterThanOrEqualTo,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "AND" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::LogicalAnd,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "OR" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::LogicalOr,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "IMPL" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Implication,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "UPDATE" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Update,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "?" "attrpath"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::HasAttribute,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "+" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Addition,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "-" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Subtraction,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "*" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Multiplication,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "/" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Division,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
            };
        "expr_op" => rules "expr_op" "CONCAT" "expr_op"
            => |mut asts| AST::BinaryOperation {
                operator: BinaryOperator::Concatenation,
                operands: vec![
                    asts.swap_remove(0),
                    asts.swap_remove(0),
                ],
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
                arguments: LinkedList::from([asts.swap_remove(0)]),
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
                        value: str::parse::<isize>(&lexeme.raw).unwrap(),
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
            => |mut asts| asts.swap_remove(1);
        "expr_simple" => rules "IND_STRING_OPEN" "ind_string_parts" "IND_STRING_CLOSE"
            => |mut asts| asts.swap_remove(1);
        "expr_simple" => rules "path_start" "PATH_END"
            => |mut asts| {
                let mut path_start = match asts.swap_remove(0) {
                    AST::__StringParts(string_parts) => string_parts,
                    _ => unreachable!(),
                };
                let path_end = match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => StringPart::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone()
                    },
                    _ => unreachable!(),
                };

                let mut parts = LinkedList::new();
                parts.append(&mut path_start);
                parts.push_back(path_end);

                AST::Path { parts }
            };
        "expr_simple" => rules "path_start" "string_parts_interpolated" "PATH_END"
            => |mut asts| {
                let mut path_start = match asts.swap_remove(0) {
                    AST::__StringParts(string_parts) => string_parts,
                    _ => unreachable!(),
                };
                let mut string_parts_interpolated = match asts.swap_remove(1) {
                    AST::__StringParts(string_parts) => string_parts,
                    _ => unreachable!(),
                };
                let path_end = match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => StringPart::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone()
                    },
                    _ => unreachable!(),
                };

                let mut parts = LinkedList::new();
                parts.append(&mut path_start);
                parts.append(&mut string_parts_interpolated);
                parts.push_back(path_end);

                AST::Path { parts }
            };
        "expr_simple" => rules "SPATH"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::SearchNixPath {
                    path: lexeme.raw.clone(),
                    position: lexeme.position.clone(),
                },
                _ => unreachable!(),
            };
        "expr_simple" => rules "URI"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::Uri(lexeme),
                _ => unreachable!(),
            };
        "expr_simple" => rules "(" "expr" ")"
            => |mut asts| asts.swap_remove(1);
        // "expr_simple" => rules "LET" "{" "binds" "}"
        "expr_simple" => rules "REC" "{" "binds" "}"
            => |mut asts| {
                let binds = asts.swap_remove(2);

                AST::Map {
                    bindings: match binds {
                        AST::__Bindings(bindings) => bindings,
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
                    recursive: false,
                }
            };
        "expr_simple" => rules "[" "expr_list" "]"
            => |mut asts| asts.swap_remove(1);

        "string_parts" => rules "STR"
            => |mut asts| AST::String {
                parts: LinkedList::from([
                    match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => StringPart::Raw {
                            content: lexeme.raw.clone(),
                            position: lexeme.position.clone()
                        },
                        _ => unreachable!(),
                    },
                ]),
            };
        "string_parts" => rules "string_parts_interpolated"
            => |mut asts| AST::String {
                parts: match asts.swap_remove(0) {
                    AST::__StringParts(string_parts) => string_parts,
                    _ => unreachable!(),
                },
            };
        "string_parts" => empty
            => |_| AST::String { parts: LinkedList::new() };

        "string_parts_interpolated" => rules "string_parts_interpolated" "STR"
            => |mut asts| {
                let mut string_parts_interpolated = asts.swap_remove(0);

                match &mut string_parts_interpolated {
                    AST::__StringParts(string_parts) => {
                        string_parts.push_back(match asts.swap_remove(0) {
                            AST::__Lexeme(lexeme) => StringPart::Raw {
                                content: lexeme.raw.clone(),
                                position: lexeme.position.clone()
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
                    AST::__StringParts(string_parts) => {
                        string_parts.push_back(StringPart::Expression {
                            expression: Box::new(asts.swap_remove(2)),
                        });
                    }
                    _ => unreachable!(),
                }

                string_parts_interpolated
            };
        "string_parts_interpolated" => rules "DOLLAR_CURLY" "expr" "}"
            => |mut asts| AST::__StringParts(LinkedList::from([
                StringPart::Expression {
                    expression: Box::new(asts.swap_remove(1)),
                }
            ]));
        "string_parts_interpolated" => rules "STR" "DOLLAR_CURLY" "expr" "}"
            => |mut asts| AST::__StringParts(LinkedList::from([
                match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => StringPart::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone()
                    },
                    _ => unreachable!(),
                },
                StringPart::Expression {
                    expression: Box::new(asts.swap_remove(2)),
                },
            ]));

        "path_start" => rules "PATH"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::__StringParts(
                    LinkedList::from([StringPart::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone()
                    }])
                ),
                _ => unreachable!(),
            };
        "path_start" => rules "HPATH"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => AST::__StringParts(
                    LinkedList::from([StringPart::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone()
                    }])
                ),
                _ => unreachable!(),
            };

        "ind_string_parts" => rules "ind_string_parts" "IND_STR"
            => |mut asts| {
                let mut ind_string_parts = asts.swap_remove(0);

                match &mut ind_string_parts {
                    AST::String { parts } => match asts.swap_remove(0) {
                        AST::__Lexeme(lexeme) => {
                            parts.push_back(StringPart::Raw {
                                content: lexeme.raw.clone(),
                                position: lexeme.position.clone()
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
                    AST::String { parts } => {
                        parts.push_back(StringPart::Expression {
                            expression: Box::new(asts.swap_remove(2)),
                        });
                    }
                    _ => unreachable!(),
                }
                ind_string_parts
            };
        "ind_string_parts" => empty
            => |_| AST::String { parts: LinkedList::new() };

        "binds" => rules "binds" "attrpath" "=" "expr" ";"
            => |mut asts| {
                let mut binds = asts.swap_remove(0);

                match &mut binds {
                    AST::__Bindings(bindings) => {
                        bindings.push_back(Bind::KeyValue(
                            match asts.swap_remove(1) {
                                AST::__AttributePath(attribute_path) => attribute_path,
                                _ => unreachable!(),
                            },
                            Box::new(asts.swap_remove(1)),
                        ));
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
                                bindings.push_back(Bind::Inherit(
                                    None,
                                    attributes,
                                ));
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
                                bindings.push_back(Bind::Inherit(
                                    Some(Box::new(asts.swap_remove(3))),
                                    attributes,
                                ));
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
                let mut attrpath = asts.swap_remove(0);

                match &mut attrpath {
                    AST::__Attributes(attributes) => {
                        attributes.push_back(match asts.swap_remove(0) {
                            AST::__Attribute(attribute) => attribute,
                            _ => unreachable!(),
                        });
                    },
                    _ => unreachable!(),
                }

                attrpath
            };
        "attrs" => rules "attrs" "string_attr"
            => |mut asts| {
                let mut attrpath = asts.swap_remove(0);

                match &mut attrpath {
                    AST::__Attributes(attributes) => {
                        attributes.push_back(match asts.swap_remove(0) {
                            AST::__Attribute(attribute) => attribute,
                            _ => unreachable!(),
                        });
                    },
                    _ => unreachable!(),
                }

                attrpath
            };
        "attrs" => empty
            => |_| AST::__Attributes(LinkedList::new());

        "attrpath" => rules "attrpath" "." "attr"
            => |mut asts| {
                let mut attrpath = asts.swap_remove(0);

                match &mut attrpath {
                    AST::__AttributePath(attribute_path) => {
                        attribute_path.attributes.push_back(
                            match asts.swap_remove(0) {
                                AST::__Attribute(attribute) => attribute,
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
                        attribute_path.attributes.push_back(
                            match asts.swap_remove(0) {
                                AST::__Attribute(attribute) => attribute,
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
                attributes: LinkedList::from([
                (match asts.swap_remove(0) {
                    AST::__Attribute(attribute) => attribute,
                    _ => unreachable!(),
                })
                ]),
            });
        "attrpath" => rules "string_attr"
            => |mut asts| AST::__AttributePath(AttributePath {
                attributes: LinkedList::from([
                (match asts.swap_remove(0) {
                    AST::__Attribute(attribute) => attribute,
                    _ => unreachable!(),
                })
                ]),
            });
        "attr" => rules "ID"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => {
                    AST::__Attribute(Attribute::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone(),
                    })
                },
                _ => unreachable!(),
            };
        "attr" => rules "OR_KW"
            => |mut asts| match asts.swap_remove(0) {
                AST::__Lexeme(lexeme) => {
                    AST::__Attribute(Attribute::Raw {
                        content: lexeme.raw.clone(),
                        position: lexeme.position.clone(),
                    })
                },
                _ => unreachable!(),
            };

        "string_attr" => rules "\"" "string_parts" "\""
            => |mut asts| AST::__Attribute(Attribute::Expression {
                expression: Box::new(asts.swap_remove(1)),
            });
        "string_attr" => rules "DOLLAR_CURLY" "expr" "}"
            => |mut asts| AST::__Attribute(Attribute::Expression {
                expression: Box::new(asts.swap_remove(1)),
            });

        "expr_list" => rules "expr_list" "expr_select"
            => |mut asts| {
                let mut expr_list = asts.swap_remove(0);

                match &mut expr_list {
                    AST::List { elements } => {
                        elements.push_back(asts.swap_remove(0));
                    }
                    _ => unreachable!(),
                }

                expr_list
            };
        "expr_list" => empty
            => |_| AST::List { elements: LinkedList::new() };

        "formals" => rules "formal" "," "formals"
            => |mut asts| {
                let mut formals = asts.swap_remove(2);
                let formal = match asts.swap_remove(0) {
                    AST::__FunctionArgument(function_argument) => function_argument,
                    _ => unreachable!(),
                };

                match &mut formals {
                    AST::__FunctionArguments(function_arguments) => {
                        function_arguments.arguments.push_back(formal);
                    },
                    _ => unreachable!(),
                }

                formals
            };
        "formals" => rules "formal"
            => |mut asts| {
                let formal = match asts.swap_remove(0) {
                    AST::__FunctionArgument(function_argument) => function_argument,
                    _ => unreachable!(),
                };

                AST::__FunctionArguments(FunctionArguments {
                    arguments: LinkedList::from([formal]),
                    ellipsis: false,
                })
            };
        "formals" => rules "ELLIPSIS"
            => |_| AST::__FunctionArguments(FunctionArguments {
                arguments: LinkedList::new(),
                ellipsis: true,
            });
        "formals" => empty
            => |_| AST::__FunctionArguments(FunctionArguments {
                arguments: LinkedList::new(),
                ellipsis: false,
            });

        "formal" => rules "ID"
            => |mut asts| {
                let id = match asts.swap_remove(0) {
                    AST::__Lexeme(lexeme) => lexeme,
                    _ => unreachable!(),
                };

                AST::__FunctionArgument(FunctionArgument {
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

                AST::__FunctionArgument(FunctionArgument {
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
        "URI" => lexemes "URI"
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
