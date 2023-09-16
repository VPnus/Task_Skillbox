# CMake generated Testfile for 
# Source directory: O:/QZskillbox_study/Test_JN/jsoncpp/src/jsontestrunner
# Build directory: O:/QZskillbox_study/Test_JN/cmake-build-debug/jsoncpp/src/jsontestrunner
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(jsoncpp_readerwriter "C:/Program Files (x86)/Microsoft Visual Studio/Shared/Python39_64/python.exe" "-B" "O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/../../test/runjsontests.py" "O:/QZskillbox_study/Test_JN/cmake-build-debug/jsoncpp-master/src/jsontestrunner/jsontestrunner_exe.exe" "O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/../../test/data")
set_tests_properties(jsoncpp_readerwriter PROPERTIES  WORKING_DIRECTORY "O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/../../test/data" _BACKTRACE_TRIPLES "O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/CMakeLists.txt;43;add_test;O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/CMakeLists.txt;0;")
add_test(jsoncpp_readerwriter_json_checker "C:/Program Files (x86)/Microsoft Visual Studio/Shared/Python39_64/python.exe" "-B" "O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/../../test/runjsontests.py" "--with-json-checker" "O:/QZskillbox_study/Test_JN/cmake-build-debug/jsoncpp-master/src/jsontestrunner/jsontestrunner_exe.exe" "O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/../../test/data")
set_tests_properties(jsoncpp_readerwriter_json_checker PROPERTIES  WORKING_DIRECTORY "O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/../../test/data" _BACKTRACE_TRIPLES "O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/CMakeLists.txt;47;add_test;O:/QZskillbox_study/Test_JN/jsoncpp-master/src/jsontestrunner/CMakeLists.txt;0;")
