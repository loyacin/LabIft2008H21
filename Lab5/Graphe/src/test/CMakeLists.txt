add_executable(grapheTesteur GrapheTesteur.cpp)
add_test(GrapheTesteur.cpp grapheTesteur)
target_link_libraries(grapheTesteur ${GTEST_LIBRARIES})

add_executable(algorithmesTesteur AlgorithmesTesteur.cpp)
add_test(AlgorithmesTesteur.cpp algorithmesTesteur)
target_link_libraries(algorithmesTesteur ${GTEST_LIBRARIES})
