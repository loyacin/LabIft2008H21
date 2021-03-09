set(SOURCE_FILES
        ../main/ContratException.cpp
        ../main/ContratException.h
        ../main/FoncteurHachage.hpp
        TableHachageTesteur.cpp)
add_executable(tableHachageTesteur ${SOURCE_FILES})

add_test(TableHachageTesteur.cpp grapheTesteur)
target_link_libraries(tableHachageTesteur ${GTEST_LIBRARIES})
