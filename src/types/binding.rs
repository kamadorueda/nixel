// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `inherit from attributes[0] attributes[1] ...;`
pub struct BindingInherit {
    pub from: Option<Box<crate::Expression>>,
    pub attributes: Box<[crate::Part]>,
    pub span: Box<crate::Span>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `from = to;`.
pub struct BindingKeyValue {
    pub from: Box<[crate::Part]>,
    pub to: Box<crate::Expression>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `KeyValue` and `Inherit`.
pub enum Binding {
    KeyValue(BindingKeyValue),
    Inherit(BindingInherit),
}

impl std::convert::From<*mut crate::ffi::Binding> for Binding {
    fn from(binding: *mut crate::ffi::Binding) -> Self {
        let crate::ffi::Binding { kind, ptr } = own(binding);

        match kind {
            crate::ffi::BindingKind_BindingKindBinding => {
                let crate::ffi::BindingKeyValue { from, to } = own(ptr);

                Self::KeyValue(BindingKeyValue {
                    from: own_ll::<crate::ffi::Part, crate::Part>(from),
                    to: Box::new(crate::Expression::from(to)),
                })
            },
            crate::ffi::BindingKind_BindingKindInherit => {
                let crate::ffi::BindingInherit { from, attributes, span } =
                    own(ptr);

                Self::Inherit(BindingInherit {
                    from: if from.is_null() {
                        None
                    } else {
                        Some(Box::new(crate::Expression::from(from)))
                    },
                    attributes: own_ll::<crate::ffi::Part, crate::Part>(
                        attributes,
                    ),
                    span: Box::new(crate::Span::from(span)),
                })
            },
            _ => unreachable!(),
        }
    }
}
