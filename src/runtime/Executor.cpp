#include "runtime/Executor.hpp"

#include <stdexcept>

Executor::Executor(Context& context) : context(context) {}

void Executor::execute(const ASTNode& node) {

    switch(node.type) {
        case ASTNodeType::Init:
            executeInit(static_cast<const InitNode&>(node));
            break;

        case ASTNodeType::Commit:
            executeCommit(static_cast<const CommitNode&>(node));
            break;

        default:
            throw std::runtime_error("Unknown AST node.");
    }
}

void Executor::executeInit(const InitNode&) {
    context.repository.init();
}
