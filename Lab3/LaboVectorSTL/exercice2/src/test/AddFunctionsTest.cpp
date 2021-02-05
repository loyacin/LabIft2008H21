#include <gtest/gtest.h>
#include <random>
#include "../main/AddFunctions.cpp"

int getRandomInt()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 0;
    int max = 100;
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

TEST(AddFunctions, givenTwoInts_whenAdd_thenIntsAreAdded)
{
    int firstNumber = getRandomInt();
    int secondNumber = getRandomInt();

    int result = add(firstNumber, secondNumber);

    int expectedNumber = firstNumber + secondNumber;
    ASSERT_EQ(expectedNumber, result);
}

TEST(AddFunctions, givenTwoFloats_whenAdd_thenFloatsAreAdded)
{
    float firstNumber = 6.6;
    float secondNumber = 7.7;

    float result = add(firstNumber, secondNumber);

    float expectedNumber = firstNumber + secondNumber;
    ASSERT_EQ(expectedNumber, result);
}

TEST(AddFunctions, givenTwoArraysOfInt_whenAdd_thenArraysOfIntAreAddedComponentWise)
{
    int firstArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int secondArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int* result = add(firstArray, secondArray);

    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(2 * i, result[i]);
    }
    delete result;
}

TEST(AddFunctions, givenTwoShorts_whenAdd_thenShortsAreAdded)
{
    short firstNumber = 3;
    short secondNumber = 6;

    short result = add(firstNumber, secondNumber);

    short expectedNumber = firstNumber + secondNumber;
    ASSERT_EQ(expectedNumber, result);
}
