#! /bin/sh -eu

# SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
#
# SPDX-License-Identifier: AGPL-3.0-only

cargo build --release

find /data/nixpkgs -type f -name '*.nix' | while read -r path; do
  if ./target/release/nixel "${path}"; then
    echo "${path} OK"
  else
    echo "${path} ERROR"
    break
  fi
done
