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
            continue;
        }

        tokens.push_back(readWord());
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