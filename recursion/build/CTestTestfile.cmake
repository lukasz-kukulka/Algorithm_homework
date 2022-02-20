# CMake generated Testfile for 
# Source directory: /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/recursion
# Build directory: /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/recursion/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(module2_test "/home/lukasz_k/Dokumenty/Programing/Algorithm_homework/recursion/build/module2-ut")
set_tests_properties(module2_test PROPERTIES  _BACKTRACE_TRIPLES "/home/lukasz_k/Dokumenty/Programing/Algorithm_homework/recursion/CMakeLists.txt;52;add_test;/home/lukasz_k/Dokumenty/Programing/Algorithm_homework/recursion/CMakeLists.txt;0;")
subdirs("googletest-build")
subdirs("tests")
