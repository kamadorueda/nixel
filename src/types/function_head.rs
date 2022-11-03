// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;
use crate::mem::own_str;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `identifier`.
pub struct FunctionHeadSimple {
    pub identifier: Box<str>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `{arguments, ...} @ identifier`.
pub struct FunctionHeadDestructured {
    pub ellipsis: bool,
    pub identifier: crate::FunctionHeadDestructuredIdentifier,
    pub arguments: Box<[crate::FunctionHeadDestructuredArgument]>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `Destructured` (`a @ {b, c, ...}`) or `Simple` (`arg:`).
pub enum FunctionHead {
    Destructured(FunctionHeadDestructured),
    Simple(FunctionHeadSimple),
}

impl std::convert::From<(crate::ffi::FunctionHeadKind, *mut crate::ffi::any)>
    for FunctionHead
{
    fn from(
        (kind, ptr): (crate::ffi::FunctionHeadKind, *mut crate::ffi::any),
    ) -> Self {
        match kind {
            crate::ffi::FunctionHeadKind_FunctionHeadKindDestructured => {
                let crate::ffi::FunctionHeadDestructured {
                    identifier_kind,
                    identifier_ptr,
                    arguments,
                    ellipsis,
                } = own(ptr);

                let mut arguments = own_ll::<
                    crate::ffi::FunctionHeadDestructuredArgument,
                    crate::FunctionHeadDestructuredArgument,
                >(arguments);

                arguments.reverse();

                FunctionHead::Destructured(FunctionHeadDestructured {
                    identifier: crate::FunctionHeadDestructuredIdentifier::from(
                        (identifier_kind, identifier_ptr),
                    ),
                    arguments,
                    ellipsis,
                })
            },
            crate::ffi::FunctionHeadKind_FunctionHeadKindSimple => {
                let crate::ffi::FunctionHeadSimple { identifier } = own(ptr);

                FunctionHead::Simple(FunctionHeadSimple {
                    identifier: own_str(identifier),
                })
            },
            _ => unreachable!(),
        }
    }
}
