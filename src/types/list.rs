// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `[element[0] element[1] ...]`.
pub struct List {
    pub elements: Box<[crate::Expression]>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for List {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::List { elements, span } = own(ptr);

        Self {
            elements: own_ll::<crate::ffi::Expression, crate::Expression>(
                elements,
            ),
            span: Box::new(crate::Span::from(span)),
        }
    }
}
