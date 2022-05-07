// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

//! Concrete Syntax Tree of the Nix expressions language.
//!
//! You most likely want to read the [CST] type first.

use std::rc::Rc;

use santiago::lexer::Lexeme;

use crate::ast::AttributePath;
use crate::ast::Binding as ASTBinding;
use crate::ast::DestructuredIdentifier as ASTDestructuredIdentifier;
use crate::ast::FunctionArgument;
use crate::ast::Part;
use crate::ast::AST;

/// Main type of a Concrete Syntax Tree.
#[derive(Clone, Debug, PartialEq)]
pub enum CST {
    Assert {
        assert: Rc<Lexeme>,
        assert_trivia: Vec<Rc<Lexeme>>,
        expression: Box<CST>,
        expression_trivia: Vec<Rc<Lexeme>>,
        semicolon: Rc<Lexeme>,
        semicolon_trivia: Vec<Rc<Lexeme>>,
        target: Box<CST>,
    },
    AttributePath {
        parts: Vec<AttributePathPart>,
    },
    BinaryOperation {
        left_operand: Box<CST>,
        left_operand_trivia: Vec<Rc<Lexeme>>,
        operator: Rc<Lexeme>,
        operator_trivia: Vec<Rc<Lexeme>>,
        right_operand: Box<CST>,
    },
    Binding {
        from: Box<CST>,
        from_trivia: Vec<Rc<Lexeme>>,
        equal: Rc<Lexeme>,
        equal_trivia: Vec<Rc<Lexeme>>,
        to: Box<CST>,
        to_trivia: Vec<Rc<Lexeme>>,
        semicolon: Rc<Lexeme>,
    },
    Float {
        lexeme: Rc<Lexeme>,
    },
    FunctionSimple {
        argument: Rc<Lexeme>,
        argument_trivia: Vec<Rc<Lexeme>>,
        vertical_two_dots: Rc<Lexeme>,
        vertical_two_dots_trivia: Vec<Rc<Lexeme>>,
        definition: Box<CST>,
    },
    FunctionDestructured {
        identifier: Option<FunctionDestructuredIdentifier>,
        open: Rc<Lexeme>,
        open_trivia: Vec<Rc<Lexeme>>,
        arguments: Vec<FunctionDestructuredArgument>,
        ellipsis: Option<FunctionDestructuredEllipsis>,
        close: Rc<Lexeme>,
        close_trivia: Vec<Rc<Lexeme>>,
        vertical_two_dots: Rc<Lexeme>,
        vertical_two_dots_trivia: Vec<Rc<Lexeme>>,
        definition: Box<CST>,
    },
    FunctionApplication {
        function: Box<CST>,
        function_trivia: Vec<Rc<Lexeme>>,
        arguments: Vec<FunctionApplicationArgument>,
    },
    HasProperty {
        expression: Box<CST>,
        expression_trivia: Vec<Rc<Lexeme>>,
        question: Rc<Lexeme>,
        question_trivia: Vec<Rc<Lexeme>>,
        attribute_path: Box<CST>,
    },
    IfThenElse {
        if_: Rc<Lexeme>,
        if_trivia: Vec<Rc<Lexeme>>,
        predicate: Box<CST>,
        predicate_trivia: Vec<Rc<Lexeme>>,
        then: Rc<Lexeme>,
        then_trivia: Vec<Rc<Lexeme>>,
        then_expression: Box<CST>,
        then_expression_trivia: Vec<Rc<Lexeme>>,
        else_: Rc<Lexeme>,
        else_trivia: Vec<Rc<Lexeme>>,
        else_expression: Box<CST>,
    },
    Inherit {
        inherit: Rc<Lexeme>,
        inherit_trivia: Vec<Rc<Lexeme>>,
        attributes: Vec<InheritAttribute>,
        semicolon: Rc<Lexeme>,
    },
    InheritFrom {
        inherit: Rc<Lexeme>,
        inherit_trivia: Vec<Rc<Lexeme>>,
        from: Box<CST>,
        from_trivia: Vec<Rc<Lexeme>>,
        attributes: Vec<InheritAttribute>,
        semicolon: Rc<Lexeme>,
    },
    Int {
        lexeme: Rc<Lexeme>,
    },
    LetIn {
        let_: Rc<Lexeme>,
        let_trivia: Vec<Rc<Lexeme>>,
        bindings: Vec<Binding>,
        in_: Rc<Lexeme>,
        in_trivia: Vec<Rc<Lexeme>>,
        target: Box<CST>,
    },
    List {
        open: Rc<Lexeme>,
        open_trivia: Vec<Rc<Lexeme>>,
        elements: Vec<ListElement>,
        close: Rc<Lexeme>,
    },
    Map {
        recursive: Option<MapRecursive>,
        open: Rc<Lexeme>,
        open_trivia: Vec<Rc<Lexeme>>,
        bindings: Vec<Binding>,
        close: Rc<Lexeme>,
    },
    SearchNixPath {
        lexeme: Rc<Lexeme>,
    },
    Parentheses {
        open: Rc<Lexeme>,
        open_trivia: Vec<Rc<Lexeme>>,
        expression: Box<CST>,
        expression_trivia: Vec<Rc<Lexeme>>,
        close: Rc<Lexeme>,
    },
    PartInterpolation {
        open: Rc<Lexeme>,
        open_trivia: Vec<Rc<Lexeme>>,
        expression: Box<CST>,
        expression_trivia: Vec<Rc<Lexeme>>,
        close: Rc<Lexeme>,
    },
    PartRaw {
        lexeme: Rc<Lexeme>,
    },
    Path {
        parts: Vec<CST>,
    },
    PropertyAccess {
        expression: Box<CST>,
        expression_trivia: Vec<Rc<Lexeme>>,
        dot: Rc<Lexeme>,
        dot_trivia: Vec<Rc<Lexeme>>,
        attribute_path: Box<CST>,
    },
    PropertyAccessWithDefault {
        expression: Box<CST>,
        expression_trivia: Vec<Rc<Lexeme>>,
        dot: Rc<Lexeme>,
        dot_trivia: Vec<Rc<Lexeme>>,
        attribute_path: Box<CST>,
        attribute_path_trivia: Vec<Rc<Lexeme>>,
        or: Rc<Lexeme>,
        or_trivia: Vec<Rc<Lexeme>>,
        default: Box<CST>,
    },
    Root {
        trivia_before: Vec<Rc<Lexeme>>,
        expression: Box<CST>,
        trivia_after: Vec<Rc<Lexeme>>,
    },
    String {
        open: Rc<Lexeme>,
        parts: Vec<CST>,
        close: Rc<Lexeme>,
    },
    UnaryOperation {
        operator: Rc<Lexeme>,
        operator_trivia: Vec<Rc<Lexeme>>,
        operand: Box<CST>,
    },
    Variable {
        lexeme: Rc<Lexeme>,
    },
    With {
        with: Rc<Lexeme>,
        with_trivia: Vec<Rc<Lexeme>>,
        expression: Box<CST>,
        expression_trivia: Vec<Rc<Lexeme>>,
        semicolon: Rc<Lexeme>,
        semicolon_trivia: Vec<Rc<Lexeme>>,
        target: Box<CST>,
    },
}

