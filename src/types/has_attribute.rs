// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `expression ? attribute_path`.
pub struct HasAttribute {
    pub expression: Box<crate::Expression>,
    pub attribute_path: Box<[crate::Part]>,
}

impl HasAttribute {
    pub fn span(&self) -> crate::Span {
        crate::Span { start: self.start().into(), end: self.end().into() }
    }

    pub fn start(&self) -> crate::Position {
        self.expression.start()
    }

    pub fn end(&self) -> crate::Position {
        self.attribute_path
            .last()
            .map_or_else(crate::Position::default, |part| part.end())
    }
}
impl std::convert::From<*mut crate::ffi::any> for HasAttribute {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::HasAttribute { expression, attribute_path } = own(ptr);

        Self {
            expression: Box::new(crate::Expression::from(expression)),
            attribute_path: own_ll::<crate::ffi::Part, crate::Part>(
                attribute_path,
            ),
        }
    }
}
