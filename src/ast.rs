// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use std::collections::LinkedList;
use std::rc::Rc;

use santiago::lexer::Lexeme;
use santiago::lexer::Position;

/// Main type of an Abstract Syntax Tree.
#[allow(clippy::manual_non_exhaustive)]
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
        argument:   Option<String>,
        arguments:  FunctionArguments,
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
    Path {
        parts:    LinkedList<StringPart>,
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
        parts:    LinkedList<StringPart>,
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
    __,
    #[doc(hidden)]
    __Attribute(Attribute),
    #[doc(hidden)]
    __Attributes(LinkedList<Attribute>),
    #[doc(hidden)]
    __AttributePath(AttributePath),
    #[doc(hidden)]
    __Bindings(LinkedList<Binding>),
    #[doc(hidden)]
    __FunctionArgument(FunctionArgument),
    #[doc(hidden)]
    __FunctionArguments(FunctionArguments),
    #[doc(hidden)]
    __StringParts(LinkedList<StringPart>),
    #[doc(hidden)]
    __Lexeme(Rc<Lexeme>),
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
            AST::Path { position, .. } => position.clone(),
            AST::PropertyAccess { expression, .. } => expression.position(),
            AST::SearchNixPath { position, .. } => position.clone(),
            AST::String { position, .. } => position.clone(),
            AST::UnaryOperation { position, .. } => position.clone(),
            AST::Uri { position, .. } => position.clone(),
            AST::Variable { position, .. } => position.clone(),
            AST::With { position, .. } => position.clone(),
            AST::__ => unreachable!(),
            AST::__Attribute(_) => unreachable!(),
            AST::__Attributes(_) => unreachable!(),
            AST::__AttributePath(_) => unreachable!(),
            AST::__Bindings(_) => unreachable!(),
            AST::__FunctionArgument(_) => unreachable!(),
            AST::__FunctionArguments(_) => unreachable!(),
            AST::__StringParts(_) => unreachable!(),
            AST::__Lexeme(_) => unreachable!(),
        }
    }
}

#[derive(Clone, Debug, PartialEq)]
pub enum Attribute {
    Raw { content: String, position: Position },
    Expression { expression: Box<AST> },
}

#[derive(Clone, Debug, PartialEq)]
pub struct AttributePath {
    pub attributes: LinkedList<Attribute>,
}

#[derive(Clone, Debug, PartialEq)]
pub enum Binding {
    KeyValue(AttributePath, Box<AST>),
    Inherit(Option<Box<AST>>, LinkedList<Attribute>),
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
pub struct FunctionArgument {
    pub identifier: String,
    pub default:    Option<Box<AST>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct FunctionArguments {
    pub arguments: LinkedList<FunctionArgument>,
    pub ellipsis:  bool,
}

#[derive(Clone, Debug, PartialEq)]
pub enum StringPart {
    Raw { content: String },
    Expression { expression: Box<AST> },
}

#[derive(Clone, Debug, PartialEq)]
pub enum UnaryOperator {
    Not,
    Negate,
}
