// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `let bindings in target`.
pub struct LetIn {
    pub bindings: Box<[crate::Binding]>,
    pub target: Box<crate::Expression>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for LetIn {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::LetIn { bindings, target, span } = own(ptr);

        Self {
            bindings: own_ll::<crate::ffi::Binding, crate::Binding>(bindings),
            target: Box::new(crate::Expression::from(target)),
            span: Box::new(crate::Span::from(span)),
        }
    }
}
