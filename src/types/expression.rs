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

impl Expression {
    pub fn span(&self) -> crate::Span {
        match self {
            Self::Assert(assert) => assert.span.as_ref().clone(),
            Self::BinaryOperation(binary_operation) => binary_operation.span(),
            Self::Error(error) => error.span.as_ref().clone(),
            Self::Float(float) => float.span.as_ref().clone(),
            Self::Function(function) => function.span.as_ref().clone(),
            Self::FunctionApplication(function_application) => {
                function_application.span()
            },
            Self::HasAttribute(has_attribute) => has_attribute.span(),
            Self::Identifier(identifier) => identifier.span.as_ref().clone(),
            Self::IfThenElse(if_then_else) => {
                if_then_else.span.as_ref().clone()
            },
            Self::IndentedString(indented_string) => {
                indented_string.span.as_ref().clone()
            },
            Self::Integer(integer) => integer.span.as_ref().clone(),
            Self::LetIn(let_in) => let_in.span.as_ref().clone(),
            Self::List(list) => list.span.as_ref().clone(),
            Self::Map(map) => map.span.as_ref().clone(),
            Self::Path(path) => path.span.as_ref().clone(),
            Self::PropertyAccess(property_access) => property_access.span(),
            Self::SearchNixPath(search_nix_path) => {
                search_nix_path.span.as_ref().clone()
            },
            Self::String(string) => string.span.as_ref().clone(),
            Self::UnaryOperation(unary_operation) => {
                unary_operation.span.as_ref().clone()
            },
            Self::Uri(uri) => uri.span.as_ref().clone(),
            Self::With(with) => with.span.as_ref().clone(),
        }
    }

    pub fn start(&self) -> crate::Position {
        match self {
            Self::Assert(assert) => assert.span.start.as_ref().clone(),
            Self::BinaryOperation(binary_operation) => binary_operation.start(),
            Self::Error(error) => error.span.start.as_ref().clone(),
            Self::Float(float) => float.span.start.as_ref().clone(),
            Self::Function(function) => function.span.start.as_ref().clone(),
            Self::FunctionApplication(function_application) => {
                function_application.start()
            },
            Self::HasAttribute(has_attribute) => has_attribute.start(),
            Self::Identifier(identifier) => {
                identifier.span.start.as_ref().clone()
            },
            Self::IfThenElse(if_then_else) => {
                if_then_else.span.start.as_ref().clone()
            },
            Self::IndentedString(indented_string) => {
                indented_string.span.start.as_ref().clone()
            },
            Self::Integer(integer) => integer.span.start.as_ref().clone(),
            Self::LetIn(let_in) => let_in.span.start.as_ref().clone(),
            Self::List(list) => list.span.start.as_ref().clone(),
            Self::Map(map) => map.span.start.as_ref().clone(),
            Self::Path(path) => path.span.start.as_ref().clone(),
            Self::PropertyAccess(property_access) => property_access.start(),
            Self::SearchNixPath(search_nix_path) => {
                search_nix_path.span.start.as_ref().clone()
            },
            Self::String(string) => string.span.start.as_ref().clone(),
            Self::UnaryOperation(unary_operation) => {
                unary_operation.span.start.as_ref().clone()
            },
            Self::Uri(uri) => uri.span.start.as_ref().clone(),
            Self::With(with) => with.span.start.as_ref().clone(),
        }
    }

    pub fn end(&self) -> crate::Position {
        match self {
            Self::Assert(assert) => assert.span.end.as_ref().clone(),
            Self::BinaryOperation(binary_operation) => binary_operation.end(),
            Self::Error(error) => error.span.end.as_ref().clone(),
            Self::Float(float) => float.span.end.as_ref().clone(),
            Self::Function(function) => function.span.end.as_ref().clone(),
            Self::FunctionApplication(function_application) => {
                function_application.end()
            },
            Self::HasAttribute(has_attribute) => has_attribute.end(),
            Self::Identifier(identifier) => {
                identifier.span.end.as_ref().clone()
            },
            Self::IfThenElse(if_then_else) => {
                if_then_else.span.end.as_ref().clone()
            },
            Self::IndentedString(indented_string) => {
                indented_string.span.end.as_ref().clone()
            },
            Self::Integer(integer) => integer.span.end.as_ref().clone(),
            Self::LetIn(let_in) => let_in.span.end.as_ref().clone(),
            Self::List(list) => list.span.end.as_ref().clone(),
            Self::Map(map) => map.span.end.as_ref().clone(),
            Self::Path(path) => path.span.end.as_ref().clone(),
            Self::PropertyAccess(property_access) => property_access.end(),
            Self::SearchNixPath(search_nix_path) => {
                search_nix_path.span.end.as_ref().clone()
            },
            Self::String(string) => string.span.end.as_ref().clone(),
            Self::UnaryOperation(unary_operation) => {
                unary_operation.span.end.as_ref().clone()
            },
            Self::Uri(uri) => uri.span.end.as_ref().clone(),
            Self::With(with) => with.span.end.as_ref().clone(),
        }
    }
}
