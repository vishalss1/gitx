#pragma once

#include "core/Repository.hpp"

#include <filesystem>

class Context {
    public:
        Context();

        std::filesystem::path cwd;
        Repository repository;
        bool verbose = false;
};