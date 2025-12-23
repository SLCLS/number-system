cmake_minimum_required(VERSION 3.10)
project(NumberSystemCLI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(NumberSystemCLI
    src/main.cpp
    src/core/validator.cpp
    src/core/navigation.cpp
    src/core/computation.cpp
    src/core/utility.cpp
    src/utils/logger.cpp
)