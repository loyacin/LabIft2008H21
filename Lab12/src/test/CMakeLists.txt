set(SOURCE_FILES
        ../main/AVL.hpp
        AVLTesteur.cpp)
add_executable(avlTreeTest ${SOURCE_FILES})

add_test(AVLTesteur.cpp avlTreeTest)
target_link_libraries(avlTreeTest ${GTEST_LIBRARIES})
