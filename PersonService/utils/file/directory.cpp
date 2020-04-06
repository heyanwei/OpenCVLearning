#include "directory.h"

#include <sys/stat.h>

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
            note = "create log dir success";
            return true;
        }
        else
        {
            note = "create log dir failed, res: " + std::to_string(res);
            return false;
        }
    }
    catch (const std::exception &e)
    {
        note = "create log dir error: " + std::string(e.what());
    }
    return false;
}
} // namespace file
} // namespace utils