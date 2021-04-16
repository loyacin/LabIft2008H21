set(SOURCE_FILES
        ../main/Tri.h
        ../main/TriBulle.hpp
        ../main/TriFusion.hpp
        ../main/TriInsertion.hpp
        ../main/TriParTas.hpp
        ../main/TriRapide.hpp
        ../main/TriSelection.hpp
        ../main/TriShell.hpp
        ../main/main.cpp
        TriTesteur.cpp)
add_executable(sortTest ${SOURCE_FILES})

add_test(TriTesteur.cpp sortTest)
target_link_libraries(sortTest ${GTEST_LIBRARIES})
