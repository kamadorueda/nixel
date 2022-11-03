// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_str;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `<nixpkgs>`.
pub struct SearchNixPath {
    pub path: Box<str>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for SearchNixPath {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::SearchNixPath { path, span } = own(ptr);

        Self { path: own_str(path), span: Box::new(crate::Span::from(span)) }
    }
}
