add_executable(incrementDateTest IncrementDateTest.cpp)
add_test(IncrementDateTest.cpp incrementDateTest)
target_link_libraries(incrementDateTest ${GTEST_LIBRARIES})
