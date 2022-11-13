// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_str;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// An [Error], with message and positions.
pub struct Error {
    pub message: Box<str>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for Error {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::Error { message, span } = own(ptr);

        Self {
            message: own_str(message),
            span: Box::new(crate::Span::from(span)),
        }
    }
}
