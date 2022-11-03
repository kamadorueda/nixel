// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `if predicate then then else else_`.
pub struct IfThenElse {
    pub predicate: Box<crate::Expression>,
    pub then: Box<crate::Expression>,
    pub else_: Box<crate::Expression>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for IfThenElse {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::IfThenElse { predicate, then, else_, span } = own(ptr);

        Self {
            predicate: Box::new(crate::Expression::from(predicate)),
            then: Box::new(crate::Expression::from(then)),
            else_: Box::new(crate::Expression::from(else_)),
            span: Box::new(crate::Span::from(span)),
        }
    }
}
