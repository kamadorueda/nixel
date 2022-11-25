// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;

#[derive(Clone, Debug, Default, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// Start and end position of an element.
pub struct Span {
    pub start: Box<crate::Position>,
    pub end: Box<crate::Position>,
}

impl std::convert::From<*mut crate::ffi::Span> for Span {
    fn from(span: *mut crate::ffi::Span) -> Self {
        let span: crate::ffi::Span = own(span);

        Self::from(span)
    }
}

impl std::convert::From<crate::ffi::Span> for Span {
    fn from(span: crate::ffi::Span) -> Self {
        let crate::ffi::Span { start, end } = span;

        Self {
            start: Box::new(crate::Position::from(start)),
            end: Box::new(crate::Position::from(end)),
        }
    }
}
