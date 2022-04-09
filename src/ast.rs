// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use santiago::lexer::Lexeme;
use santiago::lexer::Position;
use std::collections::LinkedList;
use std::rc::Rc;

/// Main type of an Abstract Syntax Tree.
#[derive(Debug, PartialEq)]
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
        value:    isize,
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
        parts: LinkedList<StringPart>,
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
        parts: LinkedList<StringPart>,
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

#[derive(Debug, PartialEq)]
pub enum Attribute {
    Raw { content: String, position: Position },
    Expression { expression: Box<AST> },
}

#[derive(Debug, PartialEq)]
pub struct AttributePath {
    pub attributes: LinkedList<Attribute>,
}

#[derive(Debug, PartialEq)]
pub enum Binding {
    KeyValue(AttributePath, Box<AST>),
    Inherit(Option<Box<AST>>, LinkedList<Attribute>),
}

#[derive(Debug, PartialEq)]
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

#[derive(Debug, PartialEq)]
pub struct FunctionArgument {
    pub identifier: String,
    pub default:    Option<Box<AST>>,
}

#[derive(Debug, PartialEq)]
pub struct FunctionArguments {
    pub arguments: LinkedList<FunctionArgument>,
    pub ellipsis:  bool,
}

#[derive(Debug, PartialEq)]
pub enum StringPart {
    Raw { content: String, position: Position },
    Expression { expression: Box<AST> },
}

#[derive(Debug, PartialEq)]
pub enum UnaryOperator {
    Not,
    Negate,
}
