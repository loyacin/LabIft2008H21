set(SOURCE_FILES
        ../main/ContratException.cpp
        ../main/ContratException.h
        GrapheTesteur.cpp
        AlgorithmesTesteur.cpp)
add_executable(grapheTesteur ${SOURCE_FILES})

add_test(GrapheTesteur.cpp grapheTesteur)
target_link_libraries(grapheTesteur ${GTEST_LIBRARIES})

add_test(AlgorithmesTesteur.cpp grapheTesteur)
target_link_libraries(grapheTesteur ${GTEST_LIBRARIES})
