// Write a program to verify whether the word input by the user is a palindrome.
// For example: ATOYOTA is a palindrome, as the word does not change when
// reversed.

#include <algorithm>
#include <iostream>
#include <string>

void checkIfPalindrome(std::string &user_input)
{
    std::string reversedStrCont{user_input};
    std::reverse(reversedStrCont.begin(), reversedStrCont.end());

    if (user_input == reversedStrCont)
        std::cout << "User input: " << user_input << " is a palindrome!" << std::endl;
    else
        std::cout << "User input: " << user_input << " is " << reversedStrCont << " if reversed." << std::endl;
}

int main()
{
    std::string user_input{""};
    do
    {
        std::cout << "Input a word: \n";
        std::cin >> user_input;
    } while (user_input != "");

    checkIfPalindrome(user_input);

    return 0;
}
