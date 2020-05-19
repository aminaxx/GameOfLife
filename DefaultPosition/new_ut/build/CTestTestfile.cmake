# CMake generated Testfile for 
# Source directory: /home/user/Desktop/new_ut
# Build directory: /home/user/Desktop/new_ut/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(CunitTest "/home/user/Desktop/new_ut/build/unit_test")
set_tests_properties(CunitTest PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Desktop/new_ut/CMakeLists.txt;26;add_test;/home/user/Desktop/new_ut/CMakeLists.txt;0;")
subdirs("mylib")
