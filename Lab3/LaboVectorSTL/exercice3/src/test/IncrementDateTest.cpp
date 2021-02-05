#include <gtest/gtest.h>
#include <random>
#include "../main/IncrementDate.cpp"

void assertDateAreEqual(const Date& expectedDate, const Date& actualDate)
{
    ASSERT_EQ(expectedDate.jour, actualDate.jour);
    ASSERT_EQ(expectedDate.mois, actualDate.mois);
    ASSERT_EQ(expectedDate.annee, actualDate.annee);
}

TEST(IncrementDate, givenADayInTheMiddleOfAMonth_whenIncrementDate_thenNextDayIsReturned)
{
    Date dayInTheMiddleOfAMonth {14, 2, 2021};

    Date* returnedDate = incrementDate(dayInTheMiddleOfAMonth);

    Date expectedDate {15, 2, 2021};
    assertDateAreEqual(expectedDate, *returnedDate);
}

TEST(IncrementDate, givenADayAtTheEndOfAMonth_whenIncrementDate_thenNextDayIsFirstDayOfNextMonth)
{
    Date dayInTheMiddleOfAMonth {31, 3, 2021};

    Date* returnedDate = incrementDate(dayInTheMiddleOfAMonth);

    Date expectedDate {1, 4, 2021};
    assertDateAreEqual(expectedDate, *returnedDate);
}

TEST(IncrementDate, givenADayAtTheEndOfAYear_whenIncrementDate_thenNextDayIsFirstDayOfNextYear)
{
    Date dayInTheMiddleOfAMonth {31, 12, 2021};

    Date* returnedDate = incrementDate(dayInTheMiddleOfAMonth);

    Date expectedDate {1, 1, 2022};
    assertDateAreEqual(expectedDate, *returnedDate);
}
