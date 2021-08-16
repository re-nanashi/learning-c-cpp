#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<std::string> s_numbers{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::vector<std::string> i_numbers{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

bool legalInput(std::string input)
{
    for (int i = 0; i < s_numbers.size(); ++i)
    {
        if (input == s_numbers[i])
            return true;
    }

    for (int i = 0; i < i_numbers.size(); ++i)
    {
        if (input == i_numbers[i])
            return true;
    }

    return false;
}

int main()
{
    std::string input{" "};

    std::cout << "Please input a digit (string/number): \n";

    while (std::cin >> input)
    {
        if (!legalInput(input))
        {
            std::cout << "Illegal input \n";
            std::cout << "Please reenter a legal input. \n";
            continue;
        }

        for (int i = 0; i < s_numbers.size(); ++i)
        {
            if (input == s_numbers[i])
                std::cout << i << std::endl;
            if (input == i_numbers[i])
                std::cout << s_numbers[i] << std::endl;
        }
    }

    return 0;
}