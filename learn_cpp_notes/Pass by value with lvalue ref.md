
```cpp
#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;
}
```
Similar to pointer in C. But here it is simple. We are not passing the address of the object and then using a pointer to point to that. Here we just declare function with "&" and the when calling the function we still call it as regular function call. 

Pass by reference with const value. Const lvalue reference can bind to const and also non const values. So can be used in both ways
```cpp
#include <iostream>

void printRef(const int& y) // y is a const reference
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    printRef(x);   // ok: x is a modifiable lvalue, y binds to x

    const int z { 5 };
    printRef(z);   // ok: z is a non-modifiable lvalue, y binds to z

    printRef(5);   // ok: 5 is rvalue literal, y binds to temporary int object

    return 0;
}
```
but ofcourse the below is not allowed.
```cpp
void addOne(const int& ref)
{
    ++ref; // not allowed: ref is const
}
```
you can use const lvalue ref in functions as read only value but you cannot change the value itself as its a constant

>**Best Practice**
>Favor passing by const reference over passing by non-const reference unless you have a specific reason to do otherwise (e.g. the function needs to change the value of an argument).

