#pragma once

#include "parser/AST.hpp"
#include "runtime/Context.hpp"

class Executor {
    public:
        explicit Executor(Context& context);

        void execute(const ASTNode& node);

    private:
        Context& context;

        void executeInit(const InitNode&);

        void executeCommit(const CommitNode& node);
};