// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;

#[derive(Clone, Debug, Eq, Ord, PartialEq, PartialOrd)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// Line and column, starting at 1.
pub struct Position {
    pub line: usize,
    pub column: usize,
}

impl std::convert::From<*mut crate::ffi::Position> for Position {
    fn from(position: *mut crate::ffi::Position) -> Self {
        let position: crate::ffi::Position = own(position);

        Self::from(position)
    }
}

impl std::convert::From<crate::ffi::Position> for Position {
    fn from(position: crate::ffi::Position) -> Self {
        let crate::ffi::Position { line, column } = position;

        Self { line, column }
    }
}
