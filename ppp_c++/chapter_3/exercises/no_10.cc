#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    std::string operation;
    double val1, val2;

    std::cin >> operation >> val1 >> val2;
    if (!std::cin)
        std::cout << "error has occured" << std::endl;

    if (operation == "+" || operation == "plus")
        std::cout << val1 + val2 << std::endl;

    if (operation == "-" || operation == "minus")
        std::cout << val1 - val2 << std::endl;

    if (operation == "*" || operation == "mul")
        std::cout << val1 * val2 << std::endl;

    if (operation == "/" || operation == "div")
        std::cout << val1 / val2 << std::endl;

    return 0;
}