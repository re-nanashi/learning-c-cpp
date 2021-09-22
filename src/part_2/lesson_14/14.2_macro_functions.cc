#include <iostream>
#include <string>

#define SQUARE(x) ((x) * (x))
#define PI 3.1416
// ideally area of cirlce should be a function because macros are not type
// sensitive
#define AREA_CIRCLE(r) (PI * (r) * (r))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
    std::cout << "Enter an integer: ";
    int num = 0;
    std::cin >> num;

    std::cout << "SQUARE(" << num << ") = " << SQUARE(num) << std::endl;
    std::cout << "Area of a circle with radius" << num << " is: " << AREA_CIRCLE(num) << std::endl;

    std::cout << "Enter another integer: ";
    int num2 = 0;
    std::cin >> num2;

    std::cout << "MIN(" << num << ", " << num2 << ") = ";
    std::cout << MIN(num, num2) << std::endl;

    std::cout << "MAX(" << num << ", " << num2 << ") = ";
    std::cout << MAX(num, num2) << std::endl;

    return 0;
}
