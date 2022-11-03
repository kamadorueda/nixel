// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_str;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `identifier ? default`.
pub struct FunctionHeadDestructuredArgument {
    pub identifier: Box<str>,
    pub default: Option<Box<crate::Expression>>,
}

impl std::convert::From<*mut crate::ffi::FunctionHeadDestructuredArgument>
    for FunctionHeadDestructuredArgument
{
    fn from(
        argument: *mut crate::ffi::FunctionHeadDestructuredArgument,
    ) -> Self {
        let crate::ffi::FunctionHeadDestructuredArgument {
            identifier,
            default_,
        } = own(argument);

        FunctionHeadDestructuredArgument {
            identifier: own_str(identifier),
            default: if default_.is_null() {
                None
            } else {
                Some(Box::new(crate::Expression::from(default_)))
            },
        }
    }
}
