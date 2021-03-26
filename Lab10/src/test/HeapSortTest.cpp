#include "gtest/gtest.h"
#include "../main/HeapSort.hpp"
#include <iostream>

TEST(HeapSort, givenAnEmptyVector_whenConstructHeap_thenHeapIsEmpty)
{
    std::vector<int> emptyVector;

    std::vector<int> returnedHeap = heapSort::constructHeap(emptyVector);

    ASSERT_TRUE(returnedHeap.empty());
}

TEST(HeapSort, givenANonEmptyVector_whenConstructHeap_thenGoodHeapIsReturned)
{
    std::vector<int> nonEmptyVector{2, 9, 7, 8, 5, 8};

    std::vector<int> returnedHeap = heapSort::constructHeap(nonEmptyVector);

    std::vector<int> expectedHeap{9, 6, 8, 2, 5, 7};
    ASSERT_EQ(expectedHeap, returnedHeap);
}

TEST(HeapSort, givenAnEmptyVector_whenHeapSort_thenSortedHeapIsEmpty)
{
    std::vector<int> emptyVector;

    std::vector<int> returnedSortedHeap = heapSort::heapSort(emptyVector);

    ASSERT_TRUE(returnedSortedHeap.empty());
}

TEST(HeapSort, givenANonEmptyVector_whenConstructHeap_thenGoodSortedHeapIsReturned)
{
    std::vector<int> nonEmptyVector{94, 67, 18, 44, 55, 12, 6, 42};

    std::vector<int> returnedHeap = heapSort::heapSort(nonEmptyVector);

    std::vector<int> expectedHeap{6, 12, 18, 42, 44, 55, 67, 94};
    ASSERT_EQ(expectedHeap, returnedHeap);
}