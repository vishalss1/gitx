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

enum class KeywordType {
    None,
    Init,
    Add,
    Commit,
    Status,
    Checkout,
    Branch,
    Merge,
    Log,
};

enum class FlagType {
    None,
    Message,      // -m
    Cached,       // --cached
    Force,        // --force
    All,          // --all
    Amend         // --amend
};

enum class IdentifierType {
    None,
    BranchName,
    FilePath,
    RemoteName,
    CommitHash,
    TagName,
};

struct Token {
    
    TokenType type;
    std::string value;

    KeywordType keyword = KeywordType::None;
    FlagType flag = FlagType::None;
    IdentifierType identifier = IdentifierType::None;

    Token(TokenType type, std::string value)
        : type(type), value(std::move(value)) {}

    Token(TokenType type, std::string value, KeywordType keyword)
        : type(type), value(std::move(value)), keyword(keyword) {}

    Token(TokenType type, std::string value, KeywordType keyword, FlagType flag)
        : type(type), value(std::move(value)), keyword(keyword), flag(flag) {}

    Token(TokenType type, std::string value,
          KeywordType keyword,
          FlagType flag,
          IdentifierType identifier)
        : type(type),
          value(std::move(value)),
          keyword(keyword),
          flag(flag),
          identifier(identifier) {}
};