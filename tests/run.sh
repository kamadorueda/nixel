#! /bin/sh -eu

cargo build --release

find /data/nixpkgs -type f -name '*.nix' | while read -r path; do
  if ./target/release/nixel "${path}"; then
    echo "${path} OK"
  else
    echo "${path} ERROR"
    break
  fi
done
