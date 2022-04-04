{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
  };

  outputs = inputs: let
    commit = inputs.self.shortRev or "dirty";
    date = inputs.self.lastModifiedDate or inputs.self.lastModified or "19700101";
    version = "1.0.1+${builtins.substring 0 8 date}.${commit}";

    nixpkgsForHost = host:
      import inputs.nixpkgs {
        overlays = [
          (self: super: {
            nixel = self.rustPlatform.buildRustPackage {
              pname = "nixel";
              inherit version;
              src = ./.;
              cargoLock.lockFile = ./Cargo.lock;

              passthru.tests = {
                version = self.testVersion {package = super.nixel;};
              };

              meta = {
                description = "Lexer, Parser, Abstract Syntax Tree and Concrete Syntax Tree for the Nix Expressions Language.";
                homepage = "https://github.com/kamadorueda/nixel";
                license = self.lib.licenses.agpl3Only;
                maintainers = [self.lib.maintainers.kamadorueda];
                platforms = self.lib.systems.doubles.all;
              };
            };
          })
        ];
        system = host;
      };

    nixpkgs."aarch64-darwin" = nixpkgsForHost "aarch64-darwin";
    nixpkgs."aarch64-linux" = nixpkgsForHost "aarch64-linux";
    nixpkgs."i686-linux" = nixpkgsForHost "i686-linux";
    nixpkgs."x86_64-darwin" = nixpkgsForHost "x86_64-darwin";
    nixpkgs."x86_64-linux" = nixpkgsForHost "x86_64-linux";
  in {
    devShells."x86_64-linux".default = with nixpkgs."x86_64-linux";
      mkShell {
        name = "nixel";
        packages = [
          cargo
          cargo-tarpaulin
          clippy
          entr
          jq
          linuxPackages_latest.perf
          reuse
          rustc
        ];
      };

    apps."x86_64-linux".dev = with nixpkgs."x86_64-linux"; {
      type = "app";
      program =
        (writeShellScript "license" ''
          git ls-files | entr sh -euc '
            UPDATE=1 cargo test
            cargo doc
            cargo tarpaulin -o html
          '
        '')
        .outPath;
    };

    apps."x86_64-linux".license = with nixpkgs."x86_64-linux"; {
      type = "app";
      program =
        (writeShellScript "license" ''
          copyright='Kevin Amado <kamadorueda@gmail.com>'
          license='AGPL-3.0-only'

          reuse addheader \
            --copyright="$copyright" \
            --license="$license" \
            --explicit-license \
            .envrc \
            Cargo.lock \
            Cargo.toml \
            flake.nix \
            flake.lock \
            tests/cases/*/* \

          git ls-files | xargs reuse addheader \
            --copyright="$copyright" \
            --license="$license" \
            --skip-unrecognised
        '')
        .outPath;
    };

    packages."aarch64-darwin".default = nixpkgs."aarch64-darwin".nixel;
    packages."aarch64-linux".default = nixpkgs."aarch64-linux".nixel;
    packages."i686-linux".default = nixpkgs."i686-linux".nixel;
    packages."x86_64-darwin".default = nixpkgs."x86_64-darwin".nixel;
    packages."x86_64-linux".default = nixpkgs."x86_64-linux".nixel;
  };
}
