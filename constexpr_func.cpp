/* Const expression functions are the functions that can be used to initialize or create const expression
In the case below, compiler will replace the result value with whatever is evaluates at compile time y the constexpr function.

- It should also be noted that the function that is created as constexpr can also resolve itself to runtime function if non constexpr variables are given as input. 
This is great as we do not need to create 2 functions, one for constexpr and one for runtime. One function will act as both 
*/
#include <iostream>
using namespace std;

constexpr float multi(int a, int b)
{
    constexpr float pi = 3.14;
    return ((a*b)*pi);
}

int main()
{
    constexpr int a=2;
    constexpr int b=2;

    constexpr float res =  multi(a,b);

    std::cout << "Multiplication Result: "<< res <<endl;

}