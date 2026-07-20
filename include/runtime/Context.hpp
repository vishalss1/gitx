#pragma once

#include "core/Repository.hpp"

#include <filesystem>

class Context {
    public:
        Repository repository;

        std::filesystem::path currentWorkingDirectory;
        bool verbose = false;
};