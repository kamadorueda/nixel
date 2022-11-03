// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// (`rec`) `{ bindings }`.
pub struct Map {
    pub recursive: bool,
    pub bindings: Box<[crate::Binding]>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for Map {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::Map { bindings, recursive, span } = own(ptr);

        Self {
            bindings: own_ll::<crate::ffi::Binding, crate::Binding>(bindings),
            recursive,
            span: Box::new(crate::Span::from(span)),
        }
    }
}
