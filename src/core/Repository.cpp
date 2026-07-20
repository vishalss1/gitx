#include "core/Repository.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

Repository::Repository(const fs::path& root) : root(root) {}

fs::path Repository::gitxDir() const {
    return root / ".gitx";
}

fs::path Repository::objectsDir() const {
    return gitxDir() / "objects";
}

fs::path Repository::refsDir() const {
    return gitxDir() / "refs" / "heads";
}

fs::path Repository::headFile() const {
    return gitxDir() / "HEAD";
}

void Repository::init() {
    fs::create_directories(objectsDir());
    fs::create_directories(refsDir());

    std::ofstream head(headFile());
    head << "ref: refs/heads/main\n";

    std::cout << "Initialized empty Gitx repository.\n";
}
