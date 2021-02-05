#include "AddFunctions.h"
#include <iostream>

int add(int number, int otherNumber)
{
    std::cout << "int add";
    return number + otherNumber;
}

float add(float number, float otherNumber)
{
    std::cout << "float add";
    return number + otherNumber;
}

int* add(const int number[10], const int otherNumber[10])
{
    std::cout << "array add";
    int* finalArray = new int[10];
    for (int i = 0; i < 10; i++) {
        finalArray[i] = number[i] + otherNumber[i];
    }
    return finalArray;
}
