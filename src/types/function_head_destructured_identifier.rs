// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own_str;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `None`, `LeftAt` (`identifier @`), `RightAt` (`@ identifier`)
pub enum FunctionHeadDestructuredIdentifier {
    None,
    LeftAt(Box<str>),
    RightAt(Box<str>),
}

impl
    std::convert::From<(
        crate::ffi::FunctionHeadDestructuredIdentifier,
        *mut crate::ffi::Str,
    )> for FunctionHeadDestructuredIdentifier
{
    fn from(
        (kind, ptr): (
            crate::ffi::FunctionHeadDestructuredIdentifier,
            *mut crate::ffi::Str,
        ),
    ) -> Self {
        match kind {
            crate::ffi::FunctionHeadDestructuredIdentifier_FunctionHeadDestructuredIdentifierNone => {
                FunctionHeadDestructuredIdentifier::None
            },
            crate::ffi::FunctionHeadDestructuredIdentifier_FunctionHeadDestructuredIdentifierLeftAt => {
                FunctionHeadDestructuredIdentifier::LeftAt(own_str(ptr))
            },
            crate::ffi::FunctionHeadDestructuredIdentifier_FunctionHeadDestructuredIdentifierRightAt => {
                FunctionHeadDestructuredIdentifier::RightAt(own_str(ptr))
            },
            _ => unreachable!(),
        }
    }
}
