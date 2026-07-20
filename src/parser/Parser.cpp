#include "parser/Parser.hpp"

#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens)
    : tokens(tokens) {}

const Token& Parser::peek() const {
    return tokens[current];
}

const Token& Parser::previous() const {
    return tokens[current - 1];
}

bool Parser::isAtEnd() const {
    return peek().type == TokenType::EndOfFile;
}

const Token& Parser::advance() {

    if (!isAtEnd()) {
        current++;
    }

    return previous();
}

bool Parser::check(TokenType type) const {
    return peek().type == type;
}

bool Parser::match(TokenType type) {

    if (!check(type))
        return false;

    advance();
    return true;
}

const Token& Parser::expect(TokenType type) {

    if (check(type))
        return advance();

    throw std::runtime_error("Unexpected token.");
}

std::unique_ptr<ASTNode> Parser::parse() {

    const Token& keyword = expect(TokenType::Keyword);

    switch (keyword.keyword) {

        case KeywordType::Init:
            return parseInit();

        case KeywordType::Commit:
            return parseCommit();

        default:
            throw std::runtime_error("Unknown command.");
    }
}

std::unique_ptr<CommitNode> Parser::parseCommit() {

    const Token& flag = expect(TokenType::Flag);

    if (flag.flag != FlagType::Message) {
        throw std::runtime_error("Expected '-m'.");
    }

    const Token& message = expect(TokenType::String);

    expect(TokenType::EndOfFile);

    return std::make_unique<CommitNode>(message.value);
}

std::unique_ptr<InitNode> Parser::parseInit() {

    expect(TokenType::EndOfFile);

    return std::make_unique<InitNode>();
}