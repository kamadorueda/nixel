# SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
#
# SPDX-License-Identifier: GPL-3.0-only

{
  inputs = {
    blank.url = "github:divnix/blank";

    fenix.url = "github:nix-community/fenix";
    fenix.inputs.nixpkgs.follows = "nixpkgs";
    fenix.inputs.rust-analyzer-src.follows = "blank";

    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
  };

  outputs = inputs: let
    commit = inputs.self.shortRev or "dirty";
    date = inputs.self.lastModifiedDate or inputs.self.lastModified or "19700101";
    version = "5.0.1+${builtins.substring 0 8 date}.${commit}";

    overlay = self: super: {
      nixel = self.rustPlatform.buildRustPackage {
        pname = "nixel";
        inherit version;
        src = ./.;
        cargoLock.lockFile = ./Cargo.lock;

        nativeBuildInputs = [
          self.pkg-config
          self.pkgsBuildBuild.rustPlatform.bindgenHook
        ];
        buildInputs = [self.gcc.cc.lib];

        # buildType = "debug";
        # doCheck = false;

        meta = {
          description = "Parser for the Nix Expressions Language";
          homepage = "https://github.com/kamadorueda/nixel";
          license = self.lib.licenses.gpl3Only;
          maintainers = [self.lib.maintainers.kamadorueda];
          platforms = self.lib.systems.doubles.all;
        };
      };
    };

    nixpkgsFor = system:
      import inputs.nixpkgs {
        overlays = [overlay];
        inherit system;
      };

    outputsFor = system: let
      fenix = inputs.fenix.packages.${system};
      nixpkgs = nixpkgsFor system;
    in {
      packages.${system}.default = nixpkgs.nixel;

      devShells.${system}.default = nixpkgs.mkShell {
        name = "nixel";
        packages = [
          fenix.stable.toolchain
          nixpkgs.cargo-license
          nixpkgs.cargo-tarpaulin
          nixpkgs.clang
          nixpkgs.linuxPackages_latest.perf
          nixpkgs.reuse
          nixpkgs.valgrind

          # Vendor dependencies
          (nixpkgs.writeShellApplication {
            name = "vendor";

            runtimeInputs = [nixpkgs.bison nixpkgs.flex];

            text = ''
              rm -rf src/vendored
              mkdir src/vendored

              bison src/parser/generator.y

              flex src/lexer/generator.l
            '';
          })

          # License stuff
          (nixpkgs.writeShellApplication {
            name = "license";

            runtimeInputs = [nixpkgs.reuse];

            text = ''
              copyright='Kevin Amado <kamadorueda@gmail.com>'
              license='GPL-3.0-only'

              find . -type f -name '*.license' -exec rm {} +

              reuse addheader \
                --copyright="$copyright" \
                --license="$license" \
                --force-dot-license \
                Cargo.lock \
                flake.lock \
                src/vendored/lexer.* \
                src/vendored/parser.* \

              git ls-files \
                | grep -v src/lexer/generator.l \
                | grep -v tests/cases \
                | grep -v tests/inputs/manual \
                | grep -v tests/inputs/nixpkgs \
                | xargs reuse addheader \
                  --copyright="$copyright" \
                  --license="$license" \
                  --skip-unrecognised

              reuse lint
            '';
          })
        ];
        shellHook = ''
          export LIBCLANG_PATH="${nixpkgs.libclang.lib}/lib"
        '';
      };
    };
  in
    builtins.foldl' inputs.nixpkgs.lib.recursiveUpdate {} [
      (outputsFor "aarch64-darwin")
      (outputsFor "aarch64-linux")
      (outputsFor "x86_64-darwin")
      (outputsFor "x86_64-linux")
      {
        packages."x86_64-linux".static = (nixpkgsFor "x86_64-linux").pkgsStatic.nixel;
      }
    ];
}
