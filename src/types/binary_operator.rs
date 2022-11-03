// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `Addition`, `Concatenation`, ...
pub enum BinaryOperator {
    Addition,
    Concatenation,
    EqualTo,
    GreaterThan,
    GreaterThanOrEqualTo,
    Division,
    Implication,
    LessThan,
    LessThanOrEqualTo,
    LogicalAnd,
    LogicalOr,
    Multiplication,
    NotEqualTo,
    Subtraction,
    Update,
}

impl std::convert::From<crate::ffi::BinaryOperator> for BinaryOperator {
    fn from(binary_operator: crate::ffi::BinaryOperator) -> Self {
        match binary_operator {
            crate::ffi::BinaryOperator_BinaryOperatorAddition => {
                BinaryOperator::Addition
            },
            crate::ffi::BinaryOperator_BinaryOperatorConcatenation => {
                BinaryOperator::Concatenation
            },
            crate::ffi::BinaryOperator_BinaryOperatorEqualTo => {
                BinaryOperator::EqualTo
            },
            crate::ffi::BinaryOperator_BinaryOperatorGreaterThan => {
                BinaryOperator::GreaterThan
            },
            crate::ffi::BinaryOperator_BinaryOperatorGreaterThanOrEqualTo => {
                BinaryOperator::GreaterThanOrEqualTo
            },
            crate::ffi::BinaryOperator_BinaryOperatorDivision => {
                BinaryOperator::Division
            },
            crate::ffi::BinaryOperator_BinaryOperatorImplication => {
                BinaryOperator::Implication
            },
            crate::ffi::BinaryOperator_BinaryOperatorLessThan => {
                BinaryOperator::LessThan
            },
            crate::ffi::BinaryOperator_BinaryOperatorLessThanOrEqualTo => {
                BinaryOperator::LessThanOrEqualTo
            },
            crate::ffi::BinaryOperator_BinaryOperatorLogicalAnd => {
                BinaryOperator::LogicalAnd
            },
            crate::ffi::BinaryOperator_BinaryOperatorLogicalOr => {
                BinaryOperator::LogicalOr
            },
            crate::ffi::BinaryOperator_BinaryOperatorMultiplication => {
                BinaryOperator::Multiplication
            },
            crate::ffi::BinaryOperator_BinaryOperatorNotEqualTo => {
                BinaryOperator::NotEqualTo
            },
            crate::ffi::BinaryOperator_BinaryOperatorSubtraction => {
                BinaryOperator::Subtraction
            },
            crate::ffi::BinaryOperator_BinaryOperatorUpdate => {
                BinaryOperator::Update
            },
            _ => unreachable!(),
        }
    }
}
