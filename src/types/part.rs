// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_str;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `${expression}`.
pub struct PartExpression {
    pub expression: Box<crate::Expression>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `"${expression}"`.
pub struct PartInterpolation {
    pub expression: Box<crate::Expression>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `"content"`.
pub struct PartRaw {
    pub content: Box<str>,
    pub span: Box<crate::Span>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `Expression`, `Interpolation`, or `Raw`.
pub enum Part {
    Expression(PartExpression),
    Interpolation(PartInterpolation),
    Raw(PartRaw),
}

impl std::convert::From<*mut crate::ffi::Part> for Part {
    fn from(part: *mut crate::ffi::Part) -> Self {
        let crate::ffi::Part { kind, ptr } = own(part);

        match kind {
            crate::ffi::PartKind_PartKindExpression => {
                let expression: crate::ffi::Expression = own(ptr);

                Self::Expression(PartExpression {
                    expression: Box::new(crate::Expression::from(expression)),
                })
            },
            crate::ffi::PartKind_PartKindInterpolation => {
                let expression: crate::ffi::Expression = own(ptr);

                Self::Interpolation(PartInterpolation {
                    expression: Box::new(crate::Expression::from(expression)),
                })
            },
            crate::ffi::PartKind_PartKindRaw => {
                let crate::ffi::PartRaw { content, span } = own(ptr);
                let crate::ffi::UtilString { content, should_unescape } =
                    own(content);
                let content = own_str(content);

                Self::Raw(PartRaw {
                    content: if should_unescape {
                        unescape(&content)
                    } else {
                        content
                    },
                    span: Box::new(crate::Span::from(span)),
                })
            },
            _ => unreachable!(),
        }
    }
}

fn unescape(content: &str) -> Box<str> {
    let mut input_chars = content.chars().peekable();
    let mut output = String::new();

    loop {
        let input_char = input_chars.next();

        if input_char.is_none() {
            break;
        }

        let mut input_char = input_char.unwrap();

        match input_char {
            '\\' => {
                input_char = input_chars.next().unwrap();

                if input_char == 'n' {
                    output.push('\n');
                } else if input_char == 'r' {
                    output.push('\r');
                } else if input_char == 't' {
                    output.push('\t');
                } else {
                    output.push(input_char);
                }
            },
            '\r' => {
                output.push('\n');
                input_chars.next_if(|s| *s == '\n');
            },
            c => {
                output.push(c);
            },
        }
    }

    output.into_boxed_str()
}
