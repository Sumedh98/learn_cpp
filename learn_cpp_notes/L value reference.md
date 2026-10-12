In C++ similar to pointers we have references. Seems like these are easier to understand. 
We pass the reference to functions instead of object itself. In C we used to do this with passing address. 

Here 
```cpp
// regular types
int        // a normal int type (not an reference)
int&       // an lvalue reference to an int object
double&    // an lvalue reference to a double object
const int& // an lvalue reference to a const int object
```

So the way we can use this is 

```cpp

#include<iostream>

int main()
{
	int x{5};
	int& y{x}; //now y actually refers to X. or in C terms it points to it. 
	
	// Here Y also holds value of X that is 5 since its basically alias to x
}
```

Important !
>For those of you already familiar with pointers, the ampersand in this context does not mean “address of”, it means “lvalue reference to”.


```cpp
int main()
{
    int& invalidRef;   // error: references must be initialized

    int x { 5 };
    int& ref { x }; // okay: reference to int is bound to int variable
    
	const int y { 5 };
    int& invalidRef { y };  // invalid: non-const lvalue reference can't bind to a non-modifiable lvalue
    int& invalidRef2 { 0 }; // invalid: non-const lvalue reference can't bind to an rvalue
    return 0;
}
```

>Once initialized, a reference in C++ cannot be **reseated**, meaning it cannot be changed to reference another object.
```cpp
#include <iostream>

int main()
{
    int x { 5 };
    int y { 6 };

    int& ref { x }; // ref is now an alias for x

    ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref)
    // The above line does NOT change ref into a reference to variable y!

    std::cout << x << '\n'; // user is expecting this to print 5

    return 0;
}
```

You cannot change the reference. It is bound to that object or lvalue. This is difference between a [[pointer]] and this I guess

### Dangling references
>When an object being referenced is destroyed before a reference to it, the reference is left referencing an object that no longer exists. Such a reference is called a **dangling reference**. Accessing a dangling reference leads to undefined behavior.



Lvalue references can only bind to modifiable lvalues.
Lvalue references to const can bind to modifiable lvalues, non-modifiable lvalues, and rvalues. This makes them a much more flexible type of reference.

```cpp
#include <iostream>

int main()
{
    const int& ref { 5 }; // The temporary object holding value 5 has its lifetime extended to match ref

    std::cout << ref << '\n'; // Therefore, we can safely use it here

    return 0;
} // Both ref and the temporary object die here
```

