#include "IncrementDate.h"

static bool hasThirtyOneDays(int month)
{
    return month == 1
           || month == 3
           || month == 5
           || month == 7
           || month == 8
           || month == 10
           || month == 12;
}

static bool hasThirtyDays(int month)
{
    return month == 4
           || month == 6
           || month == 9
           || month == 11;
}

static bool isLastDayOfTheMonth(int day, int month)
{
    return (day == 30 && hasThirtyDays(month))
           || (day == 31 && hasThirtyOneDays(month));
}

static int getNextDay(const Date &date)
{
    int actualDay = date.jour;
    int nextDay = date.jour + 1;
    if (isLastDayOfTheMonth(actualDay, date.mois))
    {
        nextDay = 1;
    }
    return nextDay;
}

static int getNextMonth(int day, int actualMonth)
{
    int nextMonth = actualMonth;
    if (day == 1)
    {
        nextMonth++;
    }
    if (nextMonth == 13)
    {
        nextMonth = 1;
    }
    return nextMonth;
}

static int getNextYear(int actualMonth, int actualYear)
{
    int nextYear = actualYear;
    if (actualMonth == 1)
    {
        nextYear++;
    }
    return nextYear;
}

static Date* incrementDate(const Date &date)
{
    int day, month, year;
    day = getNextDay(date);
    month = getNextMonth(day, date.mois);
    year = getNextYear(month, date.annee);
    return new Date {day, month, year};
}
