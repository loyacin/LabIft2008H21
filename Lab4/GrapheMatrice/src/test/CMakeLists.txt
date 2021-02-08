add_executable(grapheTesteur GrapheTesteur.cpp)
add_test(GrapheTesteur.cpp grapheTesteur)
target_link_libraries(grapheTesteur ${GTEST_LIBRARIES})
