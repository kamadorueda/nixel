// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `Not` and `Negate`.
pub enum UnaryOperator {
    Not,
    Negate,
}

impl std::convert::From<crate::ffi::UnaryOperator> for UnaryOperator {
    fn from(unary_operator: crate::ffi::UnaryOperator) -> Self {
        match unary_operator {
            crate::ffi::UnaryOperator_UnaryOperatorNot => UnaryOperator::Not,
            crate::ffi::UnaryOperator_UnaryOperatorNegate => {
                UnaryOperator::Negate
            },
            _ => unreachable!(),
        }
    }
}
