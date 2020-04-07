#include "directory.h"

#include "gtest/gtest.h"
#include <glog/logging.h>

namespace utils
{
namespace file
{

TEST(DirTest, Check)
{
    std::string note;
    bool res = deletedir("dir", note);
    LOG(INFO) << "first time delete dir, res- " << res << ", note- " << note;
    res = isdirexist("dir", note);
    LOG(INFO) << "first time check dir, res- " << res << ", note- " << note;

    res = createdir("dir", note);
    LOG(INFO) << "first time create dir, res- " << res << ", note- " << note;

    res = isdirexist("dir", note);
    LOG(INFO) << "second time check dir, res- " << res << ", note- " << note;

    res = createdir("dir", note);
    LOG(INFO) << "second time create dir, res- " << res << ", note- " << note;
}

} // namespace file
} // namespace utils