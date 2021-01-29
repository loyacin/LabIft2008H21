#include <gtest/gtest.h>
#include "../main/MaClass.cpp"

TEST(MaClass, pass)
{
    ASSERT_EQ(0, 0);
}

/**
TEST(MaClass, fail)
{
    ASSERT_EQ(0, 1);
}
*/

TEST(MaClass, givenEvenNumAber_whenIsEven_thenTrue)
{
    int evenNumber = 8;

    bool returnedIsEven = MaClass::isEven(evenNumber);

    ASSERT_TRUE(returnedIsEven);
}

TEST(MaClass, givenOddNumber_whenIsEven_thenFalse)
{
    int oddNumber = 3;

    bool returnedIsEven = MaClass::isEven(oddNumber);

    ASSERT_FALSE(returnedIsEven);
}

TEST(MaClass, givenANumber_whenTimesThreee_thenNumberTimesThreeIsReturned)
{
    int number = 42;

    int returnedNumber = MaClass::timesThree(number);

    int expectedNumber = 42 * 3;
    ASSERT_EQ(expectedNumber, returnedNumber);
}

TEST(MaClass, givenNumber_whenTimesThreee_thenNumberTimesThreeIsReturned)
{
    int number = 36;

    int returnedNumber = MaClass::timesThree(number);

    int expectedNumber = 36 * 3;
    ASSERT_EQ(expectedNumber, returnedNumber);
}
