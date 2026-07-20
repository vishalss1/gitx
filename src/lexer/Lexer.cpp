#include "lexer/Lexer.hpp"

#include <cctype>
#include <unordered_map>

Lexer::Lexer(const std::string& source)
    : source(source) {}

bool Lexer::isAtEnd() const {
    return current >= source.size();
}

char Lexer::peek() const {

    if (isAtEnd())
        return '\0';

    return source[current];
}

char Lexer::advance() {

    if (isAtEnd())
        return '\0';

    return source[current++];
}

void Lexer::skipWhitespace() {

    while (!isAtEnd() &&
           std::isspace(static_cast<unsigned char>(peek()))) {
        advance();
    }
}

KeywordType Lexer::getKeywordType(const std::string& word) const {

    static const std::unordered_map<std::string, KeywordType> keywords = {
        {"init",     KeywordType::Init},
        {"add",      KeywordType::Add},
        {"commit",   KeywordType::Commit},
        {"status",   KeywordType::Status},
        {"checkout", KeywordType::Checkout},
        {"branch",   KeywordType::Branch},
        {"merge",    KeywordType::Merge},
        {"log",      KeywordType::Log},
    };

    auto it = keywords.find(word);

    if (it != keywords.end())
        return it->second;

    return KeywordType::None;
}

FlagType Lexer::getFlagType(const std::string& flag) const {

    static const std::unordered_map<std::string, FlagType> flags = {
        {"-m",        FlagType::Message},
        {"--cached",  FlagType::Cached},
        {"--force",   FlagType::Force},
        {"--all",     FlagType::All},
        {"--amend",   FlagType::Amend},
    };

    auto it = flags.find(flag);

    if (it != flags.end())
        return it->second;

    return FlagType::None;
}

std::vector<Token> Lexer::tokenize() {

    std::vector<Token> tokens;

    while (!isAtEnd()) {

        skipWhitespace();

        if (isAtEnd())
            break;

        char c = peek();

        if (c == '"') {
            tokens.push_back(readString());
        }
        else if (c == '-') {
            tokens.push_back(readFlag());
        }
        else {
            tokens.push_back(readWord());
        }
    }

    tokens.emplace_back(TokenType::EndOfFile, "");

    return tokens;
}

Token Lexer::readWord() {

    size_t start = current;

    while (!isAtEnd() &&
          (std::isalnum(static_cast<unsigned char>(peek())) ||
           peek() == '_')) {

        advance();
    }

    std::string word = source.substr(start, current - start);

    KeywordType keyword = getKeywordType(word);

    if (keyword != KeywordType::None) {
        return Token(TokenType::Keyword, word, keyword);
    }

    return Token(TokenType::Identifier, word);
}

Token Lexer::readString() {

    advance(); // opening "

    size_t start = current;

    while (!isAtEnd() && peek() != '"') {
        advance();
    }

    std::string word = source.substr(start, current - start);

    if (!isAtEnd())
        advance(); // closing "

    return Token(TokenType::String, word);
}

Token Lexer::readFlag() {

    size_t start = current;

    advance(); // first '-'

    while (!isAtEnd() &&
          (std::isalnum(static_cast<unsigned char>(peek())) ||
           peek() == '-' ||
           peek() == '_')) {

        advance();
    }

    std::string flag = source.substr(start, current - start);

    FlagType flagType = getFlagType(flag);

    return Token(
        TokenType::Flag,
        flag,
        KeywordType::None,
        flagType
    );
}