
In lame man terms, L value is something that has a name and lives in memory and can be referenced later
R-value is something that has temporary value. 

example
x=5 here x is an L value

y= x+5, the expression x+5 is an R value because it is temporary. 
Same goes for like `x = foo();` here also return of a function is remporary for its R-value

As a general rule of thumb, left of = sign is L-value and right of = is R value. not always but generrally

> Lvalue expressions evaluate to an identifiable object.  
> Rvalue expressions evaluate to a value.

In situation like y=x; x is a L-value but will undergo l->r transformation

Function to print if something is L or R value. here T& refers to template asking for a an L value as reference

```cpp
#include <iostream>
#include <string>

// T& is an lvalue reference, so this overload will be preferred for lvalues
template <typename T>
constexpr bool is_lvalue(T&)
{
    return true;
}

// T&& is an rvalue reference, so this overload will be preferred for rvalues
template <typename T>
constexpr bool is_lvalue(T&&)
{
    return false;
}

// A helper macro (#expr prints whatever is passed in for expr as text)
#define PRINTVCAT(expr) { std::cout << #expr << " is an " << (is_lvalue(expr) ? "lvalue\n" : "rvalue\n"); }

int getint() { return 5; }

int main()
{
    PRINTVCAT(5);        // rvalue
    PRINTVCAT(getint()); // rvalue
    int x { 5 };
    PRINTVCAT(x);        // lvalue
    PRINTVCAT(std::string {"Hello"}); // rvalue
    PRINTVCAT("Hello");  // lvalue
    PRINTVCAT(++x);      // lvalue
    PRINTVCAT(x++);      // rvalue
}
```