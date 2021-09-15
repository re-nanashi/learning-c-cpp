// Write a program that tells the user the number of vowels in a sentece.
// 1. iterate through the string then check if i % 2 == 0 ? upper case : do nothing

#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::string user_input{""};

    do
    {
        std::cout << "Enter a valid string: " << std::endl;
        std::cin >> user_input;
    } while (user_input == "");

    for (int i = 1; i <= user_input.length(); ++i)
    {
        if (i % 2 == 0)
        {
            user_input[i - 1] = toupper(user_input[i - 1]);
        }
    }
    std::cout << "Result: " << user_input << std::endl;

    return 0;
}
