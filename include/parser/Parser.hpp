#pragma once

#include <memory>
#include <vector>

#include "lexer/Token.hpp"
#include "parser/AST.hpp"

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);

    std::unique_ptr<ASTNode> parse();

private:
    const std::vector<Token>& tokens;
    size_t current = 0;

    const Token& peek() const;
    const Token& previous() const;
    const Token& advance();

    bool isAtEnd() const;

    bool check(TokenType type) const;
    bool match(TokenType type);

    const Token& expect(TokenType type);

    std::unique_ptr<CommitNode> parseCommit();
    std::unique_ptr<InitNode> parseInit();
};