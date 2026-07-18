#include "fs/FileReader.hpp"
#include "lexer/Lexer.hpp"
#include "parser/Parser.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: gitx <file.gitx>\n";
        return 1;
    }

    std::string source = FileReader::Read(argv[1]);

    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    auto ast = parser.parse();

    if(ast->type == ASTNodeType::Commit) {
        auto* commit = static_cast<CommitNode*>(ast.get());
        std::cout << commit->message << '\n';
    }

    return 0;
}