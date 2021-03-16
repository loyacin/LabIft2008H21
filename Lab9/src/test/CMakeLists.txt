set(SOURCE_FILES
        ../main/ContratException.cpp
        ../main/ContratException.h
        ../main/ArbreBinaire.hpp
        ArbreBinaireTesteur.cpp)
add_executable(arbreBinaireTesteur ${SOURCE_FILES})

add_test(ArbreBinaireTesteur.cpp arbreBinaireTesteur)
target_link_libraries(arbreBinaireTesteur ${GTEST_LIBRARIES})
