// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

use santiago::lexer::Lexeme;
use santiago::lexer::Position;
use std::collections::LinkedList;
use std::rc::Rc;

#[derive(Clone, Debug, PartialEq)]
pub enum AST {
    Assert {
        expression: Box<AST>,
        target:     Box<AST>,
    },
    BinaryOperation {
        operator: BinaryOperator,
        operands: Vec<AST>,
    },
    Float {
        value:    f64,
        position: Position,
    },
    Function {
        argument:   Option<String>,
        arguments:  FunctionArguments,
        definition: Box<AST>,
    },
    FunctionApplication {
        function:  Box<AST>,
        arguments: LinkedList<AST>,
    },
    IfThenElse {
        predicate: Box<AST>,
        then:      Box<AST>,
        else_:     Box<AST>,
    },
    Int {
        value:    isize,
        position: Position,
    },
    LetIn {
        bindings: LinkedList<Bind>,
        target:   Box<AST>,
    },
    List {
        elements: LinkedList<AST>,
    },
    Map {
        bindings:  LinkedList<Bind>,
        recursive: bool,
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
    },
    Uri(Rc<Lexeme>),
    Variable {
        identifier: String,
        position:   Position,
    },
    With {
        expression: Box<AST>,
        target:     Box<AST>,
    },

    // Temporary containers
    __Attribute(Attribute),
    __Attributes(LinkedList<Attribute>),
    __AttributePath(AttributePath),
    __Bindings(LinkedList<Bind>),
    __FunctionArgument(FunctionArgument),
    __FunctionArguments(FunctionArguments),
    __StringParts(LinkedList<StringPart>),
    __Lexeme(Rc<Lexeme>),
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
pub enum Bind {
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
    HasAttribute,
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
    Raw { content: String, position: Position },
    Expression { expression: Box<AST> },
}

#[derive(Clone, Debug, PartialEq)]
pub enum UnaryOperator {
    Not,
    Negate,
}
