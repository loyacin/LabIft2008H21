add_executable(addFunctionsTest AddFunctionsTest.cpp)
add_test(AddFunctionsTest.cpp addFunctionsTest)
target_link_libraries(addFunctionsTest ${GTEST_LIBRARIES})
