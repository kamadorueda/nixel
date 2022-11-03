// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_str;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
pub struct TriviaBoundary {
    pub span: Box<crate::Span>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
pub struct TriviaComment {
    pub content: Box<str>,
    pub span: Box<crate::Span>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
pub struct TriviaMultilineComment {
    pub content: Box<str>,
    pub span: Box<crate::Span>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
pub struct TriviaWhitespace {
    pub content: Box<str>,
    pub span: Box<crate::Span>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `Comment`, `MultilineComment`, and `Whitespace`.
pub enum Trivia {
    #[doc(hidden)]
    Boundary(crate::TriviaBoundary),
    Comment(crate::TriviaComment),
    MultilineComment(crate::TriviaMultilineComment),
    Whitespace(crate::TriviaWhitespace),
}

impl std::convert::From<*mut crate::ffi::Trivia> for Trivia {
    fn from(trivia: *mut crate::ffi::Trivia) -> Self {
        let crate::ffi::Trivia { kind, ptr, span } = own(trivia);

        match kind {
            crate::ffi::TriviaKind_TriviaKindBoundary => {
                assert!(ptr.is_null());
                Self::Boundary(crate::TriviaBoundary {
                    span: Box::new(crate::Span::from(span)),
                })
            },
            crate::ffi::TriviaKind_TriviaKindComment => {
                Self::Comment(crate::TriviaComment {
                    content: own_str(ptr),
                    span: Box::new(crate::Span::from(span)),
                })
            },
            crate::ffi::TriviaKind_TriviaKindMultilineComment => {
                Self::MultilineComment(crate::TriviaMultilineComment {
                    content: own_str(ptr),
                    span: Box::new(crate::Span::from(span)),
                })
            },
            crate::ffi::TriviaKind_TriviaKindWhitespace => {
                Self::Whitespace(crate::TriviaWhitespace {
                    content: own_str(ptr),
                    span: Box::new(crate::Span::from(span)),
                })
            },
            _ => unreachable!(),
        }
    }
}
