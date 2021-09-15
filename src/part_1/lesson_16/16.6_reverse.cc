#include <algorithm>
#include <iostream>
#include <string>

bool isPalindrome(std::string &str)
{
    std::string original_str{str};
    std::reverse(original_str.begin(), original_str.end());

    if (str == original_str)
        return true;
    else
        return false;
}

int main()
{
    std::string sampleStr{"Hello String! We will reverse you!"};
    std::cout << "The original sample string is: " << std::endl;
    std::cout << sampleStr << std::endl << std::endl;

    std::reverse(sampleStr.begin(), sampleStr.end());

    std::cout << "After applying std::reverse algorithm: " << std::endl;
    // Reverses the string variable
    std::cout << sampleStr << std::endl;

    std::string user_input{""};
    std::cin >> user_input;
    if (isPalindrome(user_input))
    {
        std::cout << "Hey cool shit you got there!" << std::endl;
    }
    else
    {
        std::cout << "Shut up bitch" << std::endl;
    }
    return 0;
}
