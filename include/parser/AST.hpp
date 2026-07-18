#pragma once

#include <memory>
#include <string>

enum class ASTNodeType {
    Commit
};

class ASTNode {
    public:
        ASTNode(ASTNodeType type) : type(type) {}
        virtual ~ASTNode() = default;

        ASTNodeType type;
};

class CommitNode : public ASTNode {
    public:
        explicit CommitNode(std::string message) : ASTNode(ASTNodeType::Commit), message(std::move(message)) {}

        std::string message;
};