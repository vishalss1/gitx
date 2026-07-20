#include "fs/FileReader.hpp"
#include "lexer/Lexer.hpp"
#include "parser/Parser.hpp"
#include "runtime/Context.hpp"
#include "runtime/Executor.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    
    std::cout << "Program started\n";
    if(argc != 2) {
        std::cerr << "Usage: gitx <file.gitx>\n";
        return 1;
    }

    std::string source = FileReader::Read(argv[1]);

    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    auto ast = parser.parse();

    Context context;

    Executor executor(context);

    for(const auto& token: tokens) {
        std::cout << token.value << '\n';
    }

    executor.execute(*ast);

    return 0;
}