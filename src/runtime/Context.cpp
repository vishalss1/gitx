#include "runtime/Context.hpp"

#include <filesystem>

Context::Context() : cwd(std::filesystem::current_path()), repository(cwd) {}