// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `function argument[0] argument[1] ...`.
pub struct FunctionApplication {
    pub function: Box<crate::Expression>,
    pub arguments: Box<[crate::Expression]>,
}

impl std::convert::From<*mut crate::ffi::any> for FunctionApplication {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::FunctionApplication { function, arguments } = own(ptr);

        Self {
            function: Box::new(crate::Expression::from(function)),
            arguments: own_ll::<crate::ffi::Expression, crate::Expression>(
                arguments,
            ),
        }
    }
}
