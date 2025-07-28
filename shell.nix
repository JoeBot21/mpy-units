let
  pkgs = import <nixpkgs> {};
in
pkgs.mkShell {
  packages = with pkgs; [
    cmake
    gcc15
    ninja
    python313
    python313Packages.setuptools
  ];
}
