// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_str;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `1.23`.
pub struct Float {
    pub value: Box<str>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for Float {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::Float { value, span } = own(ptr);

        Self { value: own_str(value), span: Box::new(crate::Span::from(span)) }
    }
}
