// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `head: body`.
pub struct Function {
    pub head: crate::FunctionHead,
    pub body: Box<crate::Expression>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for Function {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::Function { head_kind, head_ptr, body, span } = own(ptr);

        Self {
            head: crate::FunctionHead::from((head_kind, head_ptr)),
            body: Box::new(crate::Expression::from(body)),
            span: Box::new(crate::Span::from(span)),
        }
    }
}
