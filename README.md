# <h2><p align="center">Number System Toolkit (CLI & GUI)</p></h2>

<div align="center">

![C++17](https://img.shields.io/badge/C++-17-blue.svg) 
![CMake](https://img.shields.io/badge/Build-CMake-green.svg) 
![Status](https://img.shields.io/badge/Status-Refactored-orange.svg)

</div>

A C++ Utility for comprehensive **Number System Conversion and Arithmethic**, designed for developers and students. This program suppports *Decimal*, *Binary*, *Octal*, and *Hexadecimal* systems with rigorous ***validation***, ***floating point** support*, and ***negative number** support*.

## Overview
This project began as a simple command-line tool and is currently in development to be integrated as a desktop application.

## Key Features
- **Multi-Base Conversions:** Seamlessly switch between Base 2, 8, 10, and 16.
- **Arithmetic Support:** Perform Arithmetic accross different number systems simultaneously with support for floating point and negative numbers.
- **Precision Handling:** Double precision. 12 digits precision limit for infinite fractions.
- **Robust Validation:** Comprehensive sanitazion and syntax checking for each and every input/process.
- **Modular Architecture:** Cleanly seperated logic, modular and easily modifiable.

## 📦 Getting Started
### Prerequisites
- **Compiler:** GCC 11.2.0 (MinGW/UCRT64) or higher (C++17 support required).
- **Build System:** CMake 3.10+

### Building the CLI
1. **Clone the repository:**
    ```
    git clone https://github.com/SLCLS/number-system.git
    cd number-system/CLI
    ```
2. **Configure and Build:**
    ```
    mkdir build && cd build
    cmake ..
    cmake --build .
    ```
3. **Run the Application:**
    ```
    ./NumberSystemCLI.exe
    ```

## 🗺 Roadmap
- [ ] **Phase 2:** Graphical User Interface (GUI) implementation using Qt Framework.

## 🤩 Author
[**SLCLS**](https://github.com/SLCLS) - A First-Year **Computer Science Student** at *FEU Institute of Technology*, **Junior Developer** at *Zenith Falcon Tech*.
- **My Github:** [@SLCLS](https://github.com/SLCLS)
- **LinkedIn:** [@slcls](https://www.linkedin.com/in/slcls/)
- **See more projects:** [WORKSPACE](https://github.com/SLCLS/WORKSPACE)