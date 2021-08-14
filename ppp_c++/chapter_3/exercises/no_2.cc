//experimenting with pointers
//fully aware that this is bad practice

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

void mile_converter(double *miles);

int main()
{
    double var_mile;
    std::cout << "Enter number of miles to convert to kilometers: " << std::endl;
    std::cin >> var_mile;

    mile_converter(&var_mile);

    std::cout << "User input is " << var_mile << " in kilometers\n";

    return 0;
}

void mile_converter(double *miles)
{
    double conversion{1.609};
    *miles *= conversion;
}
