#include "runtime/Executor.hpp"

#include <cstdlib>
#include <stdexcept>

Executor::Executor(Context& context) : context(context) {}

void Executor::execute(const ASTNode& node) {
    switch(node.type) {
        case ASTNodeType::Commit:
            executeCommit(static_cast<const CommitNode&>(node));
            break;

        default:
            throw std::runtime_error("Unknown AST node.");
    }
}

void Executor::executeCommit(const CommitNode& node) {
    context.repository.commit(node.message);
}