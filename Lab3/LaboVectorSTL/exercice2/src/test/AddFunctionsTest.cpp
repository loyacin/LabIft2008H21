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
