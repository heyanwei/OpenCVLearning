# CMake generated Testfile for 
# Source directory: /home/wilson/code/opencv/source/opencv-master/modules/core
# Build directory: /home/wilson/code/opencv/source/opencv-master/build/modules/core
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_core "/home/wilson/code/opencv/source/opencv-master/build/bin/opencv_test_core" "--gtest_output=xml:opencv_test_core.xml")
set_tests_properties(opencv_test_core PROPERTIES  LABELS "Main;opencv_core;Accuracy" WORKING_DIRECTORY "/home/wilson/code/opencv/source/opencv-master/build/test-reports/accuracy")
add_test(opencv_perf_core "/home/wilson/code/opencv/source/opencv-master/build/bin/opencv_perf_core" "--gtest_output=xml:opencv_perf_core.xml")
set_tests_properties(opencv_perf_core PROPERTIES  LABELS "Main;opencv_core;Performance" WORKING_DIRECTORY "/home/wilson/code/opencv/source/opencv-master/build/test-reports/performance")
add_test(opencv_sanity_core "/home/wilson/code/opencv/source/opencv-master/build/bin/opencv_perf_core" "--gtest_output=xml:opencv_perf_core.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_core PROPERTIES  LABELS "Main;opencv_core;Sanity" WORKING_DIRECTORY "/home/wilson/code/opencv/source/opencv-master/build/test-reports/sanity")
