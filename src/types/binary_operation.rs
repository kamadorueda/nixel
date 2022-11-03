// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `left operator right`.
pub struct BinaryOperation {
    pub left: Box<crate::Expression>,
    pub operator: crate::BinaryOperator,
    pub right: Box<crate::Expression>,
}

impl std::convert::From<*mut crate::ffi::any> for BinaryOperation {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::BinaryOperation { operator_: operator, left, right } =
            own(ptr);

        Self {
            operator: crate::BinaryOperator::from(operator),
            left: Box::new(crate::Expression::from(left)),
            right: Box::new(crate::Expression::from(right)),
        }
    }
}
