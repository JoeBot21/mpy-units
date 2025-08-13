let
  pkgs = import <nixpkgs> {};
in
pkgs.mkShell {
  packages = with pkgs; [
    cmake
    gcc15
    gsl-lite
    ninja
  ];
}
