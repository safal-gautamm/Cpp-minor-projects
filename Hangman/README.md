# Hangman Game with ncurses

## Overview

This is a classic **Hangman** word guessing game implemented in C++ with an interactive terminal user interface powered by the **ncurses** library.

Unlike traditional console input/output using `cin` and `cout`, this version leverages ncurses to provide:  
- Immediate, non-blocking key input without pressing Enter  
- Dynamic screen updates and text positioning  
- Clean and colorful terminal UI elements  
- Improved user experience for command-line gameplay

---

## What is ncurses?

**ncurses** is a programming library that provides an API to write text-based user interfaces in a terminal-independent manner. It allows you to:  
- Control cursor movement  
- Handle keyboard input efficiently  
- Use colors and attributes  
- Create windows and manage screen content dynamically  

It is widely used for building TUIs (Text-based User Interfaces) on Unix-like systems.

---

## Prerequisites

Make sure you have the ncurses development libraries installed.

### On Arch Linux

```bash
sudo pacman -S ncurses
```

### On Debian/Ubuntu
```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

### Building/Compiling
Assuming your source code is in main.cpp and the word list is in vocab.txt in the same directory:
```bash
g++ main.cpp -lncurses -o hangman
```
The `-lncurses` flag links your program against the ncurses library.

### Running
```bash
./hangman
```