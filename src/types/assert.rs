// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `assert expression; target`.
pub struct Assert {
    pub expression: Box<crate::Expression>,
    pub target: Box<crate::Expression>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for Assert {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::Assert { expression, target, span } = own(ptr);

        Self {
            expression: Box::new(crate::Expression::from(expression)),
            target: Box::new(crate::Expression::from(target)),
            span: Box::new(crate::Span::from(span)),
        }
    }
}
