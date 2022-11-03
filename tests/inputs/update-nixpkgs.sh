#! /bin/sh -eux

# SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
#
# SPDX-License-Identifier: GPL-3.0-only

rm -rf tests/cases/nixpkgs*
cd tests/inputs
rm -rf nixpkgs
git clone --depth 1 https://github.com/nixos/nixpkgs
find nixpkgs ! -name '*.nix' -type f -exec rm -rf {} \;
find nixpkgs -name '*.nix' | sort | tail --lines=+1001 | xargs rm
