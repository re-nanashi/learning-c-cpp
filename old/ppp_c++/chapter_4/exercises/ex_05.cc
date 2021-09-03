#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

double calculate(double val1, double val2, char op)
{
    double answer{0.0};
    switch (op)
    {
    case '+':
        answer = val1 + val2;
        break;
    case '-':
        answer = val1 - val2;
        break;
    case '*':
        answer = val1 * val2;
        break;
    case '/':
        answer = val1 / val2;
        break;
    default:
        std::cout << "invalid operator\n";
        break;
    }

    return answer;
}

int main()
{
    double num1{0.0}, num2{0.0}, answer{0.0};
    char cal_operator;
    std::cout << "Please enter two numbers and an operation: \n";
    std::cin >> num1 >> num2 >> cal_operator;

    answer = calculate(num1, num2, cal_operator);
    std::cout << "The sum of " << num1 << " and " << num2 << " is " << answer << ".\n";

    return 0;
}