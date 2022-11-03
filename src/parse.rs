// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

/// Parse the `input` [String].
pub fn parse(input: String) -> crate::Parsed {
    let mut input = input.into_bytes();

    input.extend_from_slice(&[0, 0]);

    parse_bytes(input)
}

/// Parse the `input` bytes ([Vec]<[u8]>).
///
/// Input must be valid UTF-8 and end with two null bytes.
pub fn parse_bytes(mut input: Vec<u8>) -> crate::Parsed {
    let len = input.len();
    assert!(len >= 2, "input must end with two null characters");
    assert!(input[len - 1] == 0, "input must end with two null characters");
    assert!(input[len - 2] == 0, "input must end with two null characters");

    let parsed = unsafe { crate::ffi::parse(input.as_mut_ptr(), len) };

    crate::Parsed::from(parsed)
}
