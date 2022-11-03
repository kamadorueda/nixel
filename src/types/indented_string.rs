// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

use crate::mem::own;
use crate::mem::own_ll;

#[derive(Clone, Debug, Eq, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
/// `''parts''`.
pub struct IndentedString {
    pub parts: Box<[crate::Part]>,
    pub span: Box<crate::Span>,
}

impl std::convert::From<*mut crate::ffi::any> for IndentedString {
    fn from(ptr: *mut crate::ffi::any) -> Self {
        let crate::ffi::IndentedString { parts, span } = own(ptr);

        let mut parts: Box<[crate::Part]> =
            own_ll::<crate::ffi::Part, crate::Part>(parts);

        strip_indentation(&mut parts);

        Self { parts, span: Box::new(crate::Span::from(span)) }
    }
}

fn strip_indentation(parts: &mut [crate::Part]) {
    let mut at_start_of_line = true;
    let mut min_indent: usize = usize::MAX;
    let mut cur_indent: usize = 0;

    // Compute the min indentation
    for part in &*parts {
        if let crate::Part::Raw(crate::PartRaw { content, .. }) = part {
            for char in content.chars() {
                if at_start_of_line {
                    match char {
                        ' ' => {
                            cur_indent += 1;
                        },
                        '\n' => {
                            cur_indent = 0;
                        },
                        _ => {
                            at_start_of_line = false;
                            if cur_indent < min_indent {
                                min_indent = cur_indent;
                            }
                        },
                    }
                } else if char == '\n' {
                    at_start_of_line = true;
                    cur_indent = 0;
                }
            }
        }
    }

    // Trim spaces from each line
    let mut cur_dropped: usize = 0;
    let parts_count = parts.len();
    for part in parts.iter_mut() {
        match part {
            crate::Part::Raw(crate::PartRaw { content, .. }) => {
                *content = content
                    .chars()
                    .filter(|char| {
                        if at_start_of_line {
                            match char {
                                ' ' => {
                                    cur_dropped += 1;
                                    cur_dropped > min_indent
                                },
                                '\n' => {
                                    cur_dropped = 0;
                                    true
                                },
                                _ => {
                                    at_start_of_line = false;
                                    cur_dropped = 0;
                                    true
                                },
                            }
                        } else {
                            if *char == '\n' {
                                at_start_of_line = true;
                            }
                            true
                        }
                    })
                    .collect::<String>()
                    .into_boxed_str();

                if parts_count == 1 {
                    if let Some(last_new_line) = content.rfind('\n') {
                        if content[last_new_line + 1..]
                            .chars()
                            .all(|char| char == ' ')
                        {
                            *content = content[0..last_new_line + 1]
                                .to_string()
                                .into_boxed_str();
                        }
                    }
                }
            },
            _ => {
                at_start_of_line = false;
                cur_dropped = 0;
            },
        }
    }
}
