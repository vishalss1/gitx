#pragma once

#include <string>
#include <vector>

#include "Token.hpp"

class Lexer {
public:
    explicit Lexer(const std::string& source);

    std::vector<Token> tokenize();

private:
    std::string source;
    size_t current = 0;

    bool isAtEnd() const;
    char peek() const;
    char advance();

    void skipWhitespace();

    KeywordType getKeywordType(const std::string& word) const;
    FlagType getFlagType(const std::string& flag) const;

    Token readWord();
    Token readString();
    Token readFlag();
};