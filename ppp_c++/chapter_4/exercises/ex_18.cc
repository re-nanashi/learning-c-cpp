#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    double a, b, c;
    std::cout << "Enter a, b, and c to solve the quadratic equation in the form ax^2 + bx + c = 0 where a != 0\n";
    std::cin >> a >> b >> c;

    double outside_b{-1 * b};
    double inside_sqrt{sqrt((b * b) - (4 * a * c))};
    double denominator{2 * a};

    double first_answer = (outside_b + inside_sqrt) / denominator;
    double second_answer = (outside_b - inside_sqrt) / denominator;

    std::cout << "x1: " << first_answer << "\n";
    std::cout << "x2: " << second_answer << "\n";

    return 0;
}