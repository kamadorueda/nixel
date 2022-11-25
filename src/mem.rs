// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

pub(crate) fn own<Src, Target>(ptr: *mut Src) -> Target {
    *unsafe { Box::<Target>::from_raw(ptr as *mut Target) }
}

pub(crate) fn own_ll<FFI, T>(ptr: *mut crate::ffi::LL) -> Box<[T]>
where
    T: From<*mut FFI>,
{
    let mut vec = Vec::new();

    let crate::ffi::LL { next: mut cursor } = own(ptr);

    while !cursor.is_null() {
        let crate::ffi::Node { ptr, next } = own(cursor);

        vec.push(T::from(ptr as *mut FFI));

        cursor = next;
    }

    vec.reverse();

    vec.into_boxed_slice()
}

pub(crate) fn own_str(ptr: *mut crate::ffi::Str) -> Box<str> {
    let crate::ffi::Str { ptr, len } = own(ptr);

    let slice = std::ptr::slice_from_raw_parts(ptr, len);

    String::from_utf8(unsafe { (*slice).iter().map(|c| *c as u8).collect::<Vec<u8>>() })
        .expect("Invalid UTF-8")
        .into_boxed_str()
}
