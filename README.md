# LibreNF
LibreNF is a Free and Open Source Nuclear fission simulation as a way to simulate Nuclear fission (at a atomic scale) for free, forever.

This project is NOT yet complete; however, people who would still like to install to help, you are free to do so via `git clone`.


# Installation

## Git Clone
```bash
git clone https://github.com/Ray17x/LibreNF
```


## Dependecies
Before compiling and/or running, ensure you have installed the proper dependecies
```bash
# APT
sudo apt update
sudo apt install libsfml-dev

# Arch / Arch-Based
sudo pacman -S sfml

# Gentoo (Portage)
sudo emerge media-libs/sfml
```


## Compiling
Then:
```sh
$ cd LibreNF
$ g++ -std=c++23 Main.cpp -o ./Binaries/LibreNF -lsfml-graphics -lsfml-window -lsfml-system
# c++17 or Higher is recommened (I use c++23 during compile time)
```

## Running
To finally run:
```sh
$ ./Binaries/LibreNF
```


# How to use
Well, this section is quite redundant as you can't really do much with it right now (it is a white screen with nothing). Feel Free to contribute.

# Contact Me
Email: ray@atl.tools

Via Discord: _koy0mi
