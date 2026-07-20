#pragma once

#include <string>
#include <filesystem>

class Repository {
    public:
        explicit Repository(const std::filesystem::path& root);

        void init();

        std::filesystem::path gitxDir() const;
        std::filesystem::path objectsDir() const;
        std::filesystem::path refsDir() const;
        std::filesystem::path headFile() const;

    private:
        std::filesystem::path root;
};