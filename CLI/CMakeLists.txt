cmake_minimum_required(VERSION 3.10)
project(NumberSystemCLI)

set(CMAKE_CSS_STANDARD 17)

include_directories(include)

Add_executable(NumberSystemCLI
    src/main.cpp
    src/validator.cpp
    src/navigation.cpp
    src/computation.cpp
    src/utility.cpp
    src/logger.cpp
)