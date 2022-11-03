// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `operator operand`.
pub struct UnaryOperation {
    pub operator: crate::UnaryOperator,
    pub operand: Box<crate::Expression>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for UnaryOperation {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::UnaryOperation { operator_, operand, span } = own(ptr);

        Self {
            operator: crate::UnaryOperator::from(operator_),
            operand: Box::new(crate::Expression::from(operand)),
            span: Box::new(crate::Span::from(span)),
        }
    }
}
