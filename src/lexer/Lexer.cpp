#include "lexer/Lexer.hpp"

#include <vector>
#include <cctype>

Lexer::Lexer(const std::string& source): source(source) {

}

bool Lexer::isAtEnd() const {
    return current >= source.size();
}

char Lexer::peek() const {
    if(isAtEnd())
        return '\0';

    return source[current];
}

char Lexer::advance() {
    if(isAtEnd())
        return '\0';

    return source[current++];
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    while(!isAtEnd()) {
        char c = peek();

        if(std::isspace(static_cast<unsigned char>(c))) {
            advance();
        } else if (c == '"') {
            tokens.push_back(readString());
        } else if(c == '-') {
            tokens.push_back(readFlag());
        } else {
            tokens.push_back(readWord());
        }
    }

    tokens.push_back({TokenType::EndOfFile, ""});

    return tokens;
}

Token Lexer::readWord() {
    size_t start = current;

    while(!isAtEnd() && (std::isalnum(static_cast<unsigned char>(peek())) || peek() == '_')) {
        advance();
    }

    std::string word = source.substr(start, current - start);

    if( word == "commit" || 
        word == "branch" ||
        word == "checkout" ||
        word == "merge" ||
        word == "tag" ||
        word == "remote"
    ) {
        return { TokenType::Keyword, word };
    }

    return { TokenType::Identifier, word };
}

Token Lexer::readString() {
    advance(); // consume  opening "
    size_t start = current;

    while(!isAtEnd() && (peek() != '"')) {
        advance();
    }

    std::string word = source.substr(start, current - start);

    if(!isAtEnd()) {
        advance(); //skip ending "
    }

    return { TokenType::String, word };
}

Token Lexer::readFlag() {
    size_t start = current;
    advance(); // skip starting -

    while(!isAtEnd() && (std::isalnum(static_cast<unsigned char> (peek())) || peek() == '_')) {
        advance();
    }

    std::string word = source.substr(start, current - start);

    return { TokenType::Flag, word };
}