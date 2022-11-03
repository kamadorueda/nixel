// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// The result of [parse()](crate::parse()) and
/// [parse_bytes()](crate::parse_bytes()).
pub struct Parsed {
    pub expression: Box<crate::Expression>,
    #[doc(hidden)]
    pub trivia: Box<[crate::Trivia]>,
}

impl std::convert::From<*mut crate::ffi::Parsed> for Parsed {
    fn from(parsed: *mut crate::ffi::Parsed) -> Self {
        let crate::ffi::Parsed { expression, trivia } = own(parsed);

        let trivia = own_ll::<crate::ffi::Trivia, crate::Trivia>(trivia);

        Self {
            expression: Box::new(crate::Expression::from(expression)),
            trivia,
        }
    }
}

impl Parsed {
    /// Return the [Trivia](crate::Trivia) after the given
    /// [Position](crate::Position).
    pub fn trivia_after(&self, position: &crate::Position) -> &[crate::Trivia] {
        let index_start = self
            .trivia
            .binary_search_by_key(&position, |trivia| {
                match trivia {
                    crate::Trivia::Boundary(boundary) => &*boundary.span.end,
                    crate::Trivia::Comment(comment) => &*comment.span.start,
                    crate::Trivia::MultilineComment(multiline_comment) => {
                        &*multiline_comment.span.start
                    },
                    crate::Trivia::Whitespace(whitespace) => {
                        &*whitespace.span.start
                    },
                }
            })
            .map_or_else(|index| index + 1, std::convert::identity);

        let mut index_end = index_start;

        loop {
            match self.trivia.get(index_end) {
                Some(crate::Trivia::Boundary(_)) | None => {
                    break;
                },
                _ => {
                    index_end += 1;
                },
            }
        }

        &self.trivia[index_start..index_end]
    }

    /// Return the [Trivia](crate::Trivia) before the given
    /// [Position](crate::Position).
    pub fn trivia_before(
        &self,
        position: &crate::Position,
    ) -> &[crate::Trivia] {
        let index_end = self
            .trivia
            .binary_search_by_key(&position, |trivia| {
                match trivia {
                    crate::Trivia::Boundary(boundary) => &*boundary.span.end,
                    crate::Trivia::Comment(comment) => &*comment.span.start,
                    crate::Trivia::MultilineComment(multiline_comment) => {
                        &*multiline_comment.span.start
                    },
                    crate::Trivia::Whitespace(whitespace) => {
                        &*whitespace.span.start
                    },
                }
            })
            .map_or_else(
                |index| index.saturating_sub(1),
                std::convert::identity,
            );

        let mut index_start = index_end;
        while index_start >= 1 {
            match self.trivia.get(index_start) {
                Some(crate::Trivia::Boundary(_)) => {
                    index_start += 1;
                    break;
                },
                _ => {
                    index_start -= 1;
                },
            }
        }

        &self.trivia[index_start..index_end + 1]
    }
}
