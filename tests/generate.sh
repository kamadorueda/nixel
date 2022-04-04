#! /bin/sh -eu

rm -rf tests/cases
mkdir -p tests/cases

mkdir -p tests/cases/readme
cat << EOF > tests/cases/readme/input
let
  greeting = "Hello World!";
in
  greeting
EOF

find /data/nixpkgs/ -type f -name '*.nix' | sort | while read -r path; do
  test_name="${path///data\/nixpkgs\//}"
  test_name="${test_name//\//-}"
  if test "${RANDOM}" -le "$((32768 / 256))"; then
    mkdir "tests/cases/${test_name}"
    cat "${path}" > "tests/cases/${test_name}/input"
  fi
done
