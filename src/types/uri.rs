// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_str;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `https://example.com` (deprecated).
pub struct Uri {
    pub uri: Box<str>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for Uri {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::Uri { uri, span } = own(ptr);

        Self { uri: own_str(uri), span: Box::new(crate::Span::from(span)) }
    }
}
