add_executable(myClassTest MaClassTest.cpp)
add_test(MaClassTest.cpp myClassTest)
target_link_libraries(myClassTest ${GTEST_LIBRARIES})
