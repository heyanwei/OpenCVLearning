#include <iostream>

#include <gflags/gflags.h>

DEFINE_bool(is_open_trace_log, true, "Do you want to see the trace logs?");

int main(int argc, char *argv[])
{
    gflags::ParseCommandLineFlags(&argc, &argv, true);  

    std::cout<<"is_open_trace_log: "<<FLAGS_is_open_trace_log<<std::endl;

    google::ShutDownCommandLineFlags();

    return 0;
}