#include <iostream>

int main()
{
    int x{};
    char ch{};

    std::cout << "Enter an integer\n";
    std::cin >> x;

    std::cout << "Enter a char\n";
    std::cin >> ch;

    std::cout << "User entered integer and chat are " << x << ch << "\n";
    return 0;
}

