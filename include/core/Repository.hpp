#pragma once

#include <string>

class Repository {
    public:
        Repository() = default;

        void init();

        void commit(const std::string& message);
};