#[derive(Clone, Debug, PartialEq)]
pub struct AttributePathPart {
    pub part: Box<CST>,
    pub part_trivia: Vec<Rc<Lexeme>>,
    pub dot: Option<AttributePathDot>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct AttributePathDot {
    pub dot: Rc<Lexeme>,
    pub dot_trivia: Vec<Rc<Lexeme>>,
}

#[derive(Clone, Debug, PartialEq)]
pub enum FunctionDestructuredArgument {
    Simple {
        identifier: Rc<Lexeme>,
        identifier_trivia: Vec<Rc<Lexeme>>,
        comma: Option<FunctionDestructuredArgumentComma>,
    },
    WithDefault {
        identifier: Rc<Lexeme>,
        identifier_trivia: Vec<Rc<Lexeme>>,
        question: Rc<Lexeme>,
        question_trivia: Vec<Rc<Lexeme>>,
        default: Box<CST>,
        default_trivia: Vec<Rc<Lexeme>>,
        comma: Option<FunctionDestructuredArgumentComma>,
    },
}

#[derive(Clone, Debug, PartialEq)]
pub struct FunctionDestructuredArgumentComma {
    pub comma: Rc<Lexeme>,
    pub comma_trivia: Vec<Rc<Lexeme>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct FunctionDestructuredEllipsis {
    pub ellipsis: Rc<Lexeme>,
    pub ellipsis_trivia: Vec<Rc<Lexeme>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct FunctionDestructuredIdentifier {
    pub at: Rc<Lexeme>,
    pub at_trivia: Vec<Rc<Lexeme>>,
    pub identifier: Rc<Lexeme>,
    pub identifier_trivia: Vec<Rc<Lexeme>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct FunctionApplicationArgument {
    pub expression: Box<CST>,
    pub expression_trivia: Vec<Rc<Lexeme>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct Binding {
    pub binding: CST,
    pub binding_trivia: Vec<Rc<Lexeme>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct InheritAttribute {
    pub attribute: Rc<Lexeme>,
    pub attribute_trivia: Vec<Rc<Lexeme>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct ListElement {
    pub expression: Box<CST>,
    pub expression_trivia: Vec<Rc<Lexeme>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct MapRecursive {
    pub rec: Rc<Lexeme>,
    pub rec_trivia: Vec<Rc<Lexeme>>,
}

/// Build a [CST].
pub fn build_concrete_syntax_tree(ast: &AST, lexemes: &[Rc<Lexeme>]) -> CST {
    let mut index = 0;

    let cst = CST::Root {
        trivia_before: _trivia(lexemes, &mut index),
        expression: _ast(ast, lexemes, &mut index),
        trivia_after: _trivia(lexemes, &mut index),
    };

    let lexemes_len = lexemes.len();

    if index != lexemes_len {
        dbg!(&cst);
        panic!(
            "Not all lexemes were consumed: {index} != {lexemes_len}, this is \
             a bug on NixEL, please report it to: github.com/kamadorueda/nixel",
        );
    }

    cst
}

pub(crate) fn _ast(
    ast: &AST,
    lexemes: &[Rc<Lexeme>],
    index: &mut usize,
) -> Box<CST> {
    Box::new(match &ast {
        AST::Assert { expression, target, .. } => {
            CST::Assert {
                assert: _lexeme(lexemes, index),
                assert_trivia: _trivia(lexemes, index),
                expression: _ast(&*expression, lexemes, index),
                expression_trivia: _trivia(lexemes, index),
                semicolon: _lexeme(lexemes, index),
                semicolon_trivia: _trivia(lexemes, index),
                target: _ast(&*target, lexemes, index),
            }
        },
        AST::BinaryOperation { operands, .. } => {
            CST::BinaryOperation {
                left_operand: _ast(&operands[0], lexemes, index),
                left_operand_trivia: _trivia(lexemes, index),
                operator: _lexeme(lexemes, index),
                operator_trivia: _trivia(lexemes, index),
                right_operand: _ast(&operands[1], lexemes, index),
            }
        },
        AST::Float { .. } => CST::Float { lexeme: _lexeme(lexemes, index) },
        AST::Function { argument, definition, .. } => {
            match argument {
                FunctionArgument::Simple { .. } => {
                    CST::FunctionSimple {
                        argument: _lexeme(lexemes, index),
                        argument_trivia: _trivia(lexemes, index),
                        vertical_two_dots: _lexeme(lexemes, index),
                        vertical_two_dots_trivia: _trivia(lexemes, index),
                        definition: _ast(&*definition, lexemes, index),
                    }
                },
                FunctionArgument::Destructured {
                    identifier: function_identifier,
                    arguments,
                    ellipsis: function_ellipsis,
                    ..
                } => {
                    let mut identifier = None;

                    if let ASTDestructuredIdentifier::LeftAt(_) =
                        function_identifier
                    {
                        identifier = Some(FunctionDestructuredIdentifier {
                            identifier: _lexeme(lexemes, index),
                            identifier_trivia: _trivia(lexemes, index),
                            at: _lexeme(lexemes, index),
                            at_trivia: _trivia(lexemes, index),
                        });
                    }

                    let open = _lexeme(lexemes, index);
                    let open_trivia = _trivia(lexemes, index);

                    let arguments = arguments
                        .iter()
                        .map(|argument| {
                            match &argument.default {
                                None => {
                                    FunctionDestructuredArgument::Simple {
                                        identifier: _lexeme(lexemes, index),
                                        identifier_trivia: _trivia(
                                            lexemes, index,
                                        ),
                                        comma: _comma(lexemes, index),
                                    }
                                },
                                Some(default) => {
                                    FunctionDestructuredArgument::WithDefault {
                                        identifier: _lexeme(lexemes, index),
                                        identifier_trivia: _trivia(
                                            lexemes, index,
                                        ),
                                        question: _lexeme(lexemes, index),
                                        question_trivia: _trivia(
                                            lexemes, index,
                                        ),
                                        default: _ast(
                                            &*default, lexemes, index,
                                        ),
                                        default_trivia: _trivia(lexemes, index),
                                        comma: _comma(lexemes, index),
                                    }
                                },
                            }
                        })
                        .collect();

                    let ellipsis = if *function_ellipsis {
                        Some(FunctionDestructuredEllipsis {
                            ellipsis: _lexeme(lexemes, index),
                            ellipsis_trivia: _trivia(lexemes, index),
                        })
                    } else {
                        None
                    };

                    let close = _lexeme(lexemes, index);
                    let close_trivia = _trivia(lexemes, index);

                    if let ASTDestructuredIdentifier::RightAt(_) =
                        function_identifier
                    {
                        identifier = Some(FunctionDestructuredIdentifier {
                            at: _lexeme(lexemes, index),
                            at_trivia: _trivia(lexemes, index),
                            identifier: _lexeme(lexemes, index),
                            identifier_trivia: _trivia(lexemes, index),
                        });
                    }

                    CST::FunctionDestructured {
                        identifier,
                        open,
                        open_trivia,
                        arguments,
                        ellipsis,
                        close,
                        close_trivia,
                        vertical_two_dots: _lexeme(lexemes, index),
                        vertical_two_dots_trivia: _trivia(lexemes, index),
                        definition: _ast(&*definition, lexemes, index),
                    }
                },
            }
        },
        AST::FunctionApplication { function, arguments, .. } => {
            CST::FunctionApplication {
                function: _ast(&*function, lexemes, index),
                function_trivia: _trivia(lexemes, index),
                arguments: arguments
                    .iter()
                    .enumerate()
                    .map(|(argument_index, argument)| {
                        FunctionApplicationArgument {
                            expression: _ast(argument, lexemes, index),
                            expression_trivia: if argument_index + 1
                                == arguments.len()
                            {
                                Vec::new()
                            } else {
                                _trivia(lexemes, index)
                            },
                        }
                    })
                    .collect(),
            }
        },
        AST::HasProperty { expression, attribute_path, .. } => {
            CST::HasProperty {
                expression: _ast(&*expression, lexemes, index),
                expression_trivia: _trivia(lexemes, index),
                question: _lexeme(lexemes, index),
                question_trivia: _trivia(lexemes, index),
                attribute_path: _attribute_path(
                    &*attribute_path,
                    lexemes,
                    index,
                ),
            }
        },
        AST::IfThenElse { predicate, then, else_, .. } => {
            CST::IfThenElse {
                if_: _lexeme(lexemes, index),
                if_trivia: _trivia(lexemes, index),
                predicate: _ast(&*predicate, lexemes, index),
                predicate_trivia: _trivia(lexemes, index),
                then: _lexeme(lexemes, index),
                then_trivia: _trivia(lexemes, index),
                then_expression: _ast(&*then, lexemes, index),
                then_expression_trivia: _trivia(lexemes, index),
                else_: _lexeme(lexemes, index),
                else_trivia: _trivia(lexemes, index),
                else_expression: _ast(&*else_, lexemes, index),
            }
        },
        AST::Int { .. } => CST::Int { lexeme: _lexeme(lexemes, index) },
        AST::LetIn { bindings, target, .. } => {
            CST::LetIn {
                let_: _lexeme(lexemes, index),
                let_trivia: _trivia(lexemes, index),
                bindings: bindings
                    .iter()
                    .map(|binding| {
                        Binding {
                            binding: _binding(binding, lexemes, index),
                            binding_trivia: _trivia(lexemes, index),
                        }
                    })
                    .collect(),
                in_: _lexeme(lexemes, index),
                in_trivia: _trivia(lexemes, index),
                target: _ast(&*target, lexemes, index),
            }
        },
        AST::List { elements, .. } => {
            CST::List {
                open: _lexeme(lexemes, index),
                open_trivia: _trivia(lexemes, index),
                elements: elements
                    .iter()
                    .map(|element| {
                        ListElement {
                            expression: _ast(element, lexemes, index),
                            expression_trivia: _trivia(lexemes, index),
                        }
                    })
                    .collect(),
                close: _lexeme(lexemes, index),
            }
        },
        AST::Map { bindings, recursive, .. } => {
            CST::Map {
                recursive: if *recursive {
                    Some(MapRecursive {
                        rec: _lexeme(lexemes, index),
                        rec_trivia: _trivia(lexemes, index),
                    })
                } else {
                    None
                },
                open: _lexeme(lexemes, index),
                open_trivia: _trivia(lexemes, index),
                bindings: bindings
                    .iter()
                    .map(|binding| {
                        Binding {
                            binding: _binding(binding, lexemes, index),
                            binding_trivia: _trivia(lexemes, index),
                        }
                    })
                    .collect(),
                close: _lexeme(lexemes, index),
            }
        },
        AST::Parentheses { expression, .. } => {
            CST::Parentheses {
                open: _lexeme(lexemes, index),
                open_trivia: _trivia(lexemes, index),

                expression: _ast(&*expression, lexemes, index),
                expression_trivia: _trivia(lexemes, index),

                close: _lexeme(lexemes, index),
            }
        },
        AST::Path { parts, .. } => {
            CST::Path {
                parts: {
                    let parts = parts
                        .iter()
                        .map(|part| _part(part, lexemes, index))
                        .collect();

                    // PATH_END
                    _lexeme(lexemes, index);

                    parts
                },
            }
        },
        AST::PropertyAccess { expression, attribute_path, default, .. } => {
            if let Some(default) = default {
                CST::PropertyAccessWithDefault {
                    expression: _ast(&*expression, lexemes, index),
                    expression_trivia: _trivia(lexemes, index),
                    dot: _lexeme(lexemes, index),
                    dot_trivia: _trivia(lexemes, index),
                    attribute_path: _attribute_path(
                        &*attribute_path,
                        lexemes,
                        index,
                    ),
                    attribute_path_trivia: _trivia(lexemes, index),
                    or: _lexeme(lexemes, index),
                    or_trivia: _trivia(lexemes, index),
                    default: _ast(&*default, lexemes, index),
                }
            } else {
                CST::PropertyAccess {
                    expression: _ast(&*expression, lexemes, index),
                    expression_trivia: _trivia(lexemes, index),
                    dot: _lexeme(lexemes, index),
                    dot_trivia: _trivia(lexemes, index),
                    attribute_path: _attribute_path(
                        &*attribute_path,
                        lexemes,
                        index,
                    ),
                }
            }
        },
        AST::SearchNixPath { .. } => {
            CST::SearchNixPath { lexeme: _lexeme(lexemes, index) }
        },
        AST::String { parts, .. } => {
            CST::String {
                open: _lexeme(lexemes, index),
                parts: parts
                    .iter()
                    .map(|part| _part(part, lexemes, index))
                    .collect(),
                close: _lexeme(lexemes, index),
            }
        },
        AST::UnaryOperation { operand, .. } => {
            CST::UnaryOperation {
                operator: _lexeme(lexemes, index),
                operator_trivia: _trivia(lexemes, index),
                operand: _ast(operand, lexemes, index),
            }
        },
        AST::Variable { .. } => {
            CST::Variable { lexeme: _lexeme(lexemes, index) }
        },
        AST::With { expression, target, .. } => {
            CST::With {
                with: _lexeme(lexemes, index),
                with_trivia: _trivia(lexemes, index),
                expression: _ast(&*expression, lexemes, index),
                expression_trivia: _trivia(lexemes, index),
                semicolon: _lexeme(lexemes, index),
                semicolon_trivia: _trivia(lexemes, index),
                target: _ast(&*target, lexemes, index),
            }
        },
        AST::__Attributes(_) => unreachable!(),
        AST::__AttributePath(_) => unreachable!(),
        AST::__Bindings(_) => unreachable!(),
        AST::__DestructuredArgument(_) => unreachable!(),
        AST::__DestructuredArguments(_) => unreachable!(),
        AST::__Part(_) => unreachable!(),
        AST::__Parts(_) => unreachable!(),
        AST::__Lexeme(_) => unreachable!(),
    })
}

fn _attribute_path(
    attribute_path: &AttributePath,
    lexemes: &[Rc<Lexeme>],
    index: &mut usize,
) -> Box<CST> {
    Box::new(CST::AttributePath {
        parts: attribute_path
            .parts
            .iter()
            .enumerate()
            .map(|(part_index, part)| {
                if part_index + 1 == attribute_path.parts.len() {
                    AttributePathPart {
                        part: Box::new(_part(part, lexemes, index)),
                        part_trivia: Vec::new(),
                        dot: None,
                    }
                } else {
                    AttributePathPart {
                        part: Box::new(_part(part, lexemes, index)),
                        part_trivia: _trivia(lexemes, index),
                        dot: Some(AttributePathDot {
                            dot: _lexeme(lexemes, index),
                            dot_trivia: _trivia(lexemes, index),
                        }),
                    }
                }
            })
            .collect(),
    })
}

fn _binding(
    binding: &ASTBinding,
    lexemes: &[Rc<Lexeme>],
    index: &mut usize,
) -> CST {
    match binding {
        ASTBinding::Binding { from, to } => {
            CST::Binding {
                from: _attribute_path(from, lexemes, index),
                from_trivia: _trivia(lexemes, index),
                equal: _lexeme(lexemes, index),
                equal_trivia: _trivia(lexemes, index),
                to: _ast(to, lexemes, index),
                to_trivia: _trivia(lexemes, index),
                semicolon: _lexeme(lexemes, index),
            }
        },
        ASTBinding::Inherit { from, attributes, .. } => {
            match from {
                Some(from) => {
                    CST::InheritFrom {
                        inherit: _lexeme(lexemes, index),
                        inherit_trivia: _trivia(lexemes, index),
                        from: Box::new(CST::Parentheses {
                            open: _lexeme(lexemes, index),
                            open_trivia: _trivia(lexemes, index),
                            expression: _ast(&*from, lexemes, index),
                            expression_trivia: _trivia(lexemes, index),
                            close: _lexeme(lexemes, index),
                        }),
                        from_trivia: _trivia(lexemes, index),
                        attributes: attributes
                            .iter()
                            .map(|_| {
                                InheritAttribute {
                                    attribute: _lexeme(lexemes, index),
                                    attribute_trivia: _trivia(lexemes, index),
                                }
                            })
                            .collect(),
                        semicolon: _lexeme(lexemes, index),
                    }
                },
                None => {
                    CST::Inherit {
                        inherit: _lexeme(lexemes, index),
                        inherit_trivia: _trivia(lexemes, index),
                        attributes: attributes
                            .iter()
                            .map(|_| {
                                InheritAttribute {
                                    attribute: _lexeme(lexemes, index),
                                    attribute_trivia: _trivia(lexemes, index),
                                }
                            })
                            .collect(),
                        semicolon: _lexeme(lexemes, index),
                    }
                },
            }
        },
    }
}

fn _comma(
    lexemes: &[Rc<Lexeme>],
    index: &mut usize,
) -> Option<FunctionDestructuredArgumentComma> {
    if lexemes[*index..]
        .iter()
        .filter(|l| l.kind != "WS")
        .filter(|l| l.kind != "COMMENT")
        .take_while(|l| l.kind == ",")
        .next()
        .is_some()
    {
        Some(FunctionDestructuredArgumentComma {
            comma: _lexeme(lexemes, index),
            comma_trivia: _trivia(lexemes, index),
        })
    } else {
        None
    }
}

fn _lexeme(lexemes: &[Rc<Lexeme>], index: &mut usize) -> Rc<Lexeme> {
    let lexeme = lexemes[*index].clone();
    *index += 1;

    lexeme
}

fn _part(part: &Part, lexemes: &[Rc<Lexeme>], index: &mut usize) -> CST {
    match part {
        Part::Expression { ast } => *_ast(ast, lexemes, index),
        Part::Interpolation { expression } => {
            CST::PartInterpolation {
                open: _lexeme(lexemes, index),
                open_trivia: _trivia(lexemes, index),
                expression: _ast(&*expression, lexemes, index),
                expression_trivia: _trivia(lexemes, index),
                close: _lexeme(lexemes, index),
            }
        },
        Part::Raw { .. } => CST::PartRaw { lexeme: _lexeme(lexemes, index) },
    }
}

fn _trivia(lexemes: &[Rc<Lexeme>], index: &mut usize) -> Vec<Rc<Lexeme>> {
    let mut trivia = Vec::new();

    while *index < lexemes.len()
        && (lexemes[*index].kind == "WS" || lexemes[*index].kind == "COMMENT")
    {
        trivia.push(lexemes[*index].clone());
        *index += 1;
    }

    trivia
}
