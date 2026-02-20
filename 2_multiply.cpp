#include <iostream>

int doubleNumber(int x)
{
    return x*2;
}

int main()
{
    int x =10;
    std::cout << "Double of number "  << x << " is " << doubleNumber(x) << "\n";
}
