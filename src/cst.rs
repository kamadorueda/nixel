// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use std::rc::Rc;

use santiago::lexer::Lexeme;

use crate::ast::AttributePath;
use crate::ast::Binding;
use crate::ast::DestructuredIdentifier;
use crate::ast::FunctionArgument;
use crate::ast::Part;
use crate::ast::AST;

#[derive(Clone, Debug)]
pub enum CST {
    Leaf { trivia: Vec<Rc<Lexeme>>, lexeme: Rc<Lexeme> },
    Node { kind: CSTNodeKind, leaves: Vec<CST> },
    Root { node: Box<CST>, trivia_after_node: Vec<Rc<Lexeme>> },
}

#[derive(Clone, Debug)]
pub enum CSTNodeKind {
    Assert,
    AttributePath,
    BinaryOperation,
    #[allow(non_camel_case_types)]
    Binding__Inherit,
    #[allow(non_camel_case_types)]
    Binding__Binding,
    Float,
    Function,
    FunctionApplication,
    HasProperty,
    IfThenElse,
    Int,
    LetIn,
    List,
    Map,
    Parentheses,
    #[allow(non_camel_case_types)]
    Part__Expression,
    #[allow(non_camel_case_types)]
    Part__Raw,
    Path,
    PropertyAccess,
    SearchNixPath,
    String,
    UnaryOperation,
    Uri,
    Variable,
    With,
}

pub fn build_concrete_syntax_tree(ast: &AST, lexemes: &[Rc<Lexeme>]) -> CST {
    let mut lexeme_index = 0;

    let cst = CST::Root {
        node:              Box::new(_ast(ast, lexemes, &mut lexeme_index)),
        trivia_after_node: _trivia(lexemes, &mut lexeme_index),
    };

    let lexemes_len = lexemes.len();

    if lexeme_index != lexemes_len {
        dbg!(&cst);
        unreachable!(
            "Not all lexemes were consumed: {lexeme_index} != {lexemes_len}, \
             this is a bug on NixEL, please report it to: \
             github.com/kamadorueda/nixel",
        );
    }

    cst
}

