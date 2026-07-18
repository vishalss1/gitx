#pragma once 

#include <string>

enum class TokenType {
    Keyword,
    Identifier,
    Flag,
    String,
    Newline,
    EndOfFile
};

struct Token {
    TokenType type;
    std::string value;
};