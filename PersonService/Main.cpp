#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include "gtest/gtest.h"

#include "utils/file/directory.h"

DEFINE_bool(is_open_trace_log, true, "Do you want to see the trace logs?");


int main(int argc, char *argv[])
{
    std::string res="";
    utils::file::createdir("log/", res);
    std::cout<<res<<std::endl;

    gflags::ParseCommandLineFlags(&argc, &argv, true);  

    FLAGS_log_dir = "log/";
    FLAGS_max_log_size = 1;
    FLAGS_alsologtostderr = true;

    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();

    testing::InitGoogleTest(&argc, argv);

    LOG(INFO)<<"is_open_trace_log: "<<FLAGS_is_open_trace_log;

    int testres = RUN_ALL_TESTS();
    LOG(INFO)<<"RUN_ALL_TESTS finish, res: "<<testres;

    google::ShutdownGoogleLogging();
    google::ShutDownCommandLineFlags();

    return 0;
}