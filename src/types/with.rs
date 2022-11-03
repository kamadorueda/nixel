// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `with expression; target`.
pub struct With {
    pub expression: Box<crate::Expression>,
    pub target: Box<crate::Expression>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for With {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::With { expression, target, span } = own(ptr);

        Self {
            expression: Box::new(crate::Expression::from(expression)),
            target: Box::new(crate::Expression::from(target)),
            span: Box::new(crate::Span::from(span)),
        }
    }
}
