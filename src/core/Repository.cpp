#include "core/Repository.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void Repository::init() {

    fs::create_directories(".gitx");
    fs::create_directories(".gitx/objects");
    fs::create_directories(".gitx/refs/heads");

    std::ofstream head(".gitx/HEAD");

    head << "ref: refs/heads/main\n";

    std::cout << "Initialized empty Gitx repository.\n";
}

void Repository::commit(const std::string& message) {

    std::cout << "Commit: " << message << '\n';
}