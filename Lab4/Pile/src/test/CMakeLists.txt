add_executable(pileTesteur PileTesteur.cpp)
add_test(PileTesteur.cpp pileTesteur)
target_link_libraries(pileTesteur ${GTEST_LIBRARIES})
