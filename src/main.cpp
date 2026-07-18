#include "fs/FileReader.hpp"
#include "lexer/Lexer.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: gitx <file.gitx>\n";
        return 1;
    }

    std::string source = FileReader::Read(argv[1]);

    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    for(const auto& token : tokens) {
        switch (token.type)
        {
        case TokenType::Keyword:
            std::cout << "Keyword: ";
            break;

        case TokenType::Identifier:
            std::cout << "Identifier: ";
            break;

        case TokenType::String:
            std::cout << "String: ";
            break;

        case TokenType::Flag:
            std::cout << "Flag: ";
            break;
            
        case TokenType::EndOfFile:
            std::cout << "EOF";
            break;
        
        default:
            break;
        }

        std::cout << token.value << '\n';
    }

    return 0;
}