// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `Assert`, `BinaryOperation`, ...
pub enum Expression {
    Assert(crate::Assert),
    BinaryOperation(crate::BinaryOperation),
    Error(crate::Error),
    Float(crate::Float),
    Function(crate::Function),
    FunctionApplication(crate::FunctionApplication),
    HasAttribute(crate::HasAttribute),
    Identifier(crate::Identifier),
    IfThenElse(crate::IfThenElse),
    IndentedString(crate::IndentedString),
    Integer(crate::Integer),
    LetIn(crate::LetIn),
    List(crate::List),
    Map(crate::Map),
    Path(crate::Path),
    PropertyAccess(crate::PropertyAccess),
    SearchNixPath(crate::SearchNixPath),
    String(crate::String_),
    UnaryOperation(crate::UnaryOperation),
    Uri(crate::Uri),
    With(crate::With),
}

impl std::convert::From<*mut crate::ffi::Expression> for Expression {
    fn from(expression: *mut crate::ffi::Expression) -> Self {
        let expression: crate::ffi::Expression = own(expression);

        Expression::from(expression)
    }
}

impl std::convert::From<crate::ffi::Expression> for Expression {
    fn from(expression: crate::ffi::Expression) -> Self {
        let crate::ffi::Expression { kind, ptr } = expression;

        match kind {
            crate::ffi::ExpressionKind_ExpressionKindAssert => {
                Expression::Assert(crate::Assert::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindBinaryOperation => {
                Expression::BinaryOperation(crate::BinaryOperation::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindError => {
                Expression::Error(crate::Error::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindFloat => {
                Expression::Float(crate::Float::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindFunction => {
                Expression::Function(crate::Function::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindFunctionApplication => {
                Expression::FunctionApplication(
                    crate::FunctionApplication::from(ptr),
                )
            },
            crate::ffi::ExpressionKind_ExpressionKindHasAttribute => {
                Expression::HasAttribute(crate::HasAttribute::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindIdentifier => {
                Expression::Identifier(crate::Identifier::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindIfThenElse => {
                Expression::IfThenElse(crate::IfThenElse::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindIndentedString => {
                Expression::IndentedString(crate::IndentedString::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindInteger => {
                Expression::Integer(crate::Integer::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindLetIn => {
                Expression::LetIn(crate::LetIn::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindList => {
                Expression::List(crate::List::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindMap => {
                Expression::Map(crate::Map::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindPath => {
                Expression::Path(crate::Path::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindPropertyAccess => {
                Expression::PropertyAccess(crate::PropertyAccess::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindSearchNixPath => {
                Expression::SearchNixPath(crate::SearchNixPath::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindString_ => {
                Expression::String(crate::String_::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindUnaryOperation => {
                Expression::UnaryOperation(crate::UnaryOperation::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindUri => {
                Expression::Uri(crate::Uri::from(ptr))
            },
            crate::ffi::ExpressionKind_ExpressionKindWith => {
                Expression::With(crate::With::from(ptr))
            },
            _ => unreachable!(),
        }
    }
}
