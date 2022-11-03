// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `"parts"`.
pub struct String_ {
    pub parts: Box<[crate::Part]>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for String_ {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::String_ { parts, span } = own(ptr);

        Self {
            parts: own_ll::<crate::ffi::Part, crate::Part>(parts),
            span: Box::new(crate::Span::from(span)),
        }
    }
}
