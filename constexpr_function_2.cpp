/*
Its a bit difficult to understand when the constexpr resolves to runtime and when at compile time. Below example gives a good understanding
*/

#include <iostream>

int getValue(int x)
{
    return x;
}

// This function can be evaluated at runtime
// When evaluated at compile-time, the function will produce a compilation error
// because the call to getValue(x) cannot be resolved at compile-time
constexpr int foo(int x)
{
    if (x < 0) return 0; // needed prior to adoption of P2448R1 in C++23 (see note below)
    return getValue(x);  // call to non-constexpr function here
}

int main()
{
    int x { foo(5) };           // okay: will evaluate at runtime
    constexpr int y { foo(5) }; // compile error: foo(5) can't evaluate at compile-time

    return 0;
}

/* here, even though foo is a constexperession, it is not truely constexp because getvalue is not a constexpr function
So its critical to make sure functions are truely constexpr so that when used in actual constexp it doesnot result in error 
*/