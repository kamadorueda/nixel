// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `expression.attribute_path`.
pub struct PropertyAccess {
    pub expression: Box<crate::Expression>,
    pub attribute_path: Box<[crate::Part]>,
    pub default: Option<Box<crate::Expression>>,
}

impl std::convert::From<*mut crate::ffi::any> for PropertyAccess {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::PropertyAccess { expression, attribute_path, default_ } =
            own(ptr);

        Self {
            expression: Box::new(crate::Expression::from(expression)),
            attribute_path: own_ll::<crate::ffi::Part, crate::Part>(
                attribute_path,
            ),
            default: if default_.is_null() {
                None
            } else {
                Some(Box::new(crate::Expression::from(default_)))
            },
        }
    }
}
