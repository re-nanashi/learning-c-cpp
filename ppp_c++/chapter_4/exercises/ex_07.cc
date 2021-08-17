#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<std::string> s_numbers{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int get_number()
{
    int input{0};
    if (std::cin >> input)
        return input;
    std::cin.clear();

    std::string s_input;
    std::cin >> s_input;
    for (int i = 0; i < s_numbers.size(); ++i)
    {
        if (s_numbers[i] == s_input)
            return i;
    }

    return (-1);
}

int main()
{
    int num1, num2;
    char cal_operator;

    std::cout << "Please enter two numbers and an operation: \n";
    num1 = get_number();
    std::cin >> cal_operator;
    num2 = get_number();

    if (num1 == -1 || num2 == -1)
    {
        std::cout << "invalid input.\n";
        return 0;
    }

    switch (cal_operator)
    {
    case '+':
        std::cout << num1 << " " << cal_operator << " " << num2 << " is equal to " << num1 + num2 << ".\n";
        break;
    case '-':
        std::cout << num1 << " " << cal_operator << " " << num2 << " is equal to " << num1 - num2 << ".\n";
        break;
    case '*':
        std::cout << num1 << " " << cal_operator << " " << num2 << " is equal to " << num1 * num2 << ".\n";
        break;
    case '/':
        if (num2 == 0)
        {
            std::cout << "Input 1 is divided by 0 thus answer is indeterminate. \n";
            break;
        }
        else
        {
            std::cout << num1 << " " << cal_operator << " " << num2 << " is equal to " << num1 / num2 << ".\n";
            break;
        }
    default:
        std::cout << "invalid operator\n";
        break;
    }

    return 0;
}
