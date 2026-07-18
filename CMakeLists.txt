cmake_minimum_required(VERSION 3.20)

project(gitx LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(gitx
    src/main.cpp
    src/fs/FileReader.cpp
    src/lexer/Lexer.cpp
    src/parser/Parser.cpp
    src/runtime/Executor.cpp
    src/core/Repository.cpp
)

target_include_directories(gitx PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)