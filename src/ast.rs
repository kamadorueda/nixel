// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use std::collections::LinkedList;
use std::rc::Rc;

use santiago::lexer::Lexeme;
use santiago::lexer::Position;

/// Main type of an Abstract Syntax Tree.
#[derive(Clone, Debug, PartialEq)]
pub enum AST {
    Assert {
        expression: Box<AST>,
        target:     Box<AST>,
        position:   Position,
    },
    BinaryOperation {
        operator: BinaryOperator,
        operands: Vec<AST>,
        position: Position,
    },
    Float {
        value:    f64,
        position: Position,
    },
    Function {
        argument:   FunctionArgument,
        definition: Box<AST>,
        position:   Position,
    },
    FunctionApplication {
        function:  Box<AST>,
        arguments: LinkedList<AST>,
    },
    HasProperty {
        expression:     Box<AST>,
        attribute_path: AttributePath,
        position:       Position,
    },
    IfThenElse {
        predicate: Box<AST>,
        then:      Box<AST>,
        else_:     Box<AST>,
        position:  Position,
    },
    Int {
        value:    i64,
        position: Position,
    },
    LetIn {
        bindings: LinkedList<Binding>,
        target:   Box<AST>,
        position: Position,
    },
    List {
        elements: LinkedList<AST>,
        position: Position,
    },
    Map {
        bindings:  LinkedList<Binding>,
        recursive: bool,
        position:  Position,
    },
    Parentheses {
        expression: Box<AST>,
        position:   Position,
    },
    Path {
        parts:    LinkedList<Part>,
        position: Position,
    },
    PropertyAccess {
        expression:     Box<AST>,
        attribute_path: AttributePath,
        default:        Option<Box<AST>>,
    },
    SearchNixPath {
        path:     String,
        position: Position,
    },
    String {
        parts:    LinkedList<Part>,
        position: Position,
    },
    UnaryOperation {
        operator: UnaryOperator,
        operand:  Box<AST>,
        position: Position,
    },
    Uri {
        uri:      String,
        position: Position,
    },
    Variable {
        identifier: String,
        position:   Position,
    },
    With {
        expression: Box<AST>,
        target:     Box<AST>,
        position:   Position,
    },

    // Temporary containers
    #[doc(hidden)]
    __Attributes(LinkedList<Part>),
    #[doc(hidden)]
    __AttributePath(AttributePath),
    #[doc(hidden)]
    __Bindings(LinkedList<Binding>),
    #[doc(hidden)]
    __DestructuredArgument(DestructuredArgument),
    #[doc(hidden)]
    __DestructuredArguments(DestructuredArguments),
    #[doc(hidden)]
    __Lexeme(Rc<Lexeme>),
    #[doc(hidden)]
    __Part(Part),
    #[doc(hidden)]
    __Parts(LinkedList<Part>),
}

impl AST {
    pub fn position(&self) -> Position {
        match &self {
            AST::Assert { position, .. } => position.clone(),
            AST::BinaryOperation { position, .. } => position.clone(),
            AST::Float { position, .. } => position.clone(),
            AST::Function { position, .. } => position.clone(),
            AST::FunctionApplication { function, .. } => function.position(),
            AST::HasProperty { position, .. } => position.clone(),
            AST::IfThenElse { position, .. } => position.clone(),
            AST::Int { position, .. } => position.clone(),
            AST::LetIn { position, .. } => position.clone(),
            AST::List { position, .. } => position.clone(),
            AST::Map { position, .. } => position.clone(),
            AST::Parentheses { position, .. } => position.clone(),
            AST::Path { position, .. } => position.clone(),
            AST::PropertyAccess { expression, .. } => expression.position(),
            AST::SearchNixPath { position, .. } => position.clone(),
            AST::String { position, .. } => position.clone(),
            AST::UnaryOperation { position, .. } => position.clone(),
            AST::Uri { position, .. } => position.clone(),
            AST::Variable { position, .. } => position.clone(),
            AST::With { position, .. } => position.clone(),
            AST::__Attributes(_) => unreachable!(),
            AST::__AttributePath(_) => unreachable!(),
            AST::__Bindings(_) => unreachable!(),
            AST::__DestructuredArgument { .. } => unreachable!(),
            AST::__DestructuredArguments { .. } => unreachable!(),
            AST::__Lexeme(_) => unreachable!(),
            AST::__Part(_) => unreachable!(),
            AST::__Parts(_) => unreachable!(),
        }
    }
}

#[derive(Clone, Debug, PartialEq)]
pub enum Part {
    Raw { content: String, position: Position },
    Expression { expression: Box<AST> },
}

#[derive(Clone, Debug, PartialEq)]
pub struct AttributePath {
    pub parts: LinkedList<Part>,
}

#[derive(Clone, Debug, PartialEq)]
pub enum Binding {
    Binding { from: AttributePath, to: Box<AST> },
    Inherit { from: Option<Box<AST>>, attributes: LinkedList<Part> },
}

#[derive(Clone, Debug, PartialEq)]
pub enum BinaryOperator {
    Addition,
    Concatenation,
    Division,
    EqualTo,
    GreaterThan,
    GreaterThanOrEqualTo,
    Implication,
    LessThan,
    LessThanOrEqualTo,
    LogicalAnd,
    LogicalOr,
    Multiplication,
    NotEqualTo,
    Subtraction,
    Update,
}

#[derive(Clone, Debug, PartialEq)]
pub enum DestructuredIdentifier {
    None,
    LeftAt(String),
    RightAt(String),
}

#[derive(Clone, Debug, PartialEq)]
pub struct DestructuredArgument {
    pub identifier: String,
    pub default:    Option<Box<AST>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct DestructuredArguments {
    pub arguments: LinkedList<DestructuredArgument>,
    pub ellipsis:  bool,
}

#[derive(Clone, Debug, PartialEq)]
pub enum FunctionArgument {
    Destructured {
        identifier: DestructuredIdentifier,
        arguments:  LinkedList<DestructuredArgument>,
        ellipsis:   bool,
    },
    Simple {
        identifier: String,
    },
}

#[derive(Clone, Debug, PartialEq)]
pub enum UnaryOperator {
    Not,
    Negate,
}
