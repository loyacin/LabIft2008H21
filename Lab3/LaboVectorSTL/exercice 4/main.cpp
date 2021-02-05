#include <iostream>

int main()
{
    int pInt = 6;
    int *p = &pInt;
    const int qInt = 6;
    qInt = 7;
    int *q = &qInt;
    int rInt = 6;
    rInt = 7;
    const int * const r = &qInt;
    *r = &pInt;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
