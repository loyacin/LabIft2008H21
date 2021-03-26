set(SOURCE_FILES
        ../main/HeapSort.hpp
        HeapSortTest.cpp)
add_executable(heapSortTest ${SOURCE_FILES})

add_test(HeapSortTest.cpp heapSortTest)
target_link_libraries(heapSortTest ${GTEST_LIBRARIES})
