#include "directory.h"

#include <sys/stat.h>
#include <unistd.h>

namespace utils
{
namespace file
{

bool createdir(std::string name, std::string &note)
{
    try
    {
        int res = mkdir(name.c_str(), S_IRWXU);
        if (res == 0)
        {
            note = "create dir success";
            return true;
        }
        else
        {
            note = "create dir failed, res: " + std::to_string(res);
            return false;
        }
    }
    catch (const std::exception &e)
    {
        note = "create dir error: " + std::string(e.what());
    }
    return false;
}

bool deletedir(std::string name, std::string &note)
{
    try
    {
        int res = rmdir(name.c_str());
        if (res == 0)
        {
            note = "delete dir success";
            return true;
        }
        else
        {
            note = "delete dir failed, res: " + std::to_string(res);
            return false;
        }
    }
    catch (const std::exception &e)
    {
        note = "delete dir error: " + std::string(e.what());
    }
    return false;
}

bool isdirexist(std::string name, std::string &note)
{
    try
    {
        if (access(name.c_str(), F_OK) == 0)
        {
            note = "the dir is exist";
            return true;
        }
        note = "the dir is not exist";
        return false;
    }
    catch (const std::exception &e)
    {
        note = "check dir error: " + std::string(e.what());
    }
    return false;
}

} // namespace file
} // namespace utils