pub(crate) fn _ast(
    ast: &AST,
    lexemes: &[Rc<Lexeme>],
    lexeme_index: &mut usize,
) -> CST {
    match &ast {
        AST::Assert { expression, target, .. } => CST::Node {
            kind:   CSTNodeKind::Assert,
            leaves: vec![
                _lexeme(lexemes, lexeme_index),
                _ast(&*expression, lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
                _ast(&*target, lexemes, lexeme_index),
            ],
        },
        AST::BinaryOperation { operands, .. } => CST::Node {
            kind:   CSTNodeKind::BinaryOperation,
            leaves: vec![
                _ast(&operands[0], lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
                _ast(&operands[1], lexemes, lexeme_index),
            ],
        },
        AST::Float { .. } => CST::Node {
            kind:   CSTNodeKind::Float,
            leaves: vec![_lexeme(lexemes, lexeme_index)],
        },
        AST::Function { argument, definition, .. } => CST::Node {
            kind:   CSTNodeKind::Function,
            leaves: match argument {
                FunctionArgument::Simple { .. } => vec![
                    _lexeme(lexemes, lexeme_index),
                    _lexeme(lexemes, lexeme_index),
                    _ast(&*definition, lexemes, lexeme_index),
                ],
                FunctionArgument::Destructured {
                    identifier,
                    arguments,
                    ellipsis,
                    ..
                } => {
                    let mut leaves =
                        Vec::with_capacity(4 + 2 * arguments.len());

                    if let DestructuredIdentifier::LeftAt(_) = identifier {
                        leaves.reserve(2);
                        leaves.push(_lexeme(lexemes, lexeme_index));
                        leaves.push(_lexeme(lexemes, lexeme_index));
                    }

                    leaves.push(_lexeme(lexemes, lexeme_index));

                    for argument in arguments {
                        leaves.push(_lexeme(lexemes, lexeme_index));

                        if let Some(default) = &argument.default {
                            leaves.reserve(2);
                            leaves.push(_lexeme(lexemes, lexeme_index));
                            leaves.push(_ast(&*default, lexemes, lexeme_index));
                        }

                        if lexemes[*lexeme_index..]
                            .iter()
                            .filter(|l| l.kind != "WS")
                            .filter(|l| l.kind != "COMMENT")
                            .take_while(|l| l.kind == ",")
                            .next()
                            .is_some()
                        {
                            leaves.push(_lexeme(lexemes, lexeme_index));
                        }
                    }

                    if *ellipsis {
                        leaves.push(_lexeme(lexemes, lexeme_index));
                    }

                    leaves.push(_lexeme(lexemes, lexeme_index));

                    if let DestructuredIdentifier::RightAt(_) = identifier {
                        leaves.reserve(2);
                        leaves.push(_lexeme(lexemes, lexeme_index));
                        leaves.push(_lexeme(lexemes, lexeme_index));
                    }

                    leaves.push(_lexeme(lexemes, lexeme_index));
                    leaves.push(_ast(&*definition, lexemes, lexeme_index));

                    leaves
                }
            },
        },
        AST::FunctionApplication { function, arguments, .. } => CST::Node {
            kind:   CSTNodeKind::FunctionApplication,
            leaves: {
                let mut leaves = Vec::with_capacity(1 + arguments.len());

                leaves.push(_ast(&*function, lexemes, lexeme_index));

                for argument in arguments {
                    leaves.push(_ast(argument, lexemes, lexeme_index));
                }

                leaves
            },
        },
        AST::HasProperty { expression, attribute_path, .. } => CST::Node {
            kind:   CSTNodeKind::HasProperty,
            leaves: vec![
                _ast(&*expression, lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
                _attribute_path(&*attribute_path, lexemes, lexeme_index),
            ],
        },
        AST::IfThenElse { predicate, then, else_, .. } => CST::Node {
            kind:   CSTNodeKind::IfThenElse,
            leaves: vec![
                _lexeme(lexemes, lexeme_index),
                _ast(&*predicate, lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
                _ast(&*then, lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
                _ast(&*else_, lexemes, lexeme_index),
            ],
        },
        AST::Int { .. } => CST::Node {
            kind:   CSTNodeKind::Int,
            leaves: vec![_lexeme(lexemes, lexeme_index)],
        },
        AST::LetIn { bindings, target, .. } => CST::Node {
            kind:   CSTNodeKind::LetIn,
            leaves: {
                let mut leaves = Vec::with_capacity(3 + bindings.len());

                leaves.push(_lexeme(lexemes, lexeme_index));

                for binding in bindings {
                    leaves.push(_binding(binding, lexemes, lexeme_index));
                }

                leaves.push(_lexeme(lexemes, lexeme_index));
                leaves.push(_ast(&*target, lexemes, lexeme_index));

                leaves
            },
        },
        AST::List { elements, .. } => CST::Node {
            kind:   CSTNodeKind::List,
            leaves: {
                let mut leaves = Vec::with_capacity(2 + elements.len());

                leaves.push(_lexeme(lexemes, lexeme_index));

                for element in elements {
                    leaves.push(_ast(element, lexemes, lexeme_index));
                }

                leaves.push(_lexeme(lexemes, lexeme_index));

                leaves
            },
        },
        AST::Map { bindings, recursive, .. } => CST::Node {
            kind:   CSTNodeKind::Map,
            leaves: {
                let mut leaves = Vec::with_capacity(3 + bindings.len());

                if *recursive {
                    leaves.push(_lexeme(lexemes, lexeme_index));
                }
                leaves.push(_lexeme(lexemes, lexeme_index));

                for binding in bindings {
                    leaves.push(_binding(binding, lexemes, lexeme_index));
                }

                leaves.push(_lexeme(lexemes, lexeme_index));

                leaves
            },
        },
        AST::Parentheses { expression, .. } => CST::Node {
            kind:   CSTNodeKind::Parentheses,
            leaves: vec![
                _lexeme(lexemes, lexeme_index),
                _ast(&*expression, lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
            ],
        },
        AST::Path { parts, .. } => CST::Node {
            kind:   CSTNodeKind::Path,
            leaves: {
                let mut leaves = Vec::with_capacity(parts.len());

                for part in parts {
                    leaves.push(_part(part, lexemes, lexeme_index));
                }

                // PATH_END
                _lexeme(lexemes, lexeme_index);

                leaves
            },
        },
        AST::PropertyAccess { expression, attribute_path, default, .. } => {
            CST::Node {
                kind:   CSTNodeKind::PropertyAccess,
                leaves: {
                    let mut leaves = Vec::with_capacity(
                        3 + if default.is_some() { 2 } else { 0 },
                    );

                    leaves.push(_ast(&*expression, lexemes, lexeme_index));
                    leaves.push(_lexeme(lexemes, lexeme_index));
                    leaves.push(_attribute_path(
                        &*attribute_path,
                        lexemes,
                        lexeme_index,
                    ));

                    if let Some(default) = default {
                        leaves.push(_lexeme(lexemes, lexeme_index));
                        leaves.push(_ast(&*default, lexemes, lexeme_index));
                    }

                    leaves
                },
            }
        }
        AST::SearchNixPath { .. } => CST::Node {
            kind:   CSTNodeKind::SearchNixPath,
            leaves: vec![_lexeme(lexemes, lexeme_index)],
        },
        AST::String { parts, .. } => CST::Node {
            kind:   CSTNodeKind::String,
            leaves: {
                let mut leaves = Vec::with_capacity(2 + parts.len());

                leaves.push(_lexeme(lexemes, lexeme_index));

                for part in parts {
                    leaves.push(_part(part, lexemes, lexeme_index));
                }

                leaves.push(_lexeme(lexemes, lexeme_index));

                leaves
            },
        },
        AST::UnaryOperation { operand, .. } => CST::Node {
            kind:   CSTNodeKind::UnaryOperation,
            leaves: vec![
                _ast(operand, lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
            ],
        },
        AST::Uri { .. } => CST::Node {
            kind:   CSTNodeKind::Uri,
            leaves: vec![_lexeme(lexemes, lexeme_index)],
        },
        AST::Variable { .. } => CST::Node {
            kind:   CSTNodeKind::Variable,
            leaves: vec![_lexeme(lexemes, lexeme_index)],
        },
        AST::With { expression, target, .. } => CST::Node {
            kind:   CSTNodeKind::With,
            leaves: vec![
                _lexeme(lexemes, lexeme_index),
                _ast(&*expression, lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
                _ast(&*target, lexemes, lexeme_index),
            ],
        },
        AST::__Attributes(_) => unreachable!(),
        AST::__AttributePath(_) => unreachable!(),
        AST::__Bindings(_) => unreachable!(),
        AST::__DestructuredArgument(_) => unreachable!(),
        AST::__DestructuredArguments(_) => unreachable!(),
        AST::__Part(_) => unreachable!(),
        AST::__Parts(_) => unreachable!(),
        AST::__Lexeme(_) => unreachable!(),
    }
}

fn _attribute_path(
    attribute_path: &AttributePath,
    lexemes: &[Rc<Lexeme>],
    lexeme_index: &mut usize,
) -> CST {
    let mut leaves = Vec::with_capacity(attribute_path.parts.len());

    for (index, part) in attribute_path.parts.iter().enumerate() {
        leaves.push(_part(part, lexemes, lexeme_index));

        if index + 1 != attribute_path.parts.len() {
            leaves.push(_lexeme(lexemes, lexeme_index));
        }
    }

    CST::Node { kind: CSTNodeKind::AttributePath, leaves }
}

fn _binding(
    binding: &Binding,
    lexemes: &[Rc<Lexeme>],
    lexeme_index: &mut usize,
) -> CST {
    match binding {
        Binding::Binding { from, to } => CST::Node {
            kind:   CSTNodeKind::Binding__Binding,
            leaves: vec![
                _attribute_path(from, lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
                _ast(&*to, lexemes, lexeme_index),
                _lexeme(lexemes, lexeme_index),
            ],
        },
        Binding::Inherit { from, attributes, .. } => CST::Node {
            kind:   CSTNodeKind::Binding__Inherit,
            leaves: {
                let mut leaves = Vec::with_capacity(
                    2 + attributes.len() + if from.is_some() { 3 } else { 0 },
                );

                leaves.push(_lexeme(lexemes, lexeme_index));

                if let Some(from) = from {
                    leaves.push(_lexeme(lexemes, lexeme_index));
                    leaves.push(_ast(&*from, lexemes, lexeme_index));
                    leaves.push(_lexeme(lexemes, lexeme_index));
                }

                for attribute in attributes {
                    leaves.push(_part(&*attribute, lexemes, lexeme_index));
                }

                leaves.push(_lexeme(lexemes, lexeme_index));

                leaves
            },
        },
    }
}

fn _lexeme(lexemes: &[Rc<Lexeme>], lexeme_index: &mut usize) -> CST {
    let trivia = _trivia(lexemes, lexeme_index);
    let lexeme = lexemes[*lexeme_index].clone();

    let cst = CST::Leaf { lexeme, trivia };

    *lexeme_index += 1;

    cst
}

fn _part(part: &Part, lexemes: &[Rc<Lexeme>], lexeme_index: &mut usize) -> CST {
    match part {
        Part::Raw { .. } => CST::Node {
            kind:   CSTNodeKind::Part__Raw,
            leaves: vec![_lexeme(lexemes, lexeme_index)],
        },
        Part::Expression { expression } => CST::Node {
            kind:   CSTNodeKind::Part__Expression,
            leaves: match &**expression {
                AST::String { .. } => {
                    vec![_ast(&*expression, lexemes, lexeme_index)]
                }
                _ => vec![
                    _lexeme(lexemes, lexeme_index),
                    _ast(&*expression, lexemes, lexeme_index),
                    _lexeme(lexemes, lexeme_index),
                ],
            },
        },
    }
}

fn _trivia(
    lexemes: &[Rc<Lexeme>],
    lexeme_index: &mut usize,
) -> Vec<Rc<Lexeme>> {
    let mut trivia = Vec::new();

    while *lexeme_index < lexemes.len()
        && (lexemes[*lexeme_index].kind == "WS"
            || lexemes[*lexeme_index].kind == "COMMENT")
    {
        trivia.push(lexemes[*lexeme_index].clone());
        *lexeme_index += 1;
    }

    trivia
}
