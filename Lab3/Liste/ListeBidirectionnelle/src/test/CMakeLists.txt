add_executable(listeTesteur ListeTesteur.cpp)
add_test(ListeTesteur.cpp listeTesteur)
target_link_libraries(listeTesteur ${GTEST_LIBRARIES})
