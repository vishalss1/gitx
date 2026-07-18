#include "fs/FileReader.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: gitx <file.gitx>\n";
        return 1;
    }

    std::string source = FileReader::Read(argv[1]);

    std::cout << source;

    return 0;
}