let
  pkgs = import <nixpkgs> {};
in
pkgs.mkShell {
  packages = with pkgs; [
    cmake
    gcc15
    gsl-lite
    ninja
    python313
    python313Packages.setuptools
  ];
}
