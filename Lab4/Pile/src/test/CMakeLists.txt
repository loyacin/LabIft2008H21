add_executable(comparableH Comparable.h)
add_executable(comparableCpp Comparable.hpp)

add_executable(pileTesteur PileTesteur.cpp)
add_test(PileTesteur.cpp pileTesteur)
target_link_libraries(pileTesteur ${GTEST_LIBRARIES})
