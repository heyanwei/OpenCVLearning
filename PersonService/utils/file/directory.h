#pragma once

#include <string>

namespace utils
{
    namespace file
    {
        bool createdir(std::string name, std::string &note);
        bool deletedir(std::string name, std::string &note);
        bool isdirexist(std::string name, std::string &note);
    }